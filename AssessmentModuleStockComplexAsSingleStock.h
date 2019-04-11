#ifndef ASSESSMENTMODULESTOCKCOMPLEXASSINGLESTOCK_H
#define ASSESSMENTMODULESTOCKCOMPLEXASSINGLESTOCK_H

// AssessmentModuleStockComplexAsSingleStock.h header file
#include "Parameters.h"
#include "AssessmentModule.h"
#include "ModelFormParameters.h"

class AssessmentModuleStockComplexAsSingleStock : public AssessmentModule {

private:
    int m_numYearsBetweenAssessments;
    double m_ACL_buffer;
    int m_firstAssessmentYear;
    double m_assessmentCV;

public:
    AssessmentModuleStockComplexAsSingleStock();
    AssessmentModuleStockComplexAsSingleStock(ModelFormParameters* modelFormParamObj);
    void assess(Parameters* paramObj, int timeStep) const;
};

#endif // ASSESSMENTMODULESTOCKCOMPLEXASSINGLESTOCK_H
