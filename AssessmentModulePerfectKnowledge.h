// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULEPERFECTKNOWLEDGE_H
#define ASSESSMENTMODULEPERFECTKNOWLEDGE_H

// AssessmentModulePerfectKnowledge.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "ModelFormParameters.h"

class AssessmentModulePerfectKnowledge : public AssessmentModule {

private:
    int m_numYearsBetweenAssessments;

public:
    AssessmentModulePerfectKnowledge();
    AssessmentModulePerfectKnowledge(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};

#endif // ASSESSMENTMODULEPERFECTKNOWLEDGE_H




