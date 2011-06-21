

#include "muzeumkontener.h"
MKontener MK::m_kontener;


MK& MK::getInstance()
{
    MK static kontener;
    return kontener;
}

void MK::addItem(EksponatMuzealny* e)
{
    m_kontener.push_back(e);
}

bool MK::deleteItem(int id){
    bool ret = false;
    MKontener::iterator it;
    for( it=m_kontener.begin(); it!=m_kontener.end(); ++it )
    {
        if ((*it)->getId() == id){
            m_kontener.erase(it);
            ret = true;
        }
    }
    return ret;
}

void MK::MK::deleteAll()
{
    m_kontener.clear();
}

EksponatMuzealny* MK::operator[](int id ){
    //    MKontener::iterator it;
    //    for( it=m_kontener.begin(); it!=m_kontener.end(); ++it )
    //    {
    //        if ((*it)->getId() == id){
    //            return (*it);
    //        }
    //    }
    //    return NULL;
    return m_kontener.at(id);
}
MKontener* MK::getList(){
    return &m_kontener;
}

int MK::countByTyp(Meta::Typ typ){
    int licznik = 0;
    MKontener::iterator it;
    for( it=m_kontener.begin(); it!=m_kontener.end(); ++it )
    {
        if ((*it)->getTyp() == typ){
            ++licznik;
        }
    }
    return licznik;
}
int MK::count(){
    return m_kontener.size();
}
EksponatMuzealny* MK::getObjectOfTyp(Meta::Typ typ){
    for( itForTyp=m_kontener.begin(); itForTyp!=m_kontener.end(); ++itForTyp )
    {
        if ((*itForTyp)->getTyp() == typ){
            return (*itForTyp);
        }
    }
    return NULL;
}

EksponatMuzealny* MK::next(Meta::Typ typ){
    for(; itForTyp!=m_kontener.end(); ++itForTyp )
    {
        if ((*itForTyp)->getTyp() == typ){
            return (*itForTyp);
        }

    }
    return NULL;
}

void MK::saveToFile(std::string filename){
    //TODO: PUSTE
}
void MK::readFromFile(std::string filename){
    //TODO: PUSTE
}

MK::MK()
{
}
