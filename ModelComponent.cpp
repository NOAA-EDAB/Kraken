// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "ModelComponent.h"

QString ModelComponent::getComponentName() {
    return m_ComponentName;
}


QString ModelComponent::getOutputName() {
    return m_OutputName;
}


void ModelComponent::initializeOutputMatrix(Parameters* paramObj) {

    QList<QList<double> > *outputMatrix = new QList<QList<double> >;
    int numSpecies = paramObj->getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        QList<double> *newList = new QList<double>;
        outputMatrix->append(*newList);
        delete newList;
    }
    m_OutputMatrix.setMatrix(*outputMatrix);
    delete outputMatrix;
}


void ModelComponent::updateLosses(int speciesIndex, double lossValue) {

//    qDebug() << "Species: " << speciesIndex << "Loss Value: " << lossValue;
    m_OutputMatrix.addMatrixValue(speciesIndex, lossValue);
}


void ModelComponent::initializeOutputLossesByGroupMatrix(Parameters* paramObj, ModelFormParameters* modelFormObj) {

    int numSpecies = paramObj->getNumberOfSpecies();
    int runLength = modelFormObj->getRunLength();
    int timeStep = modelFormObj->getTimeStep();
    int numTimeSteps = runLength/timeStep;

    QList <QList <QList <double > > > *tempList = new QList<QList<QList<double> > >;
    for (int i = 0; i < numSpecies; i++) {
        QList <QList <double> > *affectingMatrix = new QList<QList<double> >;
        for (int ts = 0; ts < numTimeSteps; ts++) {
            QList<double> *newList = new QList<double>;
            affectingMatrix->append(*newList);
            delete newList;
        }
        tempList->append(*affectingMatrix);
    }
    m_OutputLossesByGroupData = *tempList;
    delete tempList;
}


void ModelComponent::outputResults(QTextStream& outputStream, QList<QString> speciesList) {

    outputStream << "\n";
    outputStream << "Time Step,";
    QString species;
    foreach (species, speciesList) {
        outputStream << species << m_OutputName << ",";
    }

    outputStream << "\n";

    QList<QList <double> > outputMatrix = m_OutputMatrix.getMatrix();
    int x = speciesList.size();
    int y = outputMatrix.at(0).size();
    for (int i = 0; i < y; i++) {
        outputStream << i << ",";
        for (int j = 0; j < x; j++) {
            outputStream << outputMatrix.at(j).at(i) << ",";
        }
        outputStream << "\n";
    }

    outputStream << "\n";
}


void ModelComponent::setNoOutput() {
    m_OutputLossesByGroup = false;
}
