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

#include "mktyp.h"

/*
  Zwraca referencjê do obiektu. Bo klasa jest singletonem.

*/
MKTyp& MKTyp::getInstance(){
    MKTyp static kontenerTyp;
    return kontenerTyp;
}

void MKTyp::updateMKTyp(){
    /*
      Czyœcimy poprzednio ustawione identyfikatory obiektów.
      Teoretycznie mo¿na by dodawaæ nowe, ale wtedy jest problem z obs³ug¹ usuwania.

    */
    (m_Types[Meta::Mebel]).clear();
    (m_Types[Meta::Obraz]).clear();
    (m_Types[Meta::PrzedmiotUzytkowy]).clear();
    (m_Types[Meta::Rekopis]).clear();
    (m_Types[Meta::Rzezba]).clear();
    (m_Types[Meta::Starodruk]).clear();
    /*
      Dla ka¿dego obiektu z g³ównego kontenera:
        W nowym kontenerze: weŸ typ aktualnego obiektu - ustaw go jako wartoœæ klucza
                            do wektora przypisanego dla tego klucza dopisz numer aktualnego obiektu

    */
    for (int i=0; i< MK::getInstance().count();++i){
        (m_Types[ ( (MK::getInstance()[i])->getTyp() ) ]).push_back(i);
    }
}
/*
  Zwraca iloœæ obiektów dla danego typu w nowym kontenerze.

*/
int MKTyp::count(Meta::Typ typ){
    return m_Types[typ].size();
}
/*
  Zwraca wskaŸnik na i-ty (id) obiekt o typie podanym jako pierwszy parametr.
  Jeœli dla danego typu nie ma obiektów zwraca NULL

*/
EksponatMuzealny* MKTyp::getObjectFor(Meta::Typ typ,int id){
    if (m_Types[typ].size() >0){
        return MK::getInstance()[((m_Types[typ])[id])];
    } else
        return NULL;
}
MKTyp::MKTyp()
{
}
