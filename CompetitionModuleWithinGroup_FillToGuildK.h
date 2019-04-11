// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef COMPETITIONMODULEWITHINGROUP_FILLTOGUILDK_H
#define COMPETITIONMODULEWITHINGROUP_FILLTOGUILDK_H

// CompetitionModuleWithinGroup_FillToGuildK.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class CompetitionModuleWithinGroup_FillToGuildK : public ModelComponent {

private:
    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timeStep, double lossValue) const;


public:
    CompetitionModuleWithinGroup_FillToGuildK(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;
};

#endif // COMPETITIONMODULEWITHINGROUP_FILLTOGUILDK_H
