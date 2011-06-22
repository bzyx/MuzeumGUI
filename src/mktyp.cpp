#include "mktyp.h"
#include <QDebug>


MKTyp& MKTyp::getInstance(){
    MKTyp static kontenerTyp;
    return kontenerTyp;
}
void MKTyp::setTyp(Meta::Typ typ){
    m_typ=typ;
}
EksponatMuzealny* MKTyp::operator[](int id){
    return getObjectFor(m_typ,id);
}

void MKTyp::updateMKTyp(){
    (m_Types[Meta::Mebel]).clear();
    (m_Types[Meta::Obraz]).clear();
    (m_Types[Meta::PrzedmiotUzytkowy]).clear();
    (m_Types[Meta::Rekopis]).clear();
    (m_Types[Meta::Rzezba]).clear();
    (m_Types[Meta::Starodruk]).clear();
    for (int i=0; i< MK::getInstance().count();++i){
        //qDebug() << (int) ((MK::getInstance()[i])->getTyp());
        (m_Types[ ( (MK::getInstance()[i])->getTyp() ) ]).push_back(i);
    }
}
int MKTyp::count(Meta::Typ typ){
    return m_Types[typ].size();
}
EksponatMuzealny* MKTyp::getObjectFor(Meta::Typ typ,int id){
    if (m_Types[typ].size() >0){
        return MK::getInstance()[((m_Types[typ])[id])];
    } else
        return NULL;
}
MKTyp::MKTyp()
{
}
