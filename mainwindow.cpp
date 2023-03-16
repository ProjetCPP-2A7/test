#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "patient.h"
#include "patient.h"
#include <QTableView>
#include <iostream>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Patient P;
    ui->setupUi(this);
    ui->table_afficher->setModel(P.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_3_clicked()
{
    int ID_PATIENT =ui->lineEdit_6->text().toInt();
        int NUMERO =ui->lineEdit_4->text().toInt();
       int NBR_SEANCE =ui->lineEdit_5->text().toInt();
        QString NOM=ui->lineEdit->text();
         QString PRENOM=ui->lineEdit_2->text();
        QString ADRESSE=ui->lineEdit_3->text();
        QString patientstr=QString::number(ID_PATIENT);
       QString  numerostr=QString::number(NUMERO);
       QString nbrstr=QString::number(NBR_SEANCE);
        Patient P (NOM, PRENOM, ADRESSE, NUMERO, NBR_SEANCE, ID_PATIENT);
        if(!patientstr.isEmpty() && !numerostr.isEmpty() && !nbrstr.isEmpty() && !NOM.isEmpty() && !PRENOM.isEmpty() && !ADRESSE.isEmpty())
        {
        bool test=P.ajouter();
        if(test){
          //  ui->tableView->setModel(Etmp.afficher());
          //  ui->tableView_2->setModel(Etmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("ajout effectué\n"
                                                 "click here to exit"), QMessageBox::Cancel);
            ui->table_afficher_2->setModel(P.afficher());
        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                     QObject::tr("ajout non  effectué\n"
                                                 "click here to exit"), QMessageBox::Cancel);
        }
        } else QMessageBox::warning(this,"ERREUR","Toutes les informations.\n"
                                     "doivent etre completées.!");
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    int ID_PATIENT=ui->lineEdit_8->text().toInt();
        bool test= P.supprimer(ID_PATIENT);
        if(test){
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("supression effectué\n"
                                                 "click here to exit"), QMessageBox::Cancel);
            ui->table_afficher_2->setModel(P.afficher());
        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                                     QObject::tr("supression non  effectué\n"
                                                 "click here to exit"), QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButton_11_clicked()
{
    int ID_PATIENT = ui->lineEdit_6->text().toInt();
       QString NOM = ui->lineEdit->text();
       QString PRENOM=ui->lineEdit_2->text();
       QString ADRESSE=ui->lineEdit_3->text();
       int NUMERO=ui->lineEdit_4->text().toInt();
    int NBR_SEANCE=ui->lineEdit_5->text().toInt();



       bool test;
    Patient P( NOM, PRENOM, ADRESSE, NUMERO, NBR_SEANCE, ID_PATIENT);
    test = P.modifier();



      if( test){


              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("modification effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              ui->table_afficher_2->setModel(P.afficher());
             /* ui->lineEdit_6->clear();
                             ui->lineEdit->clear();
                             ui->lineEdit_6->clear();
                             ui->lineEdit_2->clear();
                             ui->lineEdit_3->clear();
                             ui->lineEdit_4->clear();
                             ui->lineEdit_5->clear();*/


                 //       ui->tabWidget_2->setCurrentIndex( (ui->tabWidget_2->currentIndex()-1) % ui->tabWidget_2->count() );



      }
          else
              QMessageBox::critical(nullptr, QObject::tr("not ok"),
                          QObject::tr("modification non effectué .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
}
