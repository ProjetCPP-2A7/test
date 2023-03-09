#include "connection.h"
#include<QString>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

connection::connection()
{

}
bool connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("Zouhair");//inserer nom de l'utilisateur
db.setPassword("Zouhair");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
void connection::closeConnection(){db.close();}
