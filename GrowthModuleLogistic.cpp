// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "GrowthModuleLogistic.h"

GrowthModuleLogistic::GrowthModuleLogistic(Parameters *paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "Logistic Growth";
    m_OutputName = " (Logistic Growth)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;
    m_OutputLossesByGroup = false;
}


double GrowthModuleLogistic::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    double Ri = paramObj->getGrowthRate(speciesIndex);
    double Bi = paramObj->getBiomass(speciesIndex, timestep);
    double Ki = paramObj->getSpeciesK(speciesIndex);
    double COVi = paramObj->getCovariate(timestep);
    double rOi = paramObj->getGrowthRateCovariate(speciesIndex);
    double kOi = paramObj->getSpeciesKCovariate(speciesIndex);
    double survQi = paramObj->getSurveyQ(speciesIndex);
    survQi = 1.0;

    double growthIncrement = (Ri * exp(rOi * COVi) * Bi * survQi) * (1 - (Bi * survQi / (Ki * exp(kOi * COVi))));

//    qDebug() << "Biomass: " << Bi << "Growth Rate: " << Ri << "K: " << Ki;
//    qDebug() << "Growth Increment: " << growthIncrement;

    return growthIncrement;

}


void GrowthModuleLogistic::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
