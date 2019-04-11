// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef INTERACTIONMATRIX_H
#define INTERACTIONMATRIX_H

// InteractionMatrix.h header file

#include <QList>
#include <QStringList>
#include <QDebug>

class InteractionMatrix {

private:
    QList<QList <double> > m_IntMatrix;


public:
    InteractionMatrix();

    void setMatrix(QList<QList <double> > matrix);
    void clearMatrix();
    QList<QList <double> > getMatrix();
    double getMatrixValue(int i, int j);
    void setMatrixValue(int i, int j, double newValue);
    void addMatrixValue(int i, double value);
    double getOffAxisMatrixRowValue(int rowIndex);
    void printMatrix(QStringList);

};

#endif // INTERACTIONMATRIX_H
