

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QDebug>
#include "src/eobraz.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP-1250"));

    ui->setupUi(this);

    //ui->lineEdit->setText( QString::number(tobr->id()) );
    //ui->lineEdit_2->setText( QString::number(tobr1->id()) );
    //MuzeumKontener az = MuzeumKontener();
    //MKontener* t = az.GetInstance();

    //EksponatMuzealnyModel* b = t->at(0);
    //ui->lineEdit->setText(b->a.c_str());
    EObraz t(17.0,18.5,"Van Gogh","EMtest",
             1,"Bardzo ³³‚ krótki opis"
             ,"Magazyn1", 100,
             EksponatMuzealny::Obraz,
             EksponatMuzealny::w,
             "XX");
    //    EObraz t2(19.0,18.5,"Van Gogh1","EMtest",
    //              1,"Bardzo ³³‚ krótki opis"
    //              ,"Magazyn1", 100,
    //              EksponatMuzealny::Obraz,
    //              EksponatMuzealny::w,
    //              "XX");
    ui->listWidget->addItems(t.getAtrybuty());
    typedef QPair<QString,QString> tst;
    EksponatMuzealny::r2f test = t.saveElement();
    foreach(tst tmp, test){
        //        qDebug()<< tmp.first << tmp.second;
        ui->textEdit->append(tmp.first +" "+ tmp.second+" \n");
    }
    //    test = t2.saveElement();
    //    foreach(tst tmp, test){
    //        qDebug()<< tmp.first << tmp.second;
    //        ui->textEdit->append(tmp.first +" "+ tmp.second+" \n");
    //    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
