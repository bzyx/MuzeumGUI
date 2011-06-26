

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QValidator>
#include <QSettings>
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
    void setDisabledIfEmpty();

private slots:
    void on_top_cb_wysTyp_currentIndexChanged(int index);
    void setVisiblePanelDodawania();
    void setVisiblePanelSzczegoly();
    void setDodawanieEnabled(bool b);
    bool checkDodajFields();
    void on_dod_cb_typ_currentIndexChanged(int index);

    void on_dod_fDat_currentIndexChanged(int index);

    void on_dod_b_anu_clicked();

    void on_dod_b_dod_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_sz_pop_clicked();

    void on_sz_nas_clicked();

    void on_actionOtw_rz_triggered();
    void actionsAfterOpen();

    void on_actionZapisz_jako_triggered();

    void on_actionZamknij_triggered();

    void on_actionZapis_triggered();

    void on_actionNowa_baza_triggered();

    void on_naStar_ostPlik_clicked();

    void on_naStart_clicked();

    void on_naStart2_clicked();

private:
    QString tytul;
    QSettings* ust;
    QString lastFileName;
    QString fileName;
    QString saveFileName;
    void setMetaToComboBox(QComboBox* cb, bool wszyskie=false);
    Ui::MainWindow *ui;
    EksponatModel* model;
    QValidator *v_dp1, *v_dp2, *v_dp3,*v_dp3a;
    void saveSettings(QSettings* file);
    void readSettings(QSettings* file);
    void closeEvent(QCloseEvent *event);
    bool OKToClose();
};

#endif // MAINWINDOW_H
