#include <string>
#include <QString>
#include <QStringList>
#include <QPair>
#include <QList>

#include "eksponatmuzealny.h"

using std::string;
int EksponatMuzealny::m_lastid = 0; /**< TODO */

/**
 * @brief
 *
 * @return int
 */
int EksponatMuzealny::getId(){
    return m_id;
}

/**
 * @brief
 *
 * @param id
 */
void EksponatMuzealny::id(int id){
    m_id = id;
}

/**
 * @brief
 *
 * @return string
 */
string EksponatMuzealny::getNazwa(){
    return m_nazwa;
}

/**
 * @brief
 *
 * @param nazwa
 */
void EksponatMuzealny::nazwa(string nazwa){
    m_nazwa = nazwa;
}

/**
 * @brief
 *
 * @return bool
 */
bool EksponatMuzealny::getWystawiony(){
    return m_wystawiony;
}

/**
 * @brief
 *
 * @param wystawiony
 */
void EksponatMuzealny::wystawiony(bool wystawiony){
    m_wystawiony=wystawiony;
}

/**
 * @brief
 *
 * @return string
 */
string EksponatMuzealny::getOpis(){
    return m_opis;
}

/**
 * @brief
 *
 * @param opis
 */
void EksponatMuzealny::opis(std::string opis){
    m_opis = opis;
}

/**
 * @brief
 *
 * @return string
 */
string EksponatMuzealny::getPolozenie(){
    return m_polozenie;
}

/**
 * @brief
 *
 * @param polozenie
 */
void EksponatMuzealny::polozenie(std::string polozenie){
    m_polozenie = polozenie;
}

/**
 * @brief
 *
 * @return int
 */
int EksponatMuzealny::getWartosc(){
    return m_wartosc;
}

/**
 * @brief
 *
 * @param wartosc
 */
void EksponatMuzealny::wartosc(int wartosc){
    m_wartosc = wartosc;
}

/**
 * @brief
 *
 * @return EksponatMuzealny::Typ
 */
EksponatMuzealny::Typ EksponatMuzealny::getTyp(){
    return m_typ;
}

/**
 * @brief
 *
 * @param typ
 */
void EksponatMuzealny::typ(EksponatMuzealny::Typ typ){
    m_typ = typ;
}

/**
 * @brief
 *
 * @return EksponatMuzealny::FormatDaty
 */
EksponatMuzealny::FormatDaty EksponatMuzealny::getFormatDaty(){
    return m_FormatDaty;
}

/**
 * @brief
 *
 * @param formatDaty
 */
void EksponatMuzealny::formatDaty(FormatDaty formatDaty){
    m_FormatDaty = formatDaty;
}

/**
 * @brief
 *
 * @return string
 */
string EksponatMuzealny::getData(){
    return m_data;
}

/**
 * @brief
 *
 * @param data
 */
void EksponatMuzealny::data(std::string data){
    m_data = data;
}


/**
 * @brief
 *
 */
EksponatMuzealny::EksponatMuzealny()
{
    m_id = EksponatMuzealny::m_lastid;
    m_lastid++;
    m_typ = EksponatMuzealny::NieOkreslonoTypu;
    m_nazwa = "Bez Nazwy";
}

/**
 * @brief
 *
 * @param nazwa
 * @param wystawiony
 * @param opis
 * @param polozenie
 * @param wartosc
 * @param typ
 * @param formatDaty
 * @param data
 */
EksponatMuzealny::EksponatMuzealny(std::string nazwa, bool wystawiony,
                                   std::string opis, std::string polozenie,
                                   int wartosc, Typ typ, FormatDaty formatDaty,
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
    //TODO: Sprawdzenie czy poprawna data wg formatu
    m_FormatDaty = formatDaty;
    m_data = data;
}

/**
 * @brief
 *
 * @param id
 */
void EksponatMuzealny::lastId(int id){
    EksponatMuzealny::m_lastid = id;
}

/**
 * @brief
 *
 * @return QStringList
 */
QStringList EksponatMuzealny::getPodstawoweAtrybuty(){
    QStringList pA;
    pA << QString::number(m_id)
       << QString(nazwaTypu(m_typ).c_str())
       << m_nazwa.c_str()
       << b2s(m_wystawiony).c_str()
       << m_opis.c_str()
       << m_polozenie.c_str()
       << QString::number(m_wartosc)
       << nazwaFormatDaty(m_FormatDaty).c_str()
       << m_data.c_str();
    return pA;
}

/**
 * @brief
 *
 * @return QStringList
 */
QStringList EksponatMuzealny::getPodstawoweHeaders(){
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

/**
 * @brief
 *
 * @param typ
 * @return string
 */
string EksponatMuzealny::nazwaTypu(EksponatMuzealny::Typ typ){
    switch (typ)
    {
    case 5:
        return "Obraz";
    case 6:
        return "Przedmiot U¿ytkowy";
    case 7:
        return "RzeŸba";
    case 8:
        return "Mebel";
    case 9:
        return "Rekopis";
    case 10:
        return "Starodruk";
    default:
        return "Nieznay typ";
    }
}

/**
 * @brief
 *
 * @param formatDaty
 * @return string
 */
string EksponatMuzealny::nazwaFormatDaty(
    EksponatMuzealny::FormatDaty formatDaty){
    switch(formatDaty)
    {
    case 5:
        return "w";
    case 6:
        return "r";
    case 7:
        return "mr";
    case 8:
        return "dmr";
    default:
        return "NieznayFormat";
    }
}

/**
 * @brief
 *
 * @param b
 * @return string
 */
string EksponatMuzealny::b2s(bool b){
    if(b)
        return "Tak";
    else
        return "Nie";
}

/**
 * @brief
 *
 */
EksponatMuzealny::~EksponatMuzealny(){

}

string EksponatMuzealny::Material2s(Material m){
    switch(m)
    {
    case 5:
        return "Braz";
    case 6:
        return "Drewno";
    case 7:
        return "Gips";
    case 8:
        return "Glina";
    case 9:
        return "Granit";
    case 10:
        return "Marmur";
    case 11:
        return "Metal";
    case 12:
        return "Mosi¹dz";
    case 13:
        return "Piaskowiec";
    case 14:
        return "Srebro";
    case 15:
        return "Z³oto";
    default:
        return "Nie Okreslono Materialu";
    }
}
