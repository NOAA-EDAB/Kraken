// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#ifndef ASSESSMENTMODULE_H
#define ASSESSMENTMODULE_H

// CompetitionModuleBetweenGroup.h header file

#include "Parameters.h"
#include <QSharedPointer>

class AssessmentModule {

protected:
    QString m_assessmentType;
    mutable double m_ACL;

public:
    virtual void assess(Parameters* paramObj, int timeStep) const = 0;
    void assessBiomass(Parameters* paramObj);
    QString getAssessmentType();
    double get_ACL();
    void set_ACL(double ACL);
};


#endif // ASSESSMENTMODULE_H
