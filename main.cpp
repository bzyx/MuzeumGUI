

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
    //Simple change
    QApplication a(argc, argv);

//    MuzeumKontener az = MuzeumKontener();
//    MKontener* t = az.GetInstance();
//    az.addItm(new EksponatMuzealnyModel(1));
//    az.addItm(new EksponatMuzealnyModel(2));
//    az.addItm(new EksponatMuzealnyModel(3));
//    az.addItm(new EksponatMuzealnyModel(4));

    //MKontener::iterator bz;
    //bz = t->begin();
    //std::cout << (*bz).a;
//    for (int i=0; i<4; ++i){
//    EksponatMuzealnyModel* b = t->at(i);
//    qDebug() << QString(b->a.c_str());
//    qDebug() << b->b;
//    qDebug() << b->c;

//    }
    EksponatMuzealny t("EMtest",
                                               1,"Bardzo krótki opis"
                                               ,"Magazyn1", 100,
                                               EksponatMuzealny::Obraz,
                                               EksponatMuzealny::w,
                                               "XX");
    qDebug() << t.getData().c_str();
    foreach(QString elem, t.getPodstawoweAtrybuty())
        qDebug() << elem;
    foreach(QString el2, t.getPodstawoweHeaders())
        qDebug() << el2;


    MainWindow w;
    w.show();

    return a.exec();
}
