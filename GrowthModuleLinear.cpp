// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014


#include "GrowthModuleLinear.h"

GrowthModuleLinear::GrowthModuleLinear(Parameters *paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "Linear Growth";
    m_OutputName = " (Linear Growth)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;
    m_OutputLossesByGroup = false;
}


double GrowthModuleLinear::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    double Ri = paramObj->getGrowthRate(speciesIndex);
    double Bi = paramObj->getBiomass(speciesIndex, timestep);

//    double survQi = paramObj->getSurveyQ(speciesIndex);
    double survQi = 1.0;
    double COVi = paramObj->getCovariate(timestep);
    double Oi = paramObj->getGrowthRateCovariate(speciesIndex);

    double growthIncrement = (Ri * exp(Oi * COVi) * Bi*survQi);
    return growthIncrement;

}

void GrowthModuleLinear::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
