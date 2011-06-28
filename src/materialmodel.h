#ifndef MATERIALMODEL_H
#define MATERIALMODEL_H

#include <QAbstractListModel>
#include <QVariant>

#include "src/material.h"
/*!
 \brief

 \class MaterialModel materialmodel.h "src/materialmodel.h"
*/
class MaterialModel: public QAbstractListModel
{
public:
/*!
 \brief

 \fn MaterialModel
*/
    MaterialModel();
/*!
 \brief

 \fn MaterialModel
 \param parent
*/
    MaterialModel(QObject *parent);
    /*!
     \brief

     \fn rowCount
     \param parent
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief

     \fn data
     \param index
     \param role
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief

     \fn headerData
     \param section
     \param orientation
     \param role
    */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
};

#endif // MATERIALMODEL_H
