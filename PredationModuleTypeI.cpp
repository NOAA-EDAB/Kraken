// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "PredationModuleTypeI.h"

PredationModuleTypeI::PredationModuleTypeI(Parameters *paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "Type I Predation";
    m_OutputName = " (Predation Losses)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;

    m_OutputLossesByGroup = true;
    if (m_OutputLossesByGroup) {
        initializeOutputLossesByGroupMatrix(paramObj,modelFormObj);
    }
}


double PredationModuleTypeI::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    double Bi = paramObj->getBiomass(speciesIndex, timestep);
    double survQi = paramObj->getSurveyQ(speciesIndex);
    // Determine number of predators (in the general case, number of stocks/species)
    int numPredators = paramObj->getNumberOfSpecies();

    // For every predator
    double Bj = 0.0;
    double survQj = 0.0;
    double Aij = 0.0;                       // Availability
    double Sij = 0.0;                       // Spatial overlap
    double lossBySpecies = 0.0;

    double lossToPredation = 0.0;

    int i = speciesIndex;                   // Subscript for prey
    for (int j = 0; j < numPredators; j++) {    // Subscript for predator
        // Get Predator Biomass
        Bj = paramObj->getBiomass(j, timestep);
        survQj = paramObj->getSurveyQ(j);

        // Get prey's availability to the predator
        Aij = paramObj->getAvailability(i,j);

        // Get spatial overlap between predator and prey
        Sij = paramObj->getSpatialOverlap(i,j);

        lossBySpecies = -1.0 * Bi * survQi * Aij * Bj * survQj * Sij;

        if (m_OutputLossesByGroup) {
            //updateOutputLossesByGroupMatrix(paramObj, speciesIndex, j, lossBySpecies);
        }

        // Calculate loss to predation on prey by predator and
        // Add to running total of loss of predation
        lossToPredation += -1.0 * Bi * survQi * Aij * Bj * survQj * Sij;
    }

    return lossToPredation;

}


void PredationModuleTypeI::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
