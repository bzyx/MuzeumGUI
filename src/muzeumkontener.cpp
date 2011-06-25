#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QList>
#include <QPair>
#include <deque>

#include <QDebug>
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
    QFile file(filename.c_str());

    if (!file.open(QIODevice::WriteOnly)){
        QMessageBox::warning(0,"B³¹d pliku",
                             "Plik jest zablokowany przed zapisem",
                             QMessageBox::Ok);
    } else {
        QXmlStreamWriter* xmlWriter = new QXmlStreamWriter();
        xmlWriter->setDevice(&file);
        xmlWriter->setAutoFormatting(true);
        xmlWriter->writeStartDocument();
        xmlWriter->writeStartElement("eksponaty");

        MKontener::iterator mk_it;
        QList<QPair<QString, QString> >::iterator it;
        QList<QPair<QString, QString> > l_toFile;
        mk_it = m_kontener.begin();
        while( mk_it!=m_kontener.end() ){
            l_toFile = (*mk_it)->saveElement();
            it = l_toFile.begin();
            xmlWriter->writeStartElement(l_toFile[1].second.replace(" ",""));
            while (it != l_toFile.end() ){
                xmlWriter->writeAttribute((*it).first.replace(" ",""),(*it).second);
                it++;
            }
            xmlWriter->writeEndElement();
            mk_it++;
        }
        xmlWriter->writeEndElement();
        xmlWriter->writeEndDocument();
    }
}
void MK::readFromFile(std::string filename){
    QFile file(filename.c_str());

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(0,QString("B³¹d pliku %1").arg(filename.c_str()),
                              "B³êdny format pliku, lub plik nie istnieje",QMessageBox::Ok);
    } else {
        int i = 0;
        QXmlStreamReader xml(&file);
        while(!xml.atEnd() && !xml.hasError()){
        QXmlStreamReader::TokenType token = xml.readNext();

        if(token == QXmlStreamReader::StartDocument){
            continue;
        }
        if(token == QXmlStreamReader::StartElement){
            if(xml.name() == "eksponaty"){
                continue;
            }
                if(xml.name() == "Obraz"){
                    i++;
                    QXmlStreamAttributes attrs = xml.attributes();
                    qDebug() <<i << attrs.value("Id") << "Mam obraz";
                }
        }

            if(xml.hasError()){
                QMessageBox::critical(0,QString("B³¹d pliku %1").arg(filename.c_str()),
                                      xml.errorString(),QMessageBox::Ok);

            }

        }
    xml.clear();
    }
}

MK::MK()
{
}
