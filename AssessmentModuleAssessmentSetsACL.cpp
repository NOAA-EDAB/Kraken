#include "AssessmentModuleAssessmentSetsACL.h"

AssessmentModuleAssessmentSetsACL::AssessmentModuleAssessmentSetsACL() {

    m_assessmentType = "ASSESSMENT SETS ACL";
    m_numYearsBetweenAssessments = 3;
    m_ACL_buffer = 1.0;
    m_indicatorSpecies = 0;
    m_firstAssessmentYear = 0;
    m_assessmentCV = 0.0;
    m_ACL = 0;
}


AssessmentModuleAssessmentSetsACL::AssessmentModuleAssessmentSetsACL(ModelFormParameters* modelFormParamObj) {

    m_assessmentType = "ASSESSMENT SETS ACL";
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
    m_ACL_buffer = modelFormParamObj->getACL_Buffer();
    m_indicatorSpecies = modelFormParamObj->getIndicatorSpecies();
    m_firstAssessmentYear = modelFormParamObj->getHistoricalEnd();
    m_assessmentCV = modelFormParamObj->getAssessmentCV();
    qDebug() << "Assessment Constructor:: Assessment Interval: " << m_numYearsBetweenAssessments << "  :: ACL_buffer: " << m_ACL_buffer << " :: Indicator Species: " << m_indicatorSpecies << " :: CV: " << m_assessmentCV;
}


void AssessmentModuleAssessmentSetsACL::assess(Parameters* paramObj, int timeStep) const {

    double newEffort = 0.0;
    int numSpecies = paramObj->getNumberOfSpecies();
    double B_true = paramObj->getBiomass(m_indicatorSpecies, timeStep);
    double q = paramObj->getCatchability(m_indicatorSpecies, timeStep);

    if ((timeStep == m_firstAssessmentYear) || ( (timeStep - m_firstAssessmentYear) % m_numYearsBetweenAssessments == 0) ) {

        double r = paramObj->getOriginalGrowthRate(m_indicatorSpecies);
//        qDebug() << "Base r: " << r << " :: Actual r: " << paramObj->getGrowthRate(m_indicatorSpecies);
        QSharedPointer<MTRand> obj_MTRand = QSharedPointer<MTRand>(new MTRand);
        double stDev = m_assessmentCV * B_true;
        double B_assessed = obj_MTRand->randNorm(B_true,stDev);
        double E = (r / (2 * q));
        m_ACL = q * E * B_assessed * m_ACL_buffer;
        if (m_ACL < 0) {
            m_ACL = 0;
        }
    }
    newEffort = m_ACL / (q * B_true);
    for (int i = 0; i < numSpecies; i++) {
        paramObj->setEffort(i, timeStep, newEffort);
    }
}



