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
    for (int i=0; i< MK::getInstance().count();++i){
        qDebug() << (int) ((MK::getInstance()[i])->getTyp());
        (m_Types[ ( (MK::getInstance()[i])->getTyp() ) ]).push_back(i);
        //(m_Types[((MK::getInstance()[i])->getTyp())]).push_back(i);
    }

    //(m_Types[Meta::Obraz]).push_back(1);
    //(m_Types[Meta::Obraz]).push_back(2);
}
int MKTyp::count(Meta::Typ typ){
    return m_Types[typ].size();
}
EksponatMuzealny* MKTyp::getObjectFor(Meta::Typ typ,int id){
    return MK::getInstance()[((m_Types[typ])[id])];
}
MKTyp::MKTyp()
{
}
