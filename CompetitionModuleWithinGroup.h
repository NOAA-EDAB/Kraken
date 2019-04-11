// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef COMPETITIONMODULEWITHINGROUP_H
#define COMPETITIONMODULEWITHINGROUP_H

// CompetitionModuleWithinGroup.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class CompetitionModuleWithinGroup : public ModelComponent {

private:
    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;


public:
    CompetitionModuleWithinGroup(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;
};

#endif // COMPETITIONMODULEWITHINGROUP_H
