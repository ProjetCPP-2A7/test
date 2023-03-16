#include "mainwindow.h"
#include "connection.h"
#include "patient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test;
     test=c.createconnection();
    MainWindow w;
    w.show();
    if(test){
     w.show();
    QMessageBox::information(nullptr,QObject::tr("databse is open"),
    QObject::tr("connection successful\n"
                "Click cancel to exit"), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("database is not open"),
    QObject::tr("connection failed \n"
                "click cancel to exit"), QMessageBox::Cancel);
    }
    return a.exec();
}
