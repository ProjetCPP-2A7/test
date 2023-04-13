#ifndef PATIENT_H
#define PATIENT_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QMessageBox>
#include <QString>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QTableView>



class Patient
{
    QString NOM ,PRENOM ,ADRESSE,SEXE;
   int NUMERO,NBR_SEANCE,ID_PATIENT;
public: 
        Patient(){}
        Patient(QString,QString,QString,int,int,int,QString);

        QString getNOM(){return NOM;}
        QString getPRENOM(){return PRENOM;}
        QString getADRESSE(){return ADRESSE;}
        int getNUMERO(){return NUMERO;}
        int getNBR_SEANCE(){return NBR_SEANCE;}
        int getID_PATIENT(){return ID_PATIENT;};
        QString getSEXE(){return SEXE;};
        void setNOM(QString n ){NOM=n;}
        void setPRENOM(QString p){PRENOM=p;}
        void setADRESSE(QString a){ADRESSE=a;}
        void setNUMERO(int num){this->NUMERO=num;}
        void setNBR_SEANCE(int nb ){this->NBR_SEANCE=nb;}
        void setID_PATIENT(int id){this->ID_PATIENT=id;}
        void setSEXE(QString SEXE){this->SEXE=SEXE;}




        bool ajouter();
        bool modifier();
         QSqlQueryModel * afficher();
          bool supprimer(int);
          QSqlQueryModel * Recherche(QString);
          QSqlQueryModel *tricin();

    };



#endif // PATIENT_H
