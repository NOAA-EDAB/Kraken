#ifndef GA_CHROMOSOME_H
#define GA_CHROMOSOME_H

#include "Parameters.h"

class GA_Chromosome {

private:

    QList<double> m_chromosome;
    QList<double> m_chromosomeMin;
    QList<double> m_chromosomeMax;
    Parameters* m_paramsPtr;

public:
    GA_Chromosome();
    GA_Chromosome(Parameters* ptr_ParamObj);
    ~GA_Chromosome();
    QList<double> getChromosome();
    QList<double> getMinChromosome();
    QList<double> getMaxChromosome();
    void setChromosomeList(QList<double>);
    double getChromosomeMin(int i);
    double getChromosomeMax(int i);
    void initializeChromosomeLists();
    int getChromosomeListSize();};

#endif // GA_CHROMOSOME_H
