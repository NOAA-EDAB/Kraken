// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include "AssessmentModule.h"

QString AssessmentModule::getAssessmentType() {

    return m_assessmentType;
}

double AssessmentModule::get_ACL() {

    return m_ACL;
}

void AssessmentModule::set_ACL(double ACL) {

    m_ACL = ACL;
}
