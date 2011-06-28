/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utw�r jest dost�pny na licencji
** Creative Commons
** Uznanie autorstwa-U�ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/

#include "materialdialog.h"
#include "src/material.h"
#include "ui_materialdialog.h"

#include <QMessageBox>

/*
  Tworzy dialog do dodawania nowych Materia��w
  Kt�ry jest opraty na modelu.

*/
MaterialDialog::MaterialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MaterialDialog)
{
    ui->setupUi(this);
    model = new MaterialModel(this);
    ui->listView->setModel(model);
}

MaterialDialog::~MaterialDialog()
{
    delete ui;
}

/*
  Po naci�nieciu przycisku dodaj
  nast�puje spraedzenie czy dany materia� ju� jest
  je�li by� wcze�niej zostaje wy�wietlony komunikat
  w przeciwnym wypadku zostaje dodany do kontenera
  a na widoku wykonana metoda reset()

*/
void MaterialDialog::on_pushButton_2_clicked()
{
    if (!ui->lineEdit->text().simplified().isEmpty()){
       if(Material::getInstance().valueForMatN(ui->lineEdit->text().simplified())){
           QMessageBox::warning(this,"Dodaj materia�","Nie mo�na doda� instniej�cego materia�u",QMessageBox::Ok);
       } else{
           Material::getInstance().addMaterial(ui->lineEdit->text().simplified());
           ui->listView->reset();
       }
    }
}
