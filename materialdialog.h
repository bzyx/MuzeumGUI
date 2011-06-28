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

#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include <src/materialmodel.h>

namespace Ui {
    class MaterialDialog;
}

/*!
 \brief
 Ma³e okno (Dialog) s³ó¿¹cy do dodawania nowych typów materia³ów.

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
     Wywo³ywana po naciœniêciu przyciksu dodaj

     \fn on_pushButton_2_clicked
    */
    void on_pushButton_2_clicked();

private:
    Ui::MaterialDialog *ui; /*!< wskaŸik do okna */
    MaterialModel *model; /*!< wskaŸnik do modelu */
};

#endif // MATERIALDIALOG_H
