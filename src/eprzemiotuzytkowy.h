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

#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EPRZEMIOTUZYTKOWY_H
#define EPRZEMIOTUZYTKOWY_H
/*!
 \brief
 Klasa zarz¹dzaj¹ca obiektami u¿ytkowymi

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
     Zwraca opis dzia³ania przedmiotu

     \fn getOpisDzialania
    */
    std::string getOpisDzialania();
    /*!
     \brief
     Ustawia opis dzia³ania przedmiotu

     \fn opisDzialania
     \param opisDzialania
    */
    void opisDzialania(std::string opisDzialania);
    /*!
     \brief
     Zwraca true jeœli eksponat mo¿e byæ dotykany

     \fn getCzyMoznaDotykac
    */
    bool getCzyMoznaDotykac();
    /*!
     \brief
     Ustawia czy przemiot mo¿e byæ dotykany

     \fn czyMoznaDotykac
     \param czyMoznaDotykac
    */
    void czyMoznaDotykac(bool czyMoznaDotykac);
    /*!
 \brief
 Pe³ny konstruktor opiszDzialania,czyMoznaDotykac + EksponatMuzealny

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
 Konstruktor domyœlny

 \fn EPrzemiotUzytkowy
*/
    EPrzemiotUzytkowy();
    /*!
     \brief
     Zwraca listê atrybutów

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nag³ówki atrybutów

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
