
#include "AssessmentModuleAverageCatchIndicatorSpecies.h"

AssessmentModuleAverageCatchIndicatorSpecies::AssessmentModuleAverageCatchIndicatorSpecies() {

    m_assessmentType = "AVERAGE CATCH INDICATOR SPECIES";
    m_numYearsBetweenAssessments = 1;
    m_numYearsOfCatch = 10;
    m_ACL_Buffer = 1.0;
    m_indicatorSpecies = 0;
}


AssessmentModuleAverageCatchIndicatorSpecies::AssessmentModuleAverageCatchIndicatorSpecies(ModelFormParameters *modelFormParamObj) {

    m_assessmentType = "AVERAGE CATCH INDICATOR SPECIES";
    m_numYearsOfCatch = 10;
    m_ACL_Buffer = modelFormParamObj->getACL_Buffer();
    m_lastHistoricalYear = modelFormParamObj->getHistoricalEnd();
    m_firstAssessmentYear = modelFormParamObj->getHistoricalEnd();
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
    m_indicatorSpecies = modelFormParamObj->getIndicatorSpecies();
    m_assessmentCV = modelFormParamObj->getAssessmentCV();
}


void AssessmentModuleAverageCatchIndicatorSpecies::assess(Parameters* paramObj, int timeStep) const {

    double summedCatch = 0;

    if (timeStep == m_firstAssessmentYear) {
        int startTime = m_firstAssessmentYear - m_numYearsOfCatch;
        int endTime = m_firstAssessmentYear;
        for (int time = startTime; time < endTime; time++) {
            double yearlyCatch = paramObj->getOutputCatch(m_indicatorSpecies, time);
            QSharedPointer<MTRand> obj_MTRand = QSharedPointer<MTRand>(new MTRand);
            double stDev = m_assessmentCV * yearlyCatch;
            double yearlyCatchEstimated = obj_MTRand->randNorm(yearlyCatch,stDev);
            summedCatch += yearlyCatchEstimated;
        }
        m_ACL = (summedCatch / m_numYearsOfCatch) * m_ACL_Buffer;
    } else if ( (timeStep - m_firstAssessmentYear) % m_numYearsBetweenAssessments == 0)  {
        int startTime = timeStep - m_numYearsOfCatch;
        int endTime = timeStep;
        for (int time = startTime; time < endTime; time++) {
            summedCatch += paramObj->getOutputCatch(m_indicatorSpecies, time);
        }
        m_ACL = (summedCatch / m_numYearsOfCatch) * m_ACL_Buffer;
    }
    double q = paramObj->getCatchability(m_indicatorSpecies, timeStep);
    double B = paramObj->getBiomass(m_indicatorSpecies, timeStep);
    double newEffort = m_ACL / (q * B);

    int numSpecies = paramObj->getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        paramObj->setEffort(i, timeStep, newEffort);
    }
}
