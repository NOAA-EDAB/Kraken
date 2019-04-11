// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "GA_Chromosome.h"

GA_Chromosome::GA_Chromosome() {

}



GA_Chromosome::GA_Chromosome(Parameters *ptr_ParamObj) {

    m_paramsPtr = ptr_ParamObj;
}


GA_Chromosome::~GA_Chromosome() {

}

void GA_Chromosome::setChromosomeList(QList<double>) {
}

double GA_Chromosome::getChromosomeMin(int i) {
}

double GA_Chromosome::getChromosomeMax(int i) {
}

void GA_Chromosome::initializeChromosomeLists() {
}

int GA_Chromosome::getChromosomeListSize() {
}
