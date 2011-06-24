#include "material.h"

#include <QDebug>
Material& Material::getInstance(){
    Material static material;
    return material;
}

void Material::addMaterial(QString name){
    lastMatnum++;
    if (materialy.value(name)==0 )
     materialy.insert(name,lastMatnum);
    else
        lastMatnum--;
}

QMap<QString,int>* Material::getMap(){
    return &materialy;
}
QString Material::nazwaForMatV(int material_key){
    QString returnValue = (Material::getInstance().getMap())->key(material_key);
//    qDebug() << "Key" << material_key;
//    qDebug() << "Niby materia³" << returnValue;
    if (returnValue.isEmpty() || returnValue.isNull())
        returnValue = "Nieznay Materia³";
    return returnValue;
}
int Material::valueForMatN(QString name){
    return (Material::getInstance().getMap())->value(name);
}

//QVariant Material::data(const QModelIndex &index, int role) const{};
//int Material::rowCount(const QModelIndex &parent) const{};
//QVariant Material::headerData(int section, Qt::Orientation orientation, int role) const{};



void Material::saveToFile(QSettings* file){
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

void Material::readFromFile(QSettings* file){
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

int  Material::count(){
    return materialy.size();
}
Material::~Material(){}
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
    lastMatnum = 11;
}

