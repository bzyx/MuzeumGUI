

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QTextCodec>
#include <QDebug>
#include <QRegExpValidator>
#include "src/eprzemiotuzytkowy.h"
#include "src/muzeumkontener.h"
#include "eksponatmodel.h"
#include "src/mktyp.h"

#include "src/emebel.h"
#include "src/eobraz.h"
#include "src/eprzemiotuzytkowy.h"
#include "src/erekopis.h"
#include "src/erzezba.h"
#include "src/estarodruk.h"

#include "src/material.h"
#include "src/materialmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP-1250"));

    ui->setupUi(this);
    connect(ui->actionPoka_panel_dodawania,SIGNAL(triggered()),this,SLOT(setVisiblePanelDodawania()));
    connect(ui->actionPoka_szczeg_y,SIGNAL(triggered()),this,SLOT(setVisiblePanelSzczegoly()));
    connect(ui->dod_b_dod,SIGNAL(clicked()),this,SLOT(checkDodajFields()));

    ui->actionPoka_panel_dodawania->trigger();
    ui->actionPoka_szczeg_y->trigger();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    setDodawanieEnabled(false);

    setMetaToComboBox(ui->comboBox_wyborTypu,true);
    setMetaToComboBox(ui->dod_cb_typ);

    ui->sz_l_dp1->hide();
    ui->sz_l_dp2->hide();
    ui->sz_l_dp3->hide();
    ui->sz_dp1->hide();
    ui->sz_dp2->hide();
    ui->sz_dp3->hide();

    QSettings ust("./settings.ini", QSettings::IniFormat);
    Material::getInstance().readFromFile(&ust);

    MaterialModel* matModel;
    matModel = new MaterialModel(this);

    ui->dod_dp2_cb->setModel(matModel);


    //    Tworzenie validatorów do opcjonalnych pól
    QRegExp rx("[1-9]\\d{0,3}"); // 0..9999
    v_dp3a = new QRegExpValidator(rx, 0);
    v_dp3 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp1 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp2 = new QDoubleValidator(0.00,30.00,2,this);

    ui->dod_fDat->addItem("Wiek (w)",Meta::w);
    ui->dod_fDat->addItem("Rok (rrrr)",Meta::r);
    ui->dod_fDat->addItem("Miesi¹c i rok (mm.rrrr)",Meta::mr);
    ui->dod_fDat->addItem("Dzieñ,miesi¹æ,rok (dd.mm.rrrr)",Meta::dmr);

    MK::getInstance().readFromFile("plik.xml");

    //    MK::getInstance().addItem(new EPrzemiotUzytkowy("ttttt",1,"EMtest",
//                                                    1,"Bardzo krótki opis"
//                                                    ,"Magazyn1", 100,
//                                                    Meta::PrzedmiotUzytkowy,
//                                                    Meta::w,
//                                                    "XXI") );
//    MK::getInstance().addItem(new EObraz(17.0,18.5,"Van Gogh","EMtest",
//                                         1,"Bardzo inny opis opis"
//                                         ,"Magazyn1", 100,
//                                         Meta::Obraz,
//                                         Meta::w,
//                                         "XX"));
//    MK::getInstance().addItem(new EObraz(1,12.5,"azPicasso","abubat",
//                                         1,"Bardaaa"
//                                         ,"Magazyn2", 100,
//                                         Meta::Obraz,
//                                         Meta::w,
//                                         "XXI"));

//    MK::getInstance().addItem(new EObraz(4,12.5,"aaPicasso","abubat",
//                                         1,"Bardaaa"
//                                         ,"Magazyn2", 100,
//                                         Meta::Obraz,
//                                         Meta::w,
//                                         "XXI"));
//    MK::getInstance().addItem(new EObraz(4,155,"zdasPicasso","abubat",
//                                         1,"Bardaaa"
//                                         ,"Magazyn2", 100,
//                                         Meta::Obraz,
//                                         Meta::w,
//                                         "XXI"));
//    MK::getInstance().addItem(new EObraz(4,12.5,"Picaaaasso","abubat",
//                                         1,"Bardaaa"
//                                         ,"Magazyn2", 100,
//                                         Meta::Obraz,
//                                         Meta::w,
//                                         "XXI"));
//    for(int i=0; i< 100; ++i){
//        MK::getInstance().addItem(new EObraz(4,12.5,"zasPicasso","abubat",
//                                             1,"Bardaaa"
//                                             ,"Magazyn2", 100,
//                                             Meta::Obraz,
//                                             Meta::w,
//                                             "XXI"));
//    }
    //MK::getInstance()[2]->nazwa("Ca³kiem nowa nazwa");
    // EObraz* test = dynamic_cast<EObraz*> (MK::getInstance()[2]);
    //test->wysokosc(222.22);
    MKTyp::getInstance().updateMKTyp();
    model = new EksponatModel(Meta::NieOkreslonoTypu,parent);
    ui->tableView->setModel(model);
    model->czyMoznaZmieniac(true);

    ui->dod_id->setText(QString::number(EksponatMuzealny::getLastId()));
    Material::getInstance().saveToFile(&ust);

}
void MainWindow::setDisabledIfEmpty(){
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
    MK::getInstance().saveToFile("plik.xml");
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
    setDisabledIfEmpty();
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
        on_tableView_clicked(QModelIndex());
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
    on_dod_b_anu_clicked();
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
        ui->dod_l_dp1->setToolTip("Rodzaj mebla.");
        ui->dod_l_dp2->setText("Material"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        ui->dod_dp2_cb->show();
        ui->dod_l_dp2->setToolTip("Materia³ z jakiego wykonano mebel.");
        ui->dod_l_dp3->hide(); ui->dod_dp3->hide();
        break; }
    case Meta::Obraz: {
        ui->dod_dp1->setValidator(v_dp1);
        ui->dod_dp2->setValidator(v_dp2);
        ui->dod_l_dp1->setText("Wysokoœæ"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Wysokoœæ obrazu.");
        ui->dod_l_dp2->setText("Szerokoœæ"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
        ui->dod_l_dp2->setToolTip("Szerokoœæ obrazu.");
        ui->dod_l_dp3->setText("Autor"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
        ui->dod_l_dp3->setToolTip("Autor obrazu.");
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::PrzedmiotUzytkowy: {
        ui->dod_l_dp1->setText("Opis dzia³ania"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Krótki opis co robi ten przedmiot.");
        ui->dod_l_dp2->setText("Czy mo¿na dotkn¹æ"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_l_dp2->setToolTip("Czy zwiedzaj¹cy mog¹ go dotkn¹æ.");
        ui->dod_dp2gb->show(); ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
        ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::Rekopis: {
        ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Autor rêkopisu.");
        ui->dod_l_dp2->setText("Czy jest zeskanowany"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_l_dp2->setToolTip("Czy rêkopis jest zeskanownay.");
        ui->dod_dp2gb->show(); ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
        ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::Rzezba: {
        ui->dod_dp3->setValidator(v_dp3);
        ui->dod_l_dp1->setText("Postaæ"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Opis/nazwa przedstawianej postaci.");
        ui->dod_l_dp2->setText("Materia³"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_dp2_cb->show();
        ui->dod_l_dp1->setToolTip("Materia³ z jakiego wykonano rzeŸbê.");
        ui->dod_l_dp3->setText("Powierzchnia"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
        ui->dod_l_dp1->setToolTip("Powierzchnia jak¹ zajmuje rzeŸba.");
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        break;}
    case Meta::Starodruk: {
        ui->dod_dp3->setValidator(v_dp3a);
        ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Autor starodruku.");
        ui->dod_l_dp2->setText("Streszczenie"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
        ui->dod_l_dp1->setToolTip("Krótkie streszczenie starodruku.");
        ui->dod_l_dp3->setText("Liczba Stron"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
        ui->dod_l_dp1->setToolTip("Liczba stron w starodruku.");
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        ui->dod_dp2_cb->hide();
        break;}
    default:
        ui->dod_l_dp1->hide();  ui->dod_dp1->hide();
        ui->dod_l_dp2->hide();  ui->dod_dp2->hide();
        ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide();  ui->dod_dp2_N->hide();
        ui->dod_dp2_cb->hide();
    }


}
bool MainWindow::checkDodajFields(){
    bool retunValue = true;
    if(ui->dod_nazwa->text().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_nazwa->setStyleSheet("QLabel { color : red; }");
        ui->dod_nazwa->setToolTip("Nale¿y podaæ nazwê obiektu.");
        ui->dod_nazwa->clear();
    } else if(!ui->dod_nazwa->text().simplified().isEmpty()){
        ui->dod_l_nazwa->setStyleSheet("");
        ui->dod_nazwa->setToolTip("");
    }

    if(ui->dod_pol->text().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_polozenie->setStyleSheet("QLabel { color : red; }");
        ui->dod_pol->setToolTip("Nale¿y podaæ po³o¿enie obiektu.");
        ui->dod_pol->clear();
    } else if(!ui->dod_pol->text().simplified().isEmpty()){
        ui->dod_l_polozenie->setStyleSheet("");
        ui->dod_pol->setToolTip("");
    }

    if(ui->dod_dat->text().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_data->setStyleSheet("QLabel { color : red; }");
        ui->dod_dat->setToolTip("Nale¿y podaæ datê w wybranym formacie");
        ui->dod_dat->clear();
    } else if(!ui->dod_dat->text().simplified().isEmpty()){
        ui->dod_l_data->setStyleSheet("");
        ui->dod_dat->setToolTip("");
    }

    if(ui->dod_opis->toPlainText().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_opis->setStyleSheet("QLabel { color : red; }");
        ui->dod_opis->setToolTip("Nale¿y podaæ opis obiektu");
        ui->dod_opis->clear();
    } else if(!ui->dod_opis->toPlainText().simplified().isEmpty()){
        ui->dod_l_opis->setStyleSheet("");
        ui->dod_opis->setToolTip("");
    }

    if (!(ui->dod_wysN->isChecked() || ui->dod_wysT->isChecked())){
        retunValue = false;
        ui->dod_l_wyst->setStyleSheet("QLabel { color : red; }");
        ui->dod_l_wyst->setToolTip("Nale¿y wybraæ czy eksponat ma byæ wystawiony.");
        ui->dod_wysN->setToolTip("Nale¿y wybraæ czy eksponat ma byæ wystawiony.");
        ui->dod_wysT->setToolTip("Nale¿y wybraæ czy eksponat ma byæ wystawiony.");
    } else if (ui->dod_wysN->isChecked() || ui->dod_wysT->isChecked()){
        ui->dod_l_wyst->setStyleSheet("");
        ui->dod_wysN->setToolTip("");
        ui->dod_wysT->setToolTip("");
    }
    if(!ui->dod_dp1->isHidden()){
        if(ui->dod_dp1->text().simplified().isEmpty()){
            retunValue = false;
            ui->dod_l_dp1->setStyleSheet("QLabel { color : red; }");
            ui->dod_dp1->setToolTip("Nale¿y wype³niæ te pole.");
            ui->dod_dp1->clear();
        } else if(!ui->dod_dp1->text().simplified().isEmpty()){
            ui->dod_l_dp1->setStyleSheet("");
            ui->dod_dp1->setToolTip("");
        }
    }

    if(!ui->dod_dp2->isHidden()){
        if(ui->dod_dp2->text().simplified().isEmpty()){
            retunValue = false;
            ui->dod_l_dp2->setStyleSheet("QLabel { color : red; }");
            ui->dod_dp2->setToolTip("Nale¿y wype³niæ te pole.");
            ui->dod_dp2->clear();
        } else if(!ui->dod_dp2->text().simplified().isEmpty()){
            ui->dod_l_dp2->setStyleSheet("");
            ui->dod_dp2->setToolTip("");
        }
    }

    if(!ui->dod_dp3->isHidden()){
        if(ui->dod_dp3->text().simplified().isEmpty()){
            retunValue = false;
            ui->dod_l_dp3->setStyleSheet("QLabel { color : red; }");
            ui->dod_dp3->setToolTip("Nale¿y wype³niæ te pole.");
            ui->dod_dp3->clear();
        } else if(!ui->dod_dp3->text().simplified().isEmpty()){
            ui->dod_l_dp3->setStyleSheet("");
            ui->dod_dp3->setToolTip("");
        }
    }
    return retunValue;
}

void MainWindow::on_dod_fDat_currentIndexChanged(int index)
{
    Meta::FormatDaty fd = static_cast<Meta::FormatDaty> (ui->dod_fDat->itemData(index).toInt());
    QRegExp wiek("[I,V,X,L]{1,3}");
    QRegExp rok("[0-2][0-9]{3}");
    QRegExp mr("^((0[1-9])|(1[0-2]))[.][0-2][0-9]{3}");
    QRegExp dmr("(0[1-9]|[12][0-9]|3[01])[.](0[1-9]|1[012])[.][0-2][0-9]{3}");
    switch (fd) {
    case Meta::w: ui->dod_dat->setValidator(new QRegExpValidator(wiek,this)); break;
    case Meta::r : ui->dod_dat->setValidator(new QRegExpValidator(rok,this));  break;
    case Meta::mr : ui->dod_dat->setValidator(new QRegExpValidator(mr,this));  break;
    case Meta::dmr : ui->dod_dat->setValidator(new QRegExpValidator(dmr,this)); break;
    //default: break;
    }
    //Ustawianie maski w zale¿noœci od ui->dod_fDat
}

void MainWindow::on_dod_b_anu_clicked()
{
    ui->dod_nazwa->clear();
    ui->dod_pol->clear();
    ui->dod_dat->clear();
    ui->dod_opis->clear();
    ui->dod_dp1->clear();
    ui->dod_dp2->clear();
    ui->dod_dp3->clear();
    ui->dod_dp2gb->hide();
    ui->dod_wart->setValue(0);
    ui->dod_fDat->setCurrentIndex(0);
    ui->dod_wysN->setChecked(true);
    ui->dod_dp2_N->setChecked(true);
    ui->dod_l_nazwa->setStyleSheet("");
    ui->dod_nazwa->setToolTip("");
    ui->dod_l_polozenie->setStyleSheet("");
    ui->dod_pol->setToolTip("");
    ui->dod_l_data->setStyleSheet("");
    ui->dod_dat->setToolTip("");
    ui->dod_l_opis->setStyleSheet("");
    ui->dod_opis->setToolTip("");
    ui->dod_l_wyst->setStyleSheet("");
    ui->dod_wysN->setToolTip("");
    ui->dod_wysT->setToolTip("");
    ui->dod_l_dp1->setStyleSheet("");
    ui->dod_dp1->setToolTip("");
    ui->dod_l_dp2->setStyleSheet("");
    ui->dod_dp2->setToolTip("");
    ui->dod_l_dp3->setStyleSheet("");
    ui->dod_dp3->setToolTip("");
}

void MainWindow::on_dod_b_dod_clicked()
{
    if (checkDodajFields()){
        ui->dod_id->setText(QString::number(EksponatMuzealny::getLastId()+1));
        Meta::Typ nowyTyp = static_cast<Meta::Typ> (ui->dod_cb_typ->itemData(ui->dod_cb_typ->currentIndex()).toInt());
        Meta::FormatDaty fd = static_cast<Meta::FormatDaty> (ui->dod_fDat->itemData(ui->dod_fDat->currentIndex()).toInt());
        int numMat = static_cast<int> (ui->dod_dp2_cb->itemData(ui->dod_dp2_cb->currentIndex()).toInt());
        switch (nowyTyp){
        case Meta::Mebel: {
            MK::getInstance().addItem(new EMebel(ui->dod_dp1->text().simplified().toStdString(),
                                                 numMat,
                                                 ui->dod_nazwa->text().simplified().toStdString(),
                                                 ui->dod_wysT->isChecked(),
                                                 ui->dod_opis->toPlainText().simplified().toStdString(),
                                                 ui->dod_pol->text().simplified().toStdString(),
                                                 ui->dod_wart->value(),
                                                 Meta::Mebel,fd,ui->dod_dat->text().simplified().toStdString()));
            break; }
        case Meta::Obraz: {
            MK::getInstance().addItem(new EObraz(ui->dod_dp1->text().toFloat(),
                                                 ui->dod_dp2->text().toFloat(),
                                                 ui->dod_dp3->text().simplified().toStdString(),
                                                 ui->dod_nazwa->text().simplified().toStdString(),
                                                 ui->dod_wysT->isChecked(),
                                                 ui->dod_opis->toPlainText().simplified().toStdString(),
                                                 ui->dod_pol->text().simplified().toStdString(),
                                                 ui->dod_wart->value(),
                                                 Meta::Obraz,fd,ui->dod_dat->text().simplified().toStdString()));

            break;}
        case Meta::PrzedmiotUzytkowy: {
            MK::getInstance().addItem(new EPrzemiotUzytkowy(ui->dod_dp1->text().simplified().toStdString(),
                                                            ui->dod_dp2_T->isChecked(),
                                                            ui->dod_nazwa->text().simplified().toStdString(),
                                                            ui->dod_wysT->isChecked(),
                                                            ui->dod_opis->toPlainText().simplified().toStdString(),
                                                            ui->dod_pol->text().simplified().toStdString(),
                                                            ui->dod_wart->value(),
                                                            Meta::PrzedmiotUzytkowy,fd,ui->dod_dat->text().simplified().toStdString()));

            break;}
        case Meta::Rekopis: {
            MK::getInstance().addItem(new ERekopis(ui->dod_dp1->text().simplified().toStdString(),
                                                   ui->dod_dp2_T->isChecked(),
                                                   ui->dod_nazwa->text().simplified().toStdString(),
                                                   ui->dod_wysT->isChecked(),
                                                   ui->dod_opis->toPlainText().simplified().toStdString(),
                                                   ui->dod_pol->text().simplified().toStdString(),
                                                   ui->dod_wart->value(),
                                                   Meta::Rekopis,fd,ui->dod_dat->text().simplified().toStdString()));

            break;}
        case Meta::Rzezba: {
            MK::getInstance().addItem(new ERzezba(ui->dod_dp1->text().simplified().toStdString(),
                                                  numMat,
                                                  ui->dod_dp3->text().toFloat(),
                                                  ui->dod_nazwa->text().simplified().toStdString(),
                                                  ui->dod_wysT->isChecked(),
                                                  ui->dod_opis->toPlainText().simplified().toStdString(),
                                                  ui->dod_pol->text().simplified().toStdString(),
                                                  ui->dod_wart->value(),
                                                  Meta::Rzezba,fd,ui->dod_dat->text().simplified().toStdString()));

            break;}
        case Meta::Starodruk: {
            MK::getInstance().addItem(new EStarodruk(ui->dod_dp1->text().simplified().toStdString(),
                                                     ui->dod_dp2->text().simplified().toStdString(),
                                                     ui->dod_dp3->text().toInt(),
                                                     ui->dod_nazwa->text().simplified().toStdString(),
                                                     ui->dod_wysT->isChecked(),
                                                     ui->dod_opis->toPlainText().simplified().toStdString(),
                                                     ui->dod_pol->text().simplified().toStdString(),
                                                     ui->dod_wart->value(),
                                                     Meta::Starodruk,fd,ui->dod_dat->text().simplified().toStdString()));

            break;}
        default:
            break;
        }
        MKTyp::getInstance().updateMKTyp();
        model->makeReset();
        setDisabledIfEmpty();
    } else if(!checkDodajFields()) {
        ui->statusBar->showMessage("Niektóre pola s¹ nieuzupe³nione lub zaieraj¹ b³êdy",700);
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString aktelem;
    if (index.row() != -1){
        aktelem = QString("%1 z %2").arg(index.row(),0).arg(model->rowCount()-1,0);
    } else {
        aktelem = QString("Wybierz eksponat");
    }
    ui->sz_licznik->setText(aktelem);

    Meta::Typ curr_typ = model->getCurrentTyp();
    EksponatMuzealny* element;
    if (index.row() >= 0){
        if(curr_typ == Meta::NieOkreslonoTypu){
            element = MK::getInstance()[index.row()];
        } else {
            element = MKTyp::getInstance().getObjectFor(curr_typ,index.row());
        }
        if(element != NULL){
            QString title;
            title = QString("%1 : %2").arg(element->getId(),0).arg(element->getNazwa().c_str());
            ui->sz_groupbox->setTitle(title);
            ui->sz_id->setText(QString::number(element->getId()));
            QString form;
            if (element->getFormatDaty() == 5)
                form = "wiek";
            else
                form = "r.";
            ui->sz_nazwa->setText(element->getNazwa().c_str());
            QString data;
            data = QString("%1 %2").arg(element->getData().c_str()).arg(form);
            ui->sz_typ->setText(Meta::nazwaTypu(element->getTyp()).c_str());
            ui->sz_wys->setText(Meta::b2s(element->getWystawiony()).c_str());
            ui->sz_pol->setText(element->getPolozenie().c_str());
            ui->sz_dat->setText(data);
            ui->sz_opi->setPlainText(element->getOpis().c_str());
            ui->sz_war->setText(QString::number(element->getWartosc()));

            switch (element->getTyp()){
            case Meta::Mebel: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_l_dp3->hide();
                ui->sz_dp3->hide();
                ui->sz_l_dp1->setText("Rodzaj");
                ui->sz_l_dp2->setText("Material");
                EMebel* m = dynamic_cast<EMebel*> (element);
                ui->sz_dp1->setText(m->getRodzaj().c_str());
                ui->sz_dp2->setText(Meta::nazwaTypu(m->getMaterial()).c_str());
                break; }
            case Meta::Obraz: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_l_dp3->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_dp3->show();
                ui->sz_l_dp1->setText("Wysokoœæ");
                ui->sz_l_dp2->setText("Szerokoœæ");
                ui->sz_l_dp3->setText("Autor obrazu.");
                EObraz* m = dynamic_cast<EObraz*> (element);
                ui->sz_dp1->setText(QString::number(m->getWysokosc()));
                ui->sz_dp2->setText(QString::number(m->getSzerokosc()));
                ui->sz_dp3->setText(m->getAutor().c_str());
                break;}
            case Meta::PrzedmiotUzytkowy: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_l_dp3->hide();
                ui->sz_dp3->hide();
                ui->sz_l_dp1->setText("Opis dzia³ania");
                ui->sz_l_dp2->setText("Czy mo¿na dotkn¹æ");
                EPrzemiotUzytkowy* m = dynamic_cast<EPrzemiotUzytkowy*> (element);
                ui->sz_dp1->setText(m->getOpisDzialania().c_str());
                ui->sz_dp2->setText(Meta::b2s(m->getCzyMoznaDotykac()).c_str());
                break;}
            case Meta::Rekopis: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_l_dp3->hide();
                ui->sz_dp3->hide();
                ui->sz_l_dp1->setText("Autor");
                ui->sz_l_dp2->setText("Zeskanowany");
                ERekopis* m = dynamic_cast<ERekopis*> (element);
                ui->sz_dp1->setText(m->getAutor().c_str());
                ui->sz_dp2->setText(Meta::b2s(m->getCzyZeskanowany()).c_str());
                break;}
            case Meta::Rzezba: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_l_dp3->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_dp3->show();
                ui->sz_l_dp1->setText("Postaæ");
                ui->sz_l_dp2->setText("Materia³");
                ui->sz_l_dp3->setText("Powierzchnia");
                ERzezba* m = dynamic_cast<ERzezba*> (element);
                ui->sz_dp1->setText(m->getPostac().c_str());
                ui->sz_dp2->setText(Meta::nazwaTypu(m->getMaterial()).c_str());
                ui->sz_dp3->setText(QString::number(m->getPowierzchnia()));
                break;}
            case Meta::Starodruk: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_l_dp3->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_dp3->show();
                ui->sz_l_dp1->setText("Autor");
                ui->sz_l_dp2->setText("Streszczenie");
                ui->sz_l_dp3->setText("Liczba Stron");
                EStarodruk* m = dynamic_cast<EStarodruk*> (element);
                ui->sz_dp1->setText(m->getAutor().c_str());
                ui->sz_dp2->setText(m->getStreszczenie().c_str());
                ui->sz_dp3->setText(QString::number(m->getLiczbaStron()));
                break;}
            default:
                ui->sz_l_dp1->hide();
                ui->sz_l_dp2->hide();
                ui->sz_l_dp3->hide();
                ui->sz_dp1->hide();
                ui->sz_dp2->hide();
                ui->sz_dp3->hide();
            }
        }
    }
}



void MainWindow::on_sz_pop_clicked()
{
    QModelIndex m;
    if( ui->tableView->currentIndex().row() > 0){
            m = ui->tableView->model()->index(ui->tableView->currentIndex().row()-1,
                                              ui->tableView->currentIndex().column());
            ui->tableView->setCurrentIndex(m);
            on_tableView_clicked(m);
    }

}

void MainWindow::on_sz_nas_clicked()
{
    QModelIndex m;
    if( ui->tableView->currentIndex().row() < ui->tableView->model()->rowCount()){
            m = ui->tableView->model()->index(ui->tableView->currentIndex().row()+1,
                                              ui->tableView->currentIndex().column());
            ui->tableView->setCurrentIndex(m);
            on_tableView_clicked(m);
    }

}
