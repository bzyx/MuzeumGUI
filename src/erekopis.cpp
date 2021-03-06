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

#include <QStringList>
#include <QString>
#include "erekopis.h"
/*
  Wszystko tak jak w eksponamuzealny.cpp
  Zmian� s� inne nazwy funkcji. Implementacjia metod abstrakcjnych.

*/
std::string ERekopis::getAutor(){
    return m_autor;
}
void ERekopis::autor(std::string autor){
    m_autor=autor;
}
bool ERekopis::getCzyZeskanowany(){
    return m_czyZeskanowany;
}
void ERekopis::czyZeskanowany(bool czyZeskanowany){
    m_czyZeskanowany = czyZeskanowany;
}

ERekopis::ERekopis(std::string autor, bool czyZeskanowany,
         std::string nazwa, bool wystawiony, std::string opis,
         std::string polozenie, int wartosc,
         Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data):EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_autor = autor;
    m_czyZeskanowany = czyZeskanowany;
}
ERekopis::ERekopis(){
    m_autor = "";
    m_czyZeskanowany = false;
}
QStringList ERekopis::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_autor.c_str()
        << Meta::b2s(m_czyZeskanowany).c_str();
    nowa.append(tmp);
    return nowa;
}
QStringList ERekopis::getHeaders(){
    QStringList nowa = getPodstawoweHeaders();
    nowa << "Autor"
         << "Zeskanowany";
    return nowa;
}
EksponatMuzealny::r2f ERekopis::saveElement(){
    r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}
ERekopis::~ERekopis(){

}
