#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"patient.h"

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


    void on_pushButton_3_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    Patient P;
};
#endif // MAINWINDOW_H
