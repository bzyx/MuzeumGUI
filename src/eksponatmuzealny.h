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

#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H
#include <string>
#include <QPair>
#include <QList>
#include <QStringList>
#include <QString>
#include "src/meta.h"
#include "src/material.h"

/*!
 \brief
Gl�wna klasa - ndaje interfejs wszyskim klasom pochodnym, wyprowadza podstawowe funkcje.
 \class EksponatMuzealny eksponatmuzealny.h "src/eksponatmuzealny.h"
*/
class EksponatMuzealny
{
public:
    /**
     * @brief
     * Record to file - struktura do zapisu danych do pliku XML
     */
    /*!
     \brief
     Struktura, kt�ra jest u�ywana podczas zapisu do pliku. S�u�y do przechowywania
     warto�ci w postaci "atryut","warto��Atrybutu"

     \typedef krotka    */
    typedef QPair<QString, QString> krotka;
    /*!
     \brief
     Lista kt�r� sk�ada si� z krotek zawieracj�ca wszyskie atrybuty i warto�ci rekordu.

     \typedef r2f    */
    typedef QList<krotka> r2f;
private:
    static int m_lastid; /*!< Przechowuje ostatnio ustawiony identyfikator */
    int m_id; /*!< Identyfikator eksponatu */
    std::string m_nazwa; /*!< Nazwa eksponatu */
    bool m_wystawiony; /*!< Czy eksponat jest wystawiony "true" je�li jest wystaiony  */
    std::string m_opis; /*!< Opis eksponatu, w za�o�eniu mo�e by� dosy� d�gui */
    std::string m_polozenie; /*!< TODO */
    int m_wartosc; /*!< Warto�c eksponatu wyra�ona z PLN */
    Meta::Typ m_typ; /*!< Typ (Rodzina) eksponatu */
    Meta::FormatDaty m_FormatDaty; /*!< Spos�b zapisu daty eksponatu */
    std::string m_data; /*!< Data zapisana w wybranym formacie */
public:
    /*!
     \brief
     Zwraca identyfikator eksponatu

     \fn getId
    */
    int getId();
    /*!
     \brief
     Ustawia identyfikator obiektu. Wprowadzona w celu zgodno�ci z get (nie u�ywa�).
     \fn id
     \param id
    */
    void id(int id);
    /*!
     \brief
     Zwraca nazw�/tytu� eksponatu

     \fn getNazwa
    */
    std::string getNazwa();
    /*!
     \brief
     * Ustawia nazw�/tytu� eksponatu

     \fn nazwa
     \param nazwa
    */
    void nazwa(std::string nazwa);
    /*!
     \brief
     Zwraca warto�� true je�li ekspoanat jest wystawiony

     \fn getWystawiony
    */
    bool getWystawiony();
    /*!
     \brief
     Ustawia czy eksponat jest wystawiony

     \fn wystawiony
     \param wystawiony
    */
    void wystawiony(bool wystawiony);
    /*!
     \brief
     Zwraca d�u�szy opis ekspoantu

     \fn getOpis
    */
    std::string getOpis();
    /*!
     \brief
     Ustawia d�u�szy opis eksponatu

     \fn opis
     \param opis
    */
    void opis(std::string opis);
    /*!
     \brief
     Zwraca po�o�enie eksponatu (mo�e to by� magazyn/galeria/sala/budynek)

     \fn getPolozenie
    */
    std::string getPolozenie();
    /*!
     \brief
     Ustawia po�o�enie eksponatu

     \fn polozenie
     \param polozenie
    */
    void polozenie(std::string polozenie);
    /*!
     \brief
     Zwraca warto�� obiektu w PLN

     \fn getWartosc
    */
    int getWartosc();
    /*!
     \brief
     Ustawia warto�� eksponatu w PLN

     \fn wartosc
     \param wartosc
    */
    void wartosc(int wartosc);
    /*!
     \brief
     Zwraca typ eksponatu.

     \fn getTyp
    */
    Meta::Typ getTyp();
    /*!
     \brief
     Ustawia typ/rodzin� eksponatu

     \fn Typ
     \param typ
    */
    void Typ(Meta::Typ typ);
    /*!
     \brief
     Zwraca format daty w jakim jest zapisana data

     \fn getFormatDaty
    */
    Meta::FormatDaty getFormatDaty();
    /*!
     \brief
     Ustawia format zapisu daty

     \fn formatDaty
     \param formatDaty
    */
    void formatDaty(Meta::FormatDaty formatDaty);
    /*!
     \brief
     Zwraca dat�. Powinna by� zapisana zgodnie z ustawionym formatem.

     \fn getData
    */
    std::string getData();
    /*!
     \brief
     Ustawia dat�. Nale�y pami�ta� o zgodno�ci z wybranm formatem daty

     \fn data
     \param data
    */
    void data(std::string data);
    /*!
 \brief
 Konstruktor domy�lny - przydziela tylko unikalny identyfikator obiektu.

 \fn EksponatMuzealny
*/
    EksponatMuzealny();
    /*!
 \brief
 Konstruktor przyjmuj�cy wszyskie mo�liwe parametry. Odpoiwednie id jest przydzielane
 automatycznie wg zmiennej klasowej lastId

 \fn EksponatMuzealny
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EksponatMuzealny(std::string nazwa, bool wystawiony, std::string opis,
                     std::string polozenie, int wartosc,
                     Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
    /*!
     \brief
     Ustawia zmienn� klasow� lastId. Mo�e by� pomocne przy wycztywaniu danych z pliku.
     U�ycie tej funkcji pozwala na zachowanie orginalnych identyfikator�w, przez
     pomini�cie zb�dnych.

     \fn lastId
     \param id
    */
    static void lastId(int id);
    /*!
     \brief
     Zwraca aktualn� warto�� zmiennej klasowej lastId.

     \fn getLastId
    */
    static int getLastId();
    /*!
     \brief
     Zwraca warto�ci atrybut�w obiekt�w.
     Metoda czysto wirtulana.
     Nale�y przeci��y� w klasach pochodnych.
     Ma zwraca� jako list� QString poszczeg�ne atrybuty obiektu.

     \fn getAtrybuty
    */
    virtual QStringList getAtrybuty() =0;
    /*!
     \brief
     Zwraca warto�ci atrybut�w nale��cych do klasy EksponatMuzealny
     Atrybuty w postaci list QString.

     \fn getPodstawoweAtrybuty
    */
    QStringList getPodstawoweAtrybuty();
    /*!
     \brief
     Zwraca nazwy atrybut�w - metoda wirtualna.
     Wymagane przeci��enie w klasie pochodnej.
     Nazwy w postaci listy QString

     \fn getHeaders
    */
    virtual QStringList getHeaders() = 0;
    /*!
     \brief
     Zwraca nazwy atrybut�w zdefiniowanych w klasie EksponatMuzealny
     Nazwy w postaci listy QString

     \fn getPodstawoweHeaders
    */
    QStringList getPodstawoweHeaders();
    /*!
     \brief
     Zwraca list� par typu QString, QString w postaci
     Atrybut, Warto�cAtrybutu
     Wymagane przeci�zenie w klasie pochodnej.

     \fn saveElement
    */
    virtual r2f saveElement() =0;
    /*!
     \brief
     Wirtualny destruktor.

     \fn ~EksponatMuzealny
    */
    virtual ~EksponatMuzealny();
};

#endif // EKSPONATMUZEALNY_H
