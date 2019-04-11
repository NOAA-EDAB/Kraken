// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULEAVERAGETOTALCATCH_H
#define ASSESSMENTMODULEAVERAGETOTALCATCH_H

// AssessmentModuleAverageTotalCatch.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "ModelFormParameters.h"


class AssessmentModuleAverageTotalCatch : public AssessmentModule {

private:
    int m_numYearsOfCatch;
    int m_numYearsBetweenAssessments;
    int m_lastHistoricalYear;
    int m_firstAssessmentYear;
    double m_ACL_Buffer;
    double m_assessmentCV;

public:
    AssessmentModuleAverageTotalCatch();
    AssessmentModuleAverageTotalCatch(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};

#endif // ASSESSMENTMODULEAVERAGETOTALCATCH_H
