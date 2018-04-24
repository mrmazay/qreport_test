#include <QCoreApplication>
#include <QObject>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "lrreportengine.h"

#define HOST                "192.168.220.101"
#define DATABASE_NAME       "devbase"
#define USER_NAME           "devbase"
#define PASSWORD            "1465714"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "test mysql";
    QStringList drivers = QSqlDatabase::drivers();
    qDebug()<<"list drivers";
    qDebug()<<drivers;

    qDebug() << QCoreApplication::libraryPaths();
    QSqlDatabase     db = QSqlDatabase::addDatabase("QMYSQL");

    QSqlQueryModel  *CardModel;
    QSqlQueryModel  *PackModel;
    QSqlQueryModel  *CharactModel;
    //****************************************************************************
       db.setHostName(HOST);
       db.setPort(3306);
       db.setDatabaseName(DATABASE_NAME);
       db.setUserName(USER_NAME);
       db.setPassword(PASSWORD);

       db.open();
       if(db.open()){
           qDebug()<<"DB Opened";
           qDebug() <<DATABASE_NAME;
           QSqlQuery sql = QSqlQuery(db);
           sql.exec("SET NAMES 'cp1251'");
       } else {
           qDebug()<<"Error "<<db.lastError().text();
       }
    //*****************************************************************************
             CardModel    = new QSqlQueryModel();
             CharactModel = new QSqlQueryModel();
             PackModel    = new QSqlQueryModel();
 LimeReport::ReportEngine report;
          // report = new LimeReport::ReportEngine();
qDebug()<<"ReportEngine Created";
             CardModel->setQuery("Select * from vCard where SiId=1");
             PackModel->setQuery("Select * from tPackage where SiId=1");
             CharactModel->setQuery("Select * from tCharacter where SiId=1");

             report.dataManager()->addModel("card",CardModel,false);
             report.dataManager()->addModel("charact",CharactModel,false);
             report.dataManager()->addModel("pack",PackModel,false);

qDebug()<<"ReportModels Created";

       //report->dataManager()->setReportVariable("SiId",SiId);

     report.loadFromFile(QCoreApplication::applicationDirPath()+"/report/Card.lrxml");
     if (report.printToPDF("./Card.pdf")){
qDebug()<<"Card.pdf Created";
       }
       ////report->designReport();
//       report->previewReport();
//qDebug()<<"ReportEngine Preview";
    return a.exec();
}
