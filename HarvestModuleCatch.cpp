// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "HarvestModuleCatch.h"

HarvestModuleCatch::HarvestModuleCatch(Parameters *paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "Catch";
    m_OutputName = " (Harvest Losses)";
    initializeOutputMatrix(paramObj);
    m_OutputLossesByGroup = false;
}


double HarvestModuleCatch::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    qDebug() << "Trying to get Catch for Species " << speciesIndex << " at Time Step " << timestep;
    // C
    double Ci = paramObj->getCatch(speciesIndex, timestep);
    qDebug() << "Catch: " << Ci;
//    if (timestep >= 28) {
//        qDebug() << "Time step: " << timestep << " :: SpeciesIndex: " << speciesIndex << "Catch: " << Ci;
//    }


    double lossToCatches = -1.0 * Ci;
    double catches = lossToCatches * -1;
    qDebug() << lossToCatches;
    if (paramObj->isFitting() == false) {
        paramObj->updateOutputCatch(speciesIndex, catches);
    }
    return lossToCatches;

}

void HarvestModuleCatch::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
