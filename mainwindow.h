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
 Klasa obs³uguj¹ca ca³¹ czêœæ "okienkow¹" programu. Zarz¹dza oknami, przyciskami
 wywow³uje odpowiednie akcji na czêœci "niewidocznej" programu.

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
     Funkja wy³¹cza widok QTableView jeœli jest on pusty.

     \fn setDisabledIfEmpty
    */
    void setDisabledIfEmpty();
private slots:
    /*!
     \brief
     Wywo³ywana jeœli przy ka¿dej zmianie typu w polu "Wyœwietlany typ: "

     \fn on_top_cb_wysTyp_currentIndexChanged
     \param index
    */
    void on_top_cb_wysTyp_currentIndexChanged(int index);
    /*!
     \brief
     Ustawia czy panel dodawania/edycji ma byæ widoczny.

     \fn setVisiblePanelDodawania
    */
    void setVisiblePanelDodawania();
    /*!
     \brief
     Ustawia czy panel szczegó³ów ma byæ widoczny.

     \fn setVisiblePanelSzczegoly
    */
    void setVisiblePanelSzczegoly();
    /*!
     \brief
     W³¹cza mo¿liowœæ dodawania.

     \fn setDodawanieEnabled
     \param b
    */
    void setDodawanieEnabled(bool b);
    /*!
     \brief
     Odpowiedzialna za sprawdzenie poprawnoœci wymganych pól podczas dodawania nowego
     eksponatu. Zwraca true jeœli jest OK.

     \fn checkDodajFields
    */
    bool checkDodajFields();
    /*!
     \brief
     Odpowiedzialna za sprawdzenie poprawnoœci pól podczas edycji eksponatu.
     Zwraca true jeœli jest OK.

     \fn checkEdytujFields
    */
    bool checkEdytujFields();
    /*!
     \brief
     Wywyo³ywana gdy zmienimy typ obiektu jaki chcemy dodaæ.
     Odpowiada za dopasowanie poprawnych pól w panelu dodawania.

     \fn on_dod_cb_typ_currentIndexChanged
     \param index
    */
    void on_dod_cb_typ_currentIndexChanged(int index);

    /*!
     \brief
     Wywyo³ywana gdy zmienaimy format Daty. Odpowiedziala za
     uruchomienie odpowiedniego walidatora.

     \fn on_dod_fDat_currentIndexChanged
     \param index
    */
    void on_dod_fDat_currentIndexChanged(int index);

    /*!
     \brief
     Wywyo³ywana po naciœniêciu przycisku anuluj w panelu dodawania.

     \fn on_dod_b_anu_clicked
    */
    void on_dod_b_anu_clicked();

    /*!
     \brief
     Wywo³ywana po naciœniêciu przycisku dodaj w panelu dodawania.

     \fn on_dod_b_dod_clicked
    */
    void on_dod_b_dod_clicked();

    /*!
     \brief
     Wywyo³ywana po pojedyñczym klilkniêciu na QTableView

     \fn on_tableView_clicked
     \param index
    */
    void on_tableView_clicked(const QModelIndex &index);

    /*!
     \brief
     Wywyo³ywana po naciœciêciu << w panelu szczegó³ów

     \fn on_sz_pop_clicked
    */
    void on_sz_pop_clicked();

    /*!
     \brief
     Wywo³ywana po naciœniêciu >> w panleu szczegó³ów

     \fn on_sz_nas_clicked
    */
    void on_sz_nas_clicked();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Plik akcji Otwórz

     \fn on_actionOtw_rz_triggered
    */
    void on_actionOtw_rz_triggered();
    /*!
     \brief
     Wywyo³uje sta³¹ czêœæ procesu po otwarciu plikiu. Wype³nienie modeli,
     odblokowanie akcji itp.

     \fn actionsAfterOpen
    */
    void actionsAfterOpen();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Plik akcji Zapisz jako

     \fn on_actionZapisz_jako_triggered
    */
    void on_actionZapisz_jako_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Plik akcji Zamknij

     \fn on_actionZamknij_triggered
    */
    void on_actionZamknij_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Plik akcji Zapisz

     \fn on_actionZapis_triggered
    */
    void on_actionZapis_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Plik akcji Nowa baza

     \fn on_actionNowa_baza_triggered
    */
    void on_actionNowa_baza_triggered();

    /*!
     \brief
     Wywo³ywana po naciœniêciu przycisku wczytania ostatnio u¿ywanego pliku

     \fn on_naStar_ostPlik_clicked
    */
    void on_naStar_ostPlik_clicked();

    /*!
     \brief
     Wywo³ywana po naciœnieciu przycisku Wczytania bazy na ekranie startowym

     \fn on_naStart_clicked
    */
    void on_naStart_clicked();

    /*!
     \brief
     Wywo³ywana po naciœnieciu przycisku utworzenia nowej bazy na ekranie startowym

     \fn on_naStart2_clicked
    */
    void on_naStart2_clicked();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Edycja akcji Dodaj

     \fn on_actionDodaj_triggered
    */
    void on_actionDodaj_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Edycja akcji Edytuj

     \fn on_actionEdytuj_triggered
    */
    void on_actionEdytuj_triggered();

    /*!
     \brief
      Wywo³ywana po wybraniu w menu Pomoc akcji O_Qt

     \fn on_actionO_Qt_triggered
    */
    void on_actionO_Qt_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Pomoc akcji O programie

     \fn on_actionO_programie_triggered
    */
    void on_actionO_programie_triggered();

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Materia³ akcji Dodaj materia³

     \fn on_actionDodaj_materia_triggered
    */
    void on_actionDodaj_materia_triggered();

    /*!
     \brief
     Wywyo³ywana po 2krotnym kliniêciu na QTableView

     \fn on_tableView_doubleClicked
     \param index
    */
    void on_tableView_doubleClicked(const QModelIndex &index);

    /*!
     \brief
     Wywo³ywana po wybraniu w menu Edycja akcji Usuñ

     \fn on_actionUsu_triggered
    */
    void on_actionUsu_triggered();

    /*!
     \brief
      Wywo³ywana po zmianie formatu daty w widoku edxyji

     \fn on_ed_cb_fDat_currentIndexChanged
     \param index
    */
    void on_ed_cb_fDat_currentIndexChanged(int index);

    /*!
     \brief
      Wywo³ywana po naciœniêciu Anuluj w widoku edycji. Czyœci pola.

     \fn on_ed_anuluj_clicked
    */
    void on_ed_anuluj_clicked();

    /*!
     \brief
     Wywo³ywana po naciœnieciu Zapisz w widoku edcyji. Ustawia nowe dane w rekordzie.

     \fn on_ed_zapisz_clicked
    */
    void on_ed_zapisz_clicked();

    /*!
     \brief
      Wywo³ywana po naciœnieciu Usuñ w widoku edcyji.

     \fn on_ed_usun_clicked
    */
    void on_ed_usun_clicked();

private:
    int currentEditing; /*!< numer aktualnie edytowaneogo rekordu -1 jeœli rzaden */
    QString tytul; /*!< tytu³ okna */
    QSettings* ust; /*!< plik z ustawieniami */
    QString lastFileName; /*!< nazwa ostatnio u¿ywanego pliku */
    QString fileName; /*!< nazwa otwartego pliku */
    QString saveFileName; /*!< nazwa zapisanego pliku */
    MaterialModel* matModel; /*!< model zawieracj¹cy materia³y */
    /*!
     \brief
     Ustawia Meta::Typ do wybranego elemetu QComboBox

     \fn setMetaToComboBox
     \param cb
     \param wszyskie
    */
    void setMetaToComboBox(QComboBox* cb, bool wszyskie=false);
    Ui::MainWindow *ui; /*!< wskaŸnik do okna */
    EksponatModel* model; /*!< wskaŸnik do modelu z danymi */
    QValidator *v_dp1, *v_dp2, *v_dp3,*v_dp3a; /*!< wskaŸniki na walidatory */
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
     Przeci¹¿enie standardowego eventu zamkniêcia okna

     \fn closeEvent
     \param event
    */
    void closeEvent(QCloseEvent *event);
    /*!
     \brief
     Funkcja zwraca true jeœli u¿ytkownik naprawdê chce zamkn¹æ program.

     \fn OKToClose
    */
    bool OKToClose();
};

#endif // MAINWINDOW_H
