
#include <QStringList>
#include <QString>
#include "eobraz.h"

/**
 * @brief
 *
 * @return float
 */
float EObraz::getWysokosc(){
    return m_wysokosc;
}

/**
 * @brief
 *
 * @param w
 */
void EObraz::wysokosc(float w){
    m_wysokosc = w;
}

/**
 * @brief
 *
 * @return float
 */
float EObraz::getSzerokosc(){
    return m_szerokosc;
}

/**
 * @brief
 *
 * @param s
 */
void EObraz::szerokosc(float s){
    m_szerokosc = s;
}

/**
 * @brief
 *
 * @return std::string
 */
std::string EObraz::getAutor(){
    return m_autor;
}

/**
 * @brief
 *
 * @param autor
 */
void EObraz::autor(std::string autor){
    m_autor = autor;
}

/**
 * @brief
 *
 * @param w
 * @param s
 * @param autor
 * @param nazwa
 * @param wystawiony
 * @param opis
 * @param polozenie
 * @param wartosc
 * @param typ
 * @param formatDaty
 * @param data
 */
EObraz::EObraz(float w, float s, std::string autor,
       std::string nazwa, bool wystawiony, std::string opis,
       std::string polozenie, int wartosc,
       Typ typ, FormatDaty formatDaty, std::string data):
    EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_wysokosc = w;
    m_szerokosc = s;
    m_autor = autor;
}

/**
 * @brief
 *
 */
/**
 * @brief
 *
 */
EObraz::EObraz():EksponatMuzealny(){
    m_wysokosc = 0.0;
    m_szerokosc = 0.0;
    m_autor = "";
}

/**
 * @brief
 *
 * @return QStringList
 */
/**
 * @brief
 *
 * @return QStringList
 */
QStringList EObraz::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << QString::number(m_wysokosc)
        << QString::number(m_szerokosc)
        << m_autor.c_str();
    nowa.append(tmp);
    return nowa;
}
/**
 * @brief
 *
 * @return QStringList
 */
/**
 * @brief
 *
 * @return QStringList
 */
/**
 * @brief
 *
 * @return QStringList
 */
QStringList EObraz::getHeaders(){
    QStringList nowa = getPodstawoweHeaders();
    nowa << "Wysokoœæ"
         << "Szerokoœæ"
         << "Autor";
    return nowa;
}

/**
 * @brief
 *
 * @return EksponatMuzealny::r2f
 */
/**
 * @brief
 *
 * @return EksponatMuzealny::r2f
 */
EksponatMuzealny::r2f EObraz::saveElement(){
//    typedef QPair<QString, QString> krotka;
//    typedef QList<krotka> r2f;
    r2f data;
    QStringList h = getHeaders();
    QStringList a = getAtrybuty();
    for (int i=0; i<h.size(); i++)
        data.append(qMakePair(h[i],a[i]));
    return data;
}

/**
 * @brief
 *
 */
/**
 * @brief
 *
 */
EObraz::~EObraz(){

}
