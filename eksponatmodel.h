#ifndef EKSPONATMODEL_H
#define EKSPONATMODEL_H

//#include <src/eksponatmuzealny.h>
#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>
#include "src/meta.h"

class EksponatModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EksponatModel(Meta::Typ typ, QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    void setNewTyp(Meta::Typ typ);
    void czyMoznaZmieniac(bool mz);
    bool isEmpty();
    ~EksponatModel();

private:
        static bool moznaZmieniac;
        Meta::Typ m_typ;

};

#endif // EKSPONATMODEL_H
