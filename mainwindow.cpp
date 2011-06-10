

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

    //std::vector<EksponatMuzealny* > EMV;

    //EMV.push_back(new EObraz("Obraz1","Opis obrazu1",1990) );
    //EMV.push_back(new EObraz("Obraz2","Opis obrazu2",1995) );

    //EObraz *tobr = dynamic_cast<EObraz*> ( EMV.at(0) );
    //tobr->setSzerokoscWysokosc(100,25);

    //ui->lineEdit->setText(tobr->nazwa().c_str());

    //qDebug()<< tobr->nazwa().c_str() << tobr->id() << tobr->typ() << tobr->szerokosc();
    //EObraz *tobr1 = dynamic_cast<EObraz*> ( EMV.at(1) );
    //qDebug()<< tobr1->nazwa().c_str() << tobr1->id() << tobr1->typ() << tobr1->szerokosc();

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
    EObraz t2(19.0,18.5,"Van Gogh1","EMtest",
              1,"Bardzo ³³‚ krótki opis"
              ,"Magazyn1", 100,
              EksponatMuzealny::Obraz,
              EksponatMuzealny::w,
              "XX");
    ui->listWidget->addItems(t.getAtrybuty());
    //pewnie coï¿½ zmieni
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
