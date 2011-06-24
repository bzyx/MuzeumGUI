#include "materialmodel.h"

MaterialModel::MaterialModel(QObject *parent)
    : QAbstractListModel(parent){}

MaterialModel::MaterialModel(){}

QVariant MaterialModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole){
        return Material::getInstance().nazwaForMatV(index.row());
    }
    if (role == Qt::UserRole){
        return index.row();
    }
    else
        return QVariant();
}

int MaterialModel::rowCount(const QModelIndex &parent) const{
    return Material::getInstance().count();
}

QVariant MaterialModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const{
    return QVariant();
}
