// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "CompetitionModuleBetweenGroup.h"

CompetitionModuleBetweenGroup::CompetitionModuleBetweenGroup(Parameters *paramObj, ModelFormParameters *modelFormObj) {

    m_ComponentName = "MSPROD bgc";
    m_OutputName = " (Competition Between Groups)";
    initializeOutputMatrix(paramObj);
//    qDebug() << m_OutputName << ": " << m_ComponentName;
    m_OutputLossesByGroup = true;
    if (m_OutputLossesByGroup) {
        initializeOutputLossesByGroupMatrix(paramObj,modelFormObj);
    }
}


double CompetitionModuleBetweenGroup::getModelComponentValue(Parameters* paramObj, int speciesIndex, int timestep) const {

    // Get growth, carrying capacity, and biomass of current species and system carrying capacity
    int i = speciesIndex;
    int g_i = 0;                                // Guild index for species i
    double r_i = paramObj->getGrowthRate(i);
    double Bi = paramObj->getBiomass(i, timestep);
    double Ki = paramObj->getSpeciesK(i);
    double Ks = paramObj->getSystemK();

    double lossByGroup = 0.0;

    // Get guild index for species i
    QString speciesName = paramObj->getSpeciesName(i);
    QString groupName = paramObj->getGuildMembership(speciesName);
    int numGroups = paramObj->getNumberOfGuilds();
    QString tempGroupName = "";
    int index = 0;
    while (groupName != tempGroupName) {
        tempGroupName = paramObj->getGuildName(index);
        if (groupName == tempGroupName) {
            g_i = index;
        }
        index++;
    }

    // Get summed value of loss to biomass from group competition
    double Bg = 0.0;
    double groupCompCoefficient = 0.0;
    double summedCompetition = 0.0;
    QString currentGroupName = "";
    for (int g = 0; g < numGroups; g++) {
        groupCompCoefficient = paramObj->getBetweenGuildCompParam(g_i,g);
        currentGroupName = paramObj->getGuildName(g);
        Bg = paramObj->getGuildBiomass(currentGroupName);

        lossByGroup = (-1.0 * r_i * Bg * groupCompCoefficient) / (Ks - Ki);
        if (m_OutputLossesByGroup) {
//            updateOutputLossesByGroupMatrix(paramObj, speciesIndex, g, lossByGroup);
        }

        summedCompetition += Bg * groupCompCoefficient;
    }

    double lossToBetweenGroupCompetition = (-1.0 * r_i * Bi * summedCompetition) / (Ks - Ki);

    return lossToBetweenGroupCompetition;

}

void CompetitionModuleBetweenGroup::updateOutputLossesByGroupMatrix(Parameters* paramObj, int affectedSpeciesIndex, int affectingSpeciesIndex, int timestep, double lossValue) const {
    qDebug() <<"Updating Losses By Group Matrix: " << m_ComponentName;
}
