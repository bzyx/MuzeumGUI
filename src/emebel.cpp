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

#include <QStringList>
#include <QString>
#include "emebel.h"
/*
  Wszystko tak jak w eksponamuzealny.cpp
  Zmian¹ s¹ inne nazwy funkcji. Implementacjia metod abstrakcjnych.

*/

std::string EMebel::getRodzaj(){
    return m_rodzaj;
}
void EMebel::rodzaj(std::string rodzaj){
    m_rodzaj = rodzaj;
}
int EMebel::getMaterial(){
    return m_material;
}
void EMebel::material(int material){
    m_material=material;
}
EMebel::EMebel(std::string rodzaj,int material ,
               std::string nazwa, bool wystawiony, std::string opis,
               std::string polozenie, int wartosc,
               Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data):EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_rodzaj = rodzaj;
    m_material = material;
}
EMebel::EMebel():EksponatMuzealny(){
    m_rodzaj = "";
    m_material = 0;
}
QStringList EMebel::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_rodzaj.c_str()
        << Material::nazwaForMatV(m_material);
    nowa.append(tmp);
    return nowa;
}
QStringList EMebel::getHeaders(){
    QStringList nowa = getPodstawoweHeaders();
    nowa << "Rodzaj"
         << "Materia³";
    return nowa;
}
EksponatMuzealny::r2f EMebel::saveElement(){
    r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}
EMebel::~EMebel(){

}
