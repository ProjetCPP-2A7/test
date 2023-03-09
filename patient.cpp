#include "patient.h"


patient::patient(QString cin,QString nom,QString prenom,QString poste,QString salaire,QString email)
{
     this->cin=cin;
     this->Nom=Nom;
     this->Prénom=Prénom;
     this->Adresse=Adresse;
     this->Numéro=Numéro;
     this->Nombredeséance=Nombredeséance;

}
QString employe:: getCIN(){return cin;}
QString employe:: getNom(){return nom ;}
QString employe::getPrenom(){return prenom ;}
QString employe:: getPoste(){return poste ;}
QString employe:: getSalaire(){return salaire;}
QString employe::getEmail(){return email ;}

void employe:: setCIN(QString cin){this->cin=cin;}
void employe:: setNom(QString nom){this->nom=nom;}
void employe:: setPrenom(QString prenom){this->prenom=prenom;}
void employe:: setPoste(QString poste){this->poste=poste;}
void employe:: setSalaire(QString salaire){this->salaire=salaire;}
void employe:: setEmail(QString email){this->email=email;}

bool employe :: ajouter()
{
    QSqlQuery query;

    query.prepare("INSERT INTO employe VALUES (:cin, :nom, :prenom,:poste,:salaire, :email)");

    query.bindValue(":cin", cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":email",email);

    return    query.exec();
}
bool employe::modifier(QString selected ){

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
