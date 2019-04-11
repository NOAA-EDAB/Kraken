#ifndef MODELCOMPONENT_H
#define MODELCOMPONENT_H

// ModelComponent.h

#include "Parameters.h"
#include "ModelFormParameters.h"
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QList>
#include <cmath>
#include "MersenneTwister.h"

class ModelComponent {

protected:

    QString m_ComponentName;
    QString m_OutputName;
    bool m_OutputLossesByGroup;

    void outputLosses(QTextStream& outputStream, QList<QString> speciesList);
    void initializeOutputMatrix(Parameters* paramObj);
    void initializeOutputLossesByGroupMatrix(Parameters* paramObj, ModelFormParameters *modelFormObj);

    InteractionMatrix m_OutputMatrix;

    QList <QList <QList <double> > > m_OutputLossesByGroupData;



public:

    virtual double getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const = 0;
    virtual void updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const = 0;
    void updateLosses(int speciesIndex, double lossValue);
    void outputResults(QTextStream& outputStream, QList<QString> speciesList);
    QString getComponentName();
    QString getOutputName();
    void setNoOutput();
};

#endif // MODELCOMPONENT_H
