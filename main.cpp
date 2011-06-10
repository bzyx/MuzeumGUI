

#include <QtGui/QApplication>
#include "mainwindow.h"

#include <iostream>
#include <vector>

#include <QDebug>

#include <src/eksponatmuzealnymodel.h>
#include <src/muzeumkontener.h>
#include <src/eksponatmuzealny.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
