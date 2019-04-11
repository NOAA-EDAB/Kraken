// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef PREDATIONMODULETYPEIII_H
#define PREDATIONMODULETYPEIII_H

// PredationModuleTypeIII.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class PredationModuleTypeIII : public ModelComponent {

private:

    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;

public:
    PredationModuleTypeIII(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;
};

#endif // PREDATIONMODULETYPEIII_H
