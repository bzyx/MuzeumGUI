#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include <src/materialmodel.h>

namespace Ui {
    class MaterialDialog;
}

/*!
 \brief

 \class MaterialDialog materialdialog.h "materialdialog.h"
*/
class MaterialDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     \brief

     \fn MaterialDialog
     \param parent
    */
    explicit MaterialDialog(QWidget *parent = 0);
    /*!
     \brief

     \fn ~MaterialDialog
    */
    ~MaterialDialog();

private slots:
    /*!
     \brief

     \fn on_pushButton_2_clicked
    */
    void on_pushButton_2_clicked();

private:
    Ui::MaterialDialog *ui; /*!< TODO */
    MaterialModel *model; /*!< TODO */
};

#endif // MATERIALDIALOG_H
