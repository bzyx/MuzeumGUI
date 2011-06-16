

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QDebug>
#include "src/eobraz.h"
#include "src/eprzemiotuzytkowy.h"
#include "src/muzeumkontener.h"
#include "eksponatmodel.h"
#include "model.h"
#include "src/mktyp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP-1250"));

    ui->setupUi(this);

    ui->toolBox->hide();
    ui->frame->hide();
    //MuzeumKontener* kontener = MuzeumKontener::getInstance();


    //ui->lineEdit->setText( QString::number(tobr->id()) );
    //ui->lineEdit_2->setText( QString::number(tobr1->id()) );
    //MuzeumKontener az = MuzeumKontener();
    //MKontener* t = az.GetInstance();

    //EksponatMuzealnyModel* b = t->at(0);
    //ui->lineEdit->setText(b->a.c_str());
//    EObraz t(17.0,18.5,"Van Gogh","EMtest",
//             1,"Bardzo ï¿½ï¿½ï¿½ krï¿½tki opis"
//             ,"Magazyn1", 100,
//             EksponatMuzealny::Obraz,
//             EksponatMuzealny::w,
//             "XX");
//    EPrzemiotUzytkowy z("ttttt",1,"EMtest",
//                      1,"Bardzo ï¿½ï¿½ï¿½ krï¿½tki opis"
//                      ,"Magazyn1", 100,
//                      EksponatMuzealny::PrzedmiotUzytkowy,
//                      EksponatMuzealny::w,
//                      "XXI");
    //    EObraz t2(19.0,18.5,"Van Gogh1","EMtest",
    //              1,"Bardzo ï¿½ï¿½ï¿½ krï¿½tki opis"
    //              ,"Magazyn1", 100,
    //              EksponatMuzealny::Obraz,
    //              EksponatMuzealny::w,
    //              "XX");

    //kontener.addItem(t);
    //kontener.addItem(z);
    MKontener* lista = MK::getInstance().getList();
//    MuzeumKontener mk = MuzeumKontener::getInstance();
    MK::getInstance().addItem(new EPrzemiotUzytkowy("ttttt",1,"EMtest",
                                             1,"Bardzo krótki opis"
                                             ,"Magazyn1", 100,
                                             EksponatMuzealny::PrzedmiotUzytkowy,
                                             EksponatMuzealny::w,
                                             "XXI") );
    MK::getInstance().addItem(new EObraz(17.0,18.5,"Van Gogh","EMtest",
                              1,"Bardzo inny opis opis"
                              ,"Magazyn1", 100,
                              EksponatMuzealny::Obraz,
                              EksponatMuzealny::w,
                              "XX"));
    MK::getInstance().addItem(new EObraz(4,12.5,"Picasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                              EksponatMuzealny::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));
    //EObraz* test1 = (EObraz*)lista->at(1);
    //ui->lineEdit->setText(test1->getAutor().c_str());
//    ui->lineEdit_2->setText(MK::getInstance()[1]->getOpis().c_str());
//    ui->listWidget->addItems(MK::getInstance()[1]->getAtrybuty());
//    typedef QPair<QString,QString> tst;
//    EksponatMuzealny::r2f test = MK::getInstance()[0]->saveElement();
//    foreach(tst tmp, test){
//        //        qDebug()<< tmp.first << tmp.second;
//        ui->textEdit->append(tmp.first +" "+ tmp.second+" \n");
//    }
    //MK::getInstance().deleteAll();

    //    test = t2.saveElement();
    //    foreach(tst tmp, test){
    //        qDebug()<< tmp.first << tmp.second;
    //        ui->textEdit->append(tmp.first +" "+ tmp.second+" \n");
    //    }
    //EksponatModel eksponatmodel(8, 4, parent);
    //eksponatmodel.metodaReset();

    //ui->tableView->setModel(&eksponatmodel);
     //TableModel *model = new TableModel(8, 4, parent);
    //EksponatModel *model = new EksponatModel(Meta::NieOkreslonoTypu,parent);
    //EksponatModel *model = new EksponatModel(Meta::Obraz,parent);
   //  ui->tableView->setModel(model);
     MKTyp::getInstance().updateMKTyp();
     EksponatMuzealny* tmp = MKTyp::getInstance().getObjectFor(Meta::Obraz,0);
     EksponatMuzealny* tmp1 = MKTyp::getInstance().getObjectFor(Meta::Obraz,1);
     qDebug() << tmp->getData().c_str();
     qDebug() << tmp1->getAtrybuty();

}

MainWindow::~MainWindow()
{
    delete ui;
}

