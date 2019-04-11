// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULEPERFECTKNOWLEDGELOWESTEFFORT_H
#define ASSESSMENTMODULEPERFECTKNOWLEDGELOWESTEFFORT_H

// AssessmentModulePerfectKnowledgeLowestEffort.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "ModelFormParameters.h"

class AssessmentModulePerfectKnowledgeLowestEffort : public AssessmentModule {

private:
    int m_numYearsBetweenAssessments;

public:
    AssessmentModulePerfectKnowledgeLowestEffort();
    AssessmentModulePerfectKnowledgeLowestEffort(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};

#endif // ASSESSMENTMODULEPERFECTKNOWLEDGELOWESTEFFORT_H




