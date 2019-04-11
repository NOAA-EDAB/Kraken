// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef MODELFORMPARAMETERS_H
#define MODELFORMPARAMETERS_H

// Model Formulation Parameters

#include <QString>
#include <QDebug>


class ModelFormParameters {

private:
    QString m_GrowthForm;
    QString m_PredationForm;
    QString m_HarvestForm;
    QString m_wgcForm;              // Within Guild Competition
    QString m_bgcForm;              // Between Guild Competition
    QString m_AssessmentType;
    QString m_StochasticGrowth;
    QString m_StochasticCatch;

    int m_NumRuns;
    int m_RunLength;
    int m_HistoricalEnd;
    int m_TimeStep;

    int m_NumYearsBetweenAssessments;
    int m_IndicatorSpecies;
    double m_AssessmentCV;
    double m_ACL_Buffer;

public:
    ModelFormParameters();

    void setGrowthForm(QString);
    void setPredationForm(QString);
    void setHarvestForm(QString);
    void setwgcForm(QString);
    void setbgcForm(QString);
    void setAssessmentType(QString);
    void setStochasticGrowth(QString);
    void setStochasticCatch(QString);

    void setNumRuns(int);
    void setRunLength(int);
    void setHistoricalEnd(int);
    void setTimeStep(int);


    QString getGrowthForm();
    QString getPredationForm();
    QString getHarvestForm();
    QString getwgcForm();
    QString getbgcForm();
    QString getAssessmentType();
    QString getStochasticGrowth();
    QString getStochasticCatch();

    int getNumRuns();
    int getRunLength();
    int getHistoricalEnd();
    int getTimeStep();

    void setAssessmentCV(double);
    void setIndicatorSpecies(int);
    void setACL_Buffer(double);
    void setNumYearsBetweenAssessments(int);

    double getAssessmentCV();
    int getIndicatorSpecies();
    double getACL_Buffer();
    int getNumYearsBetweenAssessments();
};

#endif // MODELFORMPARAMETERS_H
