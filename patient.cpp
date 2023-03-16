#include "patient.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

Patient::Patient(QString NOM,QString PRENOM,QString ADRESSE,int NUMERO,int NBR_SEANCE,int ID_PATIENT)
{
     this->ID_PATIENT=ID_PATIENT;
     this->NOM=NOM;
     this->PRENOM=PRENOM;
     this->ADRESSE=ADRESSE;
     this->NUMERO=NUMERO;
     this->NBR_SEANCE=NBR_SEANCE;

}
/*QString Patient:: getID_PATIENT(){return cin;}
QString Patient:: getNom(){return nom ;}
QString Patient::getPrenom(){return prenom ;}
QString Patient:: getPoste(){return poste ;}
QString Patient:: getSalaire(){return salaire;}
QString Patient::getEmail(){return email ;}

void employe:: setCIN(QString cin){this->cin=cin;}
void employe:: setNom(QString nom){this->nom=nom;}
void employe:: setPrenom(QString prenom){this->prenom=prenom;}
void employe:: setPoste(QString poste){this->poste=poste;}
void employe:: setSalaire(QString salaire){this->salaire=salaire;}
void employe:: setEmail(QString email){this->email=email;}
*/

bool Patient::ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO PATIENT VALUES (:ID_PATIENT, :NOM, :PRENOM,:ADRESSE,:NUMERO, :NBR_SEANCE)");

    query.bindValue(":ID_PATIENT",ID_PATIENT);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":NUMERO", NUMERO);
    query.bindValue(":NBR_SEANCE",NBR_SEANCE);

    return    query.exec();
}
/*bool employe::modifier(QString selected ){

    QSqlQuery query;


    query.prepare(" UPDATE evenement SET CIN= :cin ,nom= :nom, prenom=:prenom,"
                  " poste= :poste ,salaire= :salaire, email=:email where CIN= :cin");

    query.bindValue(":cin", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email",email);

    return    query.exec();

}
*/
QSqlQueryModel * Patient::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select *from PATIENT ") ;
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_PATIENT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("NUMERO"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("NBR_SEANCE"));
return model;
}
bool Patient::supprimer(int ID_PATIENT){

    QSqlQuery query;
        QString res=QString::number(ID_PATIENT);
        query.prepare("Delete from PATIENT where ID_PATIENT= :ID_PATIENT");
        query.bindValue(":ID_PATIENT",res);
        return query.exec();

}
bool Patient::modifier(){

    QSqlQuery query;
    QString res = QString::number(NUMERO);

    QString res1 = QString::number(ID_PATIENT);


    QString res2 = QString::number(NBR_SEANCE);
    query.prepare(" UPDATE PATIENT SET NOM= :NOM,PRENOM=:PRENOM,ADRESSE=:ADRESSE ,NUMERO= :NUMERO, NBR_SEANCE=:NBR_SEANCE where ID_PATIENT= :ID_PATIENT");
    //control  saisie
    //qDebug()<<cin;
    query.bindValue(":ID_PATIENT",res1);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":NUMERO",res);
    query.bindValue(":NBR_SEANCE", res2);

     return query.exec();
    //qDebug()<<query.lastError();
}
