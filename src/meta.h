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

#ifndef META_H
#define META_H
#include <string>
/*!
 \brief
 Klasa Meta zawiera klika przydatnych metdod i enumeratorów które s¹ u¿ywane przez rodzinê klas
     wyprowadzon¹ z EksponatMuzealny. Zawiera definicjê ró¿nych typów i metody do ich obs³ugi.

 \class Meta meta.h "src/meta.h"
*/
class Meta
{
public:
    /*!
     \brief
     Enumerator okreœlaj¹cy typ eksponatu. Ka¿dy eksponat MUSI miec okreœlony swój typ.

     \enum
    */
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ; /*!< Okreœla typ ekspoantu */

    /*!
     \brief
     Enumerator okreœlaj¹cy foramat Zapisu daty.
     NzF = Nie zdefiniowano formatu.
     w = Wiek
     r = rok
     mr = miesi¹c rok
     dmr = dzieñ miesi¹c rok

     \enum
    */
    typedef enum {NzF=-1,w=5,r,mr,dmr} FormatDaty;
    /*!
     \brief
     Zwraca nazwê formatu daty w postaci std::string'a dla zadanej wartoœci eneumeratora.

     \fn nazwaFormatDaty
     \param formatDaty
    */
    static std::string nazwaFormatDaty(Meta::FormatDaty formatDaty);
    /*!
     \brief
     Zwraca wartoœæ enumeratora dla nazwy podanej jako std::string.

     \fn formatDatyNazwa
     \param formatDaty
    */
    static Meta::FormatDaty formatDatyNazwa(std::string formatDaty);
    /*!
     \brief
     Zwraca wartoœæ bool jako string ("Tak/Nie")

     \fn b2s
     \param b
    */
    static std::string b2s(bool b);
    /*!
     \brief
     Zwraca wartoœæ bool z interpretacji string

     \fn s2b
     \param b
    */
    static bool s2b(std::string b);
    /*!
     \brief
     Zwraca nazwê typu jako std::string dla zadanej wartoœci enumeratora.

     \fn nazwaTypu
     \param typ
    */
    static std::string nazwaTypu(int typ);
private:
/*!
 \brief
 Konstruktor jest w sekcji prywatnej gdy¿ korzystamy tylko z zdefiniowanych enumeratorów i funkcji
 statycznych.
 \fn Meta
*/
    Meta();
};

#endif // META_H
