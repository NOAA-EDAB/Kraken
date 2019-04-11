
#include "AssessmentModuleStockComplexAsSingleStock.h"

AssessmentModuleStockComplexAsSingleStock::AssessmentModuleStockComplexAsSingleStock() {

    m_assessmentType = "STOCK COMPLEX AS SINGLE STOCK";
    m_numYearsBetweenAssessments = 3;
    m_ACL_buffer = 1.0;
    m_firstAssessmentYear = 0;
    m_assessmentCV = 0.0;
    m_ACL = 0;
}


AssessmentModuleStockComplexAsSingleStock::AssessmentModuleStockComplexAsSingleStock(ModelFormParameters* modelFormParamObj) {

    m_assessmentType = "STOCK COMPLEX AS SINGLE STOCK";
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
    m_ACL_buffer = modelFormParamObj->getACL_Buffer();
    m_firstAssessmentYear = modelFormParamObj->getHistoricalEnd();
    m_assessmentCV = modelFormParamObj->getAssessmentCV();
}


void AssessmentModuleStockComplexAsSingleStock::assess(Parameters* paramObj, int timeStep) const {

    double newEffort = 0.0;
    int numSpecies = paramObj->getNumberOfSpecies();
    double stockComplexBiomassAssessed = 0.0;
    double stockBiomass = 0.0;
    double stockCatchability = 0.0;
    double sum_stock_qB = 0.0;
    double r = 0.4;
    double stDev = 0.0;
    if ((timeStep == m_firstAssessmentYear) || ( (timeStep - m_firstAssessmentYear) % m_numYearsBetweenAssessments == 0 ) ) {
        QSharedPointer<MTRand> obj_MTRand = QSharedPointer<MTRand>(new MTRand);
        for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
            stockBiomass = paramObj->getBiomass(speciesIndex, timeStep);
            stDev = m_assessmentCV * stockBiomass;
            stockComplexBiomassAssessed += obj_MTRand->randNorm(stockBiomass, stDev);
            stockCatchability = paramObj->getCatchability(speciesIndex, timeStep);
            sum_stock_qB += stockBiomass * stockCatchability;
        }
        m_ACL = stockComplexBiomassAssessed * (r / 2.0) * m_ACL_buffer;
        newEffort = m_ACL / sum_stock_qB;
        for (int speciesIndex = 0; speciesIndex < numSpecies; speciesIndex++) {
            paramObj->setEffort(speciesIndex, timeStep, newEffort);
        }
    }
}



