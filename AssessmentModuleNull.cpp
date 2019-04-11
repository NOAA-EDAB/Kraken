// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "AssessmentModuleNull.h"

AssessmentModuleNull::AssessmentModuleNull() {

    m_assessmentType = "NULL";
}


void AssessmentModuleNull::assess(Parameters* paramObj, int timestep) const{

    qDebug() << "Null Assessment - Leaving Catch alone";
}
