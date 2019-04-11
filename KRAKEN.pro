#-------------------------------------------------
#
# Project created by QtCreator 2012-12-21T13:15:22
#
#-------------------------------------------------

QT       += core gui

TARGET = KRAKEN
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
        ms_prod_mainwindow.cpp \
    PredationModuleTypeI.cpp \
    Parameters.cpp \
    ModelFormParameters.cpp \
    ModelComponent.cpp \
    Model.cpp \
    InteractionMatrix.cpp \
    HarvestModuleExploitRate.cpp \
    HarvestModuleEffortQ.cpp \
    GrowthModuleLogistic.cpp \
    CompetitionModuleWithinGroup.cpp \
    CompetitionModuleBetweenGroup.cpp \
    PredationModuleTypeIII.cpp \
    PredationModuleTypeII.cpp \
    TimeSeriesObservations.cpp \
    MeasureOfFitness.cpp \
    GA_Estimator.cpp \
    HarvestModuleCatch.cpp \
    CompetitionModuleWithinGroup_FillToGuildK.cpp \
    CompetitionBetweenSpeciesNoK.cpp \
    GrowthModuleLinear.cpp \
    AssessmentModule.cpp \
    AssessmentModulePerfectKnowledge.cpp \
    AssessmentModuleNull.cpp \
    AssessmentModulePerfectKnowledgeLowestEffort.cpp \
    AssessmentModuleAverageTotalCatch.cpp \
    AssessmentModuleAverageCatchIndicatorSpecies.cpp \
    AssessmentModuleAssessmentSetsACL.cpp \
    AssessmentModuleStockComplexAsSingleStock.cpp

HEADERS  += \
    ui_ms_prod_mainwindow.h \
    TimeSeriesObservations.h \
    PredationModuleTypeIII.h \
    PredationModuleTypeII.h \
    PredationModuleTypeI.h \
    PredationModule.h \
    Parameters.h \
    ms_prod_mainwindow.h \
    ModelFormParameters.h \
    ModelComponent (2).h \
    ModelComponent.h \
    Model.h \
    MersenneTwister.h \
    MeasureOfFitness.h \
    InteractionMatrix.h \
    HarvestModuleExploitRate.h \
    HarvestModuleEffortQ.h \
    HarvestModuleCatch.h \
    HarvestModule.h \
    GrowthModuleLogistic.h \
    GrowthModuleLinear.h \
    GrowthModule.h \
    GA_Estimator.h \
    CompetitionWithinGroup.h \
    CompetitionModuleWithinGroup_FillToGuildK.h \
    CompetitionModuleWithinGroup.h \
    CompetitionModuleBetweenSpeciesNoK.h \
    CompetitionModuleBetweenGroup.h \
    AssessmentModulePerfectKnowledgeLowestEffort.h \
    AssessmentModulePerfectKnowledge.h \
    AssessmentModuleNull.h \
    AssessmentModuleAverageTotalCatch.h \
    AssessmentModuleAverageCatchIndicatorSpecies.h \
    AssessmentModuleAssessmentSetsACL.h \
    AssessmentModule.h \
    AssessmentModuleStockComplexAsSingleStock.h

FORMS    += ms_prod_mainwindow.ui

OTHER_FILES += \
    MS_PROD_MAIN_IMAGE.jpg

RESOURCES += \
    MS_PROD_resource_QT.qrc
