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

#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include <src/materialmodel.h>

namespace Ui {
    class MaterialDialog;
}

/*!
 \brief
 Ma�e okno (Dialog) s��cy do dodawania nowych typ�w materia��w.

 \class MaterialDialog materialdialog.h "materialdialog.h"
*/
class MaterialDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     \brief
    Konstruktor w stylu Qt

     \fn MaterialDialog
     \param parent
    */
    explicit MaterialDialog(QWidget *parent = 0);
    /*!
     \brief
     Destruktor

     \fn ~MaterialDialog
    */
    ~MaterialDialog();

private slots:
    /*!
     \brief
     Wywo�ywana po naci�ni�ciu przyciksu dodaj

     \fn on_pushButton_2_clicked
    */
    void on_pushButton_2_clicked();

private:
    Ui::MaterialDialog *ui; /*!< wska�ik do okna */
    MaterialModel *model; /*!< wska�nik do modelu */
};

#endif // MATERIALDIALOG_H
