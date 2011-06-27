

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QTextCodec>
#include <QDebug>
#include <QRegExpValidator>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QMessageBox>
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
    tytul = "Muzemum - baza danych";
    setWindowTitle(tytul);
    ui->setupUi(this);
    connect(ui->actionPoka_panel_dodawania,SIGNAL(triggered()),this,SLOT(setVisiblePanelDodawania()));
    connect(ui->actionPoka_szczeg_y,SIGNAL(triggered()),this,SLOT(setVisiblePanelSzczegoly()));
    connect(ui->dod_b_dod,SIGNAL(clicked()),this,SLOT(checkDodajFields()));

    ui->actionPoka_panel_dodawania->trigger();
    ui->actionPoka_szczeg_y->trigger();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    setDodawanieEnabled(false);

    setMetaToComboBox(ui->top_cb_wysTyp,true);
    setMetaToComboBox(ui->dod_cb_typ);

    ui->sz_l_dp1->hide();
    ui->sz_l_dp2->hide();
    ui->sz_l_dp3->hide();
    ui->sz_dp1->hide();
    ui->sz_dp2->hide();
    ui->sz_dp3->hide();

    ui->top_cb_wysTyp->setEnabled(false);
    ust = new QSettings("settings.ini", QSettings::IniFormat);
    readSettings(ust);
    Material::getInstance().readFromFile(ust);

    //MaterialModel* matModel;
    matModel = new MaterialModel(this);
    ui->dod_dp2_cb->setModel(matModel);
    ui->ed_dp2_cb->setModel(matModel);


    //    Tworzenie validator�w do opcjonalnych p�l
    QRegExp rx("[1-9]\\d{0,3}"); // 0..9999
    v_dp3a = new QRegExpValidator(rx, 0);
    v_dp3 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp1 = new QDoubleValidator(0.00,30.00,2,this);
    v_dp2 = new QDoubleValidator(0.00,30.00,2,this);

    ui->dod_fDat->addItem("Wiek (w)",Meta::w);
    ui->dod_fDat->addItem("Rok (rrrr)",Meta::r);
    ui->dod_fDat->addItem("Miesi�c i rok (mm.rrrr)",Meta::mr);
    ui->dod_fDat->addItem("Dzie�,miesi��,rok (dd.mm.rrrr)",Meta::dmr);

    ui->ed_cb_fDat->addItem("Wiek (w)",Meta::w);
    ui->ed_cb_fDat->addItem("Rok (rrrr)",Meta::r);
    ui->ed_cb_fDat->addItem("Miesi�c i rok (mm.rrrr)",Meta::mr);
    ui->ed_cb_fDat->addItem("Dzie�,miesi��,rok (dd.mm.rrrr)",Meta::dmr);

    MKTyp::getInstance().updateMKTyp();
    model = new EksponatModel(Meta::NieOkreslonoTypu,parent);
    ui->tableView->setModel(model);
    model->czyMoznaZmieniac(true);

    ui->dod_id->setText(QString::number(EksponatMuzealny::getLastId()));


    setDisabledIfEmpty();
    ui->tableView->hide();
    ui->naStart->show();
    ui->naStart2->show();
    ui->top_cb_wysTyp->hide();
    ui->top_l_wysTyp->hide();
    ui->mainToolBar->setEnabled(false);
    ui->menuEdycja->setEnabled(false);
    ui->centralWidget->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #E86600, stop: 1 #E82200);");
    //  ui->naStart->setStyleSheet("margin: 0 1px 0 1px;color: white;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #2198c0, stop: 1 #0d5ca6);");
    ui->naStart->setStyleSheet("margin: 0 1px 0 1px;color: white;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BF3F0A, stop: 1 #7F2A07);");
    ui->naStart2->setStyleSheet("margin: 0 1px 0 1px;color: white;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BF3F0A, stop: 1 #7F2A07);");
    if(!lastFileName.isEmpty()){
        ui->naStar_ostPlik->setStyleSheet("margin: 0 1px 0 1px;color: white;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #BF3F0A, stop: 1 #7F2A07);");
        ui->naStar_ostPlik->setText(ui->naStar_ostPlik->text().append("\n").append(lastFileName));
        ui->naStar_ostPlik->show();
    } else {
        ui->naStar_ostPlik->hide();
    }
    ui->actionZapis->setEnabled(false);
    ui->actionZapisz_jako->setEnabled(false);
}
void MainWindow::setDisabledIfEmpty(){
    if (model->isEmpty()){
        ui->tableView->reset();
        ui->tableView->setEnabled(false);
        ui->statusBar->showMessage("Brak danych do wy�wietlenia.",1000);
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
    delete ust;
}


void MainWindow::on_top_cb_wysTyp_currentIndexChanged(int index)
{
    if(ui->top_cb_wysTyp->itemText(0)=="")
        ui->top_cb_wysTyp->removeItem(0);
    Meta::Typ nowyTyp = static_cast<Meta::Typ> (ui->top_cb_wysTyp->itemData(index).toInt());
    model->setNewTyp(nowyTyp);
    setDisabledIfEmpty();
}

void  MainWindow::setVisiblePanelDodawania(){
    if(ui->panelDodawania->isHidden()){
        ui->actionPoka_panel_dodawania->setText("Ukryj panel dodawania");
        ui->panelDodawania->setCurrentIndex(0);
        ui->panelDodawania->show();
    } else {
        ui->actionPoka_panel_dodawania->setText("Poka� panel dodawania");
        ui->panelDodawania->hide();
    }
}

void  MainWindow::setVisiblePanelSzczegoly(){
    if(ui->panelSzczegolow->isHidden()){
        ui->actionPoka_szczeg_y->setText("Ukryj panel szczeg��w");
        ui->panelSzczegolow->show();
        on_tableView_clicked(QModelIndex());
    } else {
        ui->actionPoka_szczeg_y->setText("Poka� panel szczeg��w");
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
    cb->addItem("Przedmiot U�ytkowy",Meta::PrzedmiotUzytkowy);
    cb->addItem("R�kopis",Meta::Rekopis);
    cb->addItem("Rze�ba",Meta::Rzezba);
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
        ui->dod_l_dp2->setToolTip("Materia� z jakiego wykonano mebel.");
        ui->dod_l_dp3->hide(); ui->dod_dp3->hide();
        break; }
    case Meta::Obraz: {
        ui->dod_dp1->setValidator(v_dp1);
        ui->dod_dp2->setValidator(v_dp2);
        ui->dod_l_dp1->setText("Wysoko��"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Wysoko�� obrazu.");
        ui->dod_l_dp2->setText("Szeroko��"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
        ui->dod_l_dp2->setToolTip("Szeroko�� obrazu.");
        ui->dod_l_dp3->setText("Autor"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
        ui->dod_l_dp3->setToolTip("Autor obrazu.");
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::PrzedmiotUzytkowy: {
        ui->dod_l_dp1->setText("Opis dzia�ania"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Kr�tki opis co robi ten przedmiot.");
        ui->dod_l_dp2->setText("Czy mo�na dotkn��"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_l_dp2->setToolTip("Czy zwiedzaj�cy mog� go dotkn��.");
        ui->dod_dp2gb->show(); ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
        ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::Rekopis: {
        ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Autor r�kopisu.");
        ui->dod_l_dp2->setText("Czy jest zeskanowany"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_l_dp2->setToolTip("Czy r�kopis jest zeskanownay.");
        ui->dod_dp2gb->show(); ui->dod_dp2_T->show(); ui->dod_dp2_N->show();
        ui->dod_l_dp3->hide();  ui->dod_dp3->hide();
        ui->dod_dp2_cb->hide();
        break;}
    case Meta::Rzezba: {
        ui->dod_dp3->setValidator(v_dp3);
        ui->dod_l_dp1->setText("Posta�"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Opis/nazwa przedstawianej postaci.");
        ui->dod_l_dp2->setText("Materia�"); ui->dod_l_dp2->show();  ui->dod_dp2->hide();
        ui->dod_dp2_cb->show();
        ui->dod_l_dp1->setToolTip("Materia� z jakiego wykonano rze�b�.");
        ui->dod_l_dp3->setText("Powierzchnia"); ui->dod_l_dp3->show(); ui->dod_dp3->show();
        ui->dod_l_dp1->setToolTip("Powierzchnia jak� zajmuje rze�ba.");
        ui->dod_dp2gb->hide(); ui->dod_dp2_T->hide(); ui->dod_dp2_N->hide();
        break;}
    case Meta::Starodruk: {
        ui->dod_dp3->setValidator(v_dp3a);
        ui->dod_l_dp1->setText("Autor"); ui->dod_l_dp1->show();  ui->dod_dp1->show();
        ui->dod_l_dp1->setToolTip("Autor starodruku.");
        ui->dod_l_dp2->setText("Streszczenie"); ui->dod_l_dp2->show();  ui->dod_dp2->show();
        ui->dod_l_dp1->setToolTip("Kr�tkie streszczenie starodruku.");
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
        ui->dod_nazwa->setToolTip("Nale�y poda� nazw� obiektu.");
        ui->dod_nazwa->clear();
    } else if(!ui->dod_nazwa->text().simplified().isEmpty()){
        ui->dod_l_nazwa->setStyleSheet("");
        ui->dod_nazwa->setToolTip("");
    }

    if(ui->dod_pol->text().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_polozenie->setStyleSheet("QLabel { color : red; }");
        ui->dod_pol->setToolTip("Nale�y poda� po�o�enie obiektu.");
        ui->dod_pol->clear();
    } else if(!ui->dod_pol->text().simplified().isEmpty()){
        ui->dod_l_polozenie->setStyleSheet("");
        ui->dod_pol->setToolTip("");
    }

    if(ui->dod_dat->text().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_data->setStyleSheet("QLabel { color : red; }");
        ui->dod_dat->setToolTip("Nale�y poda� dat� w wybranym formacie");
        ui->dod_dat->clear();
    } else if(!ui->dod_dat->text().simplified().isEmpty()){
        ui->dod_l_data->setStyleSheet("");
        ui->dod_dat->setToolTip("");
    }

    if(ui->dod_opis->toPlainText().simplified().isEmpty()){
        retunValue = false;
        ui->dod_l_opis->setStyleSheet("QLabel { color : red; }");
        ui->dod_opis->setToolTip("Nale�y poda� opis obiektu");
        ui->dod_opis->clear();
    } else if(!ui->dod_opis->toPlainText().simplified().isEmpty()){
        ui->dod_l_opis->setStyleSheet("");
        ui->dod_opis->setToolTip("");
    }

    if (!(ui->dod_wysN->isChecked() || ui->dod_wysT->isChecked())){
        retunValue = false;
        ui->dod_l_wyst->setStyleSheet("QLabel { color : red; }");
        ui->dod_l_wyst->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
        ui->dod_wysN->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
        ui->dod_wysT->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
    } else if (ui->dod_wysN->isChecked() || ui->dod_wysT->isChecked()){
        ui->dod_l_wyst->setStyleSheet("");
        ui->dod_wysN->setToolTip("");
        ui->dod_wysT->setToolTip("");
    }
    if(!ui->dod_dp1->isHidden()){
        if(ui->dod_dp1->text().simplified().isEmpty()){
            retunValue = false;
            ui->dod_l_dp1->setStyleSheet("QLabel { color : red; }");
            ui->dod_dp1->setToolTip("Nale�y wype�ni� te pole.");
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
            ui->dod_dp2->setToolTip("Nale�y wype�ni� te pole.");
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
            ui->dod_dp3->setToolTip("Nale�y wype�ni� te pole.");
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
    default: break;
    }
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
        //MKTyp::getInstance().updateMKTyp();
        model->makeReset();
        setDisabledIfEmpty();
    } else if(!checkDodajFields()) {
        ui->statusBar->showMessage("Niekt�re pola s� nieuzupe�nione lub zaieraj� b��dy",700);
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
                ui->sz_dp2->setText(Material::nazwaForMatV(m->getMaterial()));
                break; }
            case Meta::Obraz: {
                ui->sz_l_dp1->show();
                ui->sz_l_dp2->show();
                ui->sz_l_dp3->show();
                ui->sz_dp1->show();
                ui->sz_dp2->show();
                ui->sz_dp3->show();
                ui->sz_l_dp1->setText("Wysoko��");
                ui->sz_l_dp2->setText("Szeroko��");
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
                ui->sz_l_dp1->setText("Opis dzia�ania");
                ui->sz_l_dp2->setText("Czy mo�na dotkn��");
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
                ui->sz_l_dp1->setText("Posta�");
                ui->sz_l_dp2->setText("Materia�");
                ui->sz_l_dp3->setText("Powierzchnia");
                ERzezba* m = dynamic_cast<ERzezba*> (element);
                ui->sz_dp1->setText(m->getPostac().c_str());
                ui->sz_dp2->setText(Material::nazwaForMatV(m->getMaterial()));
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

void MainWindow::on_actionOtw_rz_triggered()
{
    fileName = QFileDialog::getOpenFileName(this,"Nazwa pliku z baz�",lastFileName,"Pliki XML (*.xml)");
    if(!fileName.isEmpty()){
        MK::getInstance().readFromFile(fileName.toStdString());
        if (MK::getInstance().count()>0)
            actionsAfterOpen();
    }

}

void MainWindow::actionsAfterOpen(){
    QString tytulOkna = tytul;
    tytulOkna += " - ";
    tytulOkna += fileName;
    lastFileName = fileName;
    setWindowTitle(tytulOkna);
    ui->centralWidget->setStyleSheet("");
    ui->naStart->setStyleSheet("");
    ui->naStart2->setStyleSheet("");
    ui->naStar_ostPlik->setStyleSheet("");
    MKTyp::getInstance().updateMKTyp();
    on_top_cb_wysTyp_currentIndexChanged(0);

    ui->top_cb_wysTyp->show();
    ui->top_l_wysTyp->show();
    ui->mainToolBar->setEnabled(true);
    ui->menuEdycja->setEnabled(true);


    ui->tableView->show();
    ui->naStart->hide();
    ui->naStart2->hide();
    ui->naStar_ostPlik->hide();
    ui->top_cb_wysTyp->setEnabled(true);

    ui->actionZapis->setEnabled(true);
    ui->actionZapisz_jako->setEnabled(true);
}

void MainWindow::saveSettings(QSettings* file){
    file->beginWriteArray("Settings");
    file->setArrayIndex(1);
    file->setValue("X",geometry().x() );
    file->setValue("Y",geometry().y());
    file->setArrayIndex(2);
    file->setValue("W",geometry().width());
    file->setValue("H",geometry().height());
    file->setArrayIndex(3);
    file->setValue("LastFIleName",lastFileName);
    file->endArray();

}
void MainWindow::readSettings(QSettings* file){
    QDesktopWidget *desktop = QApplication::desktop();
    int size = file->beginReadArray("Settings");
    bool popr;
    QRect r = geometry();
    int wart;
    if (size == 4){}
    file->setArrayIndex(1);
    wart = file->value("X").toString().toInt(&popr);
    if(popr)
        r.setX(wart);
    else
        r.setX((desktop->width()-800)/2);
    popr = false;
    wart = file->value("Y").toString().toInt(&popr);
    if(popr)
        r.setY(wart);
    else
        r.setY((desktop->height()-550)/2);

    file->setArrayIndex(2);
    popr = false;
    wart = file->value("W").toString().toInt(&popr);
    if(popr)
        r.setWidth(wart);
    else
        r.setWidth(800);

    popr = false;
    wart = file->value("H").toString().toInt(&popr);
    if(popr)
        r.setHeight(wart);
    else
        r.setHeight(550);

    file->setArrayIndex(3);
    QString lfile = file->value("LastFIleName").toString();
    if (!lfile.isEmpty())
        lastFileName = lfile;
    else
        lastFileName = QString();

    setGeometry(r);
    //int value = file->value("MaterialId").toInt();
    file->endArray();
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    saveFileName = QFileDialog::getSaveFileName(this,"Zapisz jako",QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation),"Pliki XML (*.xml)");
    if (!saveFileName.isEmpty()){
        MK::getInstance().saveToFile(saveFileName.toStdString());
        lastFileName = saveFileName;
        QString tmp = tytul;
        tmp += " - ";
        tmp += saveFileName;
        lastFileName = saveFileName;
        setWindowTitle(tmp);
        ui->statusBar->showMessage("Plik zosta� zapisany",800);
    } else {
        ui->statusBar->showMessage("Plik nie zosta� zapisany",1000);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (OKToClose()) {
        Material::getInstance().saveToFile(ust);
        saveSettings(ust);
        event->accept();
    } else {
        event->ignore();
    }
}

bool MainWindow::OKToClose()
{
    QMessageBox ostrz;
    ostrz.setWindowTitle("Muzemum - baza danych");
    ostrz.setIcon(QMessageBox::Warning);
    ostrz.setText("Czy napewno chcesz wyj�� z programu? \nJe�li baza nie zosta�a zapisana spowoduje to jej utracenie.");
    ostrz.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    ostrz.setDefaultButton(QMessageBox::Yes);
    ostrz.setEscapeButton(QMessageBox::Cancel);
    ostrz.button(QMessageBox::Yes)->setText("Tak");
    ostrz.button(QMessageBox::No)->setText("Nie");
    ostrz.button(QMessageBox::Cancel)->setText("Anuluj");
    int ret = ostrz.exec();
    if (ret == QMessageBox::Yes)
        return true;
    else if (ret == QMessageBox::Cancel)
        return false;

    return false;
}

void MainWindow::on_actionZamknij_triggered()
{
    close();
}

void MainWindow::on_actionZapis_triggered()
{
    if(!saveFileName.isEmpty()){
        MK::getInstance().saveToFile(saveFileName.toStdString());
        QString tmp = tytul;
        tmp += " - ";
        tmp += saveFileName;
        lastFileName = saveFileName;
        setWindowTitle(tmp);
        ui->statusBar->showMessage("Plik zosta� zapisany",800);
    } else {
        on_actionZapisz_jako_triggered();
    }
}

void MainWindow::on_actionNowa_baza_triggered()
{
    saveFileName = QFileDialog::getSaveFileName(this,"Utw�rz now� baz�",QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation),"Pliki XML (*.xml)");
    if (!saveFileName.isEmpty()){
        MK::getInstance().saveToFile(saveFileName.toStdString());
        QString tmp = tytul;
        tmp += " - ";
        tmp += saveFileName;
        lastFileName = saveFileName;
        setWindowTitle(tmp);
        ui->statusBar->showMessage("Plik zosta� utworzony",800);
    } else {
        ui->statusBar->showMessage("Plik nie zosta� utworzony",1000);
    }
}

void MainWindow::on_naStar_ostPlik_clicked()
{
    QDir file(lastFileName);
    if (!file.exists()){
        MK::getInstance().readFromFile(lastFileName.toStdString());
        if (MK::getInstance().count()>0){
            //QString tmp = tytul;
            // tmp += " - ";
            //tmp += lastFileName;
            fileName = lastFileName;
            saveFileName = lastFileName;
            //setWindowTitle(tmp);

            //            for (unsigned int i=0; i< 50; ++i){

            //                MK::getInstance().addItem(new EObraz(4,12.5,"Picaaaasso","abubat",
            //                                                     1,"Bardaaa"
            //                                                     ,"Magazyn2", 100,
            //                                                     Meta::Obraz,
            //                                                     Meta::w,
            //                                                     "XXI"));

            //            }

            actionsAfterOpen();
            ui->statusBar->showMessage("Plik zosta� wczytany",800);
        }
    } else {
        ui->statusBar->showMessage("Plik nie istnieje",1000);
    }
}

void MainWindow::on_naStart_clicked()
{
    on_actionOtw_rz_triggered();
}

void MainWindow::on_naStart2_clicked()
{
    on_actionNowa_baza_triggered();
}

void MainWindow::on_actionDodaj_triggered()
{
    if(!ui->panelDodawania->isVisible())
        ui->actionPoka_panel_dodawania->trigger();
    ui->panelDodawania->setCurrentIndex(0);
}

void MainWindow::on_actionEdytuj_triggered()
{
    QModelIndex index = ui->tableView->currentIndex();
    if(index.row() != -1){
        on_tableView_doubleClicked(index);
    } else {
        QMessageBox::warning(this,"Muzeum - baza danych","Nale�y zaznaczy� element do edycji.",QMessageBox::Ok);
    }
    //    if(!ui->panelDodawania->isVisible())
    //        ui->actionPoka_panel_dodawania->trigger();
    //    ui->panelDodawania->setCurrentIndex(1);
}

void MainWindow::on_actionO_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionO_programie_triggered()
{
    QMessageBox::about(this,
                       "O programie...",
                       QString(
                           "<p>Muzeum - baza danych</p>"
                           "<p align=\"right\"> <br><i>Marcin Jabrzyk</i><br><b>Programowanie Komputer�w 4</b><br>Informatyka sem. 4 gr. R<br> <br>2011 </p>")
                       );
}

void MainWindow::on_actionDodaj_materia_triggered()
{
    MaterialDialog dialog;
    dialog.exec();
    delete matModel;
    matModel = new MaterialModel(this);
    ui->dod_dp2_cb->setModel(matModel);
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    if(model->getCurrentTyp()!= Meta::NieOkreslonoTypu){
        QMessageBox::information(this,"Muzeum - baza danych","Mo�liwo�� edycji jest dost�pna w trybie widoku wszystkich element�w",QMessageBox::Ok);
    }else {
    Meta::Typ typObiektu = MK::getInstance()[index.row()]->getTyp();
    currentEditing = index.row();
    if(!ui->panelDodawania->isVisible())
        ui->actionPoka_panel_dodawania->trigger();
    ui->panelDodawania->setCurrentIndex(1);
    int id= ui->tableView->model()->data(index,Qt::UserRole).toInt();
    ui->ed_id->setText(QString::number(id));
    ui->ed_typ->setText(Meta::nazwaTypu(MK::getInstance()[index.row()]->getTyp()).c_str());
    ui->ed_nazwa->setText(MK::getInstance()[index.row()]->getNazwa().c_str());
    ui->ed_wys_T->setChecked(MK::getInstance()[index.row()]->getWystawiony());
    ui->ed_wys_N->setChecked(!MK::getInstance()[index.row()]->getWystawiony());
    ui->ed_pol->setText(MK::getInstance()[index.row()]->getPolozenie().c_str());
    ui->ed_wart->setValue(MK::getInstance()[index.row()]->getWartosc());
    Meta::FormatDaty fd = MK::getInstance()[index.row()]->getFormatDaty();
    int inx = 0;
    switch (fd){
    case Meta::w: inx = 0; break;
    case Meta::r: inx = 1; break;
    case Meta::mr: inx = 2; break;
    case Meta::dmr: inx = 3; break;
    default: inx = 0;
    }
    ui->ed_cb_fDat->setCurrentIndex(inx);
    ui->ed_dat->setText(MK::getInstance()[index.row()]->getData().c_str());
    ui->ed_opi->setPlainText(MK::getInstance()[index.row()]->getOpis().c_str());

    ui->dod_dp1->setValidator(0);
    ui->dod_dp2->setValidator(0);
    ui->dod_dp3->setValidator(0);

    switch (typObiektu){
    case Meta::Mebel: {
        EMebel* m = dynamic_cast<EMebel*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Rodzaj");  ui->ed_l_dp1->show();
        ui->ed_dp1->setText(m->getRodzaj().c_str());  ui->ed_dp1->show();
        ui->ed_l_dp2->setText("Materia�");ui->ed_l_dp2->show();
        ui->ed_dp2->hide();
        ui->ed_dp2_N->hide();
        ui->ed_dp2_T->hide();
        ui->ed_dp2_gb->hide();
        ui->ed_dp2_cb->setCurrentIndex(m->getMaterial()); ui->ed_dp2_cb->show();
        ui->ed_l_dp3->hide();
        ui->ed_dp3->hide();
        break;}
    case Meta::Obraz: {
        EObraz* m = dynamic_cast<EObraz*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Wysoko��"); ui->ed_l_dp1->show();
        ui->ed_dp1->setText(QString::number(m->getWysokosc())); ui->ed_dp1->show();
        ui->ed_dp1->setValidator(v_dp1);
        ui->ed_l_dp2->setText("Szeroko��"); ui->ed_l_dp2->show();
        ui->ed_dp2->setText(QString::number(m->getSzerokosc())); ui->ed_dp2->show();
        ui->ed_dp2->setValidator(v_dp2);
        ui->ed_dp2_N->hide();
        ui->ed_dp2_T->hide();
        ui->ed_dp2_gb->hide();
        ui->ed_dp2_cb->hide();
        ui->ed_l_dp3->setText("Autor"); ui->ed_l_dp3->show();
        ui->ed_dp3->setText(m->getAutor().c_str()); ui->ed_dp3->show();
        break;}
    case Meta::PrzedmiotUzytkowy: {
        EPrzemiotUzytkowy* m = dynamic_cast<EPrzemiotUzytkowy*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Opis dzia�ania");ui->ed_l_dp1->show();
        ui->ed_dp1->setText(m->getOpisDzialania().c_str());ui->ed_dp1->show();
        ui->ed_l_dp2->setText("Czy mo�na dotkn��");ui->ed_l_dp2->show();
        ui->ed_dp2->hide();
        ui->ed_dp2_N->setChecked(!m->getCzyMoznaDotykac());ui->ed_dp2_N->show();
        ui->ed_dp2_T->setChecked(m->getCzyMoznaDotykac());ui->ed_dp2_T->show();
        ui->ed_dp2_gb->show();
        ui->ed_dp2_cb->hide();
        ui->ed_l_dp3->hide();
        ui->ed_dp3->hide();
        break;}
    case Meta::Rekopis: {
        ERekopis* m = dynamic_cast<ERekopis*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Autor");ui->ed_l_dp1->show();
        ui->ed_dp1->setText(m->getAutor().c_str());ui->ed_dp1->show();
        ui->ed_l_dp2->setText("Czy jest zeskanowany");ui->ed_l_dp2->show();
        ui->ed_dp2->hide();
        ui->ed_dp2_N->setChecked(!m->getCzyZeskanowany());ui->ed_dp2_N->show();
        ui->ed_dp2_T->setChecked(m->getCzyZeskanowany());ui->ed_dp2_T->show();
        ui->ed_dp2_gb->show();
        ui->ed_dp2_cb->hide();
        ui->ed_l_dp3->hide();
        ui->ed_dp3->hide();
        break;}
    case Meta::Rzezba: {
        ERzezba* m = dynamic_cast<ERzezba*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Posta�");  ui->ed_l_dp1->show();
        ui->ed_dp1->setText(m->getPostac().c_str());  ui->ed_dp1->show();
        ui->ed_l_dp2->setText("Materia�");ui->ed_l_dp2->show();
        ui->ed_dp2->hide();
        ui->ed_dp2_N->hide();
        ui->ed_dp2_T->hide();
        ui->ed_dp2_gb->hide();
        ui->ed_dp2_cb->setCurrentIndex(m->getMaterial()); ui->ed_dp2_cb->show();
        ui->ed_l_dp3->setText("Powierzchnia"); ui->ed_l_dp3->show();
        ui->ed_dp3->setText(QString::number(m->getPowierzchnia())); ui->ed_dp3->show();
        ui->ed_dp3->setValidator(v_dp3);

        break;}
    case Meta::Starodruk:{
        EStarodruk* m = dynamic_cast<EStarodruk*>(MK::getInstance()[index.row()]);
        ui->ed_l_dp1->setText("Autor");  ui->ed_l_dp1->show();
        ui->ed_dp1->setText(m->getAutor().c_str());  ui->ed_dp1->show();
        ui->ed_l_dp2->setText("Streszczenie");ui->ed_l_dp2->show();
        ui->ed_dp2->setText(m->getStreszczenie().c_str()); ui->ed_dp2->show();
        ui->ed_dp2_N->hide();
        ui->ed_dp2_T->hide();
        ui->ed_dp2_gb->hide();
        ui->ed_dp2_cb->hide();
        ui->ed_l_dp3->setText("Liczba Stron"); ui->ed_l_dp3->show();
        ui->ed_dp3->setText(QString::number(m->getLiczbaStron())); ui->ed_dp3->show();
        ui->ed_dp3->setValidator(v_dp3a);
        break;}
    default: {
        ui->ed_l_dp1->hide();
        ui->ed_dp1->hide();
        ui->ed_l_dp2->hide();
        ui->ed_dp2->hide();
        ui->ed_dp2_N->hide();
        ui->ed_dp2_T->hide();
        ui->ed_dp2_gb->hide();
        ui->ed_dp2_cb->hide();
        ui->ed_l_dp3->hide();
        ui->ed_dp3->hide();
        break;}
    }
}


}
void MainWindow::on_actionUsu_triggered(){
    QModelIndex index = ui->tableView->currentIndex();
    if(index.row() != -1){
        int i= ui->tableView->model()->data(index,Qt::UserRole).toInt();
        MK::getInstance().deleteItem(i);
        //    delete model;
        //    model = new EksponatModel(Meta::NieOkreslonoTypu,this->parent());
        //    ui->tableView->setModel(model);
        //    model->czyMoznaZmieniac(true);
        //    MKTyp::getInstance().updateMKTyp();
        model->makeReset();
        setDisabledIfEmpty();
        ui->tableView->reset();
        setDisabledIfEmpty();
    } else{
        QMessageBox::warning(this,"Muzeum - baza danych","Nale�y zaznaczy� element do usunini�cia.",QMessageBox::Ok);
    }
}

void MainWindow::on_ed_cb_fDat_currentIndexChanged(int index)
{
    Meta::FormatDaty fd = static_cast<Meta::FormatDaty> (ui->ed_cb_fDat->itemData(index).toInt());
    QRegExp wiek("[I,V,X,L]{1,3}");
    QRegExp rok("[0-2][0-9]{3}");
    QRegExp mr("^((0[1-9])|(1[0-2]))[.][0-2][0-9]{3}");
    QRegExp dmr("(0[1-9]|[12][0-9]|3[01])[.](0[1-9]|1[012])[.][0-2][0-9]{3}");
    switch (fd) {
    case Meta::w: ui->ed_dat->setValidator(new QRegExpValidator(wiek,this)); break;
    case Meta::r : ui->ed_dat->setValidator(new QRegExpValidator(rok,this));  break;
    case Meta::mr : ui->ed_dat->setValidator(new QRegExpValidator(mr,this));  break;
    case Meta::dmr : ui->ed_dat->setValidator(new QRegExpValidator(dmr,this)); break;
    default: break;
    }
}

void MainWindow::on_ed_anuluj_clicked()
{
    ui->ed_id->clear();
    ui->ed_typ->clear();
    ui->ed_nazwa->clear();
    ui->ed_wys_T->setChecked(false);
    ui->ed_wys_N->setChecked(true);
    ui->ed_pol->clear();
    ui->ed_wart->clear();
    ui->ed_dat->clear();
    ui->ed_opi->clear();
    ui->ed_cb_fDat->setCurrentIndex(0);

    ui->ed_l_dp1->hide();
    ui->ed_dp1->hide();
    ui->ed_l_dp2->hide();
    ui->ed_dp2->hide();
    ui->ed_dp2_N->hide();
    ui->ed_dp2_T->hide();
    ui->ed_dp2_gb->hide();
    ui->ed_dp2_cb->hide();
    ui->ed_l_dp3->hide();
    ui->ed_dp3->hide();

    ui->ed_l_nazwa->setStyleSheet("");
    ui->ed_nazwa->setToolTip("");
    ui->ed_l_pol->setStyleSheet("");
    ui->ed_pol->setToolTip("");
    ui->ed_l_dat->setStyleSheet("");
    ui->ed_dat->setToolTip("");
    ui->ed_l_opis->setStyleSheet("");
    ui->ed_opi->setToolTip("");
    ui->ed_l_wyst->setStyleSheet("");
    ui->ed_wys_N->setToolTip("");
    ui->ed_wys_T->setToolTip("");
    ui->ed_l_dp1->setStyleSheet("");
    ui->ed_dp1->setToolTip("");
    ui->ed_l_dp2->setStyleSheet("");
    ui->ed_dp2->setToolTip("");
    ui->ed_l_dp3->setStyleSheet("");
    ui->ed_dp3->setToolTip("");
}
bool MainWindow::checkEdytujFields(){
    bool retunValue = true;
    if(ui->ed_nazwa->text().simplified().isEmpty()){
        retunValue = false;
        ui->ed_l_nazwa->setStyleSheet("QLabel { color : red; }");
        ui->ed_nazwa->setToolTip("Nale�y poda� nazw� obiektu.");
        ui->ed_nazwa->clear();
    } else if(!ui->ed_nazwa->text().simplified().isEmpty()){
        ui->ed_l_nazwa->setStyleSheet("");
        ui->ed_nazwa->setToolTip("");
    }

    if(ui->ed_pol->text().simplified().isEmpty()){
        retunValue = false;
        ui->ed_l_pol->setStyleSheet("QLabel { color : red; }");
        ui->ed_pol->setToolTip("Nale�y poda� po�o�enie obiektu.");
        ui->ed_pol->clear();
    } else if(!ui->ed_pol->text().simplified().isEmpty()){
        ui->ed_l_pol->setStyleSheet("");
        ui->ed_pol->setToolTip("");
    }

    if(ui->ed_dat->text().simplified().isEmpty()){
        retunValue = false;
        ui->ed_l_dat->setStyleSheet("QLabel { color : red; }");
        ui->ed_dat->setToolTip("Nale�y poda� dat� w wybranym formacie");
        ui->ed_dat->clear();
    } else if(!ui->ed_dat->text().simplified().isEmpty()){
        ui->ed_l_dat->setStyleSheet("");
        ui->ed_dat->setToolTip("");
    }

    if(ui->ed_opi->toPlainText().simplified().isEmpty()){
        retunValue = false;
        ui->ed_l_opis->setStyleSheet("QLabel { color : red; }");
        ui->ed_opi->setToolTip("Nale�y poda� opis obiektu");
        ui->ed_opi->clear();
    } else if(!ui->ed_opi->toPlainText().simplified().isEmpty()){
        ui->ed_l_opis->setStyleSheet("");
        ui->ed_opi->setToolTip("");
    }

    if (!(ui->ed_wys_N->isChecked() || ui->ed_wys_T->isChecked())){
        retunValue = false;
        ui->ed_l_wyst->setStyleSheet("QLabel { color : red; }");
        ui->ed_l_wyst->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
        ui->ed_wys_N->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
        ui->ed_wys_T->setToolTip("Nale�y wybra� czy eksponat ma by� wystawiony.");
    } else if (ui->ed_wys_N->isChecked() || ui->ed_wys_T->isChecked()){
        ui->ed_l_wyst->setStyleSheet("");
        ui->ed_wys_N->setToolTip("");
        ui->ed_wys_T->setToolTip("");
    }
    if(!ui->ed_dp1->isHidden()){
        if(ui->ed_dp1->text().simplified().isEmpty()){
            retunValue = false;
            ui->ed_l_dp1->setStyleSheet("QLabel { color : red; }");
            ui->ed_dp1->setToolTip("Nale�y wype�ni� te pole.");
            ui->ed_dp1->clear();
        } else if(!ui->ed_dp1->text().simplified().isEmpty()){
            ui->ed_l_dp1->setStyleSheet("");
            ui->ed_dp1->setToolTip("");
        }
    }

    if(!ui->ed_dp2->isHidden()){
        if(ui->ed_dp2->text().simplified().isEmpty()){
            retunValue = false;
            ui->ed_l_dp2->setStyleSheet("QLabel { color : red; }");
            ui->ed_dp2->setToolTip("Nale�y wype�ni� te pole.");
            ui->ed_dp2->clear();
        } else if(!ui->ed_dp2->text().simplified().isEmpty()){
            ui->ed_l_dp2->setStyleSheet("");
            ui->ed_dp2->setToolTip("");
        }
    }

    if(!ui->ed_dp3->isHidden()){
        if(ui->ed_dp3->text().simplified().isEmpty()){
            retunValue = false;
            ui->ed_l_dp3->setStyleSheet("QLabel { color : red; }");
            ui->ed_dp3->setToolTip("Nale�y wype�ni� te pole.");
            ui->ed_dp3->clear();
        } else if(!ui->ed_dp3->text().simplified().isEmpty()){
            ui->ed_l_dp3->setStyleSheet("");
            ui->ed_dp3->setToolTip("");
        }
    }
    return retunValue;
}

void MainWindow::on_ed_zapisz_clicked()
{
    if(currentEditing!=-1){
    if(checkEdytujFields()){
    Meta::Typ typObiektu = MK::getInstance()[currentEditing]->getTyp();
    MK::getInstance()[currentEditing]->nazwa(ui->ed_nazwa->text().simplified().toStdString());
    MK::getInstance()[currentEditing]->wystawiony(ui->ed_wys_T->isChecked());
    MK::getInstance()[currentEditing]->polozenie(ui->ed_pol->text().simplified().toStdString());
    MK::getInstance()[currentEditing]->wartosc(ui->ed_wart->value());
    Meta::FormatDaty fd = static_cast<Meta::FormatDaty> (ui->ed_cb_fDat->itemData(ui->ed_cb_fDat->currentIndex()).toInt());
    MK::getInstance()[currentEditing]->formatDaty(fd);
    MK::getInstance()[currentEditing]->data(ui->ed_dat->text().simplified().toStdString());
    MK::getInstance()[currentEditing]->opis(ui->ed_opi->toPlainText().simplified().toStdString());

    switch (typObiektu){
    case Meta::Mebel: {
        EMebel* m = dynamic_cast<EMebel*>(MK::getInstance()[currentEditing]);
        m->rodzaj(ui->ed_dp1->text().simplified().toStdString());
        int numMat = static_cast<int> (ui->ed_dp2_cb->itemData(ui->ed_dp2_cb->currentIndex()).toInt());
        m->material(numMat);
        break;}
    case Meta::Obraz: {
        EObraz* m = dynamic_cast<EObraz*>(MK::getInstance()[currentEditing]);
        m->wysokosc(ui->ed_dp1->text().toDouble());
        m->szerokosc(ui->ed_dp2->text().toDouble());
        m->autor(ui->ed_dp3->text().simplified().toStdString());
        break;}
    case Meta::PrzedmiotUzytkowy: {
        EPrzemiotUzytkowy* m = dynamic_cast<EPrzemiotUzytkowy*>(MK::getInstance()[currentEditing]);
        m->opisDzialania(ui->ed_dp1->text().toStdString());
        m->czyMoznaDotykac(ui->ed_dp2_T->isChecked());
        break;}
    case Meta::Rekopis: {
        ERekopis* m = dynamic_cast<ERekopis*>(MK::getInstance()[currentEditing]);
        m->autor(ui->ed_dp1->text().simplified().toStdString());
        m->czyZeskanowany(ui->ed_dp2_T->isChecked());
        break;}
    case Meta::Rzezba: {
        ERzezba* m = dynamic_cast<ERzezba*>(MK::getInstance()[currentEditing]);
        m->postac(ui->ed_dp1->text().simplified().toStdString());
        int numMat = static_cast<int> (ui->ed_dp2_cb->itemData(ui->ed_dp2_cb->currentIndex()).toInt());
        m->material(numMat);
        m->powierchnia(ui->ed_dp3->text().toDouble());
        break;}
    case Meta::Starodruk:{
        EStarodruk* m = dynamic_cast<EStarodruk*>(MK::getInstance()[currentEditing]);
        m->autor(ui->ed_dp1->text().simplified().toStdString());
        m->sterszczenie(ui->ed_dp2->text().simplified().toStdString());
        m->liczbaStron(ui->ed_dp3->text().toInt());
        break;}
    default: {
        break;}
    }

    //on_ed_anuluj_clicked();
    ui->statusBar->showMessage("Zmiany zosta�y zapisane",1000);
    }
    currentEditing =-1;
    }

}

void MainWindow::on_ed_usun_clicked()
{
    on_actionUsu_triggered();
}
