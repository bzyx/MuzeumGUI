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

#ifndef EKSPONATMODEL_H
#define EKSPONATMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>
#include "src/meta.h"

/*!
 \brief
  Klasa g��wnego modelu programu. Jest stworzona w taki spos�b aby wspo�dzia�a
  z QTableView. Zaimplementowane s� podstawowe wymagane metody przez Qt i
  specjalne funkcje umo�liwiajce zmian� wy�witelanego w widoku typu danych.

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
     Zwraca liczb� wierszy.

     \fn rowCount
     \param parent
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief
     Zwraca liczb� kolumn.

     \fn columnCount
     \param parent
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief
     Zwraca dane obs�uguje DisplayRole i UserRole.

     \fn data
     \param index
     \param role
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief
     Zwraca nag��wek do widoku.

     \fn headerData
     \param section
     \param orientation
     \param role
    */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    /*!
     \brief
     Ustawia nowy wy�wietlany typ.

     \fn setNewTyp
     \param typ
    */
    void setNewTyp(Meta::Typ typ);
    /*!
     \brief
     Zwraca aktulanie wy�wietlany typ.

     \fn getCurrentTyp
    */
    Meta::Typ getCurrentTyp();
    /*!
     \brief
     Ustawia warto�� czy mo�na zmienia� wy�wietlany typ. true = mo�na zmienai�

     \fn czyMoznaZmieniac
     \param mz
    */
    void czyMoznaZmieniac(bool mz);
    /*!
     \brief
     Zwraca true je�li model jest pusty.

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
     Wykonuje operacj� reset() na modelu. Wymagane przy dodawaniu, edycji i usuwaniu danych.

     \fn ~EksponatModel
    */
    ~EksponatModel();

private:
        static bool moznaZmieniac; /*!< Przechowuje informacje czy mo�na zmienia� */
        Meta::Typ m_typ; /*!< Przechowuje jaki aktulanie wy�wietlany jest typ */

};

#endif // EKSPONATMODEL_H
