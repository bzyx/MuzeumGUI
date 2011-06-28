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

#ifndef ESTARODRUK_H
#define ESTARODRUK_H
/*!
 \brief
 Klasa zarz�dzaj�ca obiekatmi typu Starodruk

 \class EStarodruk estarodruk.h "src/estarodruk.h"
*/
class EStarodruk : public EksponatMuzealny
{
private:
    std::string m_autor; /*!< Autor starodruku */
    std::string m_streszczenie; /*!< Streszczenie starodruku */
    int m_liczbaStron; /*!< Liczba stron starodruku */
public:
    /*!
     \brief
     Zwraca autora starodruku

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
     Zwraca kr�tkie streszczenie starodruku

     \fn getStreszczenie
    */
    std::string getStreszczenie();
    /*!
     \brief
     Ustawia kr�tkie streszczenie starordruku

     \fn sterszczenie
     \param streszczenie
    */
    void sterszczenie(std::string streszczenie);
    /*!
     \brief
     Zwraca liczb� stron starodruku

     \fn getLiczbaStron
    */
    int getLiczbaStron();
    /*!
     \brief
     Ustawia liczb� stron w starodruku

     \fn liczbaStron
     \param liczbaStron
    */
    void liczbaStron(int liczbaStron);
/*!
 \brief
 Konstruktor pe�ny: autor, streszczenie, liczba stron + EksponatMuzealny

 \fn EStarodruk
 \param autor
 \param streszczenie
 \param liczbaStron
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EStarodruk(std::string autor, std::string streszczenie, int liczbaStron,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/*!
 \brief
 Konstrutkor domy�lny

 \fn EStarodruk
*/
    EStarodruk();
    /*!
     \brief
     Zwraca list� atrybut�w

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nazwy atrybut�w

     \fn getHeaders
    */
    QStringList getHeaders();
    /*!
     \brief
     Rekord do pliku

     \fn saveElement
    */
    r2f saveElement();
    /*!
     \brief
     Destrutkor

     \fn ~EStarodruk
    */
    ~EStarodruk();
};

#endif // ESTARODRUK_H
