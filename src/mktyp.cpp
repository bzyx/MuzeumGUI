#include "mktyp.h"


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
    (m_Types[Meta::Obraz]).push_back(1);
    (m_Types[Meta::Obraz]).push_back(2);
}
EksponatMuzealny* MKTyp::getObjectFor(Meta::Typ typ,int id){
    return MK::getInstance()[((m_Types[typ])[id])];
}
MKTyp::MKTyp()
{
}
