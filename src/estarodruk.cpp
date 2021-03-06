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
#include "estarodruk.h"
/*
  Wszystko tak jak w eksponamuzealny.cpp
  Zmian� s� inne nazwy funkcji. Implementacjia metod abstrakcjnych.

*/
std::string EStarodruk::getAutor(){
    return m_autor;
}
void EStarodruk::autor(std::string autor){
    m_autor = autor;
}
std::string EStarodruk::getStreszczenie(){
    return m_streszczenie;
}
void EStarodruk::sterszczenie(std::string streszczenie){
    m_streszczenie = streszczenie;
}
int EStarodruk::getLiczbaStron(){
    return m_liczbaStron;
}
void EStarodruk::liczbaStron(int liczbaStron){
    m_liczbaStron = liczbaStron;
}
EStarodruk::EStarodruk(std::string autor, std::string streszczenie, int liczbaStron,
                       std::string nazwa, bool wystawiony, std::string opis,
                       std::string polozenie, int wartosc,
                       Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data):
    EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_autor = autor;
    m_streszczenie = streszczenie;
    m_liczbaStron = liczbaStron;
}
EStarodruk::EStarodruk():EksponatMuzealny(){
    m_autor = "";
    m_streszczenie = "";
    m_liczbaStron =0;
}
QStringList EStarodruk::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_autor.c_str()
        << m_streszczenie.c_str()
        << QString::number(m_liczbaStron);
    nowa.append(tmp);
    return nowa;
}
QStringList EStarodruk::getHeaders(){

    QStringList nowa = getPodstawoweHeaders();
    nowa << "Autor"
         << "Streszczenie"
         << "Liczba stron";
    return nowa;
}
EksponatMuzealny::r2f EStarodruk::saveElement(){
    r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}
EStarodruk::~EStarodruk(){

}
