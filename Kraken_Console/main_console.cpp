#include "KrakenConsole.h"
#include <QCoreApplication>
#include <iostream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication KrakenApp(argc, argv);
    KrakenConsole *krakenConsoleObject = new KrakenConsole(argc, argv);
    krakenConsoleObject->startConsole();

    return 0;
//    return KrakenApp.exec();
}
