#include <QFile>
#include <QMessageBox>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QList>
#include <QPair>
#include <deque>

#include "muzeumkontener.h"

#include "src/emebel.h"
#include "src/eobraz.h"
#include "src/eprzemiotuzytkowy.h"
#include "src/erekopis.h"
#include "src/erzezba.h"
#include "src/estarodruk.h"

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
        QMessageBox::warning(0,"B≥πd pliku",
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
            xmlWriter->writeStartElement(l_toFile[1].second.simplified().replace(" ",""));
            while (it != l_toFile.end() ){
                xmlWriter->writeAttribute((*it).first.simplified().replace(" ",""),(*it).second);
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
    QXmlStreamAttributes attrs;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(0,QString("B≥πd pliku %1").arg(filename.c_str()),
                              "B≥Ídny format pliku, lub plik nie istnieje",QMessageBox::Ok);
    } else {
        MK::getInstance().deleteAll();
        EksponatMuzealny::lastId(0);


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
                if(xml.name() == "Mebel"){
                    attrs = xml.attributes();
                    paraseAttributesAndAdd(Meta::Mebel,&attrs);
                } else
                    if(xml.name() == "Obraz"){
                        attrs = xml.attributes();
                        paraseAttributesAndAdd(Meta::Obraz,&attrs);
                    } else
                        if(xml.name() == "PrzedmiotUøytkowy"){
                            attrs = xml.attributes();
                            paraseAttributesAndAdd(Meta::PrzedmiotUzytkowy,&attrs);
                        } else
                            if(xml.name() == "Rzeüba"){
                                attrs = xml.attributes();
                                paraseAttributesAndAdd(Meta::Rzezba,&attrs);
                            } else
                                if(xml.name() == "Rekopis"){
                                    attrs = xml.attributes();
                                    paraseAttributesAndAdd(Meta::Rekopis,&attrs);
                                } else
                                    if(xml.name() == "Starodruk"){
                                        attrs = xml.attributes();
                                        paraseAttributesAndAdd(Meta::Starodruk,&attrs);
                                    }
                                    else {

                                    }
            }

            if(xml.hasError()){
                QMessageBox::critical(0,QString("B≥πd pliku %1").arg(filename.c_str()),
                                      xml.errorString(),QMessageBox::Ok);

            }

        }
        //xml.clear();
    }
}

void MK::paraseAttributesAndAdd(Meta::Typ typ,QXmlStreamAttributes* attr){
    bool poprawnyRekord = true;
    for (int i=0; i < attr->count(); ++i)
        if(attr->at(i).value().isEmpty())
            poprawnyRekord = false;
    if(poprawnyRekord){
        //    attr->at(0).value() -> Id (nie potrzebne)
        //    attr->at(1).value() -> Typ (nie potrzebne mamy z tagu XML)
        QString nazwa = attr->at(2).value().toString();
        bool wystawiony = Meta::s2b(attr->at(3).value().toString().toStdString());
        QString opis = attr->at(4).value().toString();
        QString polozenie = attr->at(5).value().toString();
        int wartosc = attr->at(6).value().toString().toInt();
        Meta::FormatDaty fDaty = Meta::formatDatyNazwa(attr->at(7).value().toString().toStdString());
        QString data = attr->at(8).value().toString();

        switch(typ){
        case Meta::Mebel: {
            if(attr->count()-1 == 10){
                QString rodzaj = attr->at(9).value().toString();
                int material = Material::valueForMatN(attr->at(10).value().toString());
                MK::getInstance().addItem(new EMebel(rodzaj.toStdString(),material,
                                                     nazwa.toStdString(), wystawiony,
                                                     opis.toStdString(),
                                                     polozenie.toStdString(),
                                                     wartosc,
                                                     Meta::Mebel, fDaty,data.toStdString()) );
            }
            break;}
        case Meta::Obraz: {
            if(attr->count()-1 == 11){
                float wys = attr->at(9).value().toString().toDouble();
                float szer = attr->at(10).value().toString().toDouble();
                QString autor = attr->at(11).value().toString();

                MK::getInstance().addItem(new EObraz(wys,szer,autor.toStdString(),
                                                     nazwa.toStdString(), wystawiony,
                                                     opis.toStdString(),
                                                     polozenie.toStdString(),
                                                     wartosc,
                                                     Meta::Obraz, fDaty,data.toStdString()) );
            }

            break;}
        case Meta::PrzedmiotUzytkowy: {
            if(attr->count()-1 == 10){
                QString opisDzial = attr->at(9).value().toString();
                bool czyMoznaDot = Meta::s2b(attr->at(10).value().toString().toStdString());
                MK::getInstance().addItem(new EPrzemiotUzytkowy(opisDzial.toStdString(),czyMoznaDot,
                                                                nazwa.toStdString(), wystawiony,
                                                                opis.toStdString(),
                                                                polozenie.toStdString(),
                                                                wartosc,
                                                                Meta::PrzedmiotUzytkowy, fDaty,data.toStdString()) );
            }

            break;}
        case Meta::Rekopis: {
            if(attr->count()-1 == 10){
                QString autor = attr->at(9).value().toString();
                bool zeskanowany = Meta::s2b(attr->at(10).value().toString().toStdString());
                MK::getInstance().addItem(new ERekopis(autor.toStdString(),zeskanowany,
                                                       nazwa.toStdString(), wystawiony,
                                                       opis.toStdString(),
                                                       polozenie.toStdString(),
                                                       wartosc,
                                                       Meta::Rekopis, fDaty,data.toStdString()) );
            }
            break;}
        case Meta::Rzezba: {
            if(attr->count()-1 == 11){
                QString postac = attr->at(9).value().toString();
                int material = Material::valueForMatN(attr->at(10).value().toString());
                float pow = attr->at(11).value().toString().toDouble();
                MK::getInstance().addItem(new ERzezba(postac.toStdString(),material, pow,
                                                      nazwa.toStdString(), wystawiony,
                                                      opis.toStdString(),
                                                      polozenie.toStdString(),
                                                      wartosc,
                                                      Meta::Rzezba, fDaty,data.toStdString()) );
            }
            break;}
        case Meta::Starodruk: {
            if(attr->count()-1 == 11){
                QString autor = attr->at(9).value().toString();
                QString streszczenie = attr->at(10).value().toString();
                int lSton = attr->at(11).value().toString().toInt();
                MK::getInstance().addItem(new EStarodruk(autor.toStdString(),streszczenie.toStdString(),lSton,
                                                         nazwa.toStdString(), wystawiony,
                                                         opis.toStdString(),
                                                         polozenie.toStdString(),
                                                         wartosc,
                                                         Meta::Starodruk, fDaty,data.toStdString()) );
            }
            break;}
        }
    }
}

MK::MK()
{
}
