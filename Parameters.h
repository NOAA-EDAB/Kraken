// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QString>
#include <QStringList>
#include <QList>
#include <QDebug>
#include <QHash>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include "InteractionMatrix.h"
#include "MersenneTwister.h"

class ModelComponent;

// Parameters.h header file

typedef QList<QList <double> > Int_Matrix;

class Parameters {

private:
    QString m_rSeed;
    QString m_OutputFilename;
    QString m_OutputType;
    QString m_OutputDirectory;
    int m_numSpecies;

    QString m_BiomassUnits;
    double m_SystemK;
    QStringList m_SpeciesList;
    QStringList m_GuildList;
    QHash<QString, QString> m_SpeciesGuildMembershipHash;
    QList<double> m_PelagicProportionList;
    QList<double> m_DemersalProportionList;

    QList<double> m_SpeciesKList;
    QList<double> m_SpeciesKCovariatesList;
    QList<double> m_SurveyQList;

    InteractionMatrix m_BiomassMatrix;
    InteractionMatrix m_HarvestLossesMatrix;
    InteractionMatrix m_PredationLossesMatrix;
    InteractionMatrix m_CompetitionWithinGroupLossesMatrix;
    InteractionMatrix m_BetweenGuildCompMatrix;
    InteractionMatrix m_WithinGuildCompMatrix;
    InteractionMatrix m_PredationMatrix;
    InteractionMatrix m_HandlingTimeMatrix;
    InteractionMatrix m_bCoefMatrix;
    InteractionMatrix m_SpatialOverlapMatrix;
    InteractionMatrix m_CatchMatrix;
    InteractionMatrix m_EffortMatrix;
    InteractionMatrix m_CatchabilityMatrix;
    InteractionMatrix m_OutputCatchMatrix;

    QList<double> m_GrowthRateList;
    QList<double> m_GrowthRateOriginalList;
    QList<double> m_GrowthRateCovariatesList;
    QList<double> m_InitialBiomassList;
    QList<double> m_HarvestRateList;
    QList<double> m_EffortList;
    QList<double> m_CatchabilitiesList;

    QList<double> m_CovariateTimeSeriesList;

    QHash<QString, double> m_GuildBiomassHash;
    bool m_loaded;

    int m_GA_generations;
    int m_GA_populationSize;
    double m_GA_mutationRate;
    int m_GA_convergenceNumber;

    QList<double> m_ChromosomeList;
    QList<double> m_ChromosomeMinList;
    QList<double> m_ChromosomeMaxList;

    void initializeChromosomeList();
    void initializeChromosomeMinList();
    void initializeChromosomeMaxList();
    void initializeChromosomeList(QString mode);
    void initializeChromosomeMinList(QString mode);
    void initializeChromosomeMaxList(QString mode);
    void setMinMaxValuesAfterReset(double, double, QList<double>, QList<double>);

    QList<double> m_InitialBiomassMinList;
    QList<double> m_InitialBiomassMaxList;
    QList<double> m_GrowthRateMinList;
    QList<double> m_GrowthRateMaxList;
    QList<double> m_SpeciesK_MinList;
    QList<double> m_SpeciesK_MaxList;
    QList<double> m_SurveyQ_MinList;
    QList<double> m_SurveyQ_MaxList;
    InteractionMatrix m_WithinGuildCompMinMatrix;
    InteractionMatrix m_WithinGuildCompMaxMatrix;
    InteractionMatrix m_PredationLossRatesMinMatrix;
    InteractionMatrix m_PredationLossRatesMaxMatrix;
    InteractionMatrix m_BetweenGuildCompMinMatrix;
    InteractionMatrix m_BetweenGuildCompMaxMatrix;
    double m_stDevGrowth;
    double m_stDevCatch;
    bool m_isFitting;

    MTRand m_MTRand;

public:
    Parameters();

    bool loaded();
    bool isFitting();
    void setFitting(bool fitting);

    void setLoadedTrue();
    void setSaveFilename(QString saveFilename);
    void setOutputDirectory(QString outputDirectory);

    void setRseed(QString seed);
    QString getBiomassUnits();
    void setBiomassUnits(QString);
    double getSystemK();
    void setSystemK(double);

    int getNumberOfSpecies();

    QStringList getSpeciesList();
    void setSpeciesList(QStringList);
    QString getSpeciesName(int);

    QList<double> getSpeciesKList();
    void setSpeciesKList(QList<double>);
    void printSpeciesKList();
    double getSpeciesK(const int speciesIndex);

    QList<double> getSurveyQList();
    void setSurveyQList(QList<double>);
    double getSurveyQ(const int speciesIndex);

    QList<double> getSpeciesKCovariatesList();
    void setSpeciesKCovariatesList(QList<double>);
    double getSpeciesKCovariate(const int speciesIndex);

    QStringList getGuildList();
    void setGuildList(QStringList);
    void printGuildList();
    int getNumberOfGuilds();
    QString getGuildName(int);

    QHash<QString, QString> getSpeciesGuildMembershipHash();
    void setSpeciesGuildMembershipHash(QStringList);
    void printSpeciesGuildMembershipHash();
    QString getGuildMembership(QString);

    Int_Matrix getBiomassMatrix();
    void setBiomassMatrix(Int_Matrix);
    void clearBiomassMatrix();
    void printBiomassMatrix();
    double getBiomass(const int speciesIndex, const int time);
    double getBiomass(const QString speciesName, const int time);
    void updateBiomass(const int speciesIndex, const int time, const double dN);
    void updateOutputCatch(const int speciesIndex, const double catches);
    void clearOutputCatchMatrix();
    void setOutputBiomassMatrix(Int_Matrix);
    double getOutputCatch(const int speciesIndex, const int time);
    void setOutputCatchMatrix(Int_Matrix);

    Int_Matrix getWithinGuildCompMatrix();
    void setWithinGuildCompMatrix(Int_Matrix);
    void printWithinGuildCompMatrix();
    double getWithinGuildCompParam(int,int);
    void setWithinGuildCompParam(int, int, double);

    Int_Matrix getBetweenGuildCompMatrix();
    void setBetweenGuildCompMatrix(Int_Matrix);
    void printBetweenGuildCompMatrix();
    double getBetweenGuildCompParam(int,int);

    Int_Matrix getPredationMatrix();
    void setPredationMatrix(Int_Matrix);
    void printPredationMatrix();
    double getAvailability(int,int);

    Int_Matrix getHandlingTimeMatrix();
    void setHandlingTimeMatrix(Int_Matrix);
    void printHandlingTimeMatrix();
    double getHandlingTime(int,int);

    Int_Matrix getbCoefMatrix();
    void setbCoefMatrix(Int_Matrix);
    void printbCoefMatrix();
    double getbCoef(int,int);

    Int_Matrix getSpatialOverlapMatrix();
    void setSpatialOverlapMatrix(Int_Matrix);
    void printSpatialOverlapMatrix();
    double getSpatialOverlap(int,int);

    void setGrowthRates(QList<double>);
    double getGrowthRate(const int speciesIndex);
    QList<double> getGrowthRateList();

    void setOriginalGrowthRates(QList<double>);
    QList<double> getOriginalGrowthRateList();
    double getOriginalGrowthRate(const int speciesIndex);

    void setGrowthRateCovariateList(QList<double>);
    QList<double> getGrowthRateCovariateList();
    double getGrowthRateCovariate(const int speciesIndex);

    void setInitialBiomassList(QList<double>);
    QList<double> getInitialBiomassList();
    void printInitialBiomassList();

    void setPelagicProportionList(QList<double>);
    QList<double> getPelagicProportionList();
    void printPelagicProportionList();

    void setDemersalProportionList(QList<double>);
    QList<double> getDemersalProportionList();
    void printDemersalProportionList();

    void setHarvestRateList(QList<double>);
    QList<double> getHarvestRateList();
    void printHarvestRateList();

    void setCatchabilitiesList(QList<double>);
    QList<double> getCatchabilitiesList();
    void printCatchabilitiesList();

    void setEffortList(QList<double>);
    void setEffort(const int speciesIndex, const int time, const double newEffort);
    QList<double> getEffortList();
    void printEffortList();

    void setCatchMatrix(Int_Matrix);
    void setEffortMatrix(Int_Matrix);
    void setCatchabilityMatrix(Int_Matrix);

    double getHarvestRate(const int speciesIndex);
    double getCatchability(const int speciesIndex);
    double getCatchability(const int speciesIndex, const int time);
    double getEffort(const int speciesIndex);
    double getEffort(const int speciesIndex, const int time);
    double getCatch(const int speciesIndex, const int time);

    void setCovariatesList(QList<double>);
    QList<double> getCovariatesList();
    double getCovariate(const int time);

    void setStDevGrowth(double);
    void setStDevCatch(double);

    double getStDevGrowth();
    double getStDevCatch();

    void setStochasticGrowthList();

    void initializeListsAndTS(const int timestep);

    void setGuildBiomass(const int timestep);
    double getGuildBiomass(QString);

    // Genetic Algoroithm Parameter Methods
    QList<double> getChromosomeList();
    void setChromosomeList(QList<double>);
    double getChromosomeMin(int i);
    double getChromosomeMax(int i);
    void initializeChromosomeLists();
    void initializeChromosomeLists(QString mode);
    int getChromosomeListSize();

    int get_GA_generations();
    int get_GA_populationSize();
    double get_GA_mutationRate();
    int get_GA_convergenceNumber();
    void set_GA_convergenceNumber(int convergenceNumber);

    void set_GA_generations(int generations);
    void set_GA_populationSize(int populationSize);
    void set_GA_mutationRate(double mutationRate);

    QList<double> getInitialBiomassMinList();
    void setInitialBiomassMinList(QList<double>);
    void printInitialBiomassMinList();

    QList<double> getInitialBiomassMaxList();
    void setInitialBiomassMaxList(QList<double>);
    void printInitialBiomassMaxList();

    QList<double> getSpeciesK_MinList();
    void setSpeciesK_MinList(QList<double>);
    void printSpeciesK_MinList();

    QList<double> getSpeciesK_MaxList();
    void setSpeciesK_MaxList(QList<double>);
    void printSpeciesK_MaxList();

    QList<double> getSurveyQ_MinList();
    void setSurveyQ_MinList(QList<double>);

    QList<double> getSurveyQ_MaxList();
    void setSurveyQ_MaxList(QList<double>);

    void setGrowthRatesMin(QList<double>);
    QList<double> getGrowthRateMinList();

    void setGrowthRatesMax(QList<double>);
    QList<double> getGrowthRateMaxList();

    Int_Matrix getWithinGuildCompMinMatrix();
    void setWithinGuildCompMinMatrix(Int_Matrix);
    void printWithinGuildCompMinMatrix();

    Int_Matrix getWithinGuildCompMaxMatrix();
    void setWithinGuildCompMaxMatrix(Int_Matrix);
    void printWithinGuildCompMaxMatrix();

    Int_Matrix getBetweenGuildCompMinMatrix();
    void setBetweenGuildCompMinMatrix(Int_Matrix);
    void printBetweenGuildCompMinMatrix();

    Int_Matrix getBetweenGuildCompMaxMatrix();
    void setBetweenGuildCompMaxMatrix(Int_Matrix);
    void printBetweenGuildCompMaxMatrix();

    Int_Matrix getPredationLossRatesMinMatrix();
    void setPredationLossRatesMinMatrix(Int_Matrix);
    void printPredationLossRatesMinMatrix();

    Int_Matrix getPredationLossRatesMaxMatrix();
    void setPredationLossRatesMaxMatrix(Int_Matrix);
    void printPredationLossRatesMaxMatrix();

    void resetChromosomeAfterSS();
    void zeroInteractionCoefficients();

    double calculatePredationToBiomassRatio(int preyIndex, int timeStep);

    QString getOutputType();
    void setOutputType(QString);
    void outputResults(const QList<ModelComponent*>);
    void initializeStochasticOutputFiles();
    void outputStochasticResults(int modelRun);
    void outputSkillAssessmentResults();

};

#endif // PARAMETERS_H
