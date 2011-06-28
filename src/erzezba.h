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

#ifndef ERZEZBA_H
#define ERZEZBA_H
/*!
 \brief
 Klasa zarz¹dajaca obiektami typu RzeŸba

 \class ERzezba erzezba.h "src/erzezba.h"
*/
class ERzezba : public EksponatMuzealny
{
private:
    std::string m_postac; /*!< Przedstawiona postaæ */
    int m_material; /*!< Numer materia³u z jakiego jest rzeŸba */
    float m_powierzchnia; /*!< Powierzchnia jak¹ zajuje rzeŸba w muzeum */
public:
    /*!
     \brief
     Zwraca nazwa postaci jak¹ przedstawia rzeŸba

     \fn getPostac
    */
    std::string getPostac();
    /*!
     \brief
     Ustawia nazwê postaci

     \fn postac
     \param postac
    */
    void postac(std::string postac);
    /*!
     \brief
     Zwraca numer materia³u z jakiego jest rzeŸba

     \fn getMaterial
    */
    int getMaterial();
    /*!
     \brief
     Ustawia numer materia³u z jakiego jest rzeŸba

     \fn material
     \param material
    */
    void material(int material);
    /*!
     \brief
     Zwraca jak du¿¹ powierzchniê zajmuje rzeŸba

     \fn getPowierzchnia
    */
    float getPowierzchnia();
    /*!
     \brief
     Ustawia powierzchniê jak¹ zajmuje rzeŸba

     \fn powierchnia
     \param powierzchnia
    */
    void powierchnia(float powierzchnia);
/*!
 \brief
Konstruktor pe³ny: postac, material, powierzchnia + EksponatMuzealny

 \fn ERzezba
 \param postac
 \param material
 \param powierzchnia
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    ERzezba(std::string postac,
            int material, float powierzchnia,
            std::string nazwa, bool wystawiony, std::string opis,
            std::string polozenie, int wartosc,
            Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/*!
 \brief
 Konsttruktor domyœlny

 \fn ERzezba
*/
    ERzezba();
    /*!
     \brief
     Zwraca atrybuty

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwrca nazwy atrybutów

     \fn getHeaders
    */
    QStringList getHeaders();
    /*!
     \brief
     Rekord do plkiku

     \fn saveElement
    */
    r2f saveElement();
    /*!
     \brief
     Destruktor

     \fn ~ERzezba
    */
    ~ERzezba();
};

#endif // ERZEZBA_H
