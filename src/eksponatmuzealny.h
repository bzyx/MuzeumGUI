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
Glówna klasa - ndaje interfejs wszyskim klasom pochodnym, wyprowadza podstawowe funkcje.
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
     Struktura, która jest u¿ywana podczas zapisu do pliku. S³u¿y do przechowywania
     wartoœci w postaci "atryut","wartoœæAtrybutu"

     \typedef krotka    */
    typedef QPair<QString, QString> krotka;
    /*!
     \brief
     Lista któr¹ sk³ada siê z krotek zawieracj¹ca wszyskie atrybuty i wartoœci rekordu.

     \typedef r2f    */
    typedef QList<krotka> r2f;
private:
    static int m_lastid; /*!< Przechowuje ostatnio ustawiony identyfikator */
    int m_id; /*!< Identyfikator eksponatu */
    std::string m_nazwa; /*!< Nazwa eksponatu */
    bool m_wystawiony; /*!< Czy eksponat jest wystawiony "true" jeœli jest wystaiony  */
    std::string m_opis; /*!< Opis eksponatu, w za³o¿eniu mo¿e byæ dosyæ d³gui */
    std::string m_polozenie; /*!< TODO */
    int m_wartosc; /*!< Wartoœc eksponatu wyra¿ona z PLN */
    Meta::Typ m_typ; /*!< Typ (Rodzina) eksponatu */
    Meta::FormatDaty m_FormatDaty; /*!< Sposób zapisu daty eksponatu */
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
     Ustawia identyfikator obiektu. Wprowadzona w celu zgodnoœci z get (nie u¿ywaæ).
     \fn id
     \param id
    */
    void id(int id);
    /*!
     \brief
     Zwraca nazwê/tytu³ eksponatu

     \fn getNazwa
    */
    std::string getNazwa();
    /*!
     \brief
     * Ustawia nazwê/tytu³ eksponatu

     \fn nazwa
     \param nazwa
    */
    void nazwa(std::string nazwa);
    /*!
     \brief
     Zwraca wartoœæ true jeœli ekspoanat jest wystawiony

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
     Zwraca d³u¿szy opis ekspoantu

     \fn getOpis
    */
    std::string getOpis();
    /*!
     \brief
     Ustawia d³u¿szy opis eksponatu

     \fn opis
     \param opis
    */
    void opis(std::string opis);
    /*!
     \brief
     Zwraca po³o¿enie eksponatu (mo¿e to byæ magazyn/galeria/sala/budynek)

     \fn getPolozenie
    */
    std::string getPolozenie();
    /*!
     \brief
     Ustawia po³o¿enie eksponatu

     \fn polozenie
     \param polozenie
    */
    void polozenie(std::string polozenie);
    /*!
     \brief
     Zwraca wartoœæ obiektu w PLN

     \fn getWartosc
    */
    int getWartosc();
    /*!
     \brief
     Ustawia wartoœæ eksponatu w PLN

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
     Ustawia typ/rodzinê eksponatu

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
     Zwraca datê. Powinna byæ zapisana zgodnie z ustawionym formatem.

     \fn getData
    */
    std::string getData();
    /*!
     \brief
     Ustawia datê. Nale¿y pamiêtaæ o zgodnoœci z wybranm formatem daty

     \fn data
     \param data
    */
    void data(std::string data);
    /*!
 \brief
 Konstruktor domyœlny - przydziela tylko unikalny identyfikator obiektu.

 \fn EksponatMuzealny
*/
    EksponatMuzealny();
    /*!
 \brief
 Konstruktor przyjmuj¹cy wszyskie mo¿liwe parametry. Odpoiwednie id jest przydzielane
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
     Ustawia zmienn¹ klasow¹ lastId. Mo¿e byæ pomocne przy wycztywaniu danych z pliku.
     U¿ycie tej funkcji pozwala na zachowanie orginalnych identyfikatorów, przez
     pominiêcie zbêdnych.

     \fn lastId
     \param id
    */
    static void lastId(int id);
    /*!
     \brief
     Zwraca aktualn¹ wartoœæ zmiennej klasowej lastId.

     \fn getLastId
    */
    static int getLastId();
    /*!
     \brief
     Zwraca wartoœci atrybutów obiektów.
     Metoda czysto wirtulana.
     Nale¿y przeci¹¿yæ w klasach pochodnych.
     Ma zwracaæ jako listê QString poszczegó³ne atrybuty obiektu.

     \fn getAtrybuty
    */
    virtual QStringList getAtrybuty() =0;
    /*!
     \brief
     Zwraca wartoœci atrybutów nale¿¹cych do klasy EksponatMuzealny
     Atrybuty w postaci list QString.

     \fn getPodstawoweAtrybuty
    */
    QStringList getPodstawoweAtrybuty();
    /*!
     \brief
     Zwraca nazwy atrybutów - metoda wirtualna.
     Wymagane przeci¹¿enie w klasie pochodnej.
     Nazwy w postaci listy QString

     \fn getHeaders
    */
    virtual QStringList getHeaders() = 0;
    /*!
     \brief
     Zwraca nazwy atrybutów zdefiniowanych w klasie EksponatMuzealny
     Nazwy w postaci listy QString

     \fn getPodstawoweHeaders
    */
    QStringList getPodstawoweHeaders();
    /*!
     \brief
     Zwraca listê par typu QString, QString w postaci
     Atrybut, WartoœcAtrybutu
     Wymagane przeci¹zenie w klasie pochodnej.

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
