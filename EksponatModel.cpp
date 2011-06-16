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

}

int EksponatModel::rowCount(const QModelIndex &parent) const{
    //qDebug() << "RowC";
    if(m_typ == Meta::NieOkreslonoTypu){
        return MK::getInstance().count();
    } else {
        return MKTyp::getInstance().count(m_typ);
    }
}
int EksponatModel::columnCount(const QModelIndex &parent) const{
   // qDebug()<< "ColC";
    QStringList attr;
    if(m_typ == Meta::NieOkreslonoTypu){
        //Nie ma wymagañ co do typu. Wystarczy ¿e w headerze bêd¹ tylko podstawowe
        //atrybuty. Mo¿na je pobraæ z obiektu dowolnego typu.
        //Nie mo¿na braæ z listy bo mo¿e byæ pusta
        EObraz t;
        attr = t.getPodstawoweHeaders();
    } else {
        EObraz t;
        //attr = t.getPodstawoweHeaders();
        attr = t.getHeaders();
        //attr = MK::getInstance().getObjectOfTyp(m_typ)->getAtrybuty();
    }
    return attr.count();
}
QVariant EksponatModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();
//POPRAWIÆ!
    if (role == Qt::DisplayRole){
        QStringList z;
        EksponatMuzealny* m;
            //EksponatMuzealny* m =MK::getInstance()[index.row()];
            //if(m_typ == Meta::NieOkreslonoTypu){
            // z = m->getPodstawoweAtrybuty();
            //} else{
               // if(m->getTyp() == m_typ){
        //qDebug()<<index.row();
                    //if(index.row()<=1)
                        m = MKTyp::getInstance().getObjectFor(m_typ,index.row());
                    //else
                    //    m = MK::getInstance().next(m_typ);
                    //qDebug()<< "Data";
                    //z = m->getPodstawoweAtrybuty();
                    z = m->getAtrybuty();
                //}
            //}
            return z[index.column()];

    }
    else
        return QVariant();
}
QVariant EksponatModel::headerData(int section, Qt::Orientation orientation, int role) const{
    QStringList z;
    if(m_typ == Meta::NieOkreslonoTypu){
        EObraz t;
        z =t.getPodstawoweHeaders();
    } else {
       // qDebug()<< "Hdata";
        //z = MK::getInstance().getObjectOfTyp(m_typ)->getPodstawoweHeaders();
        EObraz t;
        //z =t.getPodstawoweHeaders();
        z = t.getHeaders();
    }
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return z[section];
    else
        return QString("%1").arg(section);
}
EksponatModel::~EksponatModel(){
}

void EksponatModel::setNewTyp(Meta::Typ typ){
    m_typ = typ;
    reset();
}
