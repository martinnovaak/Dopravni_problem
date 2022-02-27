#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createButton_clicked();
    void solve();

private:
    Ui::MainWindow *ui;
    unsigned int rows;
    unsigned int columns;
    QVector<QSpinBox*> costCells;
    QVector<QSpinBox*> demandCells;
    QVector<QSpinBox*> supplyCells;
    QVector<QLabel*> lbls;
    QPushButton * calculate = nullptr;

    void setupForm();
};
#endif // MAINWINDOW_H
