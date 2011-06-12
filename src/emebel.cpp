
#include <QStringList>
#include <QString>
#include "emebel.h"

std::string EMebel::getRodzaj(){
    return m_rodzaj;
}
void EMebel::rodzaj(std::string rodzaj){
    m_rodzaj = rodzaj;
}
EksponatMuzealny::Material EMebel::getMaterial(){
    return m_material;
}
void EMebel::material(EksponatMuzealny::Material material){
    m_material=material;
}
EMebel::EMebel(std::string rodzaj,EksponatMuzealny::Material material ,
               std::string nazwa, bool wystawiony, std::string opis,
               std::string polozenie, int wartosc,
               Typ typ, FormatDaty formatDaty, std::string data):EksponatMuzealny(nazwa,wystawiony,opis,polozenie,
        wartosc,typ,formatDaty,data){
    m_rodzaj = rodzaj;
    m_material = material;
}
EMebel::EMebel():EksponatMuzealny(){
    m_rodzaj = "";
    m_material = EksponatMuzealny::NieOkreslonoMaterialu;
}
QStringList EMebel::getAtrybuty(){
    QStringList nowa = getPodstawoweAtrybuty();
    QStringList tmp;
    tmp << m_rodzaj.c_str()
        << EksponatMuzealny::Material2s(m_material).c_str();
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
};
