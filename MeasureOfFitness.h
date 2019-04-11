// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef MEASUREOFFITNESS_H
#define MEASUREOFFITNESS_H

// MeasureOfFitness.h header file

#include "Parameters.h"
#include "TimeSeriesObservations.h"

class MeasureOfFitness {

private:

    double m_MAE;
    double m_RMSE;
    double m_RMSE_modified;
    double m_MEF_modified;
    double calculateAdjustedMEF(double, double);

    Parameters* m_paramsPtr;
    TimeSeriesObservations* m_tsObservationsPtr;


public:
    MeasureOfFitness();
    void calculateMeasuresOfFitness(Parameters* paramObj, TimeSeriesObservations* tsObservationsObj);
    void calculateMeasuresOfFitness(Parameters* paramObj, TimeSeriesObservations* tsObservationsObj, int speciesIndex);
    double getTSbiomassValue(int speciesIndex, int timeStep, Parameters* paramObj, TimeSeriesObservations* tsObj);
    void outputMeasuresOfFitness();
    double getMAE();
    double getRMSE();
    double getRMSE_modified();
    double getMEF_modified();
};


#endif // MEASUREOFFITNESS_H
