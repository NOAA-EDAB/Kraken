// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "CompetitionModuleBetweenSpeciesNoK.h"

CompetitionModuleBetweenSpeciesNoK::CompetitionModuleBetweenSpeciesNoK(Parameters* paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "Comp Between Species No K";
    m_OutputName = " (Competition Between Species)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;

    m_OutputLossesByGroup = true;
    if (m_OutputLossesByGroup) {
        initializeOutputLossesByGroupMatrix(paramObj, modelFormObj);
    }
}


double CompetitionModuleBetweenSpeciesNoK::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    // Get biomass and survey Q of current species
    int i = speciesIndex;
    double Bi = paramObj->getBiomass(i, timestep);
//    double survQi = paramObj->getSurveyQ(i);
    double survQi = 1.0;

    // Initialize competition coefficient and biomass for other species
    double compCoefficient = 0.0;
    double Bj = 0.0;
    double survQj = 1.0;

    double Sij = 0.0;           // Spatial overlap between i and j

    double lossBySpecies = 0.0;

    // Initialize summed competition term
    double summedTerm = 0.0;

    // For each other species
    int numGroups = paramObj->getNumberOfSpecies();

    for (int j = 0; j < numGroups; j++) {
        // get the interaction coefficient

        compCoefficient = paramObj->getWithinGuildCompParam(i,j);
//        if ((i == 0) && (j ==0) && (timestep == 1)) {
//            std::cout << "DD term: " << compCoefficient << "\n";
//        }

        // get the interaction species biomass and survey Q
        Bj = paramObj->getBiomass(j, timestep);
//        survQj = paramObj->getSurveyQ(j);
        survQj = 1;

        // get the spatial overlap
        Sij = paramObj->getSpatialOverlap(i,j);

        lossBySpecies = -1.0 * Bi*survQi * compCoefficient * Bj* survQj * Sij;

/*        if (m_OutputLossesByGroup) {
            QList<double> tempList;
            m_OutputLossesByGroupData.at(i).at(timestep).at(j) = lossBySpecies;

        }
*/
        // Update summed term
        summedTerm += compCoefficient * Bj * survQj * Sij;
    }

    // calculate loss to biomass from competition
   double lossToWithinGroupCompetition = -1.0 * (Bi* survQi * summedTerm);

    return lossToWithinGroupCompetition;

}

void CompetitionModuleBetweenSpeciesNoK::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const {

//    m_OutputLossesByGroupData[affectedSpeciesIndex].addMatrixValue(affectingSpeciesIndex,lossValue);
}

