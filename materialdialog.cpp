#include "materialdialog.h"
#include "src/material.h"
#include "ui_materialdialog.h"
#include <QMessageBox>

#include <QDebug>

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
