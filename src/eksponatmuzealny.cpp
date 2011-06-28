#include "eksponatmuzealny.h"

using std::string;
int EksponatMuzealny::m_lastid = 0;

int EksponatMuzealny::getId(){
    return m_id;
}
void EksponatMuzealny::id(int id){
    m_id = id;
}
string EksponatMuzealny::getNazwa(){
    return m_nazwa;
}
void EksponatMuzealny::nazwa(string nazwa){
    m_nazwa = nazwa;
}
bool EksponatMuzealny::getWystawiony(){
    return m_wystawiony;
}
void EksponatMuzealny::wystawiony(bool wystawiony){
    m_wystawiony=wystawiony;
}
string EksponatMuzealny::getOpis(){
    return m_opis;
}
void EksponatMuzealny::opis(std::string opis){
    m_opis = opis;
}
string EksponatMuzealny::getPolozenie(){
    return m_polozenie;
}
void EksponatMuzealny::polozenie(std::string polozenie){
    m_polozenie = polozenie;
}
int EksponatMuzealny::getWartosc(){
    return m_wartosc;
}
void EksponatMuzealny::wartosc(int wartosc){
    m_wartosc = wartosc;
}

Meta::Typ EksponatMuzealny::getTyp(){
    return m_typ;
}
void EksponatMuzealny::Typ(Meta::Typ typ){
    m_typ = typ;
}
Meta::FormatDaty EksponatMuzealny::getFormatDaty(){
    return m_FormatDaty;
}
void EksponatMuzealny::formatDaty(Meta::FormatDaty formatDaty){
    m_FormatDaty = formatDaty;
}
string EksponatMuzealny::getData(){
    return m_data;
}
void EksponatMuzealny::data(std::string data){
    m_data = data;
}
EksponatMuzealny::EksponatMuzealny()
{
    m_id = EksponatMuzealny::m_lastid;
    m_lastid++;
    m_typ = Meta::NieOkreslonoTypu;
    m_nazwa = "Bez Nazwy";
}
EksponatMuzealny::EksponatMuzealny(std::string nazwa, bool wystawiony,
                                   std::string opis, std::string polozenie,
                                   int wartosc, Meta::Typ typ, Meta::FormatDaty formatDaty,
                                   std::string data)
{
    m_id = EksponatMuzealny::m_lastid;
    m_lastid++;
    m_nazwa = nazwa;
    m_wystawiony = wystawiony;
    m_opis = opis;
    m_polozenie = polozenie;
    m_wartosc = wartosc;
    m_typ = typ;
    m_FormatDaty = formatDaty;
    m_data = data;
}
void EksponatMuzealny::lastId(int id){
    EksponatMuzealny::m_lastid = id;
}

int EksponatMuzealny::getLastId(){
    return EksponatMuzealny::m_lastid;
}
QStringList EksponatMuzealny::getPodstawoweAtrybuty(){
/*
  Tworzymy now¹ instancjê listy.
  Nastêpnie u¿ywaj¹c przeci¹zonego operatora <<
  dodajemy kolejne atrybuty przekonwertowne na
  QString lub C-String

 */
    QStringList pA;
    pA << QString::number(m_id)
       << QString(Meta::nazwaTypu(m_typ).c_str())
       << m_nazwa.c_str()
       << Meta::b2s(m_wystawiony).c_str()
       << m_opis.c_str()
       << m_polozenie.c_str()
       << QString::number(m_wartosc)
       << Meta::nazwaFormatDaty(m_FormatDaty).c_str()
       << m_data.c_str();
    return pA;
}
QStringList EksponatMuzealny::getPodstawoweHeaders(){
    /*
     Argumenty s¹ podane jako bezpoœrednie C-Stringi

    */
    QStringList pH;
    pH << "Id"
       << "Typ"
       << "Nazwa"
       << "Wystawiony"
       << "Opis"
       << "Po³o¿enie"
       << "Wartoœæ"
       << "Format daty"
       << "Data";
    return pH;
}
EksponatMuzealny::~EksponatMuzealny(){

}
