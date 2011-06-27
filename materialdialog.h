#ifndef MATERIALDIALOG_H
#define MATERIALDIALOG_H

#include <QDialog>
#include <src/materialmodel.h>

namespace Ui {
    class MaterialDialog;
}

class MaterialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MaterialDialog(QWidget *parent = 0);
    ~MaterialDialog();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MaterialDialog *ui;
    MaterialModel *model;
};

#endif // MATERIALDIALOG_H
