// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULENULL_H
#define ASSESSMENTMODULENULL_H

// AssessmentModuleNull.h header file
#include "Parameters.h"
#include "AssessmentModule.h"

class AssessmentModuleNull : public AssessmentModule {

private:

public:
    AssessmentModuleNull();
//    AssessmentModuleNull(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};

#endif // ASSESSMENTMODULENULL_H
