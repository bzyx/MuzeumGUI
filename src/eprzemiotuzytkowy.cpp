
#include <QStringList>
#include <QString>
#include "eprzemiotuzytkowy.h"

std::string EPrzemiotUzytkowy::getOpisDzialania(){
    return m_opisDzialania;
}
void EPrzemiotUzytkowy::opisDzialania(std::string opisDzialania){
    m_opisDzialania = opisDzialania;
}
bool EPrzemiotUzytkowy::getCzyMoznaDotykac(){
    return m_czyMoznaDotykac;
}
void EPrzemiotUzytkowy::czyMoznaDotykac(bool czyMoznaDotykac){
    m_czyMoznaDotykac = czyMoznaDotykac;
}
EPrzemiotUzytkowy::EPrzemiotUzytkowy
(std::string opisDzialania, bool czyMoznaDotykac,
 std::string nazwa, bool wystawiony, std::string opis,
 std::string polozenie, int wartosc,
 Meta::Typ typ, FormatDaty formatDaty, std::string data):
    EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data)
{
    m_opisDzialania = opisDzialania;
    m_czyMoznaDotykac = czyMoznaDotykac;
}


EPrzemiotUzytkowy::EPrzemiotUzytkowy(){
    m_opisDzialania = "";
    m_czyMoznaDotykac = false;
}
QStringList EPrzemiotUzytkowy::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_opisDzialania.c_str()
        << b2s(m_czyMoznaDotykac).c_str();
    nowa.append(tmp);
    return nowa;
}
QStringList EPrzemiotUzytkowy::getHeaders(){
    QStringList nowa = getPodstawoweHeaders();
    nowa << "Opis dzia³ania"
         << "Czy mo¿na dotykaæ";
    return nowa;
}
EksponatMuzealny::r2f EPrzemiotUzytkowy::saveElement(){
    EksponatMuzealny::r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}
EPrzemiotUzytkowy::~EPrzemiotUzytkowy(){

}
