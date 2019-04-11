// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef GA_ESTIMATOR_H
#define GA_ESTIMATOR_H

// GA_Estimator.h header file

#include <cmath>

#include "Parameters.h"
#include "TimeSeriesObservations.h"
#include "ModelFormParameters.h"
#include "MeasureOfFitness.h"
#include "Model.h"
#include "MersenneTwister.h"
#include <cmath>
#include <QString>

class GA_Estimator {

private:

    QString m_OutputFilename;
    QString m_OutputFilenameBest;
    int m_generation;
    double m_mutationRate;
    int m_maxGenerations;
    int m_convergenceNumber;
    int m_numGenerationsSinceBestFit;
    double m_populationSize;
    double m_generationBestFitness;
    double m_bestOverallFitness;

    Parameters* m_paramsPtr;
    TimeSeriesObservations* m_timeSeriesPtr;
    ModelFormParameters* m_modelFormPtr;
    MeasureOfFitness m_measureOfFitnessObj;

    Parameters* m_bestChromosome;
    QList<Parameters> m_bestChromosomeList;
    QList<Parameters> m_chromosomeParametersList;
    QList<double> m_chromosomeFitnessList;
    QList<double> m_chromosomeSelectionProbabilityList;
    QList<int> m_rouletteWheelList;
    QList<double> m_chromosomeRMSElist;

    QFile m_outfile;
    QTextStream m_textStreamOut;

    void initialize_GA_params();
    void initializeOutputFile();

    void createPopulation();
    void calculateFitness();
    void calculateFitness(int speciesIndex);
    void eliminateUnfit();
    void calculateSelectionProbabilities();
    void createNextGeneration();
    void rouletteSelection();
    void tournamentSelection();
    void createFullChromosomeFromSS();
    double mutate(double value, int mode, double min, double maz);
    double getMutationRate();

    void outputResults();
    void appendResults();
    void outputBestRun();

    MTRand m_MTRand;

public:
    GA_Estimator();
    GA_Estimator(Parameters* ptr_paramObj, TimeSeriesObservations *ptr_tsObservationsObj, ModelFormParameters* ptr_modelParamters);
    ~GA_Estimator();

    void setSaveFilenames(QString filename, QString filenameBest);

    void estimateParameters();

};


#endif // GA_ESTIMATOR_H
