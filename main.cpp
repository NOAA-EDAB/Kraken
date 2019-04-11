// Programmed by Robert Gamble at Northeast Fisheries Science Center in Woods Hole, MA
// E-mail: Robert.Gamble@noaa.gov
// Phone #: 508-495-2202
// Codebase distributed on: 12/10/2014

#include <QApplication>
#include <iostream>

#include "ms_prod_mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MS_PROD_MainWindow w;
    w.show();

    return a.exec();
}

//int main(int argc, char *argv[])
//{
//        QCoreApplication a(argc, argv);

        //Put your application code here

        //This line shouldn't be reached until the application is quitting
//        QTimer::singleShot(0, &a, SLOT(quit()));
//        return a.exec();
//}
