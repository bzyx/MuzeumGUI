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

#ifndef META_H
#define META_H
#include <string>
/*!
 \brief
 Klasa Meta zawiera klika przydatnych metdod i enumerator�w kt�re s� u�ywane przez rodzin� klas
     wyprowadzon� z EksponatMuzealny. Zawiera definicj� r�nych typ�w i metody do ich obs�ugi.

 \class Meta meta.h "src/meta.h"
*/
class Meta
{
public:
    /*!
     \brief
     Enumerator okre�laj�cy typ eksponatu. Ka�dy eksponat MUSI miec okre�lony sw�j typ.

     \enum
    */
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ; /*!< Okre�la typ ekspoantu */

    /*!
     \brief
     Enumerator okre�laj�cy foramat Zapisu daty.
     NzF = Nie zdefiniowano formatu.
     w = Wiek
     r = rok
     mr = miesi�c rok
     dmr = dzie� miesi�c rok

     \enum
    */
    typedef enum {NzF=-1,w=5,r,mr,dmr} FormatDaty;
    /*!
     \brief
     Zwraca nazw� formatu daty w postaci std::string'a dla zadanej warto�ci eneumeratora.

     \fn nazwaFormatDaty
     \param formatDaty
    */
    static std::string nazwaFormatDaty(Meta::FormatDaty formatDaty);
    /*!
     \brief
     Zwraca warto�� enumeratora dla nazwy podanej jako std::string.

     \fn formatDatyNazwa
     \param formatDaty
    */
    static Meta::FormatDaty formatDatyNazwa(std::string formatDaty);
    /*!
     \brief
     Zwraca warto�� bool jako string ("Tak/Nie")

     \fn b2s
     \param b
    */
    static std::string b2s(bool b);
    /*!
     \brief
     Zwraca warto�� bool z interpretacji string

     \fn s2b
     \param b
    */
    static bool s2b(std::string b);
    /*!
     \brief
     Zwraca nazw� typu jako std::string dla zadanej warto�ci enumeratora.

     \fn nazwaTypu
     \param typ
    */
    static std::string nazwaTypu(int typ);
private:
/*!
 \brief
 Konstruktor jest w sekcji prywatnej gdy� korzystamy tylko z zdefiniowanych enumerator�w i funkcji
 statycznych.
 \fn Meta
*/
    Meta();
};

#endif // META_H
