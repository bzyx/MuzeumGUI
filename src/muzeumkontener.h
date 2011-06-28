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

#ifndef MK_H
#define MK_H

#include <deque>
#include <string>
#include <QXmlStreamReader>
#include <src/eksponatmuzealny.h>

/*!
 \brief
    Wewnêtrzna struktura przechowywania danych. Wybra³em deque z powodu istnienia metod at i
    operatora[]. Poza tym ten kontener posiada zalety kontenerów vector i list.
    http://www.cplusplus.com/reference/stl/

 \typedef MKontener*/
typedef std::deque<EksponatMuzealny *> MKontener;

/*!
 \brief
 MK - MuzeumKontener klasa zarz¹dza i przechowuje wszyskie obiekty eksponatów.
 KLasa zosta³a zaprojektowana jako sigleton, aby u³atwiæ dostêp do danych i nie prowadziæ
 do fragmentowania struktury danych.
 Mo¿liwy jest dostêp bezpoœrednio do wewnêtrznej struktry danych, jednak takie podejœcie
 jest MOCNO NIE ZALECNE, poniewa¿ mo¿e doprowadziæ do niepoprawnego dzi³ania programu.
 Klasa jest odpowiedzialna za odczyt i zapis pliku z swoimi danymi w postaci pliku XML (StAX)

 \class MK muzeumkontener.h "src/muzeumkontener.h"
*/
class MK
{
public:
    /*!
     \brief
     Metoda zwracaj¹ca referencjê do klasy.

     \fn getInstance
    */
    static MK& getInstance();
    /*!
     \brief
     Dodaje element do listy. Ewentualne sprawdzenie czy taki element ju¿ istnienje nale¿y wykonaæ
     samodzielnie.

     \fn addItem
     \param e
    */
    void addItem(EksponatMuzealny *e);
    /*!
     \brief
      Usuwa element o zadanym identyfikatorze, elementu klasy
      EksponatMuzealny. Nie jest to równoznaczne identyfikatorowi elementu w liœcie!

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
     Zwraca wskaŸnik do elementu o zdanym identyfikatorze. Zgodny z
     numerem elementu w liœcie.

     \fn operator []
     \param id
    */
    EksponatMuzealny* operator[] (int id);
    /*!
     \brief
     Zwraca wskaŸnik do wewnêtrzej struktury.
     U¯YCIE NIE WSKAZANE.

     \fn getList
    */
    MKontener* getList();
    /*!
     \brief
     Zwraca iloœæ elementów o zadanym typie.

     \fn countByTyp
     \param typ
    */
    int countByTyp(Meta::Typ typ);
    /*!
     \brief
     Zwraca iloœæ wszyskich elementów przechowywanych w kontenerze.

     \fn count
    */
    int count();
    /*!
     \brief
     Zapisuje ca³¹ listê do pliku o zadanej nazwie. W efekcie wygenerowuje plik xml.

     \fn saveToFile
     \param filename
    */
    void saveToFile(std::string filename);
    /*!
     \brief
     Odczytuje plik o zdanej nazwie. W przypadku b³êdu wyœwietla okno dialogowe.

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
  Prywatny konstruktor kopiuj¹cy. Singleton.


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
    static MKontener m_kontener; /*!< Wewnêtrzna lista przechuj¹ca obiekty eksponatów */

    /*!
     \brief
     Funkcja która przyjmuje specjalny typ w którym s¹ atrybuty i ich wartosci wczytane z pliku
     XML. Dekoduje te wartoœci sprawdza i w przypadku jeœli wszystko siê zgadza dodaje do listy.
     Zapamiêtuje Id wczytane z pliku.

     \fn paraseAttributesAndAdd
     \param Meta::Typ
     \param attr
    */
    void paraseAttributesAndAdd(Meta::Typ,QXmlStreamAttributes* attr);
};

#endif // MK_H
