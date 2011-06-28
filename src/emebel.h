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

#ifndef EMEBEL_H
#define EMEBEL_H
/*!
 \brief
 Klasa zarz¹daj¹ca obiekatami typu mebel

 \class EMebel emebel.h "src/emebel.h"
*/
class EMebel : public EksponatMuzealny
{
private:
    std::string m_rodzaj; /**< Opis rodzaju mebla */
    int m_material; /**< Numer materia³u z jakiego jest mebel */
public:
    /*!
     \brief
       Zwraca rodzaj jaki rodzaj mebla
     \fn getRodzaj
    */
    std::string getRodzaj();
    /*!
     \brief
     Ustawia rodzaj mebla
     \fn rodzaj
     \param std::string
    */
    void rodzaj(std::string);
    /*!
     \brief
     Zwraca numer materia³u z jakiego jest mebel.
     \fn getMaterial
    */
    int getMaterial();
    /*!
     \brief
     Ustawia numer materia³u z jakgo jest mebel. Stosowaæ prez klasê Material

     \fn material
     \param material
    */
    void material(int material);
/*!
 \brief
 rodzaj,material + EksponatMuzealny
 \fn EMebel
 \param rodzaj
 \param material
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EMebel(std::string rodzaj,int material ,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/*!
 \brief
 Konstruktor domyslny
 \fn EMebel
*/
    EMebel();
    /*!
     \brief
      Zwraca WSZYSTKIE atrybuty eksponatu (podstawowe + Mebla)
     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nag³ówek atrybutów
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
     \fn ~EMebel
    */
    ~EMebel();
};

#endif // EMEBEL_H
