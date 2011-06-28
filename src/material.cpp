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

#include "material.h"
/*
  Zwraca referencjê do singletonu.

*/
Material& Material::getInstance(){
    Material static material;
    return material;
}

/*
  Dodaje nowy materia³.

*/
void Material::addMaterial(QString name){
    lastMatnum++;
    /*
      Dodajemy materia³ tylko wtedy gdy nie istenie jeszcze
      materia³ o takiej nazwie.
      Wtedy wyszukanie w map'ie zwróci wartoœæ 0.

    */
    if (materialy.value(name)==0 )
     materialy.insert(name,lastMatnum);
    else
        lastMatnum--;
}
/*
  Zwraca wskaŸnik do wewnêtrznej struktury danych.

*/
QMap<QString,int>* Material::getMap(){
    return &materialy;
}
/*
  Zwraca nazwê materia³u dla zadanego klucza (identyfikatora materia³u)

*/
QString Material::nazwaForMatV(int material_key){
    QString returnValue = (Material::getInstance().getMap())->key(material_key);
    /*
      Jeœli zwrócona wartoœæ jest pusta zwracamy "Nieznany Materia³"

    */
    if (returnValue.isEmpty() || returnValue.isNull())
        returnValue = "Nieznay Materia³";
    return returnValue;
}
/*
  Zwraca identyfikator materia³u dla zadanej nazwy.
  W przypdaku podania z³ej nazwy/nie istnienia zwracana jest wartoœæ 0.

*/
int Material::valueForMatN(QString name){
    return (Material::getInstance().getMap())->value(name);
}
/*
  Zapisuje mapê materia³ów do piliku z ustawieniami.

*/
void Material::saveToFile(QSettings* file){
    /*
      W pliku z ustawieniami tworzymy now¹ grupê.
      Iterujemy po mapie i wpisujemy kolejno nazwê materia³u i jej identyfikator.

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
  Odczytuje materia³y z pliku z ustawieniami.

*/
void Material::readFromFile(QSettings* file){
    /*
      Odczytujemy utworzon¹ przez nas grupê.

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
  Zwraca iloœæ materia³ów.
  Aby ca³oœæ dzia³¹³a dobrze w widoku modelu nale¿a³o dodaæ 1.

*/
int  Material::count(){
    return materialy.size()+1;
}
Material::~Material(){}
/*
  W konstruktorze znajduj¹ siê definicje podstawowych materia³ów.
  Te materia³y i ich id s¹ zawsze dostêpne w progamie.

*/
Material::Material(){
    materialy.insert("Br¹z",1);
    materialy.insert("D¹b",2);
    materialy.insert("Gips",3);
    materialy.insert("Glina",4);
    materialy.insert("Granit",5);
    materialy.insert("Marmur",6);
    materialy.insert("Metal",7);
    materialy.insert("Mosi¹dz",8);
    materialy.insert("Piaskowiec",9);
    materialy.insert("Srebro",10);
    materialy.insert("Z³oto",11);
    /*
      Nale¿y pamiêtaæ o ustawieniu ostatniego numeru, aby nie nadpisywaæ danych.

    */
    lastMatnum = 11;
}

