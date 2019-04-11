#include "HarvestModuleEffortQ.h"

HarvestModuleEffortQ::HarvestModuleEffortQ(Parameters* paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "qE";
    m_OutputName = " (Harvest Losses)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;
    m_OutputLossesByGroup = false;
    m_modelFormParamObj = modelFormObj;
}


double HarvestModuleEffortQ::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    // Q and E

    qDebug() << "Inside getModelComponentValue";

    double Bi = paramObj->getBiomass(speciesIndex, timestep);
    qDebug() << "After getting Biomass";
    double Qi = paramObj->getCatchability(speciesIndex, timestep);
    qDebug() << "After getting Catchability";
    double Ei = paramObj->getEffort(speciesIndex, timestep);
    qDebug() << "After getting Effort";
    double catches = Bi * Qi * Ei;
    qDebug() << "Catches 1 = " << catches;

    if (timestep > m_modelFormParamObj->getHistoricalEnd()) {
        MTRand obj_MTRand;
        qDebug() << "Before getting StDevCatch";
        double CV_catch = paramObj->getStDevCatch();
        qDebug() << "After getting StDevCatch = " << CV_catch;
        double stDev = catches * CV_catch;
        double stochasticCatch = obj_MTRand.randNorm(catches,stDev);
        if (stochasticCatch < 0) {
            stochasticCatch = 0;
        }
        catches = stochasticCatch;
        qDebug() << "Catches 2 = " << catches;
    }
    if (paramObj->isFitting() == false) {
        qDebug() << "Catches: " << catches;
        paramObj->updateOutputCatch(speciesIndex, catches);
        qDebug() << "After Updating";
    }
    double lossToCatches = catches*-1.0;

    return lossToCatches;
}


void HarvestModuleEffortQ::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
