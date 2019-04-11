// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "InteractionMatrix.h"

typedef QList<QList <double> > Int_Matrix;

InteractionMatrix::InteractionMatrix() {

}

void InteractionMatrix::setMatrix(Int_Matrix matrix) {
    m_IntMatrix = matrix;
}

Int_Matrix InteractionMatrix::getMatrix() {
    return m_IntMatrix;
}

void InteractionMatrix::printMatrix(const QStringList typeList) {
    int x = m_IntMatrix.size();
    int y = m_IntMatrix.at(0).size();
    qDebug() << x << "   " << y;
    for (int i = 0; i < x; i++) {
        qDebug() << "Name: " << typeList.at(i);
        for (int j = 0; j < y; j++) {
            qDebug() << m_IntMatrix.at(i).at(j);
        }
    }
    QString str;
    foreach (str, typeList) {
        qDebug() << "Name: " << str;
    }
}


void InteractionMatrix::clearMatrix() {

    m_IntMatrix.clear();
}

double InteractionMatrix::getMatrixValue(int i, int j) {

    int sizeOfBiomassList = m_IntMatrix.at(i).size();
//    qDebug() << "Size of biomass list: " << sizeOfBiomassList;
    return m_IntMatrix.at(i).at(j);
}


void InteractionMatrix::setMatrixValue(int i, int j, double newValue) {

//    qDebug() << "Old Value: " << m_IntMatrix.at(i).at(j);
    Int_Matrix *intMatrix = new QList<QList<double> >;
    int size = m_IntMatrix.size();
    for (int n = 0; n < size; n++) {
//        qDebug() << "n: " << n;
        QList<double> tempList = m_IntMatrix.at(n);
        if (n == i) {
            QList<double> *newList = new QList<double>;
            int size2 = tempList.size();
            for (int n2 = 0; n2 < size2; n2++) {
 //               qDebug() << "n: " << n << " :: n2: " << n2;
                if (n2 == j) {
                    newList->append(newValue);
                } else {
                    newList->append(tempList.at(n2));
                }
            }
            tempList = *newList;
            delete newList;
        }
        intMatrix->append(tempList);
    }
    m_IntMatrix = *intMatrix;
    delete intMatrix;
//    qDebug() << "New Value: " << m_IntMatrix.at(i).at(j);

}





void InteractionMatrix::addMatrixValue(int i, double value) {

    m_IntMatrix[i].append(value);
}


double InteractionMatrix::getOffAxisMatrixRowValue(int rowIndex) {

    double sum = 0.0;
    int sizeOfRow = m_IntMatrix.size();
    for (int i = 0; i < sizeOfRow; i++) {
        if (i != rowIndex) {
            sum += m_IntMatrix.at(rowIndex).at(i);
        }
    }
    return sum;
}


