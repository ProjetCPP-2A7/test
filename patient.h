#ifndef PATIENT_H
#define PATIENT_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QMessageBox>
#include <QString>



class Patient
{
    QString NOM ,PRENOM ,ADRESSE;
   int NUMERO,NBR_SEANCE,ID_PATIENT;
public: 
        Patient(){}
        Patient(QString,QString,QString,int,int,int);

        QString getNOM(){return NOM;}
        QString getPRENOM(){return PRENOM;}
        QString getADRESSE(){return ADRESSE;}
        int getNUMERO(){return NUMERO;}
        int getNBR_SEANCE(){return NBR_SEANCE;}
        int getID_PATIENT(){return ID_PATIENT;};
        void setNOM(QString n ){NOM=n;}
        void setPRENOM(QString p){PRENOM=p;}
        void setADRESSE(QString a){ADRESSE=a;}
        void setNUMERO(int num){this->NUMERO=num;}
        void setNBR_SEANCE(int nb ){this->NBR_SEANCE=nb;}
        void setID_PATIENT(int id){this->ID_PATIENT=id;}




        bool ajouter();
        bool modifier();
         QSqlQueryModel * afficher();
          bool supprimer(int);

    };


#endif // PATIENT_H
