#include "KrakenConsole.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QVariant>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

KrakenConsole::KrakenConsole() {
    std::cout << "Default Constructor";
}

KrakenConsole::KrakenConsole(int &argc, char **argv)
{
/*    QFile* logOutputFile = new QFile("logOut.txt");
//    if (!logOutputFile->open(QIODevice::WriteOnly | QIODevice::Text))
//         qDebug() << "Output file NOT OPENED";
//    m_logOutputFile = *logOutputFile;
//    m_logOutputFileStream = new QTextStream(&m_logOutputFile);*/
    std::string argument;
    std::string parameterFilename;
    std::string dataFilename;
    std::string outputFilename;
    std::string dataID;
    m_dataID = "000";
    m_fit = false;

    for (int i = 1; i < argc; i++) {
        argument = argv[i];
        if (argument == "-p") {
            i++;
            parameterFilename = argv[i];
            std::cout << "Parameter Filename = " << parameterFilename << "\n";
            m_parameterFilename = QString::fromStdString(parameterFilename);
/*            QString q_parameterFilename = QString::fromStdString(parameterFilename);
            QStringList q_parameterFilenameList = q_parameterFilename.split("\\");
            int sizeOfList = q_parameterFilenameList.size();
            if (sizeOfList == 1) {
                m_parameterFilename = q_parameterFilename;
            } else {
                m_parameterFilename = q_parameterFilenameList.at(sizeOfList-1);
                q_parameterFilenameList.removeLast();
                QString q_outputDirectory = q_parameterFilenameList.join("\\");
                q_outputDirectory.append("\\");
                m_parameterDirectory = q_outputDirectory;
                std::cout << "Parameter Filename = " << m_parameterFilename.toStdString() << " :: Parameter Directory = " << m_parameterDirectory.toStdString() << "\n";
            }
*/
        } else if (argument == "-id") {
            i++;
            dataID = argv[i];
            std::cout << "Data ID = " << dataID << "\n";
            m_dataID = QString::fromStdString(dataID);
            m_logOutputFileStream << "rSeed: " << m_dataID << "\n";
        } else if (argument == "-d") {
            i++;
            dataFilename = argv[i];
            std::cout << "Data Filename = " << dataFilename << "\n";
            m_dataFilename = QString::fromStdString(dataFilename);
        } else if (argument == "-o") {
            i++;
            outputFilename = argv[i];
            std::cout << "Output Filename = " << outputFilename << "\n";
            QString q_outputFilename = QString::fromStdString(outputFilename);
            QStringList q_outputFilenameList = q_outputFilename.split("\\");
            int sizeOfList = q_outputFilenameList.size();
            if (sizeOfList == 1) {
                m_outputFilename = q_outputFilename;
                m_outputDirectory = QDir::currentPath();
            } else {
                m_outputFilename = q_outputFilenameList.at(sizeOfList-1);
                q_outputFilenameList.removeLast();
                QString q_outputDirectory = q_outputFilenameList.join("\\");
                q_outputDirectory.append("\\");
                m_outputDirectory = q_outputDirectory;
                std::cout << "Output Filename = " << m_outputFilename.toStdString() << " :: Output Directory = " << m_outputDirectory.toStdString() << "\n";
            }
        } else if (argument == "-fit"){
            m_fit = true;
        } else {
            std::cout << "Argument not found: " << argument << "\n";
        }

    }
}

void KrakenConsole::startConsole() {
    setArgumentParameters();
    loadFromParameterFile();
    if (m_fit) {
        fitModel();
    } else {
        runModel();
    }
}


void KrakenConsole::setArgumentParameters() {

    paramObj.setRseed(m_dataID);
    paramObj.setSaveFilename(m_outputFilename);
    paramObj.setOutputDirectory(m_outputDirectory);
}


void KrakenConsole::loadFromParameterFile() {
    QFile file(m_parameterFilename);
    std::cout << "Parameter filename: " << m_parameterFilename.toStdString();
    if (file.exists()) {
       file.open(QIODevice::ReadOnly | QIODevice::Text);
        std::cout << "Opening File";
    } else {
        std::cout << "File does not exist";
    }
    QTextStream parameterFileStream(&file);
    while(!parameterFileStream.atEnd())
    {
        QString line;
        line = parameterFileStream.readLine();
        lineList = line.split(",");
        QString parameterName = lineList.at(0);
        // Convert parameter name to upper case to allow case insensitivity
        parameterName = parameterName.toUpper();
        parameterName = parameterName.trimmed();
//        std::cout << parameterName.toStdString();
        if (parameterName == "SYSTEM CARRYING CAPACITY") {
            setSystemK();
        } else if (parameterName == "SPECIES") {
            setSpecies();
        } else if (parameterName == "INITIAL BIOMASS") {
            setInitialBiomass();
        } else if (parameterName == "INITIAL BIOMASS MIN") {
            setInitialBiomassMin();
        } else if (parameterName == "INITIAL BIOMASS MAX") {
            setInitialBiomassMax();
        } else if (parameterName == "SPECIES K") {
            setSpeciesK();
        } else if (parameterName == "SPECIES K MIN") {
            setSpeciesMinK();
        } else if (parameterName == "SPECIES K MAX") {
            setSpeciesMaxK();
        } else if (parameterName == "SPECIES K COVARIATE COEFFICIENT") {
            setSpeciesKCovariateCoefficients();
        } else if (parameterName == "SURVEY Q") {
            setSurveyQ();
        } else if (parameterName == "SURVEY Q MIN") {
            setSurveyMinQ();
        } else if (parameterName == "SURVEY Q MAX") {
            setSurveyMaxQ();
        } else if (parameterName == "UNITS") {
            setUnits();
        } else if (parameterName =="ASSESSMENT TYPE") {
            setAssessmentType();
        } else if (parameterName == "GUILDS") {
            setGuilds();
        } else if (parameterName == "GUILD MEMBERSHIP") {
            setGuildMembership();
        } else if (parameterName == "GROWTH RATE") {
            setGrowthRates();
        } else if (parameterName == "GROWTH RATE MIN") {
            setGrowthRatesMin();
        } else if (parameterName == "GROWTH RATE MAX") {
            setGrowthRatesMax();
        } else if (parameterName == "GROWTH RATE COVARIATE COEFFICIENT") {
            setGrowthRateCovariateCoefficients();
        } else if (parameterName == "HARVEST RATE") {
            setHarvestRates();
        } else if (parameterName == "COVARIATE TS") {
            setCovariateTimeSeries();
        } else if (parameterName == "STDEV STOCHASTIC GROWTH") {
            setStDevStochasticGrowth();
        } else if (parameterName == "STDEV STOCHASTIC CATCH") {
            setStDevStochasticCatch();
        } else if (parameterName == "CATCHABILITY") {
            QList<QList<double> > *catchabilityMatrix = new QList<QList<double> >;
            catchabilityMatrix = initializeTimeSeriesMatrix(parameterFileStream);
            paramObj.setCatchabilityMatrix(*catchabilityMatrix);
            delete catchabilityMatrix;
        } else if (parameterName == "EFFORT") {
            QList<QList<double> > *effortMatrix = new QList<QList<double> >;
            effortMatrix = initializeTimeSeriesMatrix(parameterFileStream);
            paramObj.setEffortMatrix(*effortMatrix);
            delete effortMatrix;
        } else if (parameterName == "BETWEEN GUILD COMPETITION COEFFICIENT") {
            QList<QList<double> > *betweenGuildCompMatrix = new QList<QList<double> >;
            QString paramLine;
            QList<QString> guildList = paramObj.getGuildList();
            int numGuilds = guildList.size();
            for (int i = 0; i < numGuilds; i++) {
                paramLine = parameterFileStream.readLine();
//                std::cout << i << " : " << paramLine;
                QStringList paramLineList = paramLine.split(",");
                paramLineList.removeFirst();
                double parameter = 0.0;
                QString strParameter = "";
                QList<double> *newList = new QList<double>;
                for (int i=0; i < numGuilds; i++) {
                    strParameter = paramLineList.at(i);
                    parameter = strParameter.toDouble();
                    newList->append(parameter);
                }
                betweenGuildCompMatrix->append(*newList);
            }
            paramObj.setBetweenGuildCompMatrix(*betweenGuildCompMatrix);
            delete betweenGuildCompMatrix;
        } else if ((parameterName == "WITHIN GUILD COMPETITION COEFFICIENT") || (parameterName == "BETWEEN SPECIES COMPETITION COEFFICIENT") || (parameterName == "BETWEEN SPECIES INTERACTION COEFFICIENT")) {
            QList<QList<double> > *withinGuildCompMatrix = new QList<QList<double> >;
            withinGuildCompMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setWithinGuildCompMatrix(*withinGuildCompMatrix);
            delete withinGuildCompMatrix;

        } else if ((parameterName == "WITHIN GUILD COMPETITION COEFFICIENT MIN") || (parameterName == "BETWEEN SPECIES COMPETITION COEFFICIENT MIN") || (parameterName == "BETWEEN SPECIES INTERACTION COEFFICIENT MIN")) {
            QList<QList<double> > *withinGuildCompMinMatrix = new QList<QList<double> >;
            withinGuildCompMinMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setWithinGuildCompMinMatrix(*withinGuildCompMinMatrix);
            delete withinGuildCompMinMatrix;

        } else if ((parameterName == "WITHIN GUILD COMPETITION COEFFICIENT MAX") || (parameterName == "BETWEEN SPECIES COMPETITION COEFFICIENT MAX") || (parameterName == "BETWEEN SPECIES INTERACTION COEFFICIENT MAX")) {
            QList<QList<double> > *withinGuildCompMaxMatrix = new QList<QList<double> >;
            withinGuildCompMaxMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setWithinGuildCompMaxMatrix(*withinGuildCompMaxMatrix);
            delete withinGuildCompMaxMatrix;

        } else if ((parameterName == "BETWEEN GUILD COMPETITION COEFFICIENT MIN") || (parameterName == "BETWEEN GROUP COMPETITION COEFFICIENT MIN") || (parameterName == "BETWEEN GROUP INTERACTION COEFFICIENT MIN")) {
            QList<QList<double> > *betweenGuildCompMinMatrix = new QList<QList<double> >;
            betweenGuildCompMinMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setBetweenGuildCompMinMatrix(*betweenGuildCompMinMatrix);
            delete betweenGuildCompMinMatrix;

        } else if ((parameterName == "BETWEEN GUILD COMPETITION COEFFICIENT MAX") || (parameterName == "BETWEEN GROUP COMPETITION COEFFICIENT MAX") || (parameterName == "BETWEEN GROUP INTERACTION COEFFICIENT MAX")) {
            QList<QList<double> > *betweenGuildCompMaxMatrix = new QList<QList<double> >;
            betweenGuildCompMaxMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setBetweenGuildCompMaxMatrix(*betweenGuildCompMaxMatrix);
            delete betweenGuildCompMaxMatrix;

        } else if (parameterName == "PREDATION LOSS RATES") {
            QList<QList<double> > *predationMatrix = new QList<QList<double> >;
            predationMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setPredationMatrix(*predationMatrix);
            delete predationMatrix;

        } else if (parameterName == "PREDATION LOSS RATES MIN") {
            QList<QList<double> > *predationLossRatesMinMatrix = new QList<QList<double> >;
            predationLossRatesMinMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setPredationLossRatesMinMatrix(*predationLossRatesMinMatrix);
            delete predationLossRatesMinMatrix;

        } else if (parameterName == "PREDATION LOSS RATES MAX") {
            QList<QList<double> > *predationLossRatesMaxMatrix = new QList<QList<double> >;
            predationLossRatesMaxMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setPredationLossRatesMaxMatrix(*predationLossRatesMaxMatrix);
            delete predationLossRatesMaxMatrix;

        } else if (parameterName == "HANDLING TIMES") {
            QList<QList<double> > *handlingTimeMatrix = new QList<QList<double> >;
            handlingTimeMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setHandlingTimeMatrix(*handlingTimeMatrix);
            delete handlingTimeMatrix;

        } else if (parameterName == "TYPE III B COEFFICIENTS") {
            QList<QList<double> > *bCoefMatrix = new QList<QList<double> >;
            bCoefMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setbCoefMatrix(*bCoefMatrix);
            delete bCoefMatrix;

        } else if (parameterName == "SPATIAL OVERLAP") {
            QList<QList<double> > *spatialOverlapMatrix = new QList<QList<double> >;
            spatialOverlapMatrix = initializeParamMatrix(parameterFileStream);
            paramObj.setSpatialOverlapMatrix(*spatialOverlapMatrix);
            delete spatialOverlapMatrix;

        } else if (parameterName == "CATCH") {
            QList<QList<double> > *catchMatrix = new QList<QList<double> >;
            catchMatrix = initializeTimeSeriesMatrix(parameterFileStream);
            paramObj.setCatchMatrix(*catchMatrix);
            delete catchMatrix;
        } else if (parameterName == "PELAGIC") {
            setPelProportionList();
        } else if (parameterName == "DEMERSAL") {
            setDemProportionList();
        } else if (parameterName == "GROWTH FORM") {
            setGrowthMode();
        } else if (parameterName == "PREDATION FORM") {
            setPredationMode();
        } else if (parameterName == "HARVEST FORM") {
            setHarvestMode();
        } else if (parameterName == "WITHIN GUILD COMPETITION FORM") {
            setwgcMode();
        } else if (parameterName == "BETWEEN GUILD COMPETITION FORM") {
            setbgcMode();
        } else if (parameterName == "STOCHASTIC GROWTH") {
            setStochasticGrowth();
        } else if (parameterName == "STOCHASTIC CATCH") {
            setStochasticCatch();
        } else if (parameterName == "NUMBER OF RUNS") {
            setNumRuns();
        } else if (parameterName == "RUN LENGTH") {
            setRunLength();
        } else if (parameterName == "HISTORICAL END") {
            setHistoricalEnd();
        } else if (parameterName == "TIME STEP") {
            setTimeStep();
        } else if (parameterName == "CV ASSESSMENT") {
            setAssessmentCV();
        } else if (parameterName == "INDICATOR SPECIES") {
            setIndicatorSpecies();
        } else if (parameterName == "ACL BUFFER") {
            setACL_Buffer();
        } else if (parameterName == "ASSESSMENT INTERVAL") {
            setNumYearsBetweenAssessments();
        } else if (parameterName == "OUTPUT TYPE") {
            setOutputType();
        } else if (parameterName == "GA GENERATIONS") {
            set_GA_generations();
        } else if (parameterName == "GA POPULATION SIZE") {
            set_GA_populationSize();
        } else if (parameterName == "GA MUTATION RATE") {
            set_GA_mutationRate();
        } else if (parameterName == "GA CONVERGENCE NUMBER") {
            set_GA_convergenceNumber();
        } else if (parameterName != "") {
//            std::cout << "Missing Parameter Value: " << parameterName.toStdString();
        }
    }
    file.close();
    paramObj.setLoadedTrue();
    std::cout << "DONE PARAMETER READING";

    // Log outputs to screen
    KrakenConsole::logResults();
}


void KrakenConsole::loadFromDataFile() {
    QFile file(m_dataFilename);
    std::cout << "Parameter filename: " << m_parameterFilename.toStdString();
    if (file.exists()) {
       file.open(QIODevice::ReadOnly | QIODevice::Text);
        std::cout << "Opening File";
    } else {
        std::cout << "File does not exist";
    }
    QTextStream tsFileStream(&file);
    int numSpecies = paramObj.getNumberOfSpecies();

    while(!tsFileStream.atEnd())
    {
        QString tsLine;
        tsLine = tsFileStream.readLine();
        lineList = tsLine.split(",");
        QString tsName = lineList.at(0);
        // Convert parameter name to upper case to allow case insensitivity
        tsName = tsName.toUpper();
        tsName = tsName.trimmed();
        if (tsName == "BIOMASS") {
            QList<double> *initialBiomassList = new QList<double>;
            QString initialBiomassStr = "0";
            for (int i=0; i < numSpecies; i++) {
                tsLine = tsFileStream.readLine();
                QStringList tsLineList = tsLine.split(",");
                tsObj.setBiomass(tsLineList);
                // First element of string is the species name
                initialBiomassStr = tsLineList.at(1);
                initialBiomassList->append(initialBiomassStr.toDouble());
            }
            paramObj.setInitialBiomassList(*initialBiomassList);
            delete initialBiomassList;
        } else if (tsName == "CATCH") {
            QList<QList<double> > *catchMatrix = new QList<QList<double> >;
            QList<double> *catchList = new QList<double>;
            QString catchStr = "";
            double catchVal = 0;
            for (int i=0; i < numSpecies; i++) {
                tsLine = tsFileStream.readLine();
                QStringList tsLineList = tsLine.split(",");
                tsObj.setCatch(tsLineList);
                int catchVectorSize = tsLineList.size();
                for (int j=1; j < catchVectorSize; j++) {
                    catchStr = tsLineList.at(j);
                    catchVal = catchStr.toDouble();
                    catchList->append(catchVal);
                }
                catchMatrix->append(*catchList);
                catchList->clear();
            }
            paramObj.setCatchMatrix(*catchMatrix);
            delete catchMatrix;
        } else if (tsName == "BIOMASS MULTIPLIER") {
            for (int i=0; i < numSpecies; i++) {
                tsLine = tsFileStream.readLine();
                QStringList tsLineList = tsLine.split(",");
                tsObj.setBiomassMultiplier(tsLineList);
            }
        } else {
        std::cout << "Missing Parameter Value: " << tsName.toStdString();
        }
    }
    file.close();

    tsObj.outputBiomass();
    tsObj.outputCatch();
    tsObj.outputBiomassMultiplier();
}


QList<QList<double> >* KrakenConsole::initializeParamMatrix(QTextStream & paramFileStream) {

    QList<QList<double> > *paramMatrix = new QList<QList<double> >;
    QString paramLine;
    int numSpecies = paramObj.getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        paramLine = paramFileStream.readLine();
//        std::cout << i << " : " << paramLine;
        QStringList paramLineList = paramLine.split(",");
        paramLineList.removeFirst();
        paramLineList.removeAll("");
        double parameter = 0.0;
        QString strParameter = "";
        QList<double> *newList = new QList<double>;
        for (int i=0; i < numSpecies; i++) {
            strParameter = paramLineList.at(i);
            parameter = strParameter.toDouble();
            newList->append(parameter);
        }
        paramMatrix->append(*newList);
        delete newList;
    }
    return paramMatrix;
}


QList<QList<double> >* KrakenConsole::initializeTimeSeriesMatrix(QTextStream & paramFileStream) {

    QList<QList<double> > *paramMatrix = new QList<QList<double> >;
    QString paramLine;
    int numSpecies = paramObj.getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        paramLine = paramFileStream.readLine();
//        std::cout << i << " : " << paramLine.toStdString();
        QStringList paramLineList = paramLine.split(",");
        paramLineList.removeFirst();
        double parameter = 0.0;
        QString strParameter = "";
        QList<double> *newList = new QList<double>;
        int catchVectorSize = paramLineList.size();
        for (int i=0; i < catchVectorSize; i++) {
            strParameter = paramLineList.at(i);
            parameter = strParameter.toDouble();
            newList->append(parameter);
        }
        delete newList;
        paramMatrix->append(*newList);
    }
    return paramMatrix;
}


void KrakenConsole::logResults() {

    // Print various parameters to screen after parameter file created
//    QStringList strSpeciesList = paramObj.getSpeciesList();
//    std::cout << strSpeciesList;

//    paramObj.printGrowthRateList();

  //  paramObj.printInitialBiomassList();

//    paramObj.printWithinGuildCompMatrix();

    //paramObj.printBetweenGuildCompMatrix();

    //paramObj.printPredationMatrix();

    //paramObj.printSpatialOverlapMatrix();

    //paramObj.printPelagicProportionList();

    //paramObj.printDemersalProportionList();

//    paramObj.printGuildList();

//    paramObj.printSpeciesGuildMembershipHash();

//    paramObj.printSpeciesKList();

}


void KrakenConsole::setSystemK() {

    QString strSystemK = lineList.at(1);
    double systemK = strSystemK.toDouble();
    paramObj.setSystemK(systemK);
    double sysK = paramObj.getSystemK();
    QString sSysK = convertDoubleToString(sysK);
}


void KrakenConsole::setUnits() {

    QString strUnits = lineList.at(1);
    paramObj.setBiomassUnits(strUnits);
}


void KrakenConsole::setOutputType() {

    QString strOutputType = lineList.at(1);
    paramObj.setOutputType(strOutputType);
}


QList<double> KrakenConsole::returnParameterList() {

    lineList.removeFirst();
    lineList.removeAll("");
    int lineListSize = lineList.size();
    double parameter = 0.0;
    QList<double> parameterList;
    for (int i = 0; i < lineListSize; i++) {
        parameter = lineList.at(i).toDouble();
        parameterList.append(parameter);
    }
    return parameterList;
}


void KrakenConsole::setSpecies() {

    lineList.removeFirst();
    lineList.removeAll("");
    paramObj.setSpeciesList(lineList);
}


void KrakenConsole::setSpeciesK() {

    QList<double> speciesKList = returnParameterList();
    paramObj.setSpeciesKList(speciesKList);
}


void KrakenConsole::setInitialBiomass() {

    QList<double> initialBiomassList = returnParameterList();
    paramObj.setInitialBiomassList(initialBiomassList);

}

void KrakenConsole::setInitialBiomassMin() {

    QList<double> initialBiomassMinList = returnParameterList();
    paramObj.setInitialBiomassMinList(initialBiomassMinList);

}

void KrakenConsole::setInitialBiomassMax() {

    QList<double> initialBiomassMaxList = returnParameterList();
    paramObj.setInitialBiomassMaxList(initialBiomassMaxList);

}

void KrakenConsole::setSpeciesMinK() {

    QList<double> speciesMinKList = returnParameterList();
    paramObj.setSpeciesK_MinList(speciesMinKList);
}


void KrakenConsole::setSpeciesMaxK() {

    QList<double> speciesMaxKList = returnParameterList();
    paramObj.setSpeciesK_MaxList(speciesMaxKList);
}


void KrakenConsole::setSpeciesKCovariateCoefficients() {

    QList<double> speciesKCovariateCoefficientsList = returnParameterList();
    paramObj.setSpeciesKCovariatesList(speciesKCovariateCoefficientsList);
}


void KrakenConsole::setSurveyQ() {

    QList<double> surveyQList = returnParameterList();
    paramObj.setSurveyQList(surveyQList);
}


void KrakenConsole::setSurveyMinQ() {

    QList<double> surveyMinQList = returnParameterList();
    paramObj.setSurveyQ_MinList(surveyMinQList);
}


void KrakenConsole::setSurveyMaxQ() {

    QList<double> surveyMaxQList = returnParameterList();
    paramObj.setSurveyQ_MaxList(surveyMaxQList);
}


void KrakenConsole::setHarvestRates() {

    QList<double> harvestRateList = returnParameterList();
    paramObj.setHarvestRateList(harvestRateList);
}

void KrakenConsole::setGrowthRates() {

    QList<double> growthRateList = returnParameterList();
    paramObj.setGrowthRates(growthRateList);
    paramObj.setOriginalGrowthRates(growthRateList);
}


void KrakenConsole::setGrowthRatesMin() {

    QList<double> growthRateMinList = returnParameterList();
    paramObj.setGrowthRatesMin(growthRateMinList);
}


void KrakenConsole::setGrowthRatesMax() {

    QList<double> growthRateMaxList = returnParameterList();
    paramObj.setGrowthRatesMax(growthRateMaxList);
}


void KrakenConsole::setGrowthRateCovariateCoefficients() {

    QList<double> growthRateCovariateCoefficientsList = returnParameterList();
    paramObj.setGrowthRateCovariateList(growthRateCovariateCoefficientsList);
}


void KrakenConsole::setCovariateTimeSeries() {

    QList<double> covariateTimeSeriesList = returnParameterList();
    paramObj.setCovariatesList(covariateTimeSeriesList);
}


void KrakenConsole::setStDevStochasticGrowth() {

    QString strStDev = lineList.at(1);
    double stDev = strStDev.toDouble();
    paramObj.setStDevGrowth(stDev);
}


void KrakenConsole::setStDevStochasticCatch() {

    QString strStDev = lineList.at(1);
    double stDev = strStDev.toDouble();
    paramObj.setStDevCatch(stDev);
}


void KrakenConsole::setNumRuns() {

    QString strNumRuns = lineList.at(1);
    int numRuns = strNumRuns.toInt();
    modelFormParamObj.setNumRuns(numRuns);
}


void KrakenConsole::setRunLength() {

    QString strRunLength = lineList.at(1);
    int runLength = strRunLength.toInt();
    modelFormParamObj.setRunLength(runLength);
}


void KrakenConsole::setHistoricalEnd() {

    QString strHistEnd = lineList.at(1);
    int histEnd = strHistEnd.toInt();
    std::cout << "Setting Historical End: " << histEnd;
    modelFormParamObj.setHistoricalEnd(histEnd);
    int HistEnd = modelFormParamObj.getHistoricalEnd();
    std::cout << "Historical End immediately after being set: " << HistEnd;
}


void KrakenConsole::setTimeStep() {

    QString strTimeStep = lineList.at(1);
    int timeStep = strTimeStep.toInt();
    modelFormParamObj.setTimeStep(timeStep);
}


void KrakenConsole::set_GA_generations() {

    QString strGenerations = lineList.at(1);
    int generations = strGenerations.toInt();
    paramObj.set_GA_generations(generations);
}


void KrakenConsole::set_GA_populationSize() {

    QString strPopSize = lineList.at(1);
    int populationSize = strPopSize.toInt();
    paramObj.set_GA_populationSize(populationSize);
}


void KrakenConsole::set_GA_mutationRate() {

    QString strMutRate = lineList.at(1);
    double mutationRate = strMutRate.toDouble();
    paramObj.set_GA_mutationRate(mutationRate);
}


void KrakenConsole::set_GA_convergenceNumber() {

    QString strConNum = lineList.at(1);
    int convergenceNumber = strConNum.toInt();
    paramObj.set_GA_convergenceNumber(convergenceNumber);
}


void KrakenConsole::setPelProportionList() {

    QList<double> pelProportionList = returnParameterList();
    paramObj.setPelagicProportionList(pelProportionList);
}

void KrakenConsole::setDemProportionList() {

    QList<double> demProportionList = returnParameterList();
    paramObj.setDemersalProportionList(demProportionList);
}


void KrakenConsole::setGuilds() {

    lineList.removeFirst();
    // Remove blank values
    int lineListSize = lineList.size();
    for (int i = lineListSize - 1; i >= 0; i--) {
        if (lineList.at(i) == "") {
            lineList.removeAt(i);
        }
    }
    paramObj.setGuildList(lineList);
}


void KrakenConsole::setGuildMembership() {

    lineList.removeFirst();
    int lineListSize = lineList.size();
    for (int i = lineListSize - 1; i >= 0; i--) {
        if (lineList.at(i) == "") {
            lineList.removeAt(i);
        }
    }
    paramObj.setSpeciesGuildMembershipHash(lineList);
}

void KrakenConsole::setGrowthMode() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setGrowthForm(value);
}

void KrakenConsole::setHarvestMode() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setHarvestForm(value);

}

void KrakenConsole::setPredationMode() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setPredationForm(value);
//    std::cout << value << "Predation";
}

void KrakenConsole::setwgcMode() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setwgcForm(value);
}

void KrakenConsole::setbgcMode() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setbgcForm(value);
}


void KrakenConsole::setAssessmentType() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setAssessmentType(value);
}


void KrakenConsole::setStochasticGrowth() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setStochasticGrowth(value);
}


void KrakenConsole::setStochasticCatch() {

    QString value = lineList.at(1);
    value = value.toUpper();
    value = value.trimmed();

    modelFormParamObj.setStochasticCatch(value);
}


void KrakenConsole::setACL_Buffer() {

    QString value = lineList.at(1);
    double ACL_Buffer = value.toDouble();
    modelFormParamObj.setACL_Buffer(ACL_Buffer);
}



void KrakenConsole::setAssessmentCV() {

    QString value = lineList.at(1);
    double assessmentCV = value.toDouble();
    modelFormParamObj.setAssessmentCV(assessmentCV);
}


void KrakenConsole::setNumYearsBetweenAssessments() {

    QString value = lineList.at(1);
    int assessmentInterval = value.toInt();
    modelFormParamObj.setNumYearsBetweenAssessments(assessmentInterval);
}


void KrakenConsole::setIndicatorSpecies() {

    QString value = lineList.at(1);
    int indicatorSpeciesIndex = value.toInt();
    modelFormParamObj.setIndicatorSpecies(indicatorSpeciesIndex);
}

QString KrakenConsole::convertDoubleToString(double number) {
    QVariant newVariant(number);
    QString newString = newVariant.toString();
    return newString;
}


void KrakenConsole::runModel() {

    Parameters* ptr_paramObj = &paramObj;
    ModelFormParameters* ptr_modelParamObj = &modelFormParamObj;
    TimeSeriesObservations* ptr_tsObj = &tsObj;
    QString outputType = ptr_paramObj->getOutputType();
    ptr_paramObj->setSaveFilename(m_outputFilename);
/*    if (outputType.toUpper() == "SINGLE RUN") {
        QString saveFilename = QFileDialog::getSaveFileName(this, QObject::tr("Save as..."), QObject::tr(""), QObject::tr("CSV (*.csv)"));
        ptr_paramObj->setSaveFilename(saveFilename);
        std::cout << "Save filename = " << saveFilename;
    } else {
        QString saveDirectory = QFileDialog::getExistingDirectory(this, QObject::tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
   //     QString saveDirectory = "C:\\Users\\rgamble\\Desktop\\Kraken\\Kraken_Windows\\Kraken Outputs";
        ptr_paramObj->setWorkingDirectory(saveDirectory);
        std::cout << "Save Directory = " << saveDirectory;
    }
*/
    Model model(ptr_paramObj, ptr_modelParamObj);
    model.runModel();
}


void KrakenConsole::fitModel() {

    QString estimationType;

    loadFromDataFile();
    Parameters* ptr_paramObj = &paramObj;
    TimeSeriesObservations* ptr_tsObj = &tsObj;
    ModelFormParameters* ptr_modelParamObj = &modelFormParamObj;
    estimationType = "GENETIC ALGORITHM";
    QString saveFilename = m_outputDirectory;
    saveFilename.append("/");
    saveFilename.append("GA_outputs_all_");
    saveFilename.append(m_dataID);
    QString saveFilenameBest = m_outputDirectory;
    saveFilenameBest.append("/");
    saveFilenameBest.append("GA_outputs_best_");
    saveFilenameBest.append(m_dataID);
    GA_Estimator o_GA_Estimator(ptr_paramObj, ptr_tsObj, ptr_modelParamObj);
    o_GA_Estimator.setSaveFilenames(saveFilename, saveFilenameBest);
    o_GA_Estimator.estimateParameters();
}


void KrakenConsole::testFramework() {

//    testLooping();
}



