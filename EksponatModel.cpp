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
    //return MK::getInstance().getList()->size();
    qDebug() << "rowCount";
    //return 5;
    return rowList.size();
    //QStringList
}
int EksponatModel::columnCount(const QModelIndex &parent) const{
    EObraz t;
    QStringList podstAttr = t.getPodstawoweHeaders();
    //return podstAttr.count();
    qDebug() << "columntCount";
    return rowList[0].size();
   // return 5;
}
QVariant EksponatModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole){
        return rowList[index.row()][index.column()];
        qDebug() << "Dispaly";
    }
    else
        return QVariant();
}
QVariant EksponatModel::headerData(int section, Qt::Orientation orientation, int role) const{
        qDebug() << "hader";
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
    //return QString("test");

}
EksponatModel::~EksponatModel(){
}


