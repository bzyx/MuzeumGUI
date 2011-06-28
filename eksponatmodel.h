#ifndef EKSPONATMODEL_H
#define EKSPONATMODEL_H

//#include <src/eksponatmuzealny.h>
#include <QAbstractTableModel>
#include <QStringList>
#include <QVariant>
#include "src/meta.h"

/*!
 \brief

 \class EksponatModel eksponatmodel.h "eksponatmodel.h"
*/
class EksponatModel : public QAbstractTableModel
{
    Q_OBJECT
public:
/*!
 \brief

 \fn EksponatModel
 \param typ
 \param parent
*/
    EksponatModel(Meta::Typ typ, QObject *parent = 0);

    /*!
     \brief

     \fn rowCount
     \param parent
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief

     \fn columnCount
     \param parent
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    /*!
     \brief

     \fn data
     \param index
     \param role
    */
    QVariant data(const QModelIndex &index, int role) const;
    /*!
     \brief

     \fn headerData
     \param section
     \param orientation
     \param role
    */
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    /*!
     \brief

     \fn setNewTyp
     \param typ
    */
    void setNewTyp(Meta::Typ typ);
    /*!
     \brief

     \fn getCurrentTyp
    */
    Meta::Typ getCurrentTyp();
    /*!
     \brief

     \fn czyMoznaZmieniac
     \param mz
    */
    void czyMoznaZmieniac(bool mz);
    /*!
     \brief

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

     \fn ~EksponatModel
    */
    ~EksponatModel();

private:
        static bool moznaZmieniac; /*!< TODO */
        Meta::Typ m_typ; /*!< TODO */

};

#endif // EKSPONATMODEL_H
