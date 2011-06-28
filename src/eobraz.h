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

#ifndef EOBRAZ_H
#define EOBRAZ_H
/*!
 \brief
  Klasa zarz¹dzaj¹ca eksponatami typu Obraz
 \class EObraz eobraz.h "src/eobraz.h"
*/
class EObraz : public EksponatMuzealny
{
private:
    float m_wysokosc;  /*!< Wysokoœæ obrazu */
    float m_szerokosc;  /*!< Szerokoœæ obrazu */
    std::string m_autor;  /*!< Autor obrazu */
public:
    /*!
     \brief
    Zwraca wyskokoœæ
     \fn getWysokosc
    */
    float getWysokosc();
    /*!
     \brief
    Ustawia wysokoœæ
     \fn wysokosc
     \param w
    */
    void wysokosc(float w);
    /*!
     \brief
    Zwraca szerokoœæ
     \fn getSzerokosc
    */
    float getSzerokosc();
    /*!
     \brief
    Ustawia szerokoœæ
     \fn szerokosc
     \param s
    */
    void szerokosc(float s);
    /*!
     \brief
    Zwraca autora
     \fn getAutor
    */
    std::string getAutor();
    /*!
     \brief
     Ustawia autora

     \fn autor
     \param autor
    */
    void autor(std::string autor);
    /*!
 \brief
  Konstruktor z wszyskimi argumentami w,s,autor + EksponatMuzealny
 \fn EObraz
 \param w
 \param s
 \param autor
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param Meta::Typ
 \param formatDaty
 \param data
*/
    EObraz(float w, float s, std::string autor,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ, Meta::FormatDaty formatDaty, std::string data);
    /*!
 \brief
 Konstruktor domyœlny.
 \fn EObraz
*/
    EObraz();
    /*!
     \brief
     Zwraca wszyskie atrybuty obiektu

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nazwy wyszystkich atrybutów.

     \fn getHeaders
    */
    QStringList getHeaders();
    /*!
     \brief
     Eksponat przygotowany do zapisu.

     \fn saveElement
    */
    r2f saveElement();
    /*!
     \brief
     Destruktor

     \fn ~EObraz
    */
    ~EObraz();
};

#endif // EOBRAZ_H
