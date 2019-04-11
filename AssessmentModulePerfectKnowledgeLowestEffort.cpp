#include "AssessmentModulePerfectKnowledgeLowestEffort.h"

AssessmentModulePerfectKnowledgeLowestEffort::AssessmentModulePerfectKnowledgeLowestEffort() {

    m_assessmentType = "PERFECT KNOWLEDGE - LOWEST EFFORT";
    m_numYearsBetweenAssessments = 1;
    qDebug() << "CONSTRUCTOR";
}


AssessmentModulePerfectKnowledgeLowestEffort::AssessmentModulePerfectKnowledgeLowestEffort(ModelFormParameters* modelFormParamObj){

    m_assessmentType = "PERFECT KNOWLEDGE - LOWEST EFFORT";
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
}

void AssessmentModulePerfectKnowledgeLowestEffort::assess(Parameters* paramObj, int timeStep) const {

    if (timeStep % m_numYearsBetweenAssessments == 0) {
//        qDebug() << "Year: " << timeStep;
        int numSpecies = paramObj->getNumberOfSpecies();
        double r = 0.0;
        double q = 0.0;
        double newEffort = 0.0;
        double lowestEffort = 0.0;
        int speciesIndex = 0;
        r = paramObj->getGrowthRate(speciesIndex);
        q = paramObj->getCatchability(speciesIndex, timeStep);
        newEffort = r / (2 * q);
        lowestEffort = newEffort;

        for (int i = 0; i < numSpecies; i++) {
            r = paramObj->getGrowthRate(i);
            q = paramObj->getCatchability(i, timeStep);
            newEffort = r / (2 * q);
            if (newEffort < lowestEffort) {
                lowestEffort = newEffort;
            }
        }
        for (int i = 0; i < numSpecies; i++) {
            paramObj->setEffort(i, timeStep, lowestEffort);
        }
    }
}
