

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
    MKontener::iterator it;
    for( it=m_kontener.begin(); it!=m_kontener.end(); ++it )
    {
        if ((*it)->getId() == id){
            return (*it);
        }
    }
    return NULL;
}
MKontener* MK::getList(){
    return &m_kontener;
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
