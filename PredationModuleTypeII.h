// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef PREDATIONMODULETYPEII_H
#define PREDATIONMODULETYPEII_H

// PredationModuleTypeII.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class PredationModuleTypeII : public ModelComponent {

private:

    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;

public:
    PredationModuleTypeII(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;
};

#endif // PREDATIONMODULETYPEII_H
