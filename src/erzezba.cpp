
#include <QStringList>
#include <QString>
#include "erzezba.h"

std::string ERzezba::getPostac(){
    return m_postac;
}

void ERzezba::postac(std::string postac){
    m_postac = postac;
}

EksponatMuzealny::Material ERzezba::getMaterial(){
    return m_material;
}

void ERzezba::material(EksponatMuzealny::Material material){
    m_material = material;
}

float ERzezba::getPowierzchnia(){
    return m_powierzchnia;
}

void ERzezba::powierchnia(float powierzchnia){
    m_powierzchnia = powierzchnia;
}

ERzezba::ERzezba(std::string postac,
                 EksponatMuzealny::Material material, float powierzchnia,
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
    m_material = EksponatMuzealny::NieOkreslonoMaterialu;
    m_powierzchnia = 0.0;
}

QStringList ERzezba::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_postac.c_str()
        << Material2s(m_material).c_str()
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

