#ifndef CONNECTION_H
#define CONNECTION_H
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QtSql/QSqlQuery>
#include<QMessageBox>


class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
    void closeConnection();
};

#endif // CONNECTION_H
