#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QMap>
#include <QSettings>
/*!
 \brief

 \class Material material.h "src/material.h"
*/
class Material
{
public:
    /*!
     \brief

     \fn getInstance
    */
    static Material& getInstance();
    /*!
     \brief

     \fn addMaterial
     \param name
    */
    void addMaterial(QString name);
    /*!
     \brief

     \fn nazwaForMatV
     \param material_key
    */
    static QString nazwaForMatV(int material_key);
    /*!
     \brief

     \fn valueForMatN
     \param name
    */
    static int valueForMatN(QString name);

//    QVariant data(const QModelIndex &index, int role) const;
//    int rowCount(const QModelIndex &parent) const;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const;


    /*!
     \brief

     \fn readFromFile
     \param file
    */
    void readFromFile(QSettings* file);
    /*!
     \brief

     \fn saveToFile
     \param file
    */
    void saveToFile(QSettings* file);

    /*!
     \brief

     \fn count
    */
    int count();
    /*!
     \brief

     \fn ~Material
    */
    ~Material();
private:
    /*!
     \brief

     \fn getMap
    */
    QMap<QString,int>* getMap();
    QMap<QString,int> materialy; /*!< TODO */
    int lastMatnum; /*!< TODO */
/*!
 \brief

 \fn Material
*/
    Material();
/*!
 \brief

 \fn Material
 \param
*/
    Material(Material& );
    /*!
     \brief

     \fn operator =
     \param
    */
    Material& operator=(Material&);
};

#endif // MATERIAL_H
