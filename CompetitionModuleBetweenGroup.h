// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef COMPETITIONMODULEBETWEENGROUP_H
#define COMPETITIONMODULEBETWEENGROUP_H

// CompetitionModuleBetweenGroup.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class CompetitionModuleBetweenGroup : public ModelComponent {

private:
    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const;


public:
    CompetitionModuleBetweenGroup(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const ;
};

#endif // COMPETITIONMODULEBETWEENGROUP_H
