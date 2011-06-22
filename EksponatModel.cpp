#include <QStringList>
#include "eksponatmodel.h"
#include <src/muzeumkontener.h>
#include <src/mktyp.h>
#include "src/eobraz.h"
#include <QDebug>


EksponatModel::EksponatModel(Meta::Typ typ, QObject *parent)
    : QAbstractTableModel(parent)
{
    m_typ = typ;
    moznaZmieniac = false;
}

int EksponatModel::rowCount(const QModelIndex &parent) const{
    if(m_typ == Meta::NieOkreslonoTypu){
        return MK::getInstance().count();
    } else {
        return MKTyp::getInstance().count(m_typ);
    }
}
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
    else
        return QVariant();
}
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

void EksponatModel::czyMoznaZmieniac(bool mz = false){
    EksponatModel::moznaZmieniac = mz;
}
EksponatModel::~EksponatModel(){
}

void EksponatModel::setNewTyp(Meta::Typ typ){
    m_typ = typ;
    if(moznaZmieniac)
        reset();
}

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
    //}
    //return true;
}

void EksponatModel::makeReset(){
    reset();
}

bool EksponatModel::moznaZmieniac;
