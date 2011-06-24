#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QMap>
#include <QSettings>
class Material
{
public:
    static Material& getInstance();
    void addMaterial(QString name);
    static QString nazwaForMatV(int material_key);
    static int valueForMatN(QString name);

//    QVariant data(const QModelIndex &index, int role) const;
//    int rowCount(const QModelIndex &parent) const;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;


    void readFromFile(QSettings* file);
    void saveToFile(QSettings* file);

    int count();
    ~Material();
private:
    QMap<QString,int>* getMap();
    QMap<QString,int> materialy;
    int lastMatnum;
    Material();
    Material(Material& );
    Material& operator=(Material&);
};

#endif // MATERIAL_H
