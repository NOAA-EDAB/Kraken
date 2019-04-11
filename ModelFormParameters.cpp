// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "ModelFormParameters.h"


ModelFormParameters::ModelFormParameters() {

    m_GrowthForm = "Logistic";
    m_PredationForm = "Type I";
    m_HarvestForm = "H";
    m_wgcForm = "MS-PROD";
    m_bgcForm = "MS-PROD";
    m_StochasticGrowth = "NONE";
    m_StochasticCatch = "NONE";
    m_AssessmentType = "NONE";
//    m_NumRuns = 1;
//    m_RunLength = 50;
//    m_HistoricalEnd = 100;
//    m_TimeStep = 1;
}


void ModelFormParameters::setGrowthForm(QString growthForm) {

    if ((growthForm == "LOGISTIC") || (growthForm == "LOGISTIC-STOCHASTIC") || (growthForm == "LINEAR")) {
        m_GrowthForm = growthForm;
    } else {
        qDebug() << "Incorrect Model Growth Form: " << growthForm;
    }
}

void ModelFormParameters::setHarvestForm(QString harvestForm) {

    if ((harvestForm == "H") || (harvestForm == "QE") || (harvestForm == "CATCH")) {
        m_HarvestForm = harvestForm;
    } else {
        qDebug() << "Incorrect Model Harvest Form: " << harvestForm;
    }
}


void ModelFormParameters::setPredationForm(QString predationForm) {

    if ((predationForm == "TYPE I") || (predationForm == "TYPE II") || (predationForm == "TYPE III")) {
        m_PredationForm = predationForm;
    } else {
        qDebug() << "Incorrect Model Predation Form: " << predationForm;
    }
}

void ModelFormParameters::setwgcForm(QString wgcForm) {

    if ((wgcForm == "MS-PROD") || (wgcForm == "NO_K") || (wgcForm == "NULL")) {
        m_wgcForm = wgcForm;
    } else {
        qDebug() << "Incorrect Model Within Guild Competition Form: " << wgcForm;
    }
}

void ModelFormParameters::setbgcForm(QString bgcForm) {

    if ((bgcForm == "MS-PROD") || (bgcForm == "NULL")) {
        m_bgcForm = bgcForm;
    } else {
        qDebug() << "Incorrect Model Within Guild Competition Form: " << bgcForm;
    }
}


void ModelFormParameters::setAssessmentType(QString assessType) {

    m_AssessmentType = assessType;
}


void ModelFormParameters::setStochasticGrowth(QString stochasticGrowth) {

    if ((stochasticGrowth == "EACH STEP") || (stochasticGrowth == "BEGINNING") || (stochasticGrowth == "NONE")) {
        m_StochasticGrowth = stochasticGrowth;
    } else {
        qDebug() << "Incorrect Stochastic Growth Form: " << stochasticGrowth;
    }
}


void ModelFormParameters::setStochasticCatch(QString stochasticCatch) {

    if ((stochasticCatch == "EACH STEP") || (stochasticCatch == "NONE")) {
        m_StochasticCatch = stochasticCatch;
    } else {
        qDebug() << "Incorrect Stochastic Catch Form: " << stochasticCatch;
    }
}


void ModelFormParameters::setNumRuns(int numRuns) {

    m_NumRuns = numRuns;
}


void ModelFormParameters::setRunLength(int runLength) {

    m_RunLength = runLength;
}


void ModelFormParameters::setHistoricalEnd(int histEnd) {

    m_HistoricalEnd = histEnd;
}


void ModelFormParameters::setTimeStep(int timeStep) {

    m_TimeStep = timeStep;
}


QString ModelFormParameters::getGrowthForm() {

    return m_GrowthForm;
}

QString ModelFormParameters::getHarvestForm() {

    return m_HarvestForm;
}

QString ModelFormParameters::getPredationForm() {

    return m_PredationForm;
}

QString ModelFormParameters::getwgcForm() {

    return m_wgcForm;
}

QString ModelFormParameters::getbgcForm() {

    return m_bgcForm;
}

QString ModelFormParameters::getAssessmentType() {

    return m_AssessmentType;
}


QString ModelFormParameters::getStochasticGrowth() {

    return m_StochasticGrowth;
}

QString ModelFormParameters::getStochasticCatch() {

    return m_StochasticCatch;
}

int ModelFormParameters::getNumRuns() {

    return m_NumRuns;
}

int ModelFormParameters::getRunLength() {

    return m_RunLength;
}

int ModelFormParameters::getHistoricalEnd() {

    return m_HistoricalEnd;
}

int ModelFormParameters::getTimeStep() {

    return m_TimeStep;
}


void ModelFormParameters::setACL_Buffer(double buffer) {

    m_ACL_Buffer = buffer;
}

void ModelFormParameters::setAssessmentCV(double cv) {

    m_AssessmentCV = cv;
}

void ModelFormParameters::setNumYearsBetweenAssessments(int numYears) {

    m_NumYearsBetweenAssessments = numYears;
}

void ModelFormParameters::setIndicatorSpecies(int speciesNum) {

    m_IndicatorSpecies = speciesNum;
}

double ModelFormParameters::getACL_Buffer() {

    return m_ACL_Buffer;
}

double ModelFormParameters::getAssessmentCV() {

    return m_AssessmentCV;
}

int ModelFormParameters::getNumYearsBetweenAssessments() {

    return m_NumYearsBetweenAssessments;
}

int ModelFormParameters::getIndicatorSpecies() {

    return m_IndicatorSpecies;
}
