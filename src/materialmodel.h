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

#ifndef MATERIALMODEL_H
#define MATERIALMODEL_H

#include <QAbstractListModel>
#include <QVariant>

#include "src/material.h"
/*!
 \brief
 Klasa tworz¹ca z klasy Materia³ model w stylu MVC (MVP) dla biblioteki Qt.
 Implementuje podstawowe wymagane metody.

 \class MaterialModel materialmodel.h "src/materialmodel.h"
*/
class MaterialModel: public QAbstractListModel
{
public:
/*!
 \brief
 Konstrtuktor domyslny

 \fn MaterialModel
*/
    MaterialModel();
/*!
 \brief
 Konstrtuktor w stylu Qt.

 \fn MaterialModel
 \param parent
*/
    MaterialModel(QObject *parent);
    /*!
     \brief
     Zwraca liczbê wierszy. U¿wane przez widoki.

     \fn rowCount
     \param parent
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief
     Zwraca dane dla danego indexu i danej roli. U¿ywane przez widoki.

     \fn data
     \param index
     \param role
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief
     Zwraca nag³ówek. Wymagana definicja. Implementacja pusta.

     \fn headerData
     \param section
     \param orientation
     \param role
    */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
};

#endif // MATERIALMODEL_H
