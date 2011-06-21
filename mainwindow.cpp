

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QTextCodec>
#include <QDebug>
#include <QRegExpValidator>
#include "src/eobraz.h"
#include "src/eprzemiotuzytkowy.h"
#include "src/muzeumkontener.h"
#include "eksponatmodel.h"
#include "src/mktyp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP-1250"));

    ui->setupUi(this);
    connect(ui->actionPoka_panel_dodawania,SIGNAL(triggered()),this,SLOT(setVisiblePanelDodawania()));
    connect(ui->actionPoka_szczeg_y,SIGNAL(triggered()),this,SLOT(setVisiblePanelSzczegoly()));

    ui->actionPoka_panel_dodawania->trigger();
    ui->actionPoka_szczeg_y->trigger();
    setDodawanieEnabled(false);

    setMetaToComboBox(ui->comboBox_wyborTypu,true);
    setMetaToComboBox(ui->dod_cb_typ);

//    Tworzenie validatorów do opcjonalnych pól
    QRegExp rx("[1-9]\\d{0,3}"); // 0..9999
    v_dp3a = new QRegExpValidator(rx, 0);
    v_dp3 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp1 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp2 = new QDoubleValidator(0.00,30.00,2,this);
    MK::getInstance().addItem(new EPrzemiotUzytkowy("ttttt",1,"EMtest",
                                             1,"Bardzo krótki opis"
                                             ,"Magazyn1", 100,
                                             Meta::PrzedmiotUzytkowy,
                                             EksponatMuzealny::w,
                                             "XXI") );
    MK::getInstance().addItem(new EObraz(17.0,18.5,"Van Gogh","EMtest",
                              1,"Bardzo inny opis opis"
                              ,"Magazyn1", 100,
                              Meta::Obraz,
                              EksponatMuzealny::w,
                              "XX"));
    MK::getInstance().addItem(new EObraz(1,12.5,"azPicasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                               Meta::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));

    MK::getInstance().addItem(new EObraz(4,12.5,"aaPicasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                               Meta::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));
    MK::getInstance().addItem(new EObraz(4,155,"zdasPicasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                               Meta::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));
    MK::getInstance().addItem(new EObraz(4,12.5,"Picaaaasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                               Meta::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));
    for(int i=0; i< 100; ++i){
    MK::getInstance().addItem(new EObraz(4,12.5,"zasPicasso","abubat",
                              1,"Bardaaa"
                              ,"Magazyn2", 100,
                               Meta::Obraz,
                              EksponatMuzealny::w,
                              "XXI"));
    }
    //MK::getInstance()[2]->nazwa("Ca³kiem nowa nazwa");
   // EObraz* test = dynamic_cast<EObraz*> (MK::getInstance()[2]);
    //test->wysokosc(222.22);
     MKTyp::getInstance().updateMKTyp();
     model = new EksponatModel(Meta::NieOkreslonoTypu,parent);
     ui->tableView->setModel(model);
     model->czyMoznaZmieniac(true);

}

 void MainWindow::seDisabledIfEmpty(){
     if (model->isEmpty()){
         ui->tableView->setEnabled(false);
         ui->statusBar->showMessage("Brak danych do wyœwietlenia.",1000);
     } else {
         ui->tableView->setEnabled(true);
         ui->statusBar->clearMessage();
     }
 }


MainWindow::~MainWindow()
{
    delete v_dp1;
    delete v_dp2;
    delete v_dp3;
    delete v_dp3a;
    delete ui;
    delete model;
}


void MainWindow::on_comboBox_wyborTypu_currentIndexChanged(int index)
{
    if(ui->comboBox_wyborTypu->itemText(0)=="")
        ui->comboBox_wyborTypu->removeItem(0);
    Meta::Typ nowyTyp = static_cast<Meta::Typ> (ui->comboBox_wyborTypu->itemData(index).toInt());
    model->setNewTyp(nowyTyp);
    seDisabledIfEmpty();
}

void  MainWindow::setVisiblePanelDodawania(){
    if(ui->panelDodawania->isHidden()){
    ui->actionPoka_panel_dodawania->setText("Ukryj panel dodawania");
    ui->panelDodawania->show();
    } else {
        ui->actionPoka_panel_dodawania->setText("Poka¿ panel dodawania");
        ui->panelDodawania->hide();
    }
}

void  MainWindow::setVisiblePanelSzczegoly(){
    if(ui->panelSzczegolow->isHidden()){
    ui->actionPoka_szczeg_y->setText("Ukryj panel szczegó³ów");
    ui->panelSzczegolow->show();
    } else {
        ui->actionPoka_szczeg_y->setText("Poka¿ panel szczegó³ów");
        ui->panelSzczegolow->hide();
    }
}

void MainWindow::setDodawanieEnabled(bool b){
    ui->dod_b_anu->setEnabled(b);
    ui->dod_b_dod->setEnabled(b);
    ui->dod_dat->setEnabled(b);
    ui->dod_fDat->setEnabled(b);
    ui->dod_nazwa->setEnabled(b);
    ui->dod_opis->setEnabled(b);
    ui->dod_wart->setEnabled(b);
    ui->dod_wysN->setEnabled(b);
    ui->dod_wysT->setEnabled(b);
    ui->dod_pol->setEnabled(b);

    if(!b){
        ui->dod_l_dp1->setHidden(true);
        ui->dod_l_dp2->setHidden(true);
        ui->dod_l_dp3->setHidden(true);

        ui->dod_dp1->setHidden(true);
        ui->dod_dp2->setHidden(true);
        ui->dod_dp3->setHidden(true);

        ui->dod_dp2_T->setHidden(true);
        ui->dod_dp2_N->setHidden(true);
    }
}

void MainWindow::setMetaToComboBox(QComboBox* cb, bool wszyskie){
    cb->addItem("");
    if(wszyskie){
    cb->addItem("Wszyskie typy",Meta::NieOkreslonoTypu);
    }
    cb->addItem("Mebel",Meta::Mebel);
    cb->addItem("Obraz",Meta::Obraz);
    cb->addItem("Przedmiot U¿ytkowy",Meta::PrzedmiotUzytkowy);
    cb->addItem("Rêkopis",Meta::Rekopis);
    cb->addItem("RzeŸba",Meta::Rzezba);
    cb->addItem("Starodruk",Meta::Starodruk);
}


void MainWindow::on_dod_cb_typ_currentIndexChanged(int index)
{
    v_dp1 = new QDoubleValidator(0.00,30.00,2,this);
    if(ui->dod_cb_typ->itemText(0)=="")
        ui->dod_cb_typ->removeItem(0);
        Meta::Typ nowyTyp = static_cast<Meta::Typ> (ui->dod_cb_typ->itemData(index).toInt());
        setDodawanieEnabled(true);

        ui->dod_dp1->setValidator(0);
        ui->dod_dp2->setValidator(0);
        ui->dod_dp3->setValidator(0);

        switch (nowyTyp){
        case Meta::Mebel: {
            ui->dod_l_dp1->setText("Rodzaj"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Material"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
            ui->dod_l_dp3->hide(); ui->dod_dp3->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
            break; }
        case Meta::Obraz: {
            ui->dod_dp1->setValidator(v_dp1);
            ui->dod_dp2->setValidator(v_dp2);
            ui->dod_l_dp1->setText("Wysokoœæ"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Szerokoœæ"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
            ui->dod_l_dp3->setText("Autor"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
            ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
            break;}
        case Meta::PrzedmiotUzytkowy: {
            ui->dod_l_dp1->setText("Opis dzia³ania"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Czy mo¿na dotkn¹æ"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
            ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
            ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
            break;}
        case Meta::Rekopis: {
            ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Czy jest zeskanowany"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
            ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
            ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
            break;}
        case Meta::Rzezba: {
            ui->dod_dp3->setValidator(v_dp3);
            ui->dod_l_dp1->setText("Postaæ"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Materia³"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
            ui->dod_l_dp3->setText("Powierzchnia"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
            ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
            break;}
        case Meta::Starodruk: {
            ui->dod_dp3->setValidator(v_dp3a);
            ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
            ui->dod_l_dp2->setText("Streszczenie"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
            ui->dod_l_dp3->setText("Liczba Stron"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
            ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
            break;}
        default:
            ui->dod_l_dp1->hide();  ui->dod_dp1->hide();
            ui->dod_l_dp2->hide();  ui->dod_dp2->hide();
            ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
            ui->dod_dp2_T->hide();  ui->dod_dp2_N->hide();
        }


    }
