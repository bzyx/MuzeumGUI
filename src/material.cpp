/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utw�r jest dost�pny na licencji
** Creative Commons
** Uznanie autorstwa-U�ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/

#include "material.h"
/*
  Zwraca referencj� do singletonu.

*/
Material& Material::getInstance(){
    Material static material;
    return material;
}

/*
  Dodaje nowy materia�.

*/
void Material::addMaterial(QString name){
    lastMatnum++;
    /*
      Dodajemy materia� tylko wtedy gdy nie istenie jeszcze
      materia� o takiej nazwie.
      Wtedy wyszukanie w map'ie zwr�ci warto�� 0.

    */
    if (materialy.value(name)==0 )
     materialy.insert(name,lastMatnum);
    else
        lastMatnum--;
}
/*
  Zwraca wska�nik do wewn�trznej struktury danych.

*/
QMap<QString,int>* Material::getMap(){
    return &materialy;
}
/*
  Zwraca nazw� materia�u dla zadanego klucza (identyfikatora materia�u)

*/
QString Material::nazwaForMatV(int material_key){
    QString returnValue = (Material::getInstance().getMap())->key(material_key);
    /*
      Je�li zwr�cona warto�� jest pusta zwracamy "Nieznany Materia�"

    */
    if (returnValue.isEmpty() || returnValue.isNull())
        returnValue = "Nieznay Materia�";
    return returnValue;
}
/*
  Zwraca identyfikator materia�u dla zadanej nazwy.
  W przypdaku podania z�ej nazwy/nie istnienia zwracana jest warto�� 0.

*/
int Material::valueForMatN(QString name){
    return (Material::getInstance().getMap())->value(name);
}
/*
  Zapisuje map� materia��w do piliku z ustawieniami.

*/
void Material::saveToFile(QSettings* file){
    /*
      W pliku z ustawieniami tworzymy now� grup�.
      Iterujemy po mapie i wpisujemy kolejno nazw� materia�u i jej identyfikator.

    */
    file->beginWriteArray("Materials");
    int l = 0;
    QMap<QString, int>::const_iterator i = materialy.constBegin();
    while (i != materialy.constEnd()) {
        l++;
        //cout << l << i.key() << ": " << i.value() << endl;
        file->setArrayIndex(l);
                file->setValue("MaterialName", i.key());
                file->setValue("MaterialId",  i.value());
       ++i;
    }
    file->endArray();
}
/*
  Odczytuje materia�y z pliku z ustawieniami.

*/
void Material::readFromFile(QSettings* file){
    /*
      Odczytujemy utworzon� przez nas grup�.

    */
    int size = file->beginReadArray("Materials");
    for (int i = 1; i < size; ++i) {
        file->setArrayIndex(i);
        QString key = file->value("MaterialName").toString();
        int value = file->value("MaterialId").toInt();
        if(lastMatnum < value)
         lastMatnum = value;
        if (materialy.value(key)==0){
            materialy.insert(key,value);
        }
    }
    file->endArray();
}

/*
  Zwraca ilo�� materia��w.
  Aby ca�o�� dzia���a dobrze w widoku modelu nale�a�o doda� 1.

*/
int  Material::count(){
    return materialy.size()+1;
}
Material::~Material(){}
/*
  W konstruktorze znajduj� si� definicje podstawowych materia��w.
  Te materia�y i ich id s� zawsze dost�pne w progamie.

*/
Material::Material(){
    materialy.insert("Br�z",1);
    materialy.insert("D�b",2);
    materialy.insert("Gips",3);
    materialy.insert("Glina",4);
    materialy.insert("Granit",5);
    materialy.insert("Marmur",6);
    materialy.insert("Metal",7);
    materialy.insert("Mosi�dz",8);
    materialy.insert("Piaskowiec",9);
    materialy.insert("Srebro",10);
    materialy.insert("Z�oto",11);
    /*
      Nale�y pami�ta� o ustawieniu ostatniego numeru, aby nie nadpisywa� danych.

    */
    lastMatnum = 11;
}

