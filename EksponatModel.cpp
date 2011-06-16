#include <QStringList>
#include "eksponatmodel.h"
#include <src/muzeumkontener.h>
#include "src/eobraz.h"
#include <QDebug>

EksponatModel::EksponatModel(int rows, int columns, QObject *parent)
    : QAbstractTableModel(parent)
{
    QStringList newList;

    for (int column = 0; column < qMax(1, columns); ++column) {
        newList.append("");
    }

    for (int row = 0; row < qMax(1, rows); ++row) {
        rowList.append(newList);
    }
}

//void EksponatModel::metodaReset(){
//    qDebug() << "reset";
//    reset();
//}

int EksponatModel::rowCount(const QModelIndex &parent) const{
        qDebug() << "rowCount";
    return MK::getInstance().getList()->size();
    //return 5;
   // return rowList.size();
    //QStringList
}
int EksponatModel::columnCount(const QModelIndex &parent) const{
    EObraz t;
    QStringList podstAttr = t.getPodstawoweHeaders();
    //return podstAttr.count();
    qDebug() << "columntCount";
    //return rowList[0].size();
   // return 5;
    return podstAttr.count();
}
QVariant EksponatModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole){
        EksponatMuzealny* m =MK::getInstance()[index.row()];
        QStringList z = m->getPodstawoweAtrybuty();
                qDebug() << "Dispaly";
        //return rowList[index.row()][index.column()];
                return z[index.column()];//QString("TTTTT");
    }
    else
        return QVariant();
}
QVariant EksponatModel::headerData(int section, Qt::Orientation orientation, int role) const{
        qDebug() << "hader";
        EObraz t;
        QStringList z =t.getPodstawoweHeaders();
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return z[section];//QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
    //return QString("test");

}
EksponatModel::~EksponatModel(){
}


