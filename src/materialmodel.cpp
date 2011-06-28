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

#include "materialmodel.h"

MaterialModel::MaterialModel(QObject *parent)
    : QAbstractListModel(parent){}

MaterialModel::MaterialModel(){}
/*
  W DisplayRole zwracamy nazw� materia�u
  W UserRole numer materia�u

*/
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
/*
  Nie ma potrzeby implementacji columnCount odk�d QListView ma tylko jedn� kolumn�.

*/

QVariant MaterialModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const{
    /*
      Zwracamy QVariant bo nie potzreba nam numer�w wierszy ani nag��wka

    */
    return QVariant();
}
