// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef GROWTHMODULELOGISTIC_H
#define GROWTHMODULELOGISTIC_H

#include "ModelComponent.h"

class GrowthModuleLogistic : public ModelComponent {

private:
    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;

public:
    GrowthModuleLogistic(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters *paramObj, int speciesIndex, int timestep) const;
};

#endif // GROWTHMODULELOGISTIC_H
