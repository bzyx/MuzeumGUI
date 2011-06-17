

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
    void setVisiblePanelDodawania(bool b);
    void setVisiblePanelSzczegoly(bool);

private:
    Ui::MainWindow *ui;
    EksponatModel* model;
};

#endif // MAINWINDOW_H
