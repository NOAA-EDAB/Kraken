#include "AssessmentModulePerfectKnowledge.h"

AssessmentModulePerfectKnowledge::AssessmentModulePerfectKnowledge() {

    m_assessmentType = "PERFECT KNOWLEDGE";
    m_numYearsBetweenAssessments = 1;
}


AssessmentModulePerfectKnowledge::AssessmentModulePerfectKnowledge(ModelFormParameters *modelFormParamObj) {

    m_assessmentType = "PERFECT KNOWLEDGE";
    m_numYearsBetweenAssessments = modelFormParamObj->getNumYearsBetweenAssessments();
}


void AssessmentModulePerfectKnowledge::assess(Parameters* paramObj, int timeStep) const {

    if (timeStep % m_numYearsBetweenAssessments == 0) {
//        qDebug() << "Year: " << timeStep;
        int numSpecies = paramObj->getNumberOfSpecies();
        double r = 0.0;
        double q = 0.0;
        double E = 0.0;
        double newEffort = 0.0;

        for (int i = 0; i < numSpecies; i++) {
            r = paramObj->getGrowthRate(i);
            q = paramObj->getCatchability(i, timeStep);
            E = paramObj->getEffort(i, timeStep);
            newEffort = r / (2 * q);
            paramObj->setEffort(i, timeStep, newEffort);
//            qDebug() << "Old E: " << paramObj->getEffort(i, timeStep) << "     New E: " << newEffort;
        }
    }
}

