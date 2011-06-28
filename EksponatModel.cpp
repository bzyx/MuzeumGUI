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
  Zwraca liczbê wierszy (obiektów) w zale¿noœci
  od tego co aktualnie wyœwietlane jest w widoku

*/
int EksponatModel::rowCount(const QModelIndex &parent) const{
    if(m_typ == Meta::NieOkreslonoTypu){
        return MK::getInstance().count();
    } else {
        return MKTyp::getInstance().count(m_typ);
    }
}

/*
  Zwraca liczbê kolumn:
  a) Liczba podstawowych atrybtów EksoponatuMuzealnego
  b) Liczba wszyskich atrbutów dla zadanego typu obiektu o ile jakikolwiek istnieje
        -jeœli nie istnieje zwracamy 0

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
  Obs³uguje DisplayRole (zwraca kolejne atrybuty, dla kolejnych kolumn)
  lub UserRole (zwraca id obiektu wyœwietlanego w inden.row()-tej linii,
                jest to niezbêdne do obs³ugi usuwania)

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
  Zwraca dane do nag³ówka i do paska z numerami wierszy.
  W zale¿noœci od tego co wyœwiwetla model dane w wierszach s¹ ró¿ne.

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
  Setter który pozwala na uruchomienie comboboxa z wyborem typu.

*/
void EksponatModel::czyMoznaZmieniac(bool mz = false){
    EksponatModel::moznaZmieniac = mz;
}

EksponatModel::~EksponatModel(){
}

/*
  Ustawia nowy wyœwietlany typ.
  Po zmianie nastêpuje satyczna metoda reset()
  która nakazuje widokowi odœwierzyæ wyœwietlane informacjie.

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
  Jeœli tak zwraca NULL

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
  Pozwala na wykonaie odœwierzenia widoku
  po operacji która tego wymaga³a. Przy okazji
  odœwierza kontener rekordów wg typu.

*/
void EksponatModel::makeReset(){
    MKTyp::getInstance().updateMKTyp();
    reset();
}

/*
  Inicjalizacja zmiennej statycznej.

*/
bool EksponatModel::moznaZmieniac;
