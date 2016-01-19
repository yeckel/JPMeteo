#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Libor Tomsik");
    QCoreApplication::setOrganizationDomain("tomsik.eu");
    QCoreApplication::setApplicationName("Jedna Parta Meteo");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
