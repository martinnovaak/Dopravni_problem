#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Dialog::Dialog(DP & a, QWidget *parent) : QDialog(parent)
{
    QVBoxLayout * layout = new QVBoxLayout;
    QHBoxLayout * hbox = new QHBoxLayout;
    lbl1 = new QLabel(tr("Solution X:"));
    hbox->addWidget(lbl1);
    layout->addLayout(hbox);
    for (int i = 0; i < a.getRows(); i++)
    {
        QHBoxLayout * hl = new QHBoxLayout;
        for (int j = 0; j < a.getColumns(); j++)
        {
            QLineEdit * le = new QLineEdit(QString::number(a(i, j)));
            hl->addWidget(le);
        }
        layout->addLayout(hl);
    }
    QHBoxLayout * hres = new QHBoxLayout;
    lbl2 = new QLabel(tr("Result: "));
    lres = new QLineEdit(QString::number(a.getRes()));
    hres->addWidget(lbl2);
    hres->addWidget(lres);
    layout->addLayout(hres);
    this->setLayout(layout);
}

