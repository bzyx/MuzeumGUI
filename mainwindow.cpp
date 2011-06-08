

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "src/eobraz.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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
    EksponatMuzealny t("EMtest",
                                               1,"Bardzo krótki opis"
                                               ,"Magazyn1", 100,
                                               EksponatMuzealny::Obraz,
                                               EksponatMuzealny::w,
                                               "XX");
    ui->listWidget->addItems(t.getPodstawoweAtrybuty());
    //pewnie coœ zmieni
}

MainWindow::~MainWindow()
{
    delete ui;
}
