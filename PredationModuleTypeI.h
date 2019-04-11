// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef PREDATIONMODULETYPEI_H
#define PREDATIONMODULETYPEI_H

// PredationModuleTypeI.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class PredationModuleTypeI : public ModelComponent {

private:
    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;


public:
    PredationModuleTypeI(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;
};

#endif // PREDATIONMODULETYPEI_H
