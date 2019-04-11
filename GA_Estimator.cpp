// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "GA_Estimator.h"


GA_Estimator::GA_Estimator() {

    initialize_GA_params();
    initializeOutputFile();
}



GA_Estimator::GA_Estimator(Parameters *ptr_paramObj, TimeSeriesObservations* ptr_tsObservationsObj, ModelFormParameters* ptr_modelParametersObj) {

    m_generationBestFitness = 10000000000.0;
    m_bestOverallFitness = 10000000000.0;

    m_timeSeriesPtr = ptr_tsObservationsObj;
    m_paramsPtr = ptr_paramObj;
    m_bestChromosome = ptr_paramObj;
    m_paramsPtr->clearBiomassMatrix();
    m_modelFormPtr = ptr_modelParametersObj;

    initialize_GA_params();
    initializeOutputFile();
    m_MTRand();
}


GA_Estimator::~GA_Estimator() {

    m_outfile.close();
}


void GA_Estimator::initialize_GA_params() {

    m_generation = 0;
    m_numGenerationsSinceBestFit = 0;

    m_populationSize = m_paramsPtr->get_GA_populationSize();
    m_mutationRate = m_paramsPtr->get_GA_mutationRate();
    m_maxGenerations = m_paramsPtr->get_GA_generations();
    m_convergenceNumber = m_paramsPtr->get_GA_convergenceNumber();
}


void GA_Estimator::setSaveFilenames(QString filename, QString filenamebest) {

    m_OutputFilename = filename;
    m_OutputFilenameBest = filenamebest;
}


void GA_Estimator::estimateParameters() {


    // Create population of randomly created individual chromosomes including all parameters to be estimated

    int numSpecies = m_paramsPtr->getNumberOfSpecies();
    qDebug() << "\n";

    m_mutationRate = getMutationRate();
    m_mutationRate = 25;
    for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
        m_generation = 0;
        m_numGenerationsSinceBestFit = 0;
        m_generationBestFitness = 10000000000.0;
        m_bestOverallFitness = 10000000000.0;
        createPopulation();
        calculateFitness(speciesIndex);
        eliminateUnfit();
        calculateSelectionProbabilities();
//        outputResults();

        //    for (int generation = 0; generation < m_maxGenerations; generation++) {
        while ((m_generation <= m_maxGenerations) && (m_numGenerationsSinceBestFit < m_convergenceNumber)) {
            // Determine next population until fitness below cutoff level

            createNextGeneration();
            // Determine fitness of each chromosome
            calculateFitness(speciesIndex);

            // Eliminate completely unfit individuals (those with a nan value)
            eliminateUnfit();

            // Create Selection Probabilities
            calculateSelectionProbabilities();

            // Output Results
//          appendResults();

      //      qDebug() << "Sp " << speciesIndex << " : Gen #" << m_generation << " : " << m_bestOverallFitness << " : # Gens Since Best = " << m_numGenerationsSinceBestFit;
        }
        m_bestChromosomeList.append(*m_bestChromosome);
        qDebug() << "Sp " << speciesIndex << " : Gen #" << m_generation << " : " << m_bestOverallFitness;
    }
    createFullChromosomeFromSS();
    m_bestChromosome->resetChromosomeAfterSS();
    outputBestRun();

    m_paramsPtr = m_bestChromosome;
    m_populationSize = m_populationSize * 1.0;
    m_mutationRate = getMutationRate();
    m_convergenceNumber = m_convergenceNumber * 1.0;
    m_generation = 0;
    m_numGenerationsSinceBestFit = 0;
    m_generationBestFitness = 10000000000.0;
    m_bestOverallFitness = 10000000000.0;
    createPopulation();
    calculateFitness();
    eliminateUnfit();
    calculateSelectionProbabilities();

   // outputResults();
   while ((m_generation <= m_maxGenerations) && (m_numGenerationsSinceBestFit < m_convergenceNumber)) {
        // Determine next population until fitness below cutoff level

        createNextGeneration();
        // Determine fitness of each chromosome
        calculateFitness();

        // Eliminate completely unfit individuals (those with a nan value)
        eliminateUnfit();

        // Create Selection Probabilities
        calculateSelectionProbabilities();

        // Output Results
//      appendResults();

//        qDebug() << "Sp " << speciesIndex << " : Gen #" << m_generation << " : " << m_bestOverallFitness << " : # Gens Since Best = " << m_numGenerationsSinceBestFit;

        m_bestChromosomeList.append(*m_bestChromosome);
        qDebug() << " : Gen #" << m_generation << " : " << m_bestOverallFitness;
    }
   outputBestRun();
}


double GA_Estimator::getMutationRate() {

    QList<double> chromosomeList = m_paramsPtr->getChromosomeList();
    int chromosomeSize = chromosomeList.size();
    double numEstimatedParameters = 0;
    double min, max;
    for (int i = 0; i < chromosomeSize; i++) {
        min = m_paramsPtr->getChromosomeMin(i);
        max = m_paramsPtr->getChromosomeMax(i);
        if (min != max) {
            numEstimatedParameters++;
        }
    }
    double mutationRate = (1 / numEstimatedParameters) * 100;
    qDebug() << "Estimated Parameters: " << numEstimatedParameters << " :: Mutation Rate: " << mutationRate;
    return mutationRate;
}



void GA_Estimator::createFullChromosomeFromSS() {

    int numSpecies = m_paramsPtr->getNumberOfSpecies();
    Parameters bestSSchromosome = m_bestChromosomeList.at(0);
    QList<double> bestCombinedChromosome = bestSSchromosome.getChromosomeList();
    for (int speciesIndex = 1; speciesIndex < numSpecies; speciesIndex++) {
        // Iterate through each best chromosome for the selected species
        bestSSchromosome = m_bestChromosomeList.at(speciesIndex);
        QList<double> ssChromosome = bestSSchromosome.getChromosomeList();
        // Set the values on the best chromosome
        // Initial Biomass
        int nextIndex = speciesIndex;
        double value = ssChromosome.at(nextIndex);
        bestCombinedChromosome.replace(nextIndex, value);
        // Growth rates
        nextIndex += numSpecies;
        value = ssChromosome.at(nextIndex);
        bestCombinedChromosome.replace(nextIndex, value);
        // Survey Q's
        nextIndex += numSpecies;
        value = ssChromosome.at(nextIndex);
        bestCombinedChromosome.replace(nextIndex, value);
        // Species K's
        nextIndex += numSpecies;
        value = ssChromosome.at(nextIndex);
        bestCombinedChromosome.replace(nextIndex, value);

        nextIndex += numSpecies*(speciesIndex+1) - speciesIndex;
        for (int i = 0; i < numSpecies; i++) {
            value = ssChromosome.at(nextIndex);
            bestCombinedChromosome.replace(nextIndex, value);
            nextIndex++;
        }
        for (int i = 0; i < numSpecies; i++) {
            value = ssChromosome.at(nextIndex);
            bestCombinedChromosome.replace(nextIndex, value);
            nextIndex++;
        }
    }
    m_bestChromosome->setChromosomeList(bestCombinedChromosome);
    int bestChromosomeSize = bestCombinedChromosome.size();
    for (int i = 0; i < bestChromosomeSize; i++) {
        std::cout << bestCombinedChromosome.at(i) << " ";
    }
}


void GA_Estimator::calculateFitness() {

    int popSize = m_chromosomeParametersList.size();
    double fitness = 0.0;
    double RMSE = 0.0;

    m_chromosomeFitnessList.clear();
    m_chromosomeRMSElist.clear();
    QList<double> chromosomeList;
    Parameters tempParam = m_chromosomeParametersList.at(0);
    Parameters* tempParamPtr = &tempParam;
    Model model(tempParamPtr, m_modelFormPtr);
    for (int i = 0; i < popSize; i++) {
        Parameters tempParam = m_chromosomeParametersList.at(i);
        Parameters* tempParamPtr = &tempParam;
//        tempParamPtr->initializeListsAndTS(0);
//        Model model(tempParamPtr, m_modelFormPtr);
        model.initializeModel(tempParamPtr);
        model.runModel_noOutput();
        m_measureOfFitnessObj.calculateMeasuresOfFitness(tempParamPtr,m_timeSeriesPtr);

        fitness = m_measureOfFitnessObj.getRMSE_modified();
        RMSE = m_measureOfFitnessObj.getRMSE();
        fitness = m_measureOfFitnessObj.getMEF_modified();
//        fitness = RMSE;
        if (fitness < m_bestOverallFitness) {
            m_bestOverallFitness = fitness;
            chromosomeList = tempParamPtr->getChromosomeList();
            m_bestChromosome->setChromosomeList(chromosomeList);
            m_numGenerationsSinceBestFit = 0;
        }
        m_chromosomeFitnessList.append(fitness);
        m_chromosomeRMSElist.append(RMSE);
    }

}


void GA_Estimator::createPopulation() {

    // Get parameters to estimate
    QList<double> chromosomeList = m_paramsPtr->getChromosomeList();
    int chromosomeSize = chromosomeList.size();
    // Create population of randomly created individual chromosomes which include all parameters to be estimated
    double paramValue;
    double logParamValue;
    double diff;
    double max;
    double min;
    double max_log;
    double min_log;
    for (int i = 0; i < m_populationSize; i++) {
        Parameters paramChromosome = *m_paramsPtr;
        paramChromosome.setFitting(true);
        QList<double> newChromosome;
        for (int j = 0; j < chromosomeSize; j++) {
            min = m_paramsPtr->getChromosomeMin(j);
            max = m_paramsPtr->getChromosomeMax(j);
            if (min == max) {
                newChromosome.append(min);
            } else {
                min_log = log(min+0.000000000000001);
                max_log = log(max+0.000000000000001);
                diff = max_log - min_log;
                logParamValue = m_MTRand.rand(diff) + min_log;
                paramValue = exp(logParamValue);
                newChromosome.append(paramValue);
            }
        }
        paramChromosome.setChromosomeList(newChromosome);
        m_chromosomeParametersList.append(paramChromosome);
    }
}


void GA_Estimator::calculateFitness(int speciesIndex) {

    int popSize = m_chromosomeParametersList.size();
    double fitness = 0.0;
    double RMSE = 0.0;
    m_chromosomeFitnessList.clear();
    m_chromosomeRMSElist.clear();
    QList<double> chromosomeList;

    // New code
    // Get parameter chromosome list from first member of population
    Parameters tempParam = m_chromosomeParametersList.at(0);
    Parameters* tempParamPtr = &tempParam;
    tempParamPtr->zeroInteractionCoefficients();
    Model model(tempParamPtr, m_modelFormPtr);

    for (int i = 0; i < popSize; i++) {
        Parameters tempParam = m_chromosomeParametersList.at(i);
        Parameters* tempParamPtr = &tempParam;
        tempParamPtr->zeroInteractionCoefficients();
//        tempParamPtr->initializeListsAndTS(0);
//        Model model(tempParamPtr, m_modelFormPtr);
        model.initializeModel(tempParamPtr);

        model.runModel_noOutput();
        m_measureOfFitnessObj.calculateMeasuresOfFitness(tempParamPtr,m_timeSeriesPtr,speciesIndex);

//        fitness = m_measureOfFitnessObj.getRMSE_modified();
        RMSE = m_measureOfFitnessObj.getRMSE();
        fitness = m_measureOfFitnessObj.getMEF_modified();
//        fitness = RMSE;
        if (fitness < m_bestOverallFitness) {
            m_bestOverallFitness = fitness;
            chromosomeList = tempParamPtr->getChromosomeList();
            m_bestChromosome->setChromosomeList(chromosomeList);
            m_numGenerationsSinceBestFit = 0;
        }
        m_chromosomeFitnessList.append(fitness);
        m_chromosomeRMSElist.append(RMSE);
    }

}


void GA_Estimator::eliminateUnfit() {

    int popSize = m_chromosomeParametersList.size();

    QList<Parameters> validChromosomesList;
    QList<double> validChromosomesFitnessList;

    for (int i = 0; i < popSize; i++) {
        if (!std::isnan(m_chromosomeFitnessList.at(i)) && !std::isinf(m_chromosomeFitnessList.at(i))) {
            Parameters tempParam = m_chromosomeParametersList.at(i);
            double tempFitness = m_chromosomeFitnessList.at(i);
            validChromosomesList.append(tempParam);
            validChromosomesFitnessList.append(tempFitness);
        }
    }

    m_chromosomeParametersList = validChromosomesList;
    m_chromosomeFitnessList = validChromosomesFitnessList;
}


void GA_Estimator::calculateSelectionProbabilities() {

    int popSize = m_chromosomeParametersList.size();

    // Reverse the fitnesses so that larger values are more fit.  Needed for calculation purposes
    QList<double> reversedChromosomesFitnessList;

    // Determine max value
    double maxValue = 0.0;
    double currentValue = 0.0;
    for (int i = 0; i < popSize; i++) {
        currentValue = m_chromosomeFitnessList.at(i);
        if (currentValue > maxValue) {
            maxValue = currentValue;
        }
    }

    // Perform reversal of fitnesses and keep track of the total sum of the reversed fitness values
    double reversedValue = 0.0;
    double sumOfFitness = 0.0;
    for (int i = 0; i < popSize; i++) {
        currentValue = m_chromosomeFitnessList.at(i);
        reversedValue = maxValue / currentValue;
        reversedChromosomesFitnessList.append(reversedValue);
        sumOfFitness += reversedValue;
    }

    // Calculate selection probabilities
    m_chromosomeSelectionProbabilityList.clear();
    double selectionProbability = 0.0;
    for (int i = 0; i < popSize; i++) {
        selectionProbability = reversedChromosomesFitnessList.at(i) / sumOfFitness;
        m_chromosomeSelectionProbabilityList.append(selectionProbability);
    }

    // Create Roulette Wheel
    m_rouletteWheelList.clear();
    int numberOfTickets = 0;
    for (int i = 0; i < popSize; i++) {
        numberOfTickets = m_chromosomeSelectionProbabilityList.at(i) * 100;
        for (int n = 0; n < numberOfTickets; n++) {
            m_rouletteWheelList.append(i);
        }
    }

}


void GA_Estimator::createNextGeneration() {


    // Increase generation number
    m_generation++;
    m_numGenerationsSinceBestFit++;

    rouletteSelection();
}


void GA_Estimator::tournamentSelection() {

    int tournamentSize = 10;
    int popSize = m_chromosomeParametersList.size();

    int firstParentIndex;
    int secondParentIndex;
    int potParentIndex;

    for (int i = 0; i < m_populationSize; i++) {
       firstParentIndex = m_MTRand.rand(popSize);
        for (int p = 1; p < tournamentSize; p++) {
            potParentIndex = m_MTRand.rand(popSize);
            if (m_chromosomeFitnessList.at(potParentIndex) > m_chromosomeFitnessList.at(firstParentIndex)) {
                firstParentIndex = potParentIndex;
            }
        }

        secondParentIndex = m_MTRand.rand(popSize);
        for (int p = 1; p < tournamentSize; p++) {
            potParentIndex = m_MTRand.rand(popSize);
            if (m_chromosomeFitnessList.at(potParentIndex) > m_chromosomeFitnessList.at(firstParentIndex)) {
                secondParentIndex = potParentIndex;
            }
        }
    }
}


void GA_Estimator::rouletteSelection() {

    long numOfTickets = m_rouletteWheelList.size();

    int firstTicket;
    int secondTicket;
    int firstParentIndex;
    int secondParentIndex;

    Parameters firstParent;
    Parameters secondParent;
    Parameters firstChild;

    QList<double> firstParentList;
    QList<double> secondParentList;
    QList<double> firstChildList;

    double testForMutationValue;

    QList<Parameters> nextGenChromosomeParametersList;

    double newParamValue = 0.0;
    double logNewParamValue = 0.0;
    double min = 0.0;
    double max = 0.0;
    double diff = 0.0;

    for (int i = 0; i < m_populationSize; i++) {
        firstTicket = m_MTRand.rand(numOfTickets);
        secondTicket = m_MTRand.rand(numOfTickets);
        firstParentIndex = m_rouletteWheelList.at(firstTicket);
        secondParentIndex = m_rouletteWheelList.at(secondTicket);

        firstParent = m_chromosomeParametersList.at(firstParentIndex);
        secondParent = m_chromosomeParametersList.at(secondParentIndex);
        firstParentList = firstParent.getChromosomeList();
        secondParentList = secondParent.getChromosomeList();

        int chromosomeSize = firstParentList.size();

        // Reset child
        firstChildList.clear();

        // For each parameter in the chromosome, recombine parents into new offspring
        for (int c = 0; c < chromosomeSize; c++) {
            min = m_paramsPtr->getChromosomeMin(c);
            max = m_paramsPtr->getChromosomeMax(c);
            if (min == max) {
                firstChildList.append(min);
            } else {
                double randParam = m_MTRand.rand();

               if ((firstParentList.at(c) < 0) && (secondParentList.at(c) < 0)) {
//                    logNewParamValue = (log(firstParentList.at(c)*-1) + log(secondParentList.at(c)*-1)) / 2;
                    logNewParamValue = (log(firstParentList.at(c)*-1))*randParam + (log(secondParentList.at(c)*-1)) * (1-randParam);
                    newParamValue = exp(logNewParamValue)*-1;
//                    newParamValue = (firstParentList.at(c)*-1 + secondParentList.at(c)*-1) / 2;
                } else {
                    logNewParamValue = (log(firstParentList.at(c))) * randParam + (log(secondParentList.at(c))) * (1-randParam);
                    newParamValue = exp(logNewParamValue);
//                    newParamValue = (firstParentList.at(c) + secondParentList.at(c)) / 2;
                }

               // Check for mutation
                testForMutationValue = m_MTRand.rand() * 100;
                if (testForMutationValue <= m_mutationRate) {
                    int mode = 1;
                    newParamValue = mutate(newParamValue, mode, min, max);
                }
//                  diff = max - min;
//                    newParamValue = m_MTRand.rand(diff) + min;
//                }
                firstChildList.append(newParamValue);
            }
//            qDebug() << "Param #:" << c << " :: " << "Min: " << min << " :: Max: " << max << "ParamValue: " << newParamValue;
        }
        firstChild = *m_paramsPtr;
        firstChild.setChromosomeList(firstChildList);
        firstChild.setFitting(true);
        nextGenChromosomeParametersList.append(firstChild);
    }
    m_chromosomeParametersList = nextGenChromosomeParametersList;
}


double GA_Estimator::mutate(double value, int mode, double min, double max) {

    double newValue = 0.0;
    // Modes
    // 1: Random between min and max

    int mutationMode = mode;
    double diff = 0.0;
    switch (mutationMode) {
        case 1:
            diff = max - min;
            newValue = m_MTRand.rand(diff) + min;
            break;
        case 2:
            double randValue = m_MTRand.rand();
            double delta_L = 0.0;
            double delta_R = 0.0;
            double indexParam = 20;
            double exponent = 1 / (1 + indexParam);
            double base = 0.0;

            if (randValue <= 0.5) {
                base = 2 * randValue;
                delta_L = pow(base, exponent) - 1;
                newValue = value + delta_L * (value - min);
        //        qDebug() << "MUTATING: RandValue = " << randValue << " :: Base = " << base << " :: Exponent = " << exponent << " :: delta_L = " << delta_L;
            } else {
                base = 2 * (1 - randValue);
                delta_R = 1 - pow(base, exponent);
                newValue = value + delta_R * (max - value);
        //        qDebug() << "MUTATING: RandValue = " << randValue << " :: Base = " << base << " :: Exponent = " << exponent << " :: delta_R = " << delta_R;
            }
        //    qDebug() << "Min = " << min << " :: Max = " << max << " :: Old Value = " << value << " :: New Value = " << newValue;
            break;
    }
    return newValue;
}


void GA_Estimator::initializeOutputFile() {

//    m_outfile = QFile("/home/rgamble/Desktop/KRAKEN/GA_output.csv");
//    if (!m_outfile.open(QIODevice::WriteOnly | QIODevice::Text)) {
//         qDebug() << "GA output file NOT OPENED";
//    }
//    m_textStreamOut(&m_outfile);
//    m_textStreamOut << "Generation,Chromosome,RMSE,Selection Probability";
//    double numParameters = m_paramsPtr->getNumberOfSpecies();
//    QString paramString;
//    QString newParamString;
//    for (int i = 0; i < numParameters; i++) {
//        newParamString.setNum(i+1);
//        paramString = "Parameter ";
//        paramString.append(newParamString);
//        m_textStreamOut << paramString << ",";
//    }
//    m_textStreamOut << "\n";

}

void GA_Estimator::outputResults() {

//    QFile outfile(m_OutputFilename);
//    if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
//         qDebug() << "GA output file NOT OPENED";
//    QTextStream textStreamOut(&outfile);
    QFile outfileBest(m_OutputFilenameBest);
    if (!outfileBest.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "GA Best output file NOT OPENED";
    QTextStream textStreamOutBest(&outfileBest);

//    textStreamOut << "Generation,Chromosome,Fitness,RMSE,Selection Probability,";
    textStreamOutBest << "Generation,Chromosome,Fitness,RMSE,Selection Probability,";
    double numParameters = m_paramsPtr->getChromosomeListSize();
//    qDebug() << "Number Parameters: " << numParameters;
    QString paramString;
    QString newParamString;
    for (int i = 0; i < numParameters; i++) {
        newParamString.setNum(i+1);
        paramString = "Parameter ";
        paramString.append(newParamString);
//        textStreamOut << paramString << ",";
        textStreamOutBest << paramString << ",";
    }
//    textStreamOut << "\n";
    textStreamOutBest << "\n";
    qDebug() << "After last parameter";
    int popSize = m_chromosomeParametersList.size();
    int chromosomeSize;

//    qDebug() << "Pop size: " << popSize;
    QList<double> chromosomeList;
    m_generationBestFitness = 1000000000000000.0;
    int bestFitnessIndex = 0;
    for (int i = 0; i < popSize; i++) {
//        textStreamOut << m_generation << "," << i << "," << m_chromosomeFitnessList.at(i) << "," << m_chromosomeRMSElist.at(i) << "," << m_chromosomeSelectionProbabilityList.at(i) << ",";
        Parameters tempParam = m_chromosomeParametersList.at(i);
        chromosomeList = tempParam.getChromosomeList();
        chromosomeSize = chromosomeList.size();
//        for (int j = 0; j < chromosomeSize; j++) {
//            textStreamOut << chromosomeList.at(j) << ",";
//        }
//        textStreamOut << "\n";

        if (m_chromosomeFitnessList.at(i) < m_generationBestFitness) {
            bestFitnessIndex = i;
            m_generationBestFitness = m_chromosomeFitnessList.at(i);
        }
    }
    textStreamOutBest << m_generation << "," << bestFitnessIndex << "," << m_chromosomeFitnessList.at(bestFitnessIndex) << "," << m_chromosomeRMSElist.at(bestFitnessIndex) << "," << m_chromosomeSelectionProbabilityList.at(bestFitnessIndex) << ",";
    Parameters tempParam = m_chromosomeParametersList.at(bestFitnessIndex);
    chromosomeList = tempParam.getChromosomeList();
    chromosomeSize = chromosomeList.size();
    for (int j = 0; j < chromosomeSize; j++) {
        textStreamOutBest << chromosomeList.at(j) << ",";
    }
    textStreamOutBest << "\n";
//    outfile.close();
    outfileBest.close();
}


void GA_Estimator::appendResults() {

//    QFile outfile(m_OutputFilename);
//    if (!outfile.open(QIODevice::Append | QIODevice::Text))
//         qDebug() << "GA output file NOT OPENED";
//    QTextStream textStreamOut(&outfile);
    QFile outfileBest(m_OutputFilenameBest);
    if (!outfileBest.open(QIODevice::Append | QIODevice::Text))
        qDebug() << "GA Best output file NOT OPENED";
    QTextStream textStreamOutBest(&outfileBest);

    int popSize = m_chromosomeParametersList.size();
    int chromosomeSize;

    QList<double> chromosomeList;
    m_generationBestFitness = 1000000000000000.0;
    int bestFitnessIndex;
    for (int i = 0; i < popSize; i++) {
//        textStreamOut << m_generation << "," << i << "," << m_chromosomeFitnessList.at(i) << "," << m_chromosomeRMSElist.at(i) << "," << m_chromosomeSelectionProbabilityList.at(i) << ",";

        if (m_chromosomeFitnessList.at(i) < m_generationBestFitness) {
            bestFitnessIndex = i;
            m_generationBestFitness = m_chromosomeFitnessList.at(i);
        }
        Parameters tempParam = m_chromosomeParametersList.at(i);
        chromosomeList = tempParam.getChromosomeList();
        chromosomeSize = chromosomeList.size();
//        for (int j = 0; j < chromosomeSize; j++) {
//            textStreamOut << chromosomeList.at(j) << ",";
//        }
//        textStreamOut << "\n";
    }
    textStreamOutBest << m_generation << "," << bestFitnessIndex << "," << m_chromosomeFitnessList.at(bestFitnessIndex) << "," << m_chromosomeRMSElist.at(bestFitnessIndex) << "," << m_chromosomeSelectionProbabilityList.at(bestFitnessIndex) << ",";
    Parameters tempParam = m_chromosomeParametersList.at(bestFitnessIndex);
    chromosomeList = tempParam.getChromosomeList();
    chromosomeSize = chromosomeList.size();
    for (int j = 0; j < chromosomeSize; j++) {
        textStreamOutBest << chromosomeList.at(j) << ",";
    }
    textStreamOutBest << "\n";
//    outfile.close();
    outfileBest.close();

}

void GA_Estimator::outputBestRun() {

    Model model(m_bestChromosome, m_modelFormPtr);
    model.runModel();
}
