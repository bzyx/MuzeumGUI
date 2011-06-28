/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utwór jest dostêpny na licencji
** Creative Commons
** Uznanie autorstwa-U¿ycie niekomercyjne-Na tych samych warunkach
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
  Tworzy dialog do dodawania nowych Materia³ów
  Który jest opraty na modelu.

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
  Po naciœnieciu przycisku dodaj
  nastêpuje spraedzenie czy dany materia³ ju¿ jest
  jeœli by³ wczeœniej zostaje wyœwietlony komunikat
  w przeciwnym wypadku zostaje dodany do kontenera
  a na widoku wykonana metoda reset()

*/
void MaterialDialog::on_pushButton_2_clicked()
{
    if (!ui->lineEdit->text().simplified().isEmpty()){
       if(Material::getInstance().valueForMatN(ui->lineEdit->text().simplified())){
           QMessageBox::warning(this,"Dodaj materia³","Nie mo¿na dodaæ instniej¹cego materia³u",QMessageBox::Ok);
       } else{
           Material::getInstance().addMaterial(ui->lineEdit->text().simplified());
           ui->listView->reset();
       }
    }
}
