// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULEASSESSMENTSETSACL_H
#define ASSESSMENTMODULEASSESSMENTSETSACL_H

// AssessmentModuleAssessmentSetsACL.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "MersenneTwister.h"
#include "ModelFormParameters.h"


class AssessmentModuleAssessmentSetsACL : public AssessmentModule {

private:
    int m_numYearsBetweenAssessments;
    double m_ACL_buffer;
    int m_indicatorSpecies;
    int m_firstAssessmentYear;
    double m_assessmentCV;

public:
    AssessmentModuleAssessmentSetsACL();
    AssessmentModuleAssessmentSetsACL(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};


#endif // ASSESSMENTMODULEASSESSMENTSETSACL_H
