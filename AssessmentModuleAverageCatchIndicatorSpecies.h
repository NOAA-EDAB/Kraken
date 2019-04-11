// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULEAVERAGECATCHINDICATORSPECIES_H
#define ASSESSMENTMODULEAVERAGECATCHINDICATORSPECIES_H

// AssessmentModuleAverageCatchIndicatorSpecies.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "ModelFormParameters.h"

class AssessmentModuleAverageCatchIndicatorSpecies : public AssessmentModule {

private:
    int m_numYearsBetweenAssessments;
    int m_numYearsOfCatch;
    int m_indicatorSpecies;
    double m_ACL_Buffer;
    int m_lastHistoricalYear;
    int m_firstAssessmentYear;
    double m_assessmentCV;

public:
    AssessmentModuleAverageCatchIndicatorSpecies();
    AssessmentModuleAverageCatchIndicatorSpecies(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};


#endif // ASSESSMENTMODULEAVERAGECATCHINDICATORSPECIES_H
