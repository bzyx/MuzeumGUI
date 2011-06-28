

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QValidator>
#include <QSettings>
#include "eksponatmodel.h"
#include "src/materialmodel.h"
#include "materialdialog.h"

namespace Ui {
    class MainWindow;
}

/*!
 \brief

 \class MainWindow mainwindow.h "mainwindow.h"
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     \brief

     \fn MainWindow
     \param parent
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     \brief

     \fn ~MainWindow
    */
    ~MainWindow();
    /*!
     \brief

     \fn setDisabledIfEmpty
    */
    void setDisabledIfEmpty();
    MaterialModel* matModel; /*!< TODO */

private slots:
    /*!
     \brief

     \fn on_top_cb_wysTyp_currentIndexChanged
     \param index
    */
    void on_top_cb_wysTyp_currentIndexChanged(int index);
    /*!
     \brief

     \fn setVisiblePanelDodawania
    */
    void setVisiblePanelDodawania();
    /*!
     \brief

     \fn setVisiblePanelSzczegoly
    */
    void setVisiblePanelSzczegoly();
    /*!
     \brief

     \fn setDodawanieEnabled
     \param b
    */
    void setDodawanieEnabled(bool b);
    /*!
     \brief

     \fn checkDodajFields
    */
    bool checkDodajFields();
    /*!
     \brief

     \fn checkEdytujFields
    */
    bool checkEdytujFields();
    /*!
     \brief

     \fn on_dod_cb_typ_currentIndexChanged
     \param index
    */
    void on_dod_cb_typ_currentIndexChanged(int index);

    /*!
     \brief

     \fn on_dod_fDat_currentIndexChanged
     \param index
    */
    void on_dod_fDat_currentIndexChanged(int index);

    /*!
     \brief

     \fn on_dod_b_anu_clicked
    */
    void on_dod_b_anu_clicked();

    /*!
     \brief

     \fn on_dod_b_dod_clicked
    */
    void on_dod_b_dod_clicked();

    /*!
     \brief

     \fn on_tableView_clicked
     \param index
    */
    void on_tableView_clicked(const QModelIndex &index);

    /*!
     \brief

     \fn on_sz_pop_clicked
    */
    void on_sz_pop_clicked();

    /*!
     \brief

     \fn on_sz_nas_clicked
    */
    void on_sz_nas_clicked();

    /*!
     \brief

     \fn on_actionOtw_rz_triggered
    */
    void on_actionOtw_rz_triggered();
    /*!
     \brief

     \fn actionsAfterOpen
    */
    void actionsAfterOpen();

    /*!
     \brief

     \fn on_actionZapisz_jako_triggered
    */
    void on_actionZapisz_jako_triggered();

    /*!
     \brief

     \fn on_actionZamknij_triggered
    */
    void on_actionZamknij_triggered();

    /*!
     \brief

     \fn on_actionZapis_triggered
    */
    void on_actionZapis_triggered();

    /*!
     \brief

     \fn on_actionNowa_baza_triggered
    */
    void on_actionNowa_baza_triggered();

    /*!
     \brief

     \fn on_naStar_ostPlik_clicked
    */
    void on_naStar_ostPlik_clicked();

    /*!
     \brief

     \fn on_naStart_clicked
    */
    void on_naStart_clicked();

    /*!
     \brief

     \fn on_naStart2_clicked
    */
    void on_naStart2_clicked();

    /*!
     \brief

     \fn on_actionDodaj_triggered
    */
    void on_actionDodaj_triggered();

    /*!
     \brief

     \fn on_actionEdytuj_triggered
    */
    void on_actionEdytuj_triggered();

    /*!
     \brief

     \fn on_actionO_Qt_triggered
    */
    void on_actionO_Qt_triggered();

    /*!
     \brief

     \fn on_actionO_programie_triggered
    */
    void on_actionO_programie_triggered();

    /*!
     \brief

     \fn on_actionDodaj_materia_triggered
    */
    void on_actionDodaj_materia_triggered();


    /*!
     \brief

     \fn on_tableView_doubleClicked
     \param index
    */
    void on_tableView_doubleClicked(const QModelIndex &index);

    /*!
     \brief

     \fn on_actionUsu_triggered
    */
    void on_actionUsu_triggered();

    /*!
     \brief

     \fn on_ed_cb_fDat_currentIndexChanged
     \param index
    */
    void on_ed_cb_fDat_currentIndexChanged(int index);

    /*!
     \brief

     \fn on_ed_anuluj_clicked
    */
    void on_ed_anuluj_clicked();

    /*!
     \brief

     \fn on_ed_zapisz_clicked
    */
    void on_ed_zapisz_clicked();

    /*!
     \brief

     \fn on_ed_usun_clicked
    */
    void on_ed_usun_clicked();

private:
    int currentEditing; /*!< TODO */
    QString tytul; /*!< TODO */
    QSettings* ust; /*!< TODO */
    QString lastFileName; /*!< TODO */
    QString fileName; /*!< TODO */
    QString saveFileName; /*!< TODO */
    /*!
     \brief

     \fn setMetaToComboBox
     \param cb
     \param wszyskie
    */
    void setMetaToComboBox(QComboBox* cb, bool wszyskie=false);
    Ui::MainWindow *ui; /*!< TODO */
    EksponatModel* model; /*!< TODO */
    QValidator *v_dp1, *v_dp2, *v_dp3,*v_dp3a; /*!< TODO */
    /*!
     \brief

     \fn saveSettings
     \param file
    */
    void saveSettings(QSettings* file);
    /*!
     \brief

     \fn readSettings
     \param file
    */
    void readSettings(QSettings* file);
    /*!
     \brief

     \fn closeEvent
     \param event
    */
    void closeEvent(QCloseEvent *event);
    /*!
     \brief

     \fn OKToClose
    */
    bool OKToClose();
};

#endif // MAINWINDOW_H
