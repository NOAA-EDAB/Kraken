#include "Parameters.h"
#include "ModelComponent.h"

Parameters::Parameters() {
    m_BiomassUnits = "mt";
    m_SystemK = 0;
    m_loaded = false;
    m_stDevGrowth = 0;
    m_stDevCatch = 0;
    m_rSeed = "-999";
    m_OutputFilename = "SkillOut_";
    m_OutputDirectory = QDir::currentPath();
    m_OutputDirectory = m_OutputDirectory.append("/");
    m_isFitting = false;
    m_GA_convergenceNumber = 100;
    m_numSpecies = 0;

}


bool Parameters::loaded() {

    return m_loaded;
}


void Parameters::setLoadedTrue() {

    m_loaded = true;
}


void Parameters::setFitting(bool fitting) {

    m_isFitting = fitting;
}

bool Parameters::isFitting() {

    return m_isFitting;
}

void Parameters::setRseed(QString seed) {

    m_rSeed = seed;
}


QString Parameters::getBiomassUnits() {
    return m_BiomassUnits;
}


void Parameters::setBiomassUnits(QString value) {
    m_BiomassUnits = value;
}

void Parameters::setOutputType(QString outputType) {
    m_OutputType = outputType;
}


QString Parameters::getOutputType() {
    return m_OutputType;
}


double Parameters::getSystemK() {
    return m_SystemK;
}


void Parameters::setSystemK(double value) {
    m_SystemK = value;
}


int Parameters::getNumberOfSpecies() {

    return m_numSpecies;
}


QStringList Parameters::getSpeciesList() {
    return m_SpeciesList;
}


void Parameters::setSpeciesList(QStringList list) {
    m_SpeciesList = list;
    m_numSpecies = m_SpeciesList.size();
}


QString Parameters::getSpeciesName(int i) {

    return m_SpeciesList.at(i);
}


QList<double> Parameters::getSpeciesKList() {
    return m_SpeciesKList;
}


void Parameters::setSpeciesKList(QList<double> list) {
    m_SpeciesKList = list;
}


void Parameters::printSpeciesKList() {
    double value;
//     qDebug() << "Species K: ";
    foreach (value, m_SpeciesKList) {
//         qDebug() << value;
    }
}


double Parameters::getSpeciesK(const int speciesIndex) {

    double speciesK = m_SpeciesKList.at(speciesIndex);
    return speciesK;
}


QList<double> Parameters::getSpeciesKCovariatesList() {
    return m_SpeciesKCovariatesList;
}


void Parameters::setSpeciesKCovariatesList(QList<double> list) {
    m_SpeciesKCovariatesList = list;
}


double Parameters::getSpeciesKCovariate(int speciesIndex) {

    double speciesKCovariate = m_SpeciesKCovariatesList.at(speciesIndex);
    return speciesKCovariate;
}


QList<double> Parameters::getInitialBiomassMinList() {
    return m_InitialBiomassMinList;
}


void Parameters::setInitialBiomassMinList(QList<double> list) {
    m_InitialBiomassMinList = list;
}


void Parameters::printInitialBiomassMinList() {
    double value;
//     qDebug() << "Initial Biomass (Min): ";
    foreach (value, m_InitialBiomassMinList) {
//         qDebug() << value;
    }
}


QList<double> Parameters::getInitialBiomassMaxList() {
    return m_InitialBiomassMaxList;
}


void Parameters::setInitialBiomassMaxList(QList<double> list) {
    m_InitialBiomassMaxList = list;
}


void Parameters::printInitialBiomassMaxList() {
    double value;
//     qDebug() << "Initial Biomass (Max): ";
    foreach (value, m_InitialBiomassMaxList) {
//         qDebug() << value;
    }
}


QList<double> Parameters::getSpeciesK_MinList() {
    return m_SpeciesK_MinList;
}


void Parameters::setSpeciesK_MinList(QList<double> list) {
    m_SpeciesK_MinList = list;
}


void Parameters::printSpeciesK_MinList() {
    double value;
//     qDebug() << "Species K (Min): ";
    foreach (value, m_SpeciesK_MinList) {
//         qDebug() << value;
    }
}


QList<double> Parameters::getSpeciesK_MaxList() {
    return m_SpeciesK_MaxList;
}


void Parameters::setSpeciesK_MaxList(QList<double> list) {
    m_SpeciesK_MaxList = list;
}


void Parameters::printSpeciesK_MaxList() {
    double value;
//     qDebug() << "Species K (Max): ";
    foreach (value, m_SpeciesK_MaxList) {
//         qDebug() << value;
    }
}


QList<double> Parameters::getSurveyQList() {
    return m_SurveyQList;
}


void Parameters::setSurveyQList(QList<double> list) {
    m_SurveyQList = list;
}


double Parameters::getSurveyQ(const int speciesIndex) {

    double surveyQ = m_SurveyQList.at(speciesIndex);
    return surveyQ;
}


QList<double> Parameters::getSurveyQ_MinList() {
    return m_SurveyQ_MinList;
}


void Parameters::setSurveyQ_MinList(QList<double> list) {
    m_SurveyQ_MinList = list;
}


QList<double> Parameters::getSurveyQ_MaxList() {
    return m_SurveyQ_MaxList;
}


void Parameters::setSurveyQ_MaxList(QList<double> list) {
    m_SurveyQ_MaxList = list;
}


QList<double> Parameters::getChromosomeList() {

    initializeChromosomeLists();

    QList<double> chromosomeList = m_ChromosomeList;
    return chromosomeList;
}


double Parameters::getChromosomeMin(int i) {

    double min = m_ChromosomeMinList.at(i);
    return min;
}


double Parameters::getChromosomeMax(int i) {

    double max = m_ChromosomeMaxList.at(i);
    return max;
}


void Parameters::initializeChromosomeLists() {

    initializeChromosomeList();
    initializeChromosomeMinList();
    initializeChromosomeMaxList();
}


void Parameters::initializeChromosomeLists(QString mode) {

    initializeChromosomeList(mode);
    initializeChromosomeMinList(mode);
    initializeChromosomeMaxList(mode);
}


void Parameters::initializeChromosomeList() {

    QList<double> chromosomeList = getInitialBiomassList();

    QList<double> growthRateList = getGrowthRateList();
//    QList<double> chromosomeList = getGrowthRateList();

    double value;
    int growthRateListSize = growthRateList.size();

    if (growthRateListSize > 0) {
        for (int i = 0; i < growthRateListSize; i++) {
            value = growthRateList.at(i);
            chromosomeList.append(value);
        }
    }

    QList<double> speciesK_List = getSpeciesKList();

    int speciesK_ListSize = speciesK_List.size();

    if (speciesK_ListSize > 0) {
        for (int i = 0; i < speciesK_ListSize; i++) {
            value = speciesK_List.at(i);
            chromosomeList.append(value);
        }
    }

    QList<double> surveyQ_List = getSurveyQList();

    int surveyQ_ListSize = surveyQ_List.size();
    if (surveyQ_ListSize > 0) {
        for (int i = 0; i < surveyQ_ListSize; i++) {
            value = surveyQ_List.at(i);
            chromosomeList.append(value);
        }
    }


    int x, y = 0;
    Int_Matrix withinGuildCompetitionList = getWithinGuildCompMatrix();
    x = withinGuildCompetitionList.size();
    if (x > 0) {
        y = withinGuildCompetitionList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = withinGuildCompetitionList.at(i).at(j);
                chromosomeList.append(value);
            }
        }
    }

    Int_Matrix betweenGuildCompetitionList = getBetweenGuildCompMatrix();
    x = betweenGuildCompetitionList.size();
    if (x > 0) {
        y = betweenGuildCompetitionList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = betweenGuildCompetitionList.at(i).at(j);
                chromosomeList.append(value);
            }
        }
    }

    Int_Matrix predationLossesList = getPredationMatrix();
    x = predationLossesList.size();
    if (x > 0) {
        y = predationLossesList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = predationLossesList.at(i).at(j);
                chromosomeList.append(value);
            }
        }
    }
    m_ChromosomeList = chromosomeList;

}


void Parameters::initializeChromosomeMinList() {

    QList<double> chromosomeMinList = getInitialBiomassMinList();

    QList<double> growthRateMinList = getGrowthRateMinList();
//    QList<double> chromosomeMinList = getGrowthRateMinList();
    double value;
    int growthRateMinListSize = growthRateMinList.size();

    if (growthRateMinListSize > 0) {
        for (int i = 0; i < growthRateMinListSize; i++) {
            value = growthRateMinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    QList<double> speciesK_MinList = getSpeciesK_MinList();
    int speciesK_MinListSize = speciesK_MinList.size();
    if (speciesK_MinListSize > 0) {
        for (int i = 0; i < speciesK_MinListSize; i++) {
           value = speciesK_MinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    QList<double> surveyQ_MinList = getSurveyQ_MinList();

    int surveyQ_MinListSize = surveyQ_MinList.size();
    if (surveyQ_MinListSize > 0) {
        for (int i = 0; i < surveyQ_MinListSize; i++) {
            value = surveyQ_MinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    int x, y = 0;

    Int_Matrix withinGuildCompetitionMinList = getWithinGuildCompMinMatrix();
    x = withinGuildCompetitionMinList.size();

    if (x > 0) {
        y = withinGuildCompetitionMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = withinGuildCompetitionMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    Int_Matrix betweenGuildCompetitionMinList = getBetweenGuildCompMinMatrix();
    x = betweenGuildCompetitionMinList.size();

    if (x > 0) {
        y = betweenGuildCompetitionMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = betweenGuildCompetitionMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    Int_Matrix predationLossRatesMinList = getPredationLossRatesMinMatrix();
    x = predationLossRatesMinList.size();

    if (x > 0) {
        y = predationLossRatesMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = predationLossRatesMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    m_ChromosomeMinList = chromosomeMinList;
}


void Parameters::initializeChromosomeMaxList() {

    QList<double> chromosomeMaxList = getInitialBiomassMaxList();

    QList<double> growthRateMaxList = getGrowthRateMaxList();
//    QList<double> chromosomeMaxList = getGrowthRateMaxList();

    double value;
    int growthRateMaxListSize = growthRateMaxList.size();

    if (growthRateMaxListSize > 0) {
        for (int i = 0; i < growthRateMaxListSize; i++) {
            value = growthRateMaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    QList<double> speciesK_MaxList = getSpeciesK_MaxList();
    int speciesK_MaxListSize = speciesK_MaxList.size();

    if (speciesK_MaxListSize > 0) {
        for (int i = 0; i < speciesK_MaxListSize; i++) {
            value = speciesK_MaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    QList<double> surveyQ_MaxList = getSurveyQ_MaxList();

    int surveyQ_MaxListSize = surveyQ_MaxList.size();
    if (surveyQ_MaxListSize > 0) {
        for (int i = 0; i < surveyQ_MaxListSize; i++) {
            value = surveyQ_MaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    int x, y = 0;

    Int_Matrix withinGuildCompetitionMaxList = getWithinGuildCompMaxMatrix();
    x = withinGuildCompetitionMaxList.size();

    if (x > 0) {
        y = withinGuildCompetitionMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = withinGuildCompetitionMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    Int_Matrix betweenGuildCompetitionMaxList = getBetweenGuildCompMaxMatrix();
    x = betweenGuildCompetitionMaxList.size();

    if (x > 0) {
        y = betweenGuildCompetitionMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = betweenGuildCompetitionMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    Int_Matrix predationLossRatesMaxList = getPredationLossRatesMaxMatrix();
    x = predationLossRatesMaxList.size();

    if (x > 0) {
        y = predationLossRatesMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = predationLossRatesMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    m_ChromosomeMaxList = chromosomeMaxList;
}



void Parameters::initializeChromosomeList(QString mode) {

    QList<double> chromosomeList = getInitialBiomassList();

    QList<double> growthRateList = getGrowthRateList();
//    QList<double> chromosomeList = getGrowthRateList();

    double value;
    int growthRateListSize = growthRateList.size();

    if (growthRateListSize > 0) {
        for (int i = 0; i < growthRateListSize; i++) {
            value = growthRateList.at(i);
            chromosomeList.append(value);
        }
    }

    QList<double> speciesK_List = getSpeciesKList();

    int speciesK_ListSize = speciesK_List.size();

    if (speciesK_ListSize > 0) {
        for (int i = 0; i < speciesK_ListSize; i++) {
            value = speciesK_List.at(i);
            chromosomeList.append(value);
        }
    }

    QList<double> surveyQ_List = getSurveyQList();

    int surveyQ_ListSize = surveyQ_List.size();
    if (surveyQ_ListSize > 0) {
        for (int i = 0; i < surveyQ_ListSize; i++) {
            value = surveyQ_List.at(i);
            chromosomeList.append(value);
        }
    }


    Int_Matrix withinGuildCompetitionList = getWithinGuildCompMatrix();
    int x, y = 0;
    x = withinGuildCompetitionList.size();
    if (mode == "Single Species") {
        if (x > 0) {
            y = withinGuildCompetitionList.at(0).size();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    if (i == j) {
                        value = withinGuildCompetitionList.at(i).at(j);
                    } else {
                        value = 0;
                    }
                    chromosomeList.append(value);
                }
            }
        }
    } else {
        if (x > 0) {
            y = withinGuildCompetitionList.at(0).size();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    value = withinGuildCompetitionList.at(i).at(j);
                    chromosomeList.append(value);
                }
            }
        }
    }


    if (mode != "Single Species") {
        Int_Matrix betweenGuildCompetitionList = getBetweenGuildCompMatrix();
        x = betweenGuildCompetitionList.size();
        if (x > 0) {
            y = betweenGuildCompetitionList.at(0).size();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    value = betweenGuildCompetitionList.at(i).at(j);
                    chromosomeList.append(value);
                }
            }
        }
    }

    if (mode != "Single Species") {
        Int_Matrix predationLossesList = getPredationMatrix();
        x = predationLossesList.size();
        if (x > 0) {
            y = predationLossesList.at(0).size();
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    value = predationLossesList.at(i).at(j);
                    chromosomeList.append(value);
                }
            }
        }
    }
    m_ChromosomeList = chromosomeList;
}


void Parameters::initializeChromosomeMinList(QString mode) {

    QList<double> chromosomeMinList = getInitialBiomassMinList();

    QList<double> growthRateMinList = getGrowthRateMinList();
//    QList<double> chromosomeMinList = getGrowthRateMinList();
    double value;
    int growthRateMinListSize = growthRateMinList.size();

    if (growthRateMinListSize > 0) {
        for (int i = 0; i < growthRateMinListSize; i++) {
            value = growthRateMinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    QList<double> speciesK_MinList = getSpeciesK_MinList();
    int speciesK_MinListSize = speciesK_MinList.size();
    if (speciesK_MinListSize > 0) {
        for (int i = 0; i < speciesK_MinListSize; i++) {
           value = speciesK_MinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    QList<double> surveyQ_MinList = getSurveyQ_MinList();

    int surveyQ_MinListSize = surveyQ_MinList.size();
    if (surveyQ_MinListSize > 0) {
        for (int i = 0; i < surveyQ_MinListSize; i++) {
            value = surveyQ_MinList.at(i);
            chromosomeMinList.append(value);
        }
    }

    int x, y = 0;

    Int_Matrix withinGuildCompetitionMinList = getWithinGuildCompMinMatrix();
    x = withinGuildCompetitionMinList.size();

    if (x > 0) {
        y = withinGuildCompetitionMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = withinGuildCompetitionMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    Int_Matrix betweenGuildCompetitionMinList = getBetweenGuildCompMinMatrix();
    x = betweenGuildCompetitionMinList.size();

    if (x > 0) {
        y = betweenGuildCompetitionMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = betweenGuildCompetitionMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    Int_Matrix predationLossRatesMinList = getPredationLossRatesMinMatrix();
    x = predationLossRatesMinList.size();

    if (x > 0) {
        y = predationLossRatesMinList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = predationLossRatesMinList.at(i).at(j);
                chromosomeMinList.append(value);
            }
        }
    }

    m_ChromosomeMinList = chromosomeMinList;
}


void Parameters::initializeChromosomeMaxList(QString mode) {

    QList<double> chromosomeMaxList = getInitialBiomassMaxList();

    QList<double> growthRateMaxList = getGrowthRateMaxList();
//    QList<double> chromosomeMaxList = getGrowthRateMaxList();

    double value;
    int growthRateMaxListSize = growthRateMaxList.size();

    if (growthRateMaxListSize > 0) {
        for (int i = 0; i < growthRateMaxListSize; i++) {
            value = growthRateMaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    QList<double> speciesK_MaxList = getSpeciesK_MaxList();
    int speciesK_MaxListSize = speciesK_MaxList.size();

    if (speciesK_MaxListSize > 0) {
        for (int i = 0; i < speciesK_MaxListSize; i++) {
            value = speciesK_MaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    QList<double> surveyQ_MaxList = getSurveyQ_MaxList();

    int surveyQ_MaxListSize = surveyQ_MaxList.size();
    if (surveyQ_MaxListSize > 0) {
        for (int i = 0; i < surveyQ_MaxListSize; i++) {
            value = surveyQ_MaxList.at(i);
            chromosomeMaxList.append(value);
        }
    }

    int x, y = 0;

    Int_Matrix withinGuildCompetitionMaxList = getWithinGuildCompMaxMatrix();
    x = withinGuildCompetitionMaxList.size();

    if (x > 0) {
        y = withinGuildCompetitionMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = withinGuildCompetitionMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    Int_Matrix betweenGuildCompetitionMaxList = getBetweenGuildCompMaxMatrix();
    x = betweenGuildCompetitionMaxList.size();

    if (x > 0) {
        y = betweenGuildCompetitionMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = betweenGuildCompetitionMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    Int_Matrix predationLossRatesMaxList = getPredationLossRatesMaxMatrix();
    x = predationLossRatesMaxList.size();

    if (x > 0) {
        y = predationLossRatesMaxList.at(0).size();
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = predationLossRatesMaxList.at(i).at(j);
                chromosomeMaxList.append(value);
            }
        }
    }

    m_ChromosomeMaxList = chromosomeMaxList;
}


void Parameters::setChromosomeList(QList<double> chromosomeList) {

    int index = 0;
    int initialBiomassListSize = m_InitialBiomassList.size();
    m_InitialBiomassList.clear();
    double paramValue;
    for (int i = index; i < initialBiomassListSize; i++) {
        paramValue = chromosomeList.at(index);
        m_InitialBiomassList.append(paramValue);
        index++;
    }
    clearBiomassMatrix();

    int growthRateListSize = m_GrowthRateList.size();
    m_GrowthRateList.clear();
    m_GrowthRateOriginalList.clear();
    for (int i = 0; i < growthRateListSize; i++) {
        paramValue = chromosomeList.at(index);
        m_GrowthRateList.append(paramValue);
        m_GrowthRateOriginalList.append(paramValue);
        index++;
    }

    int speciesK_ListSize = m_SpeciesKList.size();

    if (speciesK_ListSize > 0) {
        m_SpeciesKList.clear();
        for (int i = 0; i < speciesK_ListSize; i++) {
            paramValue = chromosomeList.at(index);
            m_SpeciesKList.append(paramValue);
            index++;
        }
    }

    int surveyQ_ListSize = m_SurveyQList.size();

    if (surveyQ_ListSize > 0) {
        m_SurveyQList.clear();
        for (int i = 0; i < surveyQ_ListSize; i++) {
            paramValue = chromosomeList.at(index);
            m_SurveyQList.append(paramValue);
            index++;
        }
    }

    int x, y = 0;

    Int_Matrix withinGuildCompetitionMatrix = getWithinGuildCompMatrix();
    x = withinGuildCompetitionMatrix.size();

    if (x > 0) {
        y = withinGuildCompetitionMatrix.at(0).size();

        m_WithinGuildCompMatrix.clearMatrix();
        Int_Matrix *wgcParamMatrix = new Int_Matrix;

        for (int i = 0; i < x; i++) {
            QList<double> *newList = new QList<double>;
            for (int j = 0; j < y; j++) {
//              qDebug() << "i = " << i << " : j = " << j;
                paramValue = chromosomeList.at(index);
//              qDebug() << paramValue;
                newList->append(paramValue);
                index++;
            }
            wgcParamMatrix->append(*newList);
            delete newList;
            // XXX
        }
        setWithinGuildCompMatrix(*wgcParamMatrix);
        delete wgcParamMatrix;
    }
    Int_Matrix betweenGuildCompetitionMatrix = getBetweenGuildCompMatrix();
    x = betweenGuildCompetitionMatrix.size();

    if (x > 0) {
        y = betweenGuildCompetitionMatrix.at(0).size();

        m_BetweenGuildCompMatrix.clearMatrix();
        Int_Matrix *bgcParamMatrix = new Int_Matrix;

        for (int i = 0; i < x; i++) {
            QList<double> *newList = new QList<double>;
            for (int j = 0; j < y; j++) {
//              qDebug() << "i = " << i << " : j = " << j;
                paramValue = chromosomeList.at(index);
//              qDebug() << paramValue;
                newList->append(paramValue);
                index++;
            }
            bgcParamMatrix->append(*newList);
            delete newList;
            // XXX
        }
        setBetweenGuildCompMatrix(*bgcParamMatrix);
        delete bgcParamMatrix;
    }

    Int_Matrix predationMatrix = getPredationMatrix();
    x = predationMatrix.size();

    if (x > 0) {
        y = predationMatrix.at(0).size();

        m_PredationLossesMatrix.clearMatrix();
        Int_Matrix *predParamMatrix = new Int_Matrix;

        for (int i = 0; i < x; i++) {
            QList<double> *newList = new QList<double>;
            for (int j = 0; j < y; j++) {
//                qDebug() << "i = " << i << " : j = " << j;
                paramValue = chromosomeList.at(index);
//              qDebug() << paramValue;
                newList->append(paramValue);
                index++;
            }
            predParamMatrix->append(*newList);
            delete newList;
            // XXX
        }
        setPredationMatrix(*predParamMatrix);
        delete predParamMatrix;
    }

}


void Parameters::setMinMaxValuesAfterReset(double value, double scalar, QList<double> minList, QList<double> maxList) {

    double minValue = value * scalar;
    double maxValue = value / scalar;
    minList.append(minValue);
    maxList.append(maxValue);
}


void Parameters::resetChromosomeAfterSS() {

    int numSpecies = getNumberOfSpecies();

    // Set Biomass min and max
    QList<double> chromosomeMinList;
    QList<double> chromosomeMaxList;
    double value = 0.0;
    double scalar = 1.0;
    double minValue = 0.0;
    double maxValue = 0.0;

    m_InitialBiomassMinList.clear();
    m_InitialBiomassMaxList.clear();
    for (int i = 0; i < numSpecies; i++) {
        value = getBiomass(i,0);
//        value = 0.0;
        if (m_WithinGuildCompMaxMatrix.getOffAxisMatrixRowValue(i) == 0) {
            minValue = value * 1.0;
            maxValue = value * 1.0;
        } else {
            minValue = value * 0.75;
            maxValue = value * 1.25;
//            setMinMaxValuesAfterReset(value, 2.0, chromosomeMinList, chromosomeMaxList);
        }
        chromosomeMinList.append(minValue);
        chromosomeMaxList.append(maxValue);
        m_InitialBiomassMinList.append(minValue);
        m_InitialBiomassMaxList.append(maxValue);
    }

    // Set min and max growth rates
    m_GrowthRateMinList.clear();
    m_GrowthRateMaxList.clear();
    for (int i = 0; i < numSpecies; i++) {
        value = getGrowthRate(i);
        if (m_WithinGuildCompMaxMatrix.getOffAxisMatrixRowValue(i) == 0) {
            minValue = value * 1;
            maxValue = value * 1;
        } else {
            minValue = value * 0.2;
            maxValue = value * 5.0;
//            setMinMaxValuesAfterReset(value, 2.0, chromosomeMinList, chromosomeMaxList);
        }
        chromosomeMinList.append(minValue);
        chromosomeMaxList.append(maxValue);
        m_GrowthRateMinList.append(minValue);
        m_GrowthRateMaxList.append(maxValue);
    }

    // Set min amd max species K's
    int speciesK_ListSize = m_SpeciesKList.size();

    if (speciesK_ListSize > 0) {
        for (int i = 0; i < speciesK_ListSize; i++) {
            value = getSpeciesK(i);
            if (m_WithinGuildCompMaxMatrix.getOffAxisMatrixRowValue(i) == 0) {
                chromosomeMinList.append(value);
                chromosomeMaxList.append(value);
            } else {
                scalar = 2.0;
                minValue = value / scalar;
                maxValue = value * scalar;
                chromosomeMinList.append(minValue);
                chromosomeMaxList.append(maxValue);
            }
        }
    }

    // Set min and max survey Q's
    m_SurveyQ_MinList.clear();
    m_SurveyQ_MaxList.clear();

    for (int i = 0; i < numSpecies; i++) {
        value = getSurveyQ(i);
        if (m_WithinGuildCompMaxMatrix.getOffAxisMatrixRowValue(i) == 0) {
            minValue = value * 1;
            maxValue = value * 1;
        } else {
            minValue = value * 0.5;
            maxValue = value * 2;
//            setMinMaxValuesAfterReset(value, 2.0, chromosomeMinList, chromosomeMaxList);
        }
        chromosomeMinList.append(minValue);
        chromosomeMaxList.append(maxValue);
        m_SurveyQ_MinList.append(minValue);
        m_SurveyQ_MaxList.append(maxValue);
    }


    int x, y = 0;

    Int_Matrix withinGuildCompetitionMinMatrix = getWithinGuildCompMinMatrix();
    Int_Matrix withinGuildCompetitionMaxMatrix = getWithinGuildCompMaxMatrix();
    x = withinGuildCompetitionMinMatrix.size();
    y = withinGuildCompetitionMinMatrix.at(0).size();

//    m_WithinGuildCompMinMatrix.clearMatrix();
//    m_WithinGuildCompMaxMatrix.clearMatrix();

    if (x > 0) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                value = getWithinGuildCompParam(i,j);
                if (i != j) {
                    minValue = withinGuildCompetitionMinMatrix.at(i).at(j);
                    maxValue = withinGuildCompetitionMaxMatrix.at(i).at(j);
                    if ((minValue != 0) && (maxValue != 0)) {
                      double Bi = getBiomass(i,0);
                      double Bj = getBiomass(j,0);
                      double Ci = getCatch(i,0);

                      minValue = (0.1 * Ci) / (Bi * Bj);
                      maxValue = (10 * Ci) / (Bi * Bj);
                    }

                } else {
                    if (m_WithinGuildCompMaxMatrix.getOffAxisMatrixRowValue(i) == 0) {
                        minValue = value * 1;
                        maxValue = value * 1;
                    } else {
                        minValue = value * 0.01;
                        maxValue = value * 100;
                    }
                }
                if ((i == 4) && (j == 0)) {
                    qDebug() << "Max Value: " << maxValue;
                }
                chromosomeMinList.append(minValue);
                chromosomeMaxList.append(maxValue);
                m_WithinGuildCompMinMatrix.setMatrixValue(i,j,minValue);
                m_WithinGuildCompMaxMatrix.setMatrixValue(i,j,maxValue);
            }
        }
    }

//    x = withinGuildCompetitionMaxList.size();

//    if (x > 0) {
//         y = withinGuildCompetitionMaxList.at(0).size();
//         for (int i = 0; i < x; i++) {
//              for (int j = 0; j < y; j++) {
//                   value = withinGuildCompetitionMaxList.at(i).at(j);
//                   chromosomeMaxList.append(value);
//              }
//         }
//    }

    Int_Matrix betweenGuildCompetitionMinList = getBetweenGuildCompMinMatrix();
    x = betweenGuildCompetitionMinList.size();

    if (x > 0) {
         y = betweenGuildCompetitionMinList.at(0).size();
         for (int i = 0; i < x; i++) {
              for (int j = 0; j < y; j++) {
                   value = betweenGuildCompetitionMinList.at(i).at(j);
                   chromosomeMinList.append(value);
              }
         }
    }

    Int_Matrix betweenGuildCompetitionMaxList = getBetweenGuildCompMaxMatrix();
    x = betweenGuildCompetitionMaxList.size();

    if (x > 0) {
         y = betweenGuildCompetitionMaxList.at(0).size();
         for (int i = 0; i < x; i++) {
              for (int j = 0; j < y; j++) {
                   value = betweenGuildCompetitionMaxList.at(i).at(j);
                   chromosomeMaxList.append(value);
              }
         }
    }

/*            Int_Matrix predationLossRatesMaxList = getPredationLossRatesMaxMatrix();
            x = predationLossRatesMaxList.size();

            if (x > 0) {
                y = predationLossRatesMaxList.at(0).size();
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < y; j++) {
                        value = predationLossRatesMaxList.at(i).at(j);
                        chromosomeMaxList.append(value);
                    }
                }
            }
        */
    m_ChromosomeMinList = chromosomeMinList;
    m_ChromosomeMaxList = chromosomeMaxList;
}


void Parameters::zeroInteractionCoefficients() {

    int numSpecies = getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSpecies; j++) {
            if (i != j) {
 //               qDebug() << "Setting to 0";
                setWithinGuildCompParam(i,j,0);
 //               double value = getBetweenGuildCompParam(i,j);
 //               qDebug() << "New Value: " << value;
            }
        }
    }
}

int Parameters::getChromosomeListSize() {

    return m_ChromosomeList.size();
}


void Parameters::setGuildList(QStringList list) {

    m_GuildList = list;

    // Initialize guild biomasses to 0.0
    int Bg = 0.0;
    QString guildName = "";
    int numberOfGuilds = getNumberOfGuilds();

    for (int g = 0; g < numberOfGuilds; g++) {
        guildName = m_GuildList.at(g);
        m_GuildBiomassHash.insert(guildName, Bg);
    }
}


double Parameters::getGuildBiomass(QString guildName) {

    return m_GuildBiomassHash.value(guildName);
}


QStringList Parameters::getGuildList() {
    return m_GuildList;
}


void Parameters::printGuildList() {

//     qDebug() << m_GuildList;
}


QString Parameters::getGuildName(int g) {

    return m_GuildList.at(g);
}


int Parameters::getNumberOfGuilds() {

    return m_GuildList.size();
}


QHash<QString, QString> Parameters::getSpeciesGuildMembershipHash() {
    return m_SpeciesGuildMembershipHash;
}


void Parameters::setSpeciesGuildMembershipHash(QStringList guildList) {

    int numSpecies = m_SpeciesList.size();
    for (int i = 0; i < numSpecies; i++) {
        m_SpeciesGuildMembershipHash.insert(m_SpeciesList.at(i), guildList.at(i));
    }
}


QString Parameters::getGuildMembership(QString speciesName) {

    return m_SpeciesGuildMembershipHash.value(speciesName);
}


void Parameters::printSpeciesGuildMembershipHash() {

//    QList<QString> speciesList = m_SpeciesGuildMembershipHash.uniqueKeys();
    int numSpecies = m_SpeciesList.size();
    QString speciesName = "";
    for (int i = 0; i < numSpecies; i++) {
        speciesName = m_SpeciesList.at(i);
        // qDebug() << speciesName << " : " << m_SpeciesGuildMembershipHash.value(speciesName);
    }
}


void Parameters::setSaveFilename(QString filename) {

    m_OutputFilename = filename;
}


QList<QList<double> > Parameters::getBiomassMatrix() {
    return m_BiomassMatrix.getMatrix();
}


void Parameters::setBiomassMatrix(QList<QList<double> > matrix) {
    m_BiomassMatrix.setMatrix(matrix);
}


void Parameters::clearBiomassMatrix() {
    QList<QList<double> > *biomassMatrix = new QList<QList<double> >;
    int speciesIndex;
    double value;
    foreach (value, m_InitialBiomassList) {
        QList<double> *newList = new QList<double>;
        newList->append(value);
        biomassMatrix->append(*newList);
        speciesIndex++;
        delete newList;
    }
    setBiomassMatrix(*biomassMatrix);
// XXX
    delete biomassMatrix;
}


void Parameters::clearOutputCatchMatrix() {
    QList<QList<double> > *outputCatchMatrix = new QList<QList<double> >;
    int speciesIndex;
    double value;
    foreach (value, m_InitialBiomassList) {
        QList<double> *newList = new QList<double>;
        outputCatchMatrix->append(*newList);
        speciesIndex++;
        delete newList;
    }
    setOutputCatchMatrix(*outputCatchMatrix);
    delete outputCatchMatrix;
}


void Parameters::setOutputCatchMatrix(QList<QList<double> > matrix) {
    m_OutputCatchMatrix.setMatrix(matrix);
}



void Parameters::printBiomassMatrix() {

    m_BiomassMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getBiomass(const int speciesIndex, const int time) {

//    qDebug() << "Number of species: " << getNumberOfSpecies();
    return m_BiomassMatrix.getMatrixValue(speciesIndex, time);
}


double Parameters::getBiomass(const QString speciesName, const int time) {

    int speciesListSize = m_SpeciesList.size();
    for (int i = 0; i < speciesListSize; i++) {
        QString nameFromSpeciesList = getSpeciesName(i);
        if (speciesName == nameFromSpeciesList) {
//            qDebug() << "Species Name: " << speciesName << " ; Index: " << i;
            return m_BiomassMatrix.getMatrixValue(i,time);
        }
    }
}



void Parameters::updateBiomass(int speciesIndex, int timeStep, double dN) {

    double prevBiomass = m_BiomassMatrix.getMatrixValue(speciesIndex, timeStep);
    double newBiomass = prevBiomass + dN;
    if (newBiomass < 0) {
        newBiomass = 0;
    }
    m_BiomassMatrix.addMatrixValue(speciesIndex, newBiomass);
}


void Parameters::updateOutputCatch(int speciesIndex, double catches) {

    m_OutputCatchMatrix.addMatrixValue(speciesIndex, catches);
}


QList<QList<double> > Parameters::getWithinGuildCompMatrix() {
    return m_WithinGuildCompMatrix.getMatrix();
}


void Parameters::setWithinGuildCompMatrix(QList<QList<double> > matrix) {
    m_WithinGuildCompMatrix.setMatrix(matrix);
}


void Parameters::printWithinGuildCompMatrix() {

    m_WithinGuildCompMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getWithinGuildCompParam(int i, int j) {

    return m_WithinGuildCompMatrix.getMatrixValue(i,j);
}


QList<QList<double> > Parameters::getWithinGuildCompMinMatrix() {
    return m_WithinGuildCompMinMatrix.getMatrix();
}


void Parameters::setWithinGuildCompMinMatrix(QList<QList<double> > matrix) {
    m_WithinGuildCompMinMatrix.setMatrix(matrix);
}


void Parameters::printWithinGuildCompMinMatrix() {

    m_WithinGuildCompMinMatrix.printMatrix(m_SpeciesList);

}


QList<QList<double> > Parameters::getWithinGuildCompMaxMatrix() {
    return m_WithinGuildCompMaxMatrix.getMatrix();
}


void Parameters::setWithinGuildCompMaxMatrix(QList<QList<double> > matrix) {
    m_WithinGuildCompMaxMatrix.setMatrix(matrix);
}


void Parameters::printWithinGuildCompMaxMatrix() {

    m_WithinGuildCompMaxMatrix.printMatrix(m_SpeciesList);

}


QList<QList<double> > Parameters::getBetweenGuildCompMinMatrix() {
    return m_BetweenGuildCompMinMatrix.getMatrix();
}


void Parameters::setBetweenGuildCompMinMatrix(QList<QList<double> > matrix) {
    m_BetweenGuildCompMinMatrix.setMatrix(matrix);
}


void Parameters::printBetweenGuildCompMinMatrix() {

    m_BetweenGuildCompMinMatrix.printMatrix(m_SpeciesList);

}


QList<QList<double> > Parameters::getBetweenGuildCompMaxMatrix() {
    return m_BetweenGuildCompMaxMatrix.getMatrix();
}


void Parameters::setBetweenGuildCompMaxMatrix(QList<QList<double> > matrix) {
    m_BetweenGuildCompMaxMatrix.setMatrix(matrix);
}


void Parameters::printBetweenGuildCompMaxMatrix() {

    m_BetweenGuildCompMaxMatrix.printMatrix(m_SpeciesList);

}

QList<QList<double> > Parameters::getPredationLossRatesMinMatrix() {
    return m_PredationLossRatesMinMatrix.getMatrix();
}


void Parameters::setPredationLossRatesMinMatrix(QList<QList<double> > matrix) {
    m_PredationLossRatesMinMatrix.setMatrix(matrix);
}


void Parameters::printPredationLossRatesMinMatrix() {

    m_PredationLossRatesMinMatrix.printMatrix(m_SpeciesList);
}


QList<QList<double> > Parameters::getPredationLossRatesMaxMatrix() {
    return m_PredationLossRatesMaxMatrix.getMatrix();
}


void Parameters::setPredationLossRatesMaxMatrix(QList<QList<double> > matrix) {
    m_PredationLossRatesMaxMatrix.setMatrix(matrix);
}


void Parameters::printPredationLossRatesMaxMatrix() {

    m_PredationLossRatesMaxMatrix.printMatrix(m_SpeciesList);
}


QList<QList<double> > Parameters::getBetweenGuildCompMatrix() {
    return m_BetweenGuildCompMatrix.getMatrix();
}


void Parameters::setBetweenGuildCompMatrix(QList<QList<double> > matrix) {
    m_BetweenGuildCompMatrix.setMatrix(matrix);
}


void Parameters::printBetweenGuildCompMatrix() {

    m_BetweenGuildCompMatrix.printMatrix(m_GuildList);

}


double Parameters::getBetweenGuildCompParam(int i, int j) {

    return m_BetweenGuildCompMatrix.getMatrixValue(i,j);
}


void Parameters::setWithinGuildCompParam(int i, int j, double value) {

//    qDebug() << "Setting matrix value: " << value;
    m_WithinGuildCompMatrix.setMatrixValue(i, j, value);
}


QList<QList<double> > Parameters::getPredationMatrix() {
    return m_PredationMatrix.getMatrix();
}


void Parameters::setPredationMatrix(QList<QList<double> > matrix) {
    m_PredationMatrix.setMatrix(matrix);
}


void Parameters::printPredationMatrix() {

    m_PredationMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getAvailability(int i, int j) {

    return m_PredationMatrix.getMatrixValue(i,j);
}


QList<QList<double> > Parameters::getHandlingTimeMatrix() {
    return m_HandlingTimeMatrix.getMatrix();
}


void Parameters::setHandlingTimeMatrix(QList<QList<double> > matrix) {
    m_HandlingTimeMatrix.setMatrix(matrix);
}


void Parameters::printHandlingTimeMatrix() {

    m_HandlingTimeMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getHandlingTime(int i, int j) {

    return m_HandlingTimeMatrix.getMatrixValue(i,j);
}


QList<QList<double> > Parameters::getbCoefMatrix() {
    return m_bCoefMatrix.getMatrix();
}


void Parameters::setbCoefMatrix(QList<QList<double> > matrix) {
    m_bCoefMatrix.setMatrix(matrix);
}


void Parameters::printbCoefMatrix() {

    m_bCoefMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getbCoef(int i, int j) {

    return m_bCoefMatrix.getMatrixValue(i,j);
}


QList<QList<double> > Parameters::getSpatialOverlapMatrix() {
    return m_SpatialOverlapMatrix.getMatrix();
}


void Parameters::setSpatialOverlapMatrix(QList<QList<double> > matrix) {
    m_SpatialOverlapMatrix.setMatrix(matrix);
}


void Parameters::printSpatialOverlapMatrix() {


    m_SpatialOverlapMatrix.printMatrix(m_SpeciesList);

}


double Parameters::getSpatialOverlap(int i, int j) {

    return m_SpatialOverlapMatrix.getMatrixValue(i,j);
}


void Parameters::setGrowthRates(QList<double> list) {

    m_GrowthRateList = list;
}


double Parameters::getGrowthRate(const int speciesIndex) {

    return m_GrowthRateList.at(speciesIndex);
}


QList<double> Parameters::getGrowthRateList() {

    return m_GrowthRateList;
}


void Parameters::setOriginalGrowthRates(QList<double> list) {

    m_GrowthRateOriginalList = list;
}


QList<double> Parameters::getOriginalGrowthRateList() {

    return m_GrowthRateOriginalList;
}


double Parameters::getOriginalGrowthRate(const int speciesIndex) {

    return m_GrowthRateOriginalList.at(speciesIndex);
}


void Parameters::setGrowthRateCovariateList(QList<double> list) {

    m_GrowthRateCovariatesList = list;
}


double Parameters::getGrowthRateCovariate(const int speciesIndex) {

    return m_GrowthRateCovariatesList.at(speciesIndex);
}


QList<double> Parameters::getGrowthRateCovariateList() {

    return m_GrowthRateCovariatesList;
}


void Parameters::setGrowthRatesMin(QList<double> list) {

    m_GrowthRateMinList = list;
}


QList<double> Parameters::getGrowthRateMinList() {

    return m_GrowthRateMinList;
}


void Parameters::setGrowthRatesMax(QList<double> list) {

    m_GrowthRateMaxList = list;
}


QList<double> Parameters::getGrowthRateMaxList() {

    return m_GrowthRateMaxList;
}


void Parameters::setHarvestRateList(QList<double> list) {

    m_HarvestRateList = list;
}


QList<double> Parameters::getHarvestRateList() {
    return m_HarvestRateList;
}


void Parameters::printHarvestRateList() {

    int x = m_HarvestRateList.size();
    // qDebug() << "Harvest Rates:";
    for (int i = 0; i < x; i++){
        // qDebug() << m_HarvestRateList.at(i);
    }
}


double Parameters::getHarvestRate(const int speciesIndex) {

    double harvestRate = m_HarvestRateList.at(speciesIndex);
    return harvestRate;
}


void Parameters::setCatchabilitiesList(QList<double> list) {
    m_CatchabilitiesList = list;
}


QList<double> Parameters::getCatchabilitiesList() {
    return m_CatchabilitiesList;
}


void Parameters::printCatchabilitiesList() {

    int x = m_CatchabilitiesList.size();
    // qDebug() << "Catchabilities:";
    for (int i = 0; i < x; i++){
        // qDebug() << m_CatchabilitiesList.at(i);
    }
}


double Parameters::getCatchability(const int speciesIndex) {

    double q = m_CatchabilitiesList.at(speciesIndex);
    return q;
}


double Parameters::getCatchability(const int speciesIndex, const int time) {

    return m_CatchabilityMatrix.getMatrixValue(speciesIndex, time);
}


void Parameters::setCatchabilityMatrix(QList<QList<double> > matrix) {
    m_CatchabilityMatrix.setMatrix(matrix);
}


void Parameters::setEffortList(QList<double> list) {
    m_EffortList = list;
}


QList<double> Parameters::getEffortList() {
    return m_EffortList;
}


void Parameters::printEffortList() {

    int x = m_EffortList.size();
    // qDebug() << "Efforts:";
    for (int i = 0; i < x; i++){
        // qDebug() << m_EffortList.at(i);
    }
}


double Parameters::getEffort(const int speciesIndex) {

    double effort = m_EffortList.at(speciesIndex);
    return effort;
}


double Parameters::getEffort(const int speciesIndex, const int time) {

    return m_EffortMatrix.getMatrixValue(speciesIndex, time);
}


void Parameters::setEffortMatrix(QList<QList<double> > matrix) {
    m_EffortMatrix.setMatrix(matrix);
}


void Parameters::setEffort(int speciesIndex, int timeStep, double newEffort) {

    m_EffortMatrix.setMatrixValue(speciesIndex, timeStep, newEffort);
}



void Parameters::setCatchMatrix(QList<QList<double> > matrix) {
    m_CatchMatrix.setMatrix(matrix);
    m_CatchMatrix.getMatrixValue(2,3);
}


double Parameters::getCatch(const int speciesIndex, const int time) {

    return m_CatchMatrix.getMatrixValue(speciesIndex, time);
}


double Parameters::getOutputCatch(const int speciesIndex, const int time) {

    return m_OutputCatchMatrix.getMatrixValue(speciesIndex, time);
}


void Parameters::setCovariatesList(QList<double> list) {

    m_CovariateTimeSeriesList = list;
}


double Parameters::getCovariate(const int time) {

    return m_CovariateTimeSeriesList.at(time);
}


QList<double> Parameters::getCovariatesList() {

    return m_CovariateTimeSeriesList;
}


void Parameters::setInitialBiomassList(QList<double> list) {
    m_InitialBiomassList = list;

    QList<QList<double> > *biomassMatrix = new QList<QList<double> >;
    int speciesIndex;
    double value;
    foreach (value, m_InitialBiomassList) {
        QList<double> *newList = new QList<double>;
        newList->append(value);
        biomassMatrix->append(*newList);
        speciesIndex++;
        delete newList;
//  XXX
    }
    setBiomassMatrix(*biomassMatrix);
    delete biomassMatrix;
}


QList<double> Parameters::getInitialBiomassList() {
    return m_InitialBiomassList;
}


void Parameters::printInitialBiomassList() {
    double value;
    // qDebug() << "Initial Biomass: ";
    foreach (value, m_InitialBiomassList) {
        // qDebug() << value;
    }
}


void Parameters::setPelagicProportionList(QList<double> list) {
    m_PelagicProportionList = list;
}


QList<double> Parameters::getPelagicProportionList() {
    return m_PelagicProportionList;
}


void Parameters::printPelagicProportionList() {
    double value;
    // qDebug() << "Pelagic Proportion: ";
    foreach (value, m_PelagicProportionList) {
        // qDebug() << value;
    }
}


void Parameters::setDemersalProportionList(QList<double> list) {
    m_DemersalProportionList = list;
}


QList<double> Parameters::getDemersalProportionList() {
    return m_DemersalProportionList;
}


void Parameters::printDemersalProportionList() {
    double value;
    // qDebug() << "Demersal Proportion: ";
    foreach (value, m_DemersalProportionList) {
        // qDebug() << value;
    }
}


void Parameters::initializeListsAndTS(const int timestep) {

//    setGuildBiomass(timestep);
    clearBiomassMatrix();
    clearOutputCatchMatrix();
    m_GrowthRateList = m_GrowthRateOriginalList;

    // Creates lists for harvest, q's, and effort

    // Reads in TS for stochasticity, climate, fitting
}


void Parameters::setGuildBiomass(int timestep) {

    QString guildName = "";

    // Initialize guild biomasses to 0
    double Bg = 0.0;
    int numGuilds = getNumberOfGuilds();
    for (int g = 0; g < numGuilds; g++) {
        guildName = m_GuildList.at(g);
        m_GuildBiomassHash.insert(guildName, Bg);
//         qDebug() << guildName << " : " << m_GuildBiomassHash.value(guildName);
    }


    // For each species in species list
    QString speciesName = "";
    double Bi = 0.0;

    int numSpecies = getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        speciesName = getSpeciesName(i);
        // Get its biomass
        Bi = getBiomass(i, timestep);
        // Check guild membership of species
        guildName = getGuildMembership(speciesName);
//         qDebug() << speciesName << " : " << guildName << " : " << Bi;
        // Add biomass to the guild's running total
        Bg = m_GuildBiomassHash.value(guildName) + Bi;
        m_GuildBiomassHash.insert(guildName,Bg);
    }

    for (int g = 0; g < numGuilds; g++) {
        guildName = m_GuildList.at(g);
//         qDebug() << guildName << " : " << m_GuildBiomassHash.value(guildName);
    }


}


void Parameters::setStDevGrowth(double stDevGrowth) {

    m_stDevGrowth = stDevGrowth;
}


void Parameters::setStDevCatch(double stDevCatch) {

    m_stDevCatch = stDevCatch;
}


double Parameters::getStDevGrowth() {

    return m_stDevGrowth;
}

double Parameters::getStDevCatch() {

    return m_stDevCatch;
}


void Parameters::setStochasticGrowthList() {

    QList<double> newList;
    double stochasticValue;
    double stDev;
    foreach (double value, m_GrowthRateOriginalList) {
        stDev = value * m_stDevGrowth;
        stochasticValue = m_MTRand.randNorm(value,stDev);
        newList.append(stochasticValue);
    }
    setGrowthRates(newList);

}


double Parameters::calculatePredationToBiomassRatio(int preyIndex, int timeStep) {

    double preyBiomass = getBiomass(preyIndex, timeStep);
    double predatorBiomass = 0.0;
    double lossesToPredation = 0.0;

    for (int predatorIndex = 0; predatorIndex < m_numSpecies; predatorIndex++) {
        predatorBiomass = getBiomass(predatorIndex, timeStep);
        lossesToPredation += preyBiomass * predatorBiomass * getWithinGuildCompParam(preyIndex,predatorIndex);
    }
    double predationToBiomassRatio = lossesToPredation / preyBiomass;
    return predationToBiomassRatio;
}


int Parameters::get_GA_generations() {

    return m_GA_generations;
}


int Parameters::get_GA_populationSize() {

    return m_GA_populationSize;
}


double Parameters::get_GA_mutationRate() {

    return m_GA_mutationRate;
}


void Parameters::set_GA_generations(int generations) {

    m_GA_generations = generations;
}


void Parameters::set_GA_populationSize(int populationSize) {

    m_GA_populationSize = populationSize;
}


void Parameters::set_GA_mutationRate(double mutationRate) {

    m_GA_mutationRate = mutationRate;
}


int Parameters::get_GA_convergenceNumber() {

    return m_GA_convergenceNumber;
}


void Parameters::set_GA_convergenceNumber(int convergenceNumber) {

    m_GA_convergenceNumber = convergenceNumber;
}


void Parameters::outputResults(const QList<ModelComponent *> modelComponentList) {

    qDebug() << "Outputting Single Run";
    QString outfilename = m_OutputDirectory;
    qDebug() << outfilename;
    qDebug() << m_OutputFilename;
    outfilename.append(m_OutputFilename);
    QFile outFile(outfilename);
    qDebug() << outfilename;
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
         qDebug() << "Output file NOT OPENED";
    QTextStream outputStream(&outFile);

    outputStream << "Time Step,";
    QString species;

    foreach (species, m_SpeciesList) {
        outputStream << species << " (Biomass),";
    }
    outputStream << "\n";
    QList<QList<double> > outputBiomassMatrix = m_BiomassMatrix.getMatrix();
    int x = m_SpeciesList.size();
    int y = outputBiomassMatrix.at(0).size();
    qDebug() << "Time Steps: " << y;
    for (int i = 0; i < y; i++) {
        outputStream << i << ",";
        for (int j = 0; j < x; j++) {
            outputStream << outputBiomassMatrix.at(j).at(i) << ",";
        }
        outputStream << "\n";
    }

    outputStream << "\n";

    ModelComponent* component;
    QList<QString> speciesList = m_SpeciesList;
    foreach (component, modelComponentList) {
        component->outputResults(outputStream, speciesList);
    }
}


void Parameters::setOutputDirectory(QString OutputDirectory) {

    m_OutputDirectory = OutputDirectory;
//    m_OutputDirectory.append("/");
}

void Parameters::initializeStochasticOutputFiles() {

    QString species;
    foreach (species, m_SpeciesList) {
        QString speciesDirectoryNameBiomass = m_OutputDirectory;
        QString speciesDirectoryNameCatch = m_OutputDirectory;
        qDebug() << "Output Directory: " << m_OutputDirectory;
        speciesDirectoryNameBiomass.append(species);
        speciesDirectoryNameCatch.append(species);
        QString biomassOutFilename = "";
        biomassOutFilename = speciesDirectoryNameBiomass.append("_Biomass.csv");
        QString catchOutFilename = "";
        catchOutFilename = speciesDirectoryNameCatch.append("_Catch.csv");
        QFile outBiomassFile(biomassOutFilename);
        QFile outCatchFile(catchOutFilename);
        if (!outBiomassFile.open(QIODevice::WriteOnly | QIODevice::Text))
             qDebug() << "Output file NOT OPENED";
        if (!outCatchFile.open(QIODevice::WriteOnly | QIODevice::Text))
             qDebug() << "Output file NOT OPENED";
        QTextStream outputBiomassStream(&outBiomassFile);
        QTextStream outputCatchStream(&outCatchFile);
//        outputBiomassStream << "Run, Biomass";
//        outputCatchStream << "Run, Catch";
    }
}


void Parameters::outputStochasticResults(int modelRun) {

//    qDebug() << modelRun;
    QString species;
    int speciesNum = 0;
    QList<QList<double> > outputBiomassMatrix = m_BiomassMatrix.getMatrix();
    int numSteps = outputBiomassMatrix.at(0).size();
    qDebug() << "Outputting Model Run: " << modelRun << " with " << numSteps << " number of steps";

    foreach (species, m_SpeciesList) {
//        qDebug() << "Species Number: " << speciesNum;
        QString speciesDirectoryNameBiomass = m_OutputDirectory;
        QString speciesDirectoryNameCatch = m_OutputDirectory;
        speciesDirectoryNameBiomass.append(species);
        speciesDirectoryNameCatch.append(species);
        QString biomassOutFilename = "";
        biomassOutFilename = speciesDirectoryNameBiomass.append("_Biomass.csv");
        QString catchOutFilename = "";
        catchOutFilename = speciesDirectoryNameCatch.append("_Catch.csv");
        QFile outBiomassFile(biomassOutFilename);
        QFile outCatchFile(catchOutFilename);
        if (!outBiomassFile.open(QIODevice::Append | QIODevice::Text))
             qDebug() << "Output file NOT OPENED";
        if (!outCatchFile.open(QIODevice::Append | QIODevice::Text))
             qDebug() << "Output file NOT OPENED";
        QTextStream outputBiomassStream(&outBiomassFile);
        QTextStream outputCatchStream(&outCatchFile);

        outputBiomassStream << "\n" << modelRun;
        for (int step = 0; step < numSteps; step++) {
//            outputBiomassStream << "," << outputBiomassMatrix.at(speciesNum).at(step);
            outputBiomassStream << "," << getBiomass(speciesNum,step);
        }
        outputCatchStream << " \n" << modelRun;
        for (int step = 0; step < numSteps-1; step++) {
            outputCatchStream << "," << getOutputCatch(speciesNum,step);
        }
        speciesNum++;
    }
}


void Parameters::outputSkillAssessmentResults() {

    qDebug() << "Outputting skill assessment results";
    QString species;
    int speciesNum = 0;
    QList<QList<double> > outputBiomassMatrix = m_BiomassMatrix.getMatrix();
    int numSteps = outputBiomassMatrix.at(0).size();
    qDebug() << "Number of Biomass steps: " << numSteps;
    QString outFilename = m_OutputDirectory;
    outFilename = outFilename.append(m_OutputFilename);
    qDebug() << "Output File: " << outFilename;
    std::cout << "Output file: " << outFilename.toStdString() << "\n";
    QFile outFile(outFilename);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text))
         qDebug() << "Output file NOT OPENED";
    QTextStream outFileStream(&outFile);
    outFileStream << "rSeed" << "\n";
    outFileStream << m_rSeed << "\n";
    outFileStream << "Kraken_Biomass" << "\n";
    foreach (species, m_SpeciesList) {
        for (int step = 0; step < numSteps; step++) {
            outFileStream << getBiomass(speciesNum,step) << " ";
        }
        outFileStream << "\n";
        speciesNum++;
    }
    speciesNum = 0;
    QList<QList<double> > outputCatchMatrix = m_OutputCatchMatrix.getMatrix();
    numSteps = outputCatchMatrix.at(0).size();
    qDebug() << "Number of Catch steps: " << numSteps;
    outFileStream << "Kraken_Catch" << "\n";
    foreach (species, m_SpeciesList) {
        for (int step = 0; step < numSteps; step++) {
            outFileStream << getOutputCatch(speciesNum,step) << " ";
        }
        outFileStream << "\n";
        speciesNum++;
    }


    outFileStream << "Growth Rates" << "\n";
    speciesNum = 0;
    foreach (species, m_SpeciesList) {
        outFileStream << getGrowthRate(speciesNum) << " ";
        speciesNum++;
    }

    outFileStream << "\n";
    outFileStream << "Density Dependent Terms" << "\n";
    double value;
    int numSpecies = getNumberOfSpecies();
    for (int i = 0; i < numSpecies; i++) {
        value = getWithinGuildCompParam(i,i);
        outFileStream << value << " ";
    }
    outFileStream << "\n";
    outFileStream << "Density Dependent Terms from chromosome" << "\n";

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSpecies; j++) {
            value = getWithinGuildCompParam(i,j);
            outFileStream << value << " ";
        }
    }

    outFileStream << "\n";
    outFileStream << "Survey Q's" << "\n";
    speciesNum = 0;
    foreach (species, m_SpeciesList) {
        outFileStream << getSurveyQ(speciesNum) << " ";
        speciesNum++;
    }
}
