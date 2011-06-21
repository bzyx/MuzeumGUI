

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "eksponatmodel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void seDisabledIfEmpty();

private slots:
    void on_comboBox_wyborTypu_currentIndexChanged(int index);
    void setVisiblePanelDodawania();
    void setVisiblePanelSzczegoly();
    //void setDodawanieEnabled(bool b);

//    void on_dod_cb_typ_currentIndexChanged(int index);

private:
    void setCzyMoznaDodawac(bool b);
    Ui::MainWindow *ui;
    EksponatModel* model;
   // bool czyMoznaDodawac;
};

#endif // MAINWINDOW_H
