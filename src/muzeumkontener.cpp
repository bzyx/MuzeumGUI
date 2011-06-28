/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utwór jest dostêpny na licencji
** Creative Commons
** Uznanie autorstwa-U¿ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/

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

/*
  Inicjalizacja zmiennej statycznej.

*/
MKontener MK::m_kontener;

/*
  Zwraca referencjê do obiektu. Klasa jest singletonem.

*/
MK& MK::getInstance()
{
    MK static kontener;
    return kontener;
}

/*
  Obiekt jest dodawany na koñcu listy. Zgodnie z rosn¹cymi id.

*/
void MK::addItem(EksponatMuzealny* e)
{
    m_kontener.push_back(e);
}

bool MK::deleteItem(int id){
    /*
      Szukamy obiektu o id podanym jak w parametrze i tak przesuwamy iterator,
      aby wskazywa³ na ten obiekt. Gdy ju¿ go mamy mo¿emy usun¹æ wskazywany obiekt.
      U¿ycie +1 by³o konieczne z b³êdów podczas usuwania ostatniego elementu.

    */
    bool ret = false;
    MKontener::iterator it;
    for( it=m_kontener.begin(); it!=m_kontener.end()+1; it++ )
    {
        if ((*it)->getId() == id){
            m_kontener.erase(it);
            ret = true;
            break;
        }
    }
    return ret;
}

/*
  Czyszczenie ca³ej listy.

*/
void MK::MK::deleteAll()
{
    m_kontener.clear();
}

/*
  Przez zastosowanie deque implementacja
  tej metody sta³a siê trywailna.

*/
EksponatMuzealny* MK::operator[](int id ){
    return m_kontener.at(id);
}

/*
  Zwraca wskaŸnik do wewnêtrznej listy.
  U¿ycie mocno nie zalecane.
  Mo¿e powodowaæ wiele szkód.

*/
MKontener* MK::getList(){
    return &m_kontener;
}

/*
  Zwraca liczbê obiektów wg. typu

*/
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

/*
  Zwraca liczbê wszyskich obiektów

*/
int MK::count(){
    return m_kontener.size();
}

/*
  Zapisuje ca³y kontener do pliku XML
  Ka¿da para atrybut wartoœæ ma tak¹ sam¹ reprezentacjê w pliku XML.
  Obiekty s¹ rozró¿niane za pomoc¹ tag'u rozpoczynaj¹cego który okreœla typ.
  W przypadku komplikacji wyœwietlany jest MessageBox

*/
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

/*
  Funkcja odczytuje dane z pliku.
  Rozpoznaje format generowany przez program.
  Zmiana kolejnoœci atrybutów nie powinno stanowiæ problemu.
  Wa¿na jest odpowiednia iloœæ argumentów.

*/
void MK::readFromFile(std::string filename){
    QFile file(filename.c_str());
    QXmlStreamAttributes attrs;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(0,QString("B³¹d pliku %1").arg(filename.c_str()),
                              "B³êdny format pliku, lub plik nie istnieje",QMessageBox::Ok);
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
                        if(xml.name() == "PrzedmiotU¿ytkowy"){
                            attrs = xml.attributes();
                            paraseAttributesAndAdd(Meta::PrzedmiotUzytkowy,&attrs);
                        } else
                            if(xml.name() == "RzeŸba"){
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
                QMessageBox::critical(0,QString("B³¹d pliku %1").arg(filename.c_str()),
                                      xml.errorString(),QMessageBox::Ok);

            }

        }
    }
}

/*
  Funkcja wykonywana podczas odczytywania.
  Zajmuje siê zliczaniuem argumentów.
  Odczytwywaniem ich i ich wartoœci.
  W pozytwny odczyt koñczy siê dodaniem obiektu do kontenera.
  B³êdy nie s¹ sygnalizowane w szczególny sposób - obiekt
  nie jest po prostu dopisany do kontenera.

*/
void MK::paraseAttributesAndAdd(Meta::Typ typ,QXmlStreamAttributes* attr){
    bool poprawnyRekord = true;
    for (int i=0; i < attr->count(); ++i)
        if(attr->at(i).value().isEmpty())
            poprawnyRekord = false;
    if(poprawnyRekord){
        EksponatMuzealny::lastId(attr->value("Id").toString().toInt());
        //    attr->at(1).value() -> Typ (nie potrzebne mamy z tagu XML)
        QString nazwa = attr->value("Nazwa").toString();//attr->at(2).value().toString();
        bool wystawiony = Meta::s2b(attr->value("Wystawiony").toString().toStdString());//Meta::s2b(attr->at(3).value().toString().toStdString());
        QString opis = attr->value("Opis").toString();
        QString polozenie = attr->value("Po³o¿enie").toString();
        int wartosc = attr->value("Wartoœæ").toString().toInt();
        Meta::FormatDaty fDaty = Meta::formatDatyNazwa(attr->value("Formatdaty").toString().toStdString());
        QString data = attr->value("Data").toString();

        switch(typ){
        case Meta::Mebel: {
            if(attr->count()-1 == 10){
                QString rodzaj = attr->value("Rodzaj").toString();
                int material = Material::valueForMatN(attr->value("Materia³").toString());
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
                float wys = attr->value("Wysokoœæ").toString().toDouble();
                float szer = attr->value("Szerokoœæ").toString().toDouble();
                QString autor = attr->value("Autor").toString();

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
                QString opisDzial = attr->value("Opisdzia³ania").toString();
                bool czyMoznaDot = Meta::s2b(attr->value("Czymo¿nadotykaæ").toString().toStdString());
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
                QString postac = attr->value("Postaæ").toString();
                int material = Material::valueForMatN(attr->value("Materia³").toString());
                float pow = attr->value("Powierzchnia").toString().toDouble();
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
                QString autor = attr->value("Autor").toString();
                QString streszczenie = attr->value("Streszczenie").toString();
                int lSton = attr->value("Liczbastron").toString().toInt();
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
