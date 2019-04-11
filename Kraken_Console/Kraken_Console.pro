#-------------------------------------------------
#
# Project created by QtCreator 2015-01-23T15:35:43
#
#-------------------------------------------------


QT       += core

QT       -= gui

QT       += widgets

TARGET = Kraken_Console
CONFIG   += console
CONFIG   -= app_bundle

#TEMPLATE = app

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp\
    ..\..\PredationModuleTypeI.cpp \
    ..\..\Parameters.cpp \
    ..\..\ModelFormParameters.cpp \
    ..\..\ModelComponent.cpp \
    ..\..\Model.cpp \
    ..\..\InteractionMatrix.cpp \
    ..\..\HarvestModuleExploitRate.cpp \
    ..\..\HarvestModuleEffortQ.cpp \
    ..\..\GrowthModuleLogistic.cpp \
    ..\..\CompetitionModuleWithinGroup.cpp \
    ..\..\CompetitionModuleBetweenGroup.cpp \
    ..\..\PredationModuleTypeIII.cpp \
    ..\..\PredationModuleTypeII.cpp \
    ..\..\TimeSeriesObservations.cpp \
    ..\..\MeasureOfFitness.cpp \
    ..\..\GA_Estimator.cpp \
    ..\..\HarvestModuleCatch.cpp \
    ..\..\CompetitionModuleWithinGroup_FillToGuildK.cpp \
    ..\..\CompetitionBetweenSpeciesNoK.cpp \
    ..\..\GrowthModuleLinear.cpp \
    ..\..\AssessmentModule.cpp \
    ..\..\AssessmentModulePerfectKnowledge.cpp \
    ..\..\AssessmentModuleNull.cpp \
    ..\..\AssessmentModulePerfectKnowledgeLowestEffort.cpp \
    ..\..\AssessmentModuleAverageTotalCatch.cpp \
    ..\..\AssessmentModuleAverageCatchIndicatorSpecies.cpp \
    ..\..\AssessmentModuleAssessmentSetsACL.cpp \
    KrakenConsole.cpp \
    ../../GA_Chromosome.cpp \
    ../../AssessmentModuleStockComplexAsSingleStock.cpp
HEADERS  += \
    ..\..\TimeSeriesObservations.h \
    ..\..\PredationModuleTypeIII.h \
    ..\..\PredationModuleTypeII.h \
    ..\..\PredationModuleTypeI.h \
    ..\..\PredationModule.h \
    ..\..\Parameters.h \
    ..\..\ModelFormParameters.h \
    ..\..\ModelComponent.h \
    ..\..\Model.h \
    ..\..\MersenneTwister.h \
    ..\..\MeasureOfFitness.h \
    ..\..\InteractionMatrix.h \
    ..\..\HarvestModuleExploitRate.h \
    ..\..\HarvestModuleEffortQ.h \
    ..\..\HarvestModuleCatch.h \
    ..\..\HarvestModule.h \
    ..\..\GrowthModuleLogistic.h \
    ..\..\GrowthModuleLinear.h \
    ..\..\GrowthModule.h \
    ..\..\GA_Estimator.h \
    ..\..\CompetitionWithinGroup.h \
    ..\..\CompetitionModuleWithinGroup_FillToGuildK.h \
    ..\..\CompetitionModuleWithinGroup.h \
    ..\..\CompetitionModuleBetweenSpeciesNoK.h \
    ..\..\CompetitionModuleBetweenGroup.h \
    ..\..\AssessmentModulePerfectKnowledgeLowestEffort.h \
    ..\..\AssessmentModulePerfectKnowledge.h \
    ..\..\AssessmentModuleNull.h \
    ..\..\AssessmentModuleAverageTotalCatch.h \
    ..\..\AssessmentModuleAverageCatchIndicatorSpecies.h \
    ..\..\AssessmentModuleAssessmentSetsACL.h \
    ..\..\AssessmentModule.h \
    KrakenConsole.h \
    ../../GA_Chromosome.h \
    ../../AssessmentModuleStockComplexAsSingleStock.h
