// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef MODEL_H
#define MODEL_H

// Model creation and execution class

#include <QList>
#include <QString>
#include <QDebug>

#include "GrowthModuleLogistic.h"
#include "GrowthModuleLinear.h"
#include "CompetitionModuleWithinGroup.h"
#include "CompetitionModuleBetweenSpeciesNoK.h"
#include "CompetitionModuleBetweenGroup.h"
#include "PredationModuleTypeI.h"
#include "PredationModuleTypeII.h"
#include "PredationModuleTypeIII.h"
#include "HarvestModuleEffortQ.h"
#include "HarvestModuleExploitRate.h"
#include "HarvestModuleCatch.h"
#include "ModelComponent.h"
#include "Parameters.h"
#include "ModelFormParameters.h"
#include "AssessmentModule.h"
#include "AssessmentModuleNull.h"
#include "AssessmentModulePerfectKnowledge.h"
#include "AssessmentModulePerfectKnowledgeLowestEffort.h"
#include "AssessmentModuleAverageTotalCatch.h"
#include "AssessmentModuleAverageCatchIndicatorSpecies.h"
#include "AssessmentModuleAssessmentSetsACL.h"
#include "AssessmentModuleStockComplexAsSingleStock.h"
#include <QSharedPointer>

class Model {

private:

    QList<ModelComponent*> m_ModelComponentList;
    ModelComponent* m_growthFormPtr;
    ModelComponent* m_competitionWithinGroupFormPtr;
    ModelComponent* m_competitionBetweenGroupFormPtr;
    ModelComponent* m_predationFormPtr;
    ModelComponent* m_harvestFormPtr;
//    QList<QSharedPointer<ModelComponent>> m_ModelComponentList;
//    QSharedPointer<ModelComponent> m_growthFormPtr;
//    QSharedPointer<ModelComponent> m_competitionWithinGroupFormPtr;
//    QSharedPointer<ModelComponent> m_competitionBetweenGroupFormPtr;
//    QSharedPointer<ModelComponent> m_predationFormPtr;
//    QSharedPointer<ModelComponent> m_harvestFormPtr;

    QSharedPointer<AssessmentModule> m_assessmentModulePtr;

    ModelFormParameters* m_modelParamsPtr;
    Parameters* m_paramsPtr;





public:

    Model();
    Model(Parameters* paramObj, ModelFormParameters* modelParamObj);
    ~Model();
    void initializeModel();
    void initializeModel(Parameters* paramObj);
    void runModel();
    void runModel_noOutput();
    void testRun();

};

#endif // MODEL_H
