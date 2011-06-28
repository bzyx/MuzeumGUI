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

#ifndef MKTYP_H
#define MKTYP_H
#include "src/muzeumkontener.h"
#include <vector>
#include <map>

/*!
 \brief
 Klasa MuzeumKontenerTyp rozszerza mo�liwo�ci klasy MuzeumKontener MK.
 Klasa jest singletonem. Przechowuje w wewn�trznej implementacji sk�adaj�cej si�
 z mapy kt�ra ka�demu typowi obiektu przypisuje vektor zawieracj�cy wyst�pienia
 obiekt�w tego typu w g��wnym kontenerze. Klasa MKTyp pozwala nam na uzyskanie
 i-tego elementu zadanego typu bez przechowywania w pami�ci kliku list odr�bnych dla ka�dego typu.

 \class MKTyp mktyp.h "src/mktyp.h"
*/
class MKTyp /*: public MK*/
{
public:
    /*!
     \brief
     Zwraca referencj� do obiektu, aby mo�lwie by�o u�ycie singletona.

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
     Zwraca ilo�� obiekt�w zadanego typu.

     \fn count
     \param typ
    */
    int count(Meta::Typ typ);

    /*!
     \brief
     Powoduje "automagiczne" ustawienie odpowiednich warto�ci do wektor�w.
     Nale�y j� wykona� po ka�dym dodaniu lub usuni�ciu obiektu.
     W przeciwnym wypadku nowe dane nie b�d� widoczne.

     \fn updateMKTyp
    */
    void updateMKTyp();
private:
    std::map<Meta::Typ,std::vector<int> > m_Types; /*!< Przechowuje wystst�pienia element�w
        w kontenerze MK */

/*!
 \brief
 Prywatny konstruktor domy�lny. Singleton.

 \fn MKTyp
*/
    MKTyp();
/*!
 \brief
 Prywatny konstruktor kopiuj�cy. Singleton.

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
