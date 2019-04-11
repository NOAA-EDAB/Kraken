#include "AssessmentModuleAverageTotalCatch.h"

AssessmentModuleAverageTotalCatch::AssessmentModuleAverageTotalCatch() {

    m_assessmentType = "AVERAGAE TOTAL CATCH";
    m_numYearsOfCatch = 10;
    m_ACL_Buffer = 1.0;
    m_numYearsBetweenAssessments = 1;
}


AssessmentModuleAverageTotalCatch::AssessmentModuleAverageTotalCatch(ModelFormParameters *modelFormParamObj) {

    m_assessmentType = "AVERAGAE TOTAL CATCH";
    m_numYearsOfCatch = 10;
    m_ACL_Buffer = modelFormParamObj->getACL_Buffer();
    m_lastHistoricalYear = modelFormParamObj->getHistoricalEnd();
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
    m_firstAssessmentYear = modelFormParamObj->getHistoricalEnd();
}

void AssessmentModuleAverageTotalCatch::assess(Parameters* paramObj, int timeStep) const {

    int numSpecies = paramObj->getNumberOfSpecies();
    if (timeStep == m_firstAssessmentYear) {
        int startTime = m_firstAssessmentYear - m_numYearsOfCatch;
        int endTime = m_firstAssessmentYear;
        double summedCatch = 0;

        for (int time = startTime; time < endTime; time++) {
            for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
                double actualCatch = paramObj->getOutputCatch(speciesIndex, time);
                QSharedPointer<MTRand> obj_MTRand = QSharedPointer<MTRand>(new MTRand);
                double stDev = m_assessmentCV * actualCatch;
                double assessedCatch = obj_MTRand->randNorm(actualCatch, stDev);
                summedCatch += assessedCatch;
            }
        }
        m_ACL = (summedCatch / m_numYearsOfCatch) * m_ACL_Buffer;

    } else if ( (timeStep - m_firstAssessmentYear) % m_numYearsBetweenAssessments == 0)  {
        int startTime = timeStep - m_numYearsOfCatch;
        int endTime = timeStep;
        double summedCatch = 0;
        for (int time = startTime; time < endTime; time++) {
            for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
                summedCatch += paramObj->getOutputCatch(speciesIndex, time);
            }
        }
        m_ACL = (summedCatch / m_numYearsOfCatch) * m_ACL_Buffer;
    }
    double q = 0.0;
    double B = 0.0;
    double newEffort = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < numSpecies; i++) {
        q = paramObj->getCatchability(i, timeStep);
        B = paramObj->getBiomass(i, timeStep);
        if (B <= 0) {
            B = 0;
        }
        denominator += q*B;
    }
    newEffort = m_ACL / denominator;
    for (int i = 0; i < numSpecies; i++) {
        paramObj->setEffort(i, timeStep, newEffort);
    }

//        qDebug() << "New Effort = " << newEffort;
}

