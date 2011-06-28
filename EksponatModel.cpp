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

#include <QStringList>

#include "eksponatmodel.h"

#include "src/muzeumkontener.h"
#include "src/mktyp.h"
#include "src/eobraz.h"


EksponatModel::EksponatModel(Meta::Typ typ, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_typ = typ;
    moznaZmieniac = false;
}

/*
  Zwraca liczb� wierszy (obiekt�w) w zale�no�ci
  od tego co aktualnie wy�wietlane jest w widoku

*/
int EksponatModel::rowCount(const QModelIndex &parent) const{
    if(m_typ == Meta::NieOkreslonoTypu){
        return MK::getInstance().count();
    } else {
        return MKTyp::getInstance().count(m_typ);
    }
}

/*
  Zwraca liczb� kolumn:
  a) Liczba podstawowych atrybt�w EksoponatuMuzealnego
  b) Liczba wszyskich atrbut�w dla zadanego typu obiektu o ile jakikolwiek istnieje
        -je�li nie istnieje zwracamy 0

*/
int EksponatModel::columnCount(const QModelIndex &parent) const{
    QStringList attr;
    EksponatMuzealny *m;
    if(m_typ == Meta::NieOkreslonoTypu){
        attr = m->getPodstawoweHeaders();
    } else {
        m = MKTyp::getInstance().getObjectFor(m_typ,0);
        if (m != NULL){
            attr = m->getHeaders();

        } else {
            return 0;
        }
    }
    return attr.count();
}
/*
  Zwraca dane dla widoku z modelu
  Obs�uguje DisplayRole (zwraca kolejne atrybuty, dla kolejnych kolumn)
  lub UserRole (zwraca id obiektu wy�wietlanego w inden.row()-tej linii,
                jest to niezb�dne do obs�ugi usuwania)

*/
QVariant EksponatModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole){
        QStringList z;
        EksponatMuzealny* m;
        if (m_typ == Meta::NieOkreslonoTypu){
            m = MK::getInstance()[index.row()];
            z = m->getPodstawoweAtrybuty();
        } else {
            m = MKTyp::getInstance().getObjectFor(m_typ,index.row());
            z = m->getAtrybuty();
        }
        return z[index.column()];
    }
    if (role == Qt::UserRole){
        int z;
        EksponatMuzealny* m;
        if (m_typ == Meta::NieOkreslonoTypu){
            m = MK::getInstance()[index.row()];
            z = m->getId();
        } else {
            m = MKTyp::getInstance().getObjectFor(m_typ,index.row());
            z = m->getId();
        }
        return z;
    }
    else
        return QVariant();
}

/*
  Zwraca dane do nag��wka i do paska z numerami wierszy.
  W zale�no�ci od tego co wy�wiwetla model dane w wierszach s� r�ne.

*/
QVariant EksponatModel::headerData(int section, Qt::Orientation orientation, int role) const{
    QStringList z;
    EksponatMuzealny *m;
    if(m_typ == Meta::NieOkreslonoTypu){
        z = m->getPodstawoweHeaders();
    } else {
        m = MKTyp::getInstance().getObjectFor(m_typ,0);
        if (m != NULL){
            z = m->getHeaders();
        } else {
            return QVariant();
        }
    }
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return z[section];
    else
        return QString("%1").arg(section);
}

/*
  Setter kt�ry pozwala na uruchomienie comboboxa z wyborem typu.

*/
void EksponatModel::czyMoznaZmieniac(bool mz = false){
    EksponatModel::moznaZmieniac = mz;
}

EksponatModel::~EksponatModel(){
}

/*
  Ustawia nowy wy�wietlany typ.
  Po zmianie nast�puje satyczna metoda reset()
  kt�ra nakazuje widokowi od�wierzy� wy�wietlane informacjie.

*/
void EksponatModel::setNewTyp(Meta::Typ typ){
    m_typ = typ;
    if(moznaZmieniac)
        reset();
}

Meta::Typ EksponatModel::getCurrentTyp(){
    return m_typ;
}

/*
  Sprawdza czy model jest pusty.
  Je�li tak zwraca NULL

*/
bool EksponatModel::isEmpty(){
    if (moznaZmieniac){
        if (m_typ == Meta::NieOkreslonoTypu){
            if(MK::getInstance().count() == 0)
                return true;
        } else {
            EksponatMuzealny *m = MKTyp::getInstance().getObjectFor(m_typ,0);
            if (m == NULL)
                return true;
        }
    }
    return false;
}

/*
  Pozwala na wykonaie od�wierzenia widoku
  po operacji kt�ra tego wymaga�a. Przy okazji
  od�wierza kontener rekord�w wg typu.

*/
void EksponatModel::makeReset(){
    MKTyp::getInstance().updateMKTyp();
    reset();
}

/*
  Inicjalizacja zmiennej statycznej.

*/
bool EksponatModel::moznaZmieniac;
