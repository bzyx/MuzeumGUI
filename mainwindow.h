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
 Klasa obs�uguj�ca ca�� cz�� "okienkow�" programu. Zarz�dza oknami, przyciskami
 wywow�uje odpowiednie akcji na cz�ci "niewidocznej" programu.

 \class MainWindow mainwindow.h "mainwindow.h"
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     \brief
     Konstruktor w stylu Qt

     \fn MainWindow
     \param parent
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     \brief
     Destruktor

     \fn ~MainWindow
    */
    ~MainWindow();
    /*!
     \brief
     Funkja wy��cza widok QTableView je�li jest on pusty.

     \fn setDisabledIfEmpty
    */
    void setDisabledIfEmpty();
private slots:
    /*!
     \brief
     Wywo�ywana je�li przy ka�dej zmianie typu w polu "Wy�wietlany typ: "

     \fn on_top_cb_wysTyp_currentIndexChanged
     \param index
    */
    void on_top_cb_wysTyp_currentIndexChanged(int index);
    /*!
     \brief
     Ustawia czy panel dodawania/edycji ma by� widoczny.

     \fn setVisiblePanelDodawania
    */
    void setVisiblePanelDodawania();
    /*!
     \brief
     Ustawia czy panel szczeg��w ma by� widoczny.

     \fn setVisiblePanelSzczegoly
    */
    void setVisiblePanelSzczegoly();
    /*!
     \brief
     W��cza mo�liow�� dodawania.

     \fn setDodawanieEnabled
     \param b
    */
    void setDodawanieEnabled(bool b);
    /*!
     \brief
     Odpowiedzialna za sprawdzenie poprawno�ci wymganych p�l podczas dodawania nowego
     eksponatu. Zwraca true je�li jest OK.

     \fn checkDodajFields
    */
    bool checkDodajFields();
    /*!
     \brief
     Odpowiedzialna za sprawdzenie poprawno�ci p�l podczas edycji eksponatu.
     Zwraca true je�li jest OK.

     \fn checkEdytujFields
    */
    bool checkEdytujFields();
    /*!
     \brief
     Wywyo�ywana gdy zmienimy typ obiektu jaki chcemy doda�.
     Odpowiada za dopasowanie poprawnych p�l w panelu dodawania.

     \fn on_dod_cb_typ_currentIndexChanged
     \param index
    */
    void on_dod_cb_typ_currentIndexChanged(int index);

    /*!
     \brief
     Wywyo�ywana gdy zmienaimy format Daty. Odpowiedziala za
     uruchomienie odpowiedniego walidatora.

     \fn on_dod_fDat_currentIndexChanged
     \param index
    */
    void on_dod_fDat_currentIndexChanged(int index);

    /*!
     \brief
     Wywyo�ywana po naci�ni�ciu przycisku anuluj w panelu dodawania.

     \fn on_dod_b_anu_clicked
    */
    void on_dod_b_anu_clicked();

    /*!
     \brief
     Wywo�ywana po naci�ni�ciu przycisku dodaj w panelu dodawania.

     \fn on_dod_b_dod_clicked
    */
    void on_dod_b_dod_clicked();

    /*!
     \brief
     Wywyo�ywana po pojedy�czym klilkni�ciu na QTableView

     \fn on_tableView_clicked
     \param index
    */
    void on_tableView_clicked(const QModelIndex &index);

    /*!
     \brief
     Wywyo�ywana po naci�ci�ciu << w panelu szczeg��w

     \fn on_sz_pop_clicked
    */
    void on_sz_pop_clicked();

    /*!
     \brief
     Wywo�ywana po naci�ni�ciu >> w panleu szczeg��w

     \fn on_sz_nas_clicked
    */
    void on_sz_nas_clicked();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Plik akcji Otw�rz

     \fn on_actionOtw_rz_triggered
    */
    void on_actionOtw_rz_triggered();
    /*!
     \brief
     Wywyo�uje sta�� cz�� procesu po otwarciu plikiu. Wype�nienie modeli,
     odblokowanie akcji itp.

     \fn actionsAfterOpen
    */
    void actionsAfterOpen();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Plik akcji Zapisz jako

     \fn on_actionZapisz_jako_triggered
    */
    void on_actionZapisz_jako_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Plik akcji Zamknij

     \fn on_actionZamknij_triggered
    */
    void on_actionZamknij_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Plik akcji Zapisz

     \fn on_actionZapis_triggered
    */
    void on_actionZapis_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Plik akcji Nowa baza

     \fn on_actionNowa_baza_triggered
    */
    void on_actionNowa_baza_triggered();

    /*!
     \brief
     Wywo�ywana po naci�ni�ciu przycisku wczytania ostatnio u�ywanego pliku

     \fn on_naStar_ostPlik_clicked
    */
    void on_naStar_ostPlik_clicked();

    /*!
     \brief
     Wywo�ywana po naci�nieciu przycisku Wczytania bazy na ekranie startowym

     \fn on_naStart_clicked
    */
    void on_naStart_clicked();

    /*!
     \brief
     Wywo�ywana po naci�nieciu przycisku utworzenia nowej bazy na ekranie startowym

     \fn on_naStart2_clicked
    */
    void on_naStart2_clicked();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Edycja akcji Dodaj

     \fn on_actionDodaj_triggered
    */
    void on_actionDodaj_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Edycja akcji Edytuj

     \fn on_actionEdytuj_triggered
    */
    void on_actionEdytuj_triggered();

    /*!
     \brief
      Wywo�ywana po wybraniu w menu Pomoc akcji O_Qt

     \fn on_actionO_Qt_triggered
    */
    void on_actionO_Qt_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Pomoc akcji O programie

     \fn on_actionO_programie_triggered
    */
    void on_actionO_programie_triggered();

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Materia� akcji Dodaj materia�

     \fn on_actionDodaj_materia_triggered
    */
    void on_actionDodaj_materia_triggered();

    /*!
     \brief
     Wywyo�ywana po 2krotnym klini�ciu na QTableView

     \fn on_tableView_doubleClicked
     \param index
    */
    void on_tableView_doubleClicked(const QModelIndex &index);

    /*!
     \brief
     Wywo�ywana po wybraniu w menu Edycja akcji Usu�

     \fn on_actionUsu_triggered
    */
    void on_actionUsu_triggered();

    /*!
     \brief
      Wywo�ywana po zmianie formatu daty w widoku edxyji

     \fn on_ed_cb_fDat_currentIndexChanged
     \param index
    */
    void on_ed_cb_fDat_currentIndexChanged(int index);

    /*!
     \brief
      Wywo�ywana po naci�ni�ciu Anuluj w widoku edycji. Czy�ci pola.

     \fn on_ed_anuluj_clicked
    */
    void on_ed_anuluj_clicked();

    /*!
     \brief
     Wywo�ywana po naci�nieciu Zapisz w widoku edcyji. Ustawia nowe dane w rekordzie.

     \fn on_ed_zapisz_clicked
    */
    void on_ed_zapisz_clicked();

    /*!
     \brief
      Wywo�ywana po naci�nieciu Usu� w widoku edcyji.

     \fn on_ed_usun_clicked
    */
    void on_ed_usun_clicked();

private:
    int currentEditing; /*!< numer aktualnie edytowaneogo rekordu -1 je�li rzaden */
    QString tytul; /*!< tytu� okna */
    QSettings* ust; /*!< plik z ustawieniami */
    QString lastFileName; /*!< nazwa ostatnio u�ywanego pliku */
    QString fileName; /*!< nazwa otwartego pliku */
    QString saveFileName; /*!< nazwa zapisanego pliku */
    MaterialModel* matModel; /*!< model zawieracj�cy materia�y */
    /*!
     \brief
     Ustawia Meta::Typ do wybranego elemetu QComboBox

     \fn setMetaToComboBox
     \param cb
     \param wszyskie
    */
    void setMetaToComboBox(QComboBox* cb, bool wszyskie=false);
    Ui::MainWindow *ui; /*!< wska�nik do okna */
    EksponatModel* model; /*!< wska�nik do modelu z danymi */
    QValidator *v_dp1, *v_dp2, *v_dp3,*v_dp3a; /*!< wska�niki na walidatory */
    /*!
     \brief
     Zapisuje ustawienia programu (geometria + ostatni plik)

     \fn saveSettings
     \param file
    */
    void saveSettings(QSettings* file);
    /*!
     \brief
     Odczytuje ustawienia programu (geometria + ostatni plik)

     \fn readSettings
     \param file
    */
    void readSettings(QSettings* file);
    /*!
     \brief
     Przeci��enie standardowego eventu zamkni�cia okna

     \fn closeEvent
     \param event
    */
    void closeEvent(QCloseEvent *event);
    /*!
     \brief
     Funkcja zwraca true je�li u�ytkownik naprawd� chce zamkn�� program.

     \fn OKToClose
    */
    bool OKToClose();
};

#endif // MAINWINDOW_H
