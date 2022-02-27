#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector>
#include <QLineEdit>
#include "DP.h"
#include <QLabel>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(DP & a, QWidget *parent = nullptr);
private:
    QVector <QLineEdit*> ledit;
    QLabel * lbl1;
    QLabel * lbl2;
    QLineEdit * lres;
};

#endif // DIALOG_H
