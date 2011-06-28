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
#include "erzezba.h"
/*
  Wszystko tak jak w eksponamuzealny.cpp
  Zmian¹ s¹ inne nazwy funkcji. Implementacjia metod abstrakcjnych.

*/
std::string ERzezba::getPostac(){
    return m_postac;
}

void ERzezba::postac(std::string postac){
    m_postac = postac;
}

int ERzezba::getMaterial(){
    return m_material;
}

void ERzezba::material(int material){
    m_material = material;
}

float ERzezba::getPowierzchnia(){
    return m_powierzchnia;
}

void ERzezba::powierchnia(float powierzchnia){
    m_powierzchnia = powierzchnia;
}

ERzezba::ERzezba(std::string postac,
                 int material, float powierzchnia,
                 std::string nazwa, bool wystawiony, std::string opis,
                 std::string polozenie, int wartosc,
                 Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data):
    EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_postac = postac;
    m_material = material;
    m_powierzchnia = powierzchnia;
}

ERzezba::ERzezba():EksponatMuzealny(){
    m_postac = "";
    m_material = 0;
    m_powierzchnia = 0.0;
}

QStringList ERzezba::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_postac.c_str()
        << Material::nazwaForMatV(m_material)
        << QString::number(m_powierzchnia);
    nowa.append(tmp);
    return nowa;
}

QStringList ERzezba::getHeaders(){
    QStringList nowa = getPodstawoweHeaders();
    nowa << "Postaæ"
         << "Materia³"
         << "Powierzchnia";
    return nowa;
}
EksponatMuzealny::r2f ERzezba::saveElement(){
    r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}
ERzezba::~ERzezba(){

}

