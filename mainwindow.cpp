#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Transportation problem"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_createButton_clicked()
{
    setupForm();

    for(int i = 0; i < costCells.size(); i++){
        costCells[i]->deleteLater();
    }
    for(int i = 0; i < supplyCells.size(); i++){
        supplyCells[i]->deleteLater();
    }
    for(int i = 0; i < demandCells.size(); i++){
        demandCells[i]->deleteLater();
    }
    for(int i = 0; i < lbls.size(); i++)
    {
        lbls[i]->deleteLater();
    }
    costCells.clear();
    demandCells.clear();
    supplyCells.clear();
    lbls.clear();
    int p = 0;
    for (unsigned int i = 1; i <= columns + 1 ; i++)
    {
        QLabel * lbl = new QLabel(this);
        if (i == columns + 1)
            lbl->setText(tr("Supply"));
        else
            lbl->setText("D"+QString::number(i));
        lbl->setGeometry((i+1)*60,60,50,50);
        lbl->setVisible(true);
        lbls.push_back(lbl);
    }
    for (unsigned int i = 1;i <= rows +1 ; i++)
    {

       QLabel * lbl = new QLabel(this);
       if(i == rows + 1)
       {
            lbl->setText(tr("Demand"));
       }
       else
       {
           lbl->setText("S"+ QString::number(i));
       }
       lbl->setGeometry(60,(i+1)*60,50,50);
       lbl->setVisible(true);
       lbls.push_back(lbl);
        for (unsigned int j = 1;j<= columns + 1;j++)
        {
            if (i == rows + 1 && columns + 1 == j)
            {
                if(calculate == nullptr)
                {
                    calculate = new QPushButton(this);
                    calculate->setText(tr("&Calculate"));
                    calculate->setVisible(true);
                    connect(calculate, SIGNAL(clicked()), this, SLOT(solve()));
                }
                calculate->setGeometry((j+1)*60,(i+1)*60,80,50);
                break;
            }
            p++;
            QSpinBox *tl = new QSpinBox(this);
            tl->setGeometry((j+1)*60,(i+1)*60,50,50);
            tl->setVisible(true);
            tl->setMaximum(INT_FAST16_MAX);
            if (columns + 1 == j)
                supplyCells.push_back(tl);
            else if(rows + 1 == i)
                demandCells.push_back(tl);
            else
                costCells.push_back(tl);
        }
    }
}

void MainWindow::setupForm()
{
    this->rows = ui->spinBox->value();
    this->columns = ui->spinBox_2->value();

    this->resize(columns * 60 + 225, rows * 60 + 225);
}

void MainWindow::solve()
{
    int * c = new int[columns * rows];
    int * a = new int[rows];
    int * b = new int[columns];
    for (int i = 0; i < costCells.size();i++)
        c[i] = costCells[i]->value();
    for (int i = 0; i < supplyCells.size(); i++)
        a[i] = supplyCells[i]->value();
    for (int i = 0; i < demandCells.size(); i++)
        b[i] = demandCells[i]->value();

    DP dopr(rows, columns, c, b, a);
    dopr.solve();
    if (dopr.getFeasible())
    {
        Dialog diag(dopr);
        diag.exec();
    }
    else
    {
        QMessageBox::warning(this, "Error",tr("No feasible solution"));
    }

    delete[] c;
    delete[] a;
    delete[] b;
}
