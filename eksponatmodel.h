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

#ifndef EKSPONATMODEL_H
#define EKSPONATMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>
#include "src/meta.h"

/*!
 \brief
  Klasa g³ównego modelu programu. Jest stworzona w taki sposób aby wspo³dzia³a
  z QTableView. Zaimplementowane s¹ podstawowe wymagane metody przez Qt i
  specjalne funkcje umo¿liwiajce zmianê wyœwitelanego w widoku typu danych.

 \class EksponatModel eksponatmodel.h "eksponatmodel.h"
*/
class EksponatModel : public QAbstractTableModel
{
    Q_OBJECT
public:
/*!
 \brief
 Konstruktor modelu w stylu Qt

 \fn EksponatModel
 \param typ
 \param parent
*/
    EksponatModel(Meta::Typ typ, QObject *parent = 0);

    /*!
     \brief
     Zwraca liczbê wierszy.

     \fn rowCount
     \param parent
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief
     Zwraca liczbê kolumn.

     \fn columnCount
     \param parent
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief
     Zwraca dane obs³uguje DisplayRole i UserRole.

     \fn data
     \param index
     \param role
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief
     Zwraca nag³ówek do widoku.

     \fn headerData
     \param section
     \param orientation
     \param role
    */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    /*!
     \brief
     Ustawia nowy wyœwietlany typ.

     \fn setNewTyp
     \param typ
    */
    void setNewTyp(Meta::Typ typ);
    /*!
     \brief
     Zwraca aktulanie wyœwietlany typ.

     \fn getCurrentTyp
    */
    Meta::Typ getCurrentTyp();
    /*!
     \brief
     Ustawia wartoœæ czy mo¿na zmieniaæ wyœwietlany typ. true = mo¿na zmienaiæ

     \fn czyMoznaZmieniac
     \param mz
    */
    void czyMoznaZmieniac(bool mz);
    /*!
     \brief
     Zwraca true jeœli model jest pusty.

     \fn isEmpty
    */
    bool isEmpty();
    /*!
     \brief

     \fn makeReset
    */
    void makeReset();
    /*!
     \brief
     Wykonuje operacjê reset() na modelu. Wymagane przy dodawaniu, edycji i usuwaniu danych.

     \fn ~EksponatModel
    */
    ~EksponatModel();

private:
        static bool moznaZmieniac; /*!< Przechowuje informacje czy mo¿na zmieniaæ */
        Meta::Typ m_typ; /*!< Przechowuje jaki aktulanie wyœwietlany jest typ */

};

#endif // EKSPONATMODEL_H
