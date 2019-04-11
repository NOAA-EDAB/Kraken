#ifndef KRAKENCONSOLE_H
#define KRAKENCONSOLE_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <fstream>
#include <string>
#include "../../Parameters.h"
#include "../../TimeSeriesObservations.h"
#include "../../MeasureOfFitness.h"
#include "../../ModelFormParameters.h"
#include "../../GrowthModuleLogistic.h"
#include "../../PredationModuleTypeI.h"
#include "../../PredationModuleTypeII.h"
#include "../../PredationModuleTypeIII.h"
#include "../../HarvestModuleEffortQ.h"
#include "../../HarvestModuleExploitRate.h"
#include "../../Model.h"
#include "../../GA_Estimator.h"

class KrakenConsole
{

public:
    KrakenConsole();
    KrakenConsole(int &argc, char **argv);
    QFile m_logOutputFile;
    void startConsole();

private:

    QTextStream m_logOutputFileStream;
    QString m_parameterFilename;
    QString m_parameterDirectory;
    QString m_dataFilename;
    QString m_outputFilename;
    QString m_outputDirectory;
    QString m_dataID;
    bool m_fit;

    Parameters paramObj;
    TimeSeriesObservations tsObj;
    ModelFormParameters modelFormParamObj;
    MeasureOfFitness measureOfFitnessObj;
    QStringList lineList;

    void setArgumentParameters();
    void loadFromParameterFile();
    void loadFromDataFile();

    void setSystemK();
    void setSpecies();
    void setInitialBiomass();
    void setInitialBiomassMin();
    void setInitialBiomassMax();
    void setSpeciesK();
    void setSpeciesMinK();
    void setSpeciesMaxK();
    void setSpeciesKCovariateCoefficients();
    void setSurveyQ();
    void setSurveyMinQ();
    void setSurveyMaxQ();
    void setUnits();
    void setOutputType();
    void setHarvestRates();
    void setCovariateTimeSeries();
    void setStDevStochasticGrowth();
    void setStDevStochasticCatch();
    void setGrowthRates();
    void setGrowthRatesMin();
    void setGrowthRatesMax();
    void setGrowthRateCovariateCoefficients();
    void setPelProportionList();
    void setDemProportionList();
    void setGuilds();
    void setGuildMembership();
    void setGrowthMode();
    void setHarvestMode();
    void setPredationMode();
    void setwgcMode();
    void setbgcMode();
    void setStochasticGrowth();
    void setStochasticCatch();
    void setNumRuns();
    void setRunLength();
    void setHistoricalEnd();
    void setTimeStep();
    void setAssessmentType();
    void setAssessmentCV();
    void setIndicatorSpecies();
    void setACL_Buffer();
    void setNumYearsBetweenAssessments();

    void set_GA_generations();
    void set_GA_populationSize();
    void set_GA_mutationRate();
    void set_GA_convergenceNumber();

    void logResults();
    void runModel();
    void fitModel();
    void testFramework();

    QString convertDoubleToString(double);
    QList<double> returnParameterList();
    QList< QList <double> >* initializeParamMatrix(QTextStream &);
    QList< QList <double> >* initializeTimeSeriesMatrix(QTextStream &);
};
#endif // KRAKENCONSOLE_H
