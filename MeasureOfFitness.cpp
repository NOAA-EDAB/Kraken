// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "MeasureOfFitness.h"
#include "math.h"

MeasureOfFitness::MeasureOfFitness() {

    m_MAE = 0.0;
    m_RMSE = 0.0;
    m_RMSE_modified = 0.0;
    m_MEF_modified = 0.0;
}


double MeasureOfFitness::getTSbiomassValue(int speciesIndex, int timeStep, Parameters* paramObj, TimeSeriesObservations* tsObj) {

    double tsBiomassIndex = 0.0;
    double tsBiomassValue = 0.0;
    double estimatedSurveyQ = 0.0;

    QString speciesName = paramObj->getSpeciesName(speciesIndex);
    tsBiomassIndex = tsObj->getBiomass(speciesName, timeStep);
    estimatedSurveyQ = paramObj->getSurveyQ(speciesIndex);
    tsBiomassValue = tsBiomassIndex * estimatedSurveyQ;

    return tsBiomassValue;
}

void MeasureOfFitness::calculateMeasuresOfFitness(Parameters* paramObj, TimeSeriesObservations* tsObj) {

    int numComparisons = tsObj->getTSlength();
    int numSpecies = paramObj->getNumberOfSpecies();
//    qDebug() << "Calculating Measures Of Fitness";
//    qDebug() << "Number of Comparisons = " << numComparisons;
//    qDebug() << "Number of Species = " << numSpecies;

    double modelBiomassValue = 0.0;
    double tsBiomassValue = 0.0;
    double difference = 0.0;
    double logDifference = 0.0;
    double MAE_term = 0.0;
    double RMSE_term = 0.0;
    double RMSE_modified_term = 0.0;
    double survQ = 1.0;

    QString speciesName;

    double MEF_term = 0.0;
    double meanOfObservations = 0.0;
    double sumOfObservations = 0.0;
    double sumObsDiffSquared = 0.0;
    double sumModelObsDiffSquared = 0.0;
    double crashedModifier = 0.0;

    QList<double> meanOfObservationsList;

    for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
        double sumOfObservations = 0.0;
        for (int timeStep = 0; timeStep < numComparisons; timeStep++) {
            speciesName = paramObj->getSpeciesName(speciesIndex);
            sumOfObservations += tsObj->getBiomass(speciesName,timeStep);
        }
        meanOfObservations = sumOfObservations / numComparisons;
        meanOfObservationsList.append(meanOfObservations);
    }

    for (int i = 0; i < numComparisons; i++) {
        for (int j = 0; j < numSpecies; j++) {
            speciesName = paramObj->getSpeciesName(j);
            survQ = paramObj->getSurveyQ(j);
 //           survQ = 1.0;
            modelBiomassValue = paramObj->getBiomass(speciesName,i) * survQ;
            tsBiomassValue = tsObj->getBiomass(speciesName,i);
            meanOfObservations = meanOfObservationsList.at(j);
            sumObsDiffSquared += (tsBiomassValue - meanOfObservations) * (tsBiomassValue - meanOfObservations);
            sumModelObsDiffSquared += (tsBiomassValue - modelBiomassValue) * (tsBiomassValue - modelBiomassValue);
            if (modelBiomassValue == 0) {
                crashedModifier += 1.0;
            }
        }
        sumOfObservations += tsObj->getBiomass(speciesName,i);
    }

    double predationToBiomassRatio = 0.0;
    double predationTooHighModifier = 0.0;
    for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
        for (int ts = 0; ts < numComparisons; ts++) {
            predationToBiomassRatio = paramObj->calculatePredationToBiomassRatio(speciesIndex, ts);
            modelBiomassValue = paramObj->getBiomass(speciesIndex,ts);
            if (predationToBiomassRatio > 1.0) {
                predationTooHighModifier += predationToBiomassRatio;
            }
        }
    }

    MEF_term = calculateAdjustedMEF(sumObsDiffSquared, sumModelObsDiffSquared);
    m_MEF_modified = MEF_term + crashedModifier + predationTooHighModifier;

    for (int i = 0; i < numComparisons; i++) {

        for (int j = 0; j < numSpecies; j++) {
            speciesName = paramObj->getSpeciesName(j);
            survQ = paramObj->getSurveyQ(j);
            modelBiomassValue = paramObj->getBiomass(speciesName, i) * survQ;
//            tsBiomassValue = getTSbiomassValue(j, i, paramObj, tsObj);
            tsBiomassValue = tsObj->getBiomass(speciesName,i);
            // Get absolute value of difference
            difference = tsBiomassValue - modelBiomassValue;
            if (difference < 0) {
                difference *= -1;
            }

            if (tsBiomassValue == 0) {
                tsBiomassValue = 0.1;
            }
            if (modelBiomassValue == 0) {
                modelBiomassValue = 0.1;
//                logDifference = logDifference + 1000;
            }

            logDifference = log(tsBiomassValue) - log(modelBiomassValue);
            if (logDifference <= 0) {
                logDifference *= -1 * 10;
            }
//            qDebug() << "tsBiomassValue: " << tsBiomassValue << "modelBiomassValue: " << modelBiomassValue << "Log Difference: " << logDifference;

            if (modelBiomassValue == 0.1) {
   //             difference = difference * 1000000;
                logDifference = logDifference + 10;
            }
            MAE_term += difference;
            RMSE_term += difference * difference;
            RMSE_modified_term += logDifference * logDifference * 100;
        }
    }

    int numObservations = numComparisons * numSpecies;

    m_MAE = MAE_term / numObservations;
    m_RMSE = sqrt(RMSE_term / numObservations);
    m_RMSE_modified = sqrt(RMSE_modified_term / numObservations);

}


void MeasureOfFitness::calculateMeasuresOfFitness(Parameters* paramObj, TimeSeriesObservations* tsObj, int speciesIndex) {

    int numComparisons = tsObj->getTSlength();
    int TSlength = tsObj->getTSlength();
    int numSpecies = 1;
    double modelBiomassValue = 0.0;
    double tsBiomassValue = 0.0;
    double difference = 0.0;
    double logDifference = 0.0;
    double MAE_term = 0.0;
    double RMSE_term = 0.0;
    double RMSE_modified_term = 0.0;
    double survQ = 1.0;
    double MEF_term = 0.0;
    double meanOfObservations = 0.0;
    double sumOfObservations = 0.0;


    QString speciesName = paramObj->getSpeciesName(speciesIndex);

    for (int i = 0; i < TSlength; i++) {
        sumOfObservations += tsObj->getBiomass(speciesName,i);
    }
    meanOfObservations = sumOfObservations / TSlength;

    double sumObsDiffSquared = 0.0;
    double sumModelObsDiffSquared = 0.0;
    double crashedModifier = 0.0;

    for (int i = 0; i < TSlength; i++) {
         survQ = paramObj->getSurveyQ(speciesIndex);
         modelBiomassValue = paramObj->getBiomass(speciesName, i) * survQ;

         tsBiomassValue = tsObj->getBiomass(speciesName,i);
//         tsBiomassValue = getTSbiomassValue(speciesIndex, i, paramObj, tsObj);

         sumObsDiffSquared += (tsBiomassValue - meanOfObservations) * (tsBiomassValue - meanOfObservations);
         sumModelObsDiffSquared += (tsBiomassValue - modelBiomassValue) * (tsBiomassValue - modelBiomassValue);
         if (modelBiomassValue == 0) {
             crashedModifier += 1.0;
         }
    }

    double predationToBiomassRatio = 0.0;
    double predationTooHighModifier = 0.0;
    for (int ts = 0; ts < numComparisons; ts++) {
        predationToBiomassRatio = paramObj->calculatePredationToBiomassRatio(speciesIndex, ts);
        modelBiomassValue = paramObj->getBiomass(speciesIndex,ts);
//        if (predationToBiomassRatio > 1.0) {
//            predationTooHighModifier += predationToBiomassRatio;
//        }
    }

    MEF_term = calculateAdjustedMEF(sumObsDiffSquared, sumModelObsDiffSquared);
    m_MEF_modified = MEF_term + crashedModifier + predationTooHighModifier;

    for (int i = 0; i < TSlength; i++) {
         survQ = paramObj->getSurveyQ(speciesIndex);
         modelBiomassValue = paramObj->getBiomass(speciesName, i) * survQ;

         tsBiomassValue = tsObj->getBiomass(speciesName,i);
//         tsBiomassValue = getTSbiomassValue(speciesIndex, i, paramObj, tsObj);

         difference = tsBiomassValue - modelBiomassValue;
         if (difference < 0) {
             difference *= -1;
         }

         if (tsBiomassValue == 0) {
             tsBiomassValue = 0.1;
         }
         if (modelBiomassValue == 0) {
             modelBiomassValue = 0.1;
         }

         logDifference = log(tsBiomassValue) - log(modelBiomassValue);
         if (logDifference < 0) {
             logDifference *= -1;
         }
//            qDebug() << "tsBiomassValue: " << tsBiomassValue << "modelBiomassValue: " << modelBiomassValue << "Log Difference: " << logDifference;

         if (modelBiomassValue == 0.1) {
//             difference = difference * 1000000;
             logDifference = logDifference + 10;
         }
         MAE_term += difference;
         RMSE_term += difference * difference;
         RMSE_modified_term += logDifference * logDifference * 100;
     }

     int numObservations = numComparisons * numSpecies;

     m_MAE = MAE_term / numObservations;
     m_RMSE = sqrt(RMSE_term / numObservations);
     m_RMSE_modified = sqrt(RMSE_modified_term / numObservations);
}


void MeasureOfFitness::outputMeasuresOfFitness() {

//    qDebug() << "MAE: " << m_MAE;
//    qDebug() << "RMSE: " << m_RMSE;
}


double MeasureOfFitness::calculateAdjustedMEF(double sumObsDiffSquared, double sumModelObsDiffSquared) {

    double MEF = (sumObsDiffSquared - sumModelObsDiffSquared) / sumObsDiffSquared;

    double MEF_adjusted = (MEF - 1.0) * -1.0;
    if (MEF_adjusted >= 1.0) {

        MEF_adjusted *= 1000;
    } else if (MEF_adjusted >= 0.7) {
        MEF_adjusted *= 50;
    } else if (MEF_adjusted >= 0.4) {
        MEF_adjusted *= 10;
    }
    return MEF_adjusted;
}

double MeasureOfFitness::getMAE() {
    return m_MAE;
}


double MeasureOfFitness::getRMSE() {
    return m_RMSE;
}


double MeasureOfFitness::getRMSE_modified() {
    return m_RMSE_modified;
}

double MeasureOfFitness::getMEF_modified() {
    return m_MEF_modified;
}
