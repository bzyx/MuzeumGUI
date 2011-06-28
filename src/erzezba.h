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

#ifndef ERZEZBA_H
#define ERZEZBA_H
/*!
 \brief
 Klasa zarz�dajaca obiektami typu Rze�ba

 \class ERzezba erzezba.h "src/erzezba.h"
*/
class ERzezba : public EksponatMuzealny
{
private:
    std::string m_postac; /*!< Przedstawiona posta� */
    int m_material; /*!< Numer materia�u z jakiego jest rze�ba */
    float m_powierzchnia; /*!< Powierzchnia jak� zajuje rze�ba w muzeum */
public:
    /*!
     \brief
     Zwraca nazwa postaci jak� przedstawia rze�ba

     \fn getPostac
    */
    std::string getPostac();
    /*!
     \brief
     Ustawia nazw� postaci

     \fn postac
     \param postac
    */
    void postac(std::string postac);
    /*!
     \brief
     Zwraca numer materia�u z jakiego jest rze�ba

     \fn getMaterial
    */
    int getMaterial();
    /*!
     \brief
     Ustawia numer materia�u z jakiego jest rze�ba

     \fn material
     \param material
    */
    void material(int material);
    /*!
     \brief
     Zwraca jak du�� powierzchni� zajmuje rze�ba

     \fn getPowierzchnia
    */
    float getPowierzchnia();
    /*!
     \brief
     Ustawia powierzchni� jak� zajmuje rze�ba

     \fn powierchnia
     \param powierzchnia
    */
    void powierchnia(float powierzchnia);
/*!
 \brief
Konstruktor pe�ny: postac, material, powierzchnia + EksponatMuzealny

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
 Konsttruktor domy�lny

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
     Zwrca nazwy atrybut�w

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
