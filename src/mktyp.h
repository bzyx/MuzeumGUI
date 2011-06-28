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

#ifndef MKTYP_H
#define MKTYP_H
#include "src/muzeumkontener.h"
#include <vector>
#include <map>

/*!
 \brief
 Klasa MuzeumKontenerTyp rozszerza mo¿liwoœci klasy MuzeumKontener MK.
 Klasa jest singletonem. Przechowuje w wewnêtrznej implementacji sk³adaj¹cej siê
 z mapy która ka¿demu typowi obiektu przypisuje vektor zawieracj¹cy wyst¹pienia
 obiektów tego typu w g³ównym kontenerze. Klasa MKTyp pozwala nam na uzyskanie
 i-tego elementu zadanego typu bez przechowywania w pamiêci kliku list odrêbnych dla ka¿dego typu.

 \class MKTyp mktyp.h "src/mktyp.h"
*/
class MKTyp /*: public MK*/
{
public:
    /*!
     \brief
     Zwraca referencjê do obiektu, aby mo¿lwie by³o u¿ycie singletona.

     \fn getInstance
    */
    static MKTyp& getInstance();
    /*!
     \brief
     Zwraca id-ty obiekt dla zadanego Typ-u.

     \fn getObjectFor
     \param Meta::Typ
     \param id
    */
    EksponatMuzealny* getObjectFor(Meta::Typ,int id);
    /*!
     \brief
     Zwraca iloœæ obiektów zadanego typu.

     \fn count
     \param typ
    */
    int count(Meta::Typ typ);

    /*!
     \brief
     Powoduje "automagiczne" ustawienie odpowiednich wartoœci do wektorów.
     Nale¿y j¹ wykonaæ po ka¿dym dodaniu lub usuniêciu obiektu.
     W przeciwnym wypadku nowe dane nie bêd¹ widoczne.

     \fn updateMKTyp
    */
    void updateMKTyp();
private:
    std::map<Meta::Typ,std::vector<int> > m_Types; /*!< Przechowuje wystst¹pienia elementów
        w kontenerze MK */

/*!
 \brief
 Prywatny konstruktor domyœlny. Singleton.

 \fn MKTyp
*/
    MKTyp();
/*!
 \brief
 Prywatny konstruktor kopiuj¹cy. Singleton.

 \fn MKTyp
 \param
*/
    MKTyp(const MKTyp&);
    /*!
     \brief
     Prywatny operator przypisania. Singleton.

     \fn operator =
     \param
    */
    MKTyp& operator=(const MKTyp&);
};

#endif // MKTYP_H
