#include "mainwindow.h"
#include "stat_categorie.h"

#include "ui_mainwindow.h"
#include "patient.h"
#include <QTableView>
#include <iostream>
#include <QMessageBox>
#include <QDesktopServices>
#include<QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Patient P;
    ui->setupUi(this);

    client_ = NULL;

    // Connect all signals and slots
    connect(ui->pushButtonSend, SIGNAL(clicked(bool)), this, SLOT(sendEmail()));
    connect(ui->pushButtonClear, SIGNAL(clicked(bool)), this, SLOT(clearFields()));


    ui->lineEdit_4->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_5->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_6->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

    ui->table_afficher_2->setModel(P.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
    client_->deleteLater();
}

//MAILING//

void MainWindow::sendEmail()
{
    // Create the email object
    Email email = createEmail();

    // Create the SMTPClient
    client_ = new SMTPClient(ui->lineEditHost->text(),
                             ui->spinBoxPort->value());

    // Connection used to receive the results
    connect(client_, SIGNAL(status(Status::e, QString)),
            this, SLOT(onStatus(Status::e, QString)), Qt::UniqueConnection);

    // Try to send the email
    client_->sendEmail(email);
}

/**
 * @brief Create and return an Email object based on the fields from the form.
 */
Email MainWindow::createEmail()
{
    // Create the credentials EmailAddress
    EmailAddress credentials(ui->lineEditEmailCredentials->text(),
                             ui->lineEditPasswordCredentials->text());

    // Create the from EmailAddress
    EmailAddress from(ui->lineEditEmailFrom->text());

    // Create the to EmailAddress
    EmailAddress to(ui->lineEditEmailTo->text());

    // Create the email
    Email email(credentials,
                from,
                to,
                ui->lineEditSubject->text(),
                ui->textEditContent->toPlainText());

    return email;
}

/**
 * @brief Function responsible for clear all fields.
 * Note: it will not change the Host and Port fields.
 */
void MainWindow::clearFields()
{
    ui->lineEditEmailCredentials->clear();
    ui->lineEditPasswordCredentials->clear();
    ui->lineEditEmailFrom->clear();
    ui->lineEditEmailTo->clear();
    ui->lineEditSubject->clear();
    ui->textEditContent->clear();
}

/**
 * @brief Slot the receives a result from the SMTPClient object.
 * @param status - The status (Success or Failed)
 * @param errorMessage - The error message if the status is Failed
 */
void MainWindow::onStatus(Status::e status, QString errorMessage)
{
    // Show a message based on the Status
    switch (status)
    {
    case Status::Success:
        QMessageBox::information(NULL, tr("SMTPClient"), tr("Message successfully sent!"));
        break;
    case Status::Failed:
    {
        QMessageBox::warning(NULL, tr("SMTPClient"), tr("Could not send the message!"));
        qCritical() << errorMessage;
    }
        break;
    default:
        break;
    }

    // Delete the client pointer
    client_->deleteLater();
}




//FIN MAILING//




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
       QString SEXE=ui->Sexe->currentText();

        Patient P (NOM, PRENOM, ADRESSE, NUMERO, NBR_SEANCE, ID_PATIENT,SEXE);
        if(!patientstr.isEmpty() && !numerostr.isEmpty() && !nbrstr.isEmpty() && !NOM.isEmpty() && !PRENOM.isEmpty() && !ADRESSE.isEmpty() )
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
    QString SEXE=ui->Sexe->currentText();



       bool test;
    Patient P( NOM, PRENOM, ADRESSE, NUMERO, NBR_SEANCE, ID_PATIENT,SEXE);
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

void MainWindow::on_chercher_textEdited(const QString &arg1)
{
    ui->table_afficher_2->setModel(P.Recherche(arg1));

           if(ui->chercher->text().isEmpty())
           {
               ui->table_afficher_2->setModel(P.afficher());
           }
}



void MainWindow::on_pdf_2_clicked()
{
    QPdfWriter pdf(qApp->applicationDirPath()+"//listePatient.pdf");

        QPainter painter(&pdf);

                         int i = 4000;


                         painter.drawText(4500,1500,"LISTE DES PATIENTS");
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 50));
                         painter.drawRect(2000,200,6300,2600);
                         painter.setPen(Qt::black);


                         QSqlQuery query;
                         query.prepare("select * from PATIENT");
                         query.exec();
                         while (query.next())

                         {
                             painter.setPen(Qt::red);
                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawRect(-50,1000+i,3600,2500);
                             painter.drawText(0,1300+i,"ID_PATIENT");
                             painter.drawText(0,1600+i,"NOM");
                             painter.drawText(0,1900+i,"PRENOM");
                             painter.drawText(0,2200+i,"ADRESSE");
                             painter.drawText(0,2500+i,"NUMERO");
                             painter.drawText(0,2800+i,"NBR_SEANCE");



                             painter.drawText(1600,1300+i,query.value(0).toString());
                             painter.drawText(1600,1600+i,query.value(1).toString());
                             painter.drawText(1600,1900+i,query.value(2).toString());
                             painter.drawText(1600,2200+i,query.value(3).toString());
                             painter.drawText(1600,2500+i,query.value(4).toString());
                             painter.drawText(1600,2800+i,query.value(5).toString());


                             i = i +3000;
                         }

                         int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                         if (reponse == QMessageBox::Yes)
                         {
                             QDesktopServices::openUrl(QUrl::fromLocalFile(qApp->applicationDirPath()+"//listePatient.pdf"));
                             painter.end();
                         }
                         if (reponse == QMessageBox::No)
                         {
                             painter.end();
                         }
}

void MainWindow::on_trier_clicked()
{
    ui->table_afficher_2->setModel(P.tricin());
}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21650221106", QUrl::TolerantMode));
}


void MainWindow::on_pushButton_4_clicked()
{
    s = new stat_categorie();
      s->choix_pie();
      s->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
