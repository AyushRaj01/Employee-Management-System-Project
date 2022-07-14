#ifndef FORMEMBERS_H
#define FORMEMBERS_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

//#include "mainwindow.h"

namespace Ui {
class formembers;
}

class formembers : public QMainWindow
{
    Q_OBJECT

public:
    //QString val;
    QSqlDatabase mydb_2;
    QSqlDatabase mydb_3;

    void connClose_2()
    {
        mydb_2.close();
        mydb_2.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen_2()
    {
        mydb_2 = QSqlDatabase :: addDatabase("QSQLITE");
        mydb_2.setDatabaseName("C:/qt/Project1/db/employeeData.db");

        if(!mydb_2.open())
        {
            qDebug()<<"Failed to open the employeeData Database";
            return false;
        }
        else
        {
            qDebug()<<"Connected to the employeeData Database";
            return true;
        }
    }

    void connClose_3()
    {
        mydb_2.close();
        mydb_2.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen_3()
    {
        mydb_3 = QSqlDatabase :: addDatabase("QSQLITE");
        mydb_3.setDatabaseName("C:/qt/Project1/db/updateRequest.db");

        if(!mydb_3.open())
        {
            qDebug()<<"Failed to open the updateRequest Database";
            return false;
        }
        else
        {
            qDebug()<<"Connected to the updateRequest Database";
            return true;
        }
    }

public:
    explicit formembers(QWidget *parent = nullptr);
    ~formembers();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::formembers *ui;
    //MainWindow *MainWindow;
};

#endif // FORMEMBERS_H
