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

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <QXmlStreamReader>
#include <src/eksponatmuzealny.h>

/*!
 \brief
    Wewn�trzna struktura przechowywania danych. Wybra�em deque z powodu istnienia metod at i
    operatora[]. Poza tym ten kontener posiada zalety kontener�w vector i list.
    http://www.cplusplus.com/reference/stl/

 \typedef MKontener*/
typedef std::deque<EksponatMuzealny *> MKontener;

/*!
 \brief
 MK - MuzeumKontener klasa zarz�dza i przechowuje wszyskie obiekty eksponat�w.
 KLasa zosta�a zaprojektowana jako sigleton, aby u�atwi� dost�p do danych i nie prowadzi�
 do fragmentowania struktury danych.
 Mo�liwy jest dost�p bezpo�rednio do wewn�trznej struktry danych, jednak takie podej�cie
 jest MOCNO NIE ZALECNE, poniewa� mo�e doprowadzi� do niepoprawnego dzi�ania programu.
 Klasa jest odpowiedzialna za odczyt i zapis pliku z swoimi danymi w postaci pliku XML (StAX)

 \class MK muzeumkontener.h "src/muzeumkontener.h"
*/
class MK
{
public:
    /*!
     \brief
     Metoda zwracaj�ca referencj� do klasy.

     \fn getInstance
    */
    static MK& getInstance();
    /*!
     \brief
     Dodaje element do listy. Ewentualne sprawdzenie czy taki element ju� istnienje nale�y wykona�
     samodzielnie.

     \fn addItem
     \param e
    */
    void addItem(EksponatMuzealny *e);
    /*!
     \brief
      Usuwa element o zadanym identyfikatorze, elementu klasy
      EksponatMuzealny. Nie jest to r�wnoznaczne identyfikatorowi elementu w li�cie!

     \fn deleteItem
     \param id
    */
    bool deleteItem(int id);
    /*!
     \brief
     Usuwa wszyskie elementy z listy.

     \fn deleteAll
    */
    void deleteAll();
    /*!
     \brief
     Zwraca wska�nik do elementu o zdanym identyfikatorze. Zgodny z
     numerem elementu w li�cie.

     \fn operator []
     \param id
    */
    EksponatMuzealny* operator[] (int id);
    /*!
     \brief
     Zwraca wska�nik do wewn�trzej struktury.
     U�YCIE NIE WSKAZANE.

     \fn getList
    */
    MKontener* getList();
    /*!
     \brief
     Zwraca ilo�� element�w o zadanym typie.

     \fn countByTyp
     \param typ
    */
    int countByTyp(Meta::Typ typ);
    /*!
     \brief
     Zwraca ilo�� wszyskich element�w przechowywanych w kontenerze.

     \fn count
    */
    int count();
    /*!
     \brief
     Zapisuje ca�� list� do pliku o zadanej nazwie. W efekcie wygenerowuje plik xml.

     \fn saveToFile
     \param filename
    */
    void saveToFile(std::string filename);
    /*!
     \brief
     Odczytuje plik o zdanej nazwie. W przypadku b��du wy�wietla okno dialogowe.

     \fn readFromFile
     \param filename
    */
    void readFromFile(std::string filename);
private:
/*!
 \brief
 Prywatny konstruktor. Singleton.

 \fn MK
*/
    MK();
/*!
 \brief
  Prywatny konstruktor kopiuj�cy. Singleton.


 \fn MK
 \param
*/
    MK(const MK&);
    /*!
     \brief
      Prywatny operator przypisania. Singleton.

     \fn operator =
     \param
    */
    MK& operator=(const MK&);
    static MKontener m_kontener; /*!< Wewn�trzna lista przechuj�ca obiekty eksponat�w */

    /*!
     \brief
     Funkcja kt�ra przyjmuje specjalny typ w kt�rym s� atrybuty i ich wartosci wczytane z pliku
     XML. Dekoduje te warto�ci sprawdza i w przypadku je�li wszystko si� zgadza dodaje do listy.
     Zapami�tuje Id wczytane z pliku.

     \fn paraseAttributesAndAdd
     \param Meta::Typ
     \param attr
    */
    void paraseAttributesAndAdd(Meta::Typ,QXmlStreamAttributes* attr);
};

#endif // MK_H
