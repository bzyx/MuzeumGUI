#ifndef MATERIALMODEL_H
#define MATERIALMODEL_H

#include <QAbstractListModel>
#include <QVariant>

#include "src/material.h"
class MaterialModel: public QAbstractListModel
{
public:
    MaterialModel();
    MaterialModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
};

#endif // MATERIALMODEL_H
