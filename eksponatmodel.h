#ifndef EKSPONATMODEL_H
#define EKSPONATMODEL_H

//#include <src/eksponatmuzealny.h>
#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>

class EksponatModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EksponatModel(int rows = 1, int columns = 1, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    ~EksponatModel();
private:
        QList<QStringList> rowList;
};

#endif // EKSPONATMODEL_H
