

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <src/eksponatmuzealnymodel.h>
#include <src/muzeumkontener.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MuzeumKontener az = MuzeumKontener();
    MKontener* t = az.GetInstance();

    EksponatMuzealnyModel* b = t->at(0);
    ui->lineEdit->setText(b->a.c_str());
}

MainWindow::~MainWindow()
{
    delete ui;
}
