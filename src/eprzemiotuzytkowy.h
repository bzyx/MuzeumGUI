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

#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EPRZEMIOTUZYTKOWY_H
#define EPRZEMIOTUZYTKOWY_H
/*!
 \brief
 Klasa zarz�dzaj�ca obiektami u�ytkowymi

 \class EPrzemiotUzytkowy eprzemiotuzytkowy.h "src/eprzemiotuzytkowy.h"
*/
class EPrzemiotUzytkowy : public EksponatMuzealny
{
private:
    std::string m_opisDzialania; /**< TODO */ /*!< TODO */
    bool m_czyMoznaDotykac; /**< TODO */ /*!< TODO */
public:
    /*!
     \brief
     Zwraca opis dzia�ania przedmiotu

     \fn getOpisDzialania
    */
    std::string getOpisDzialania();
    /*!
     \brief
     Ustawia opis dzia�ania przedmiotu

     \fn opisDzialania
     \param opisDzialania
    */
    void opisDzialania(std::string opisDzialania);
    /*!
     \brief
     Zwraca true je�li eksponat mo�e by� dotykany

     \fn getCzyMoznaDotykac
    */
    bool getCzyMoznaDotykac();
    /*!
     \brief
     Ustawia czy przemiot mo�e by� dotykany

     \fn czyMoznaDotykac
     \param czyMoznaDotykac
    */
    void czyMoznaDotykac(bool czyMoznaDotykac);
    /*!
 \brief
 Pe�ny konstruktor opiszDzialania,czyMoznaDotykac + EksponatMuzealny

 \fn EPrzemiotUzytkowy
 \param opisDzialania
 \param czyMoznaDotykac
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EPrzemiotUzytkowy(std::string opisDzialania, bool czyMoznaDotykac,
                      std::string nazwa, bool wystawiony, std::string opis,
                      std::string polozenie, int wartosc,
                      Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data
                      );
    /*!
 \brief
 Konstruktor domy�lny

 \fn EPrzemiotUzytkowy
*/
    EPrzemiotUzytkowy();
    /*!
     \brief
     Zwraca list� atrybut�w

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nag��wki atrybut�w

     \fn getHeaders
    */
    QStringList getHeaders();
    /*!
     \brief
     Rekord do zapisu

     \fn saveElement
    */
    r2f saveElement();
    /*!
     \brief
     Destruktor

     \fn ~EPrzemiotUzytkowy
    */
    ~EPrzemiotUzytkowy();
};

#endif // EPRZEMIOTUZYTKOWY_H
