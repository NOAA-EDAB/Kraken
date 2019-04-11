// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef COMPETITIONMODULEBETWEENSPECIESNOK_H
#define COMPETITIONMODULEBETWEENSPECIESNOK_H

// CompetitionModuleBetweenSpeciesNoK.h header file

#include "Parameters.h"
#include "ModelComponent.h"

class CompetitionModuleBetweenSpeciesNoK : public ModelComponent {

private:

    void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const;

public:
    CompetitionModuleBetweenSpeciesNoK(Parameters* paramObj, ModelFormParameters *modelFormObj);
    double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const;

};

#endif // COMPETITIONMODULEBETWEENSPECIESNOK_H
