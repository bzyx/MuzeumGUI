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
/*!
  \file materialmodel.cpp

*/
#include "materialmodel.h"

MaterialModel::MaterialModel(QObject *parent)
    : QAbstractListModel(parent){}

MaterialModel::MaterialModel(){}
/*
  W DisplayRole zwracamy nazwê materia³u
  W UserRole numer materia³u

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

QVariant MaterialModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const{
    return QVariant();
}
