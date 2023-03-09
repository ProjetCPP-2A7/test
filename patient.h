#ifndef PATIENT_H
#define PATIENT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>



class Patient
{
private :
    QString Nom ,Prénom ,Adresse,Numéro,Nombredeséance,Identifiant;
public:
    patient(QString,QString,QString,QString,QString,QString) ;
        patient(){};

        QString getNom();
        QString getPrénom();
        QString getAdresse();
        QString getNuméro();
        QString getNombredeséance();
        QString getIdentifiant();
        void setNom(QString  );
        void setPrénom(QString );
        void setAdresse(QString );
        void setNuméro(QString );
        void setNombredeséance(QString );
        void setIdentifiant(QString );




        bool ajouter();
        bool modifier(QString);
         QSqlQueryModel * afficher();
          bool supprimer(QString cin);

    };


#endif // PATIENT_H
