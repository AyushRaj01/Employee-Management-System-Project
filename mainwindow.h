#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtGlobal>

#include "afterlogin.h"
#include "formembers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb_1;
    QSqlDatabase mydb_2;

    void connClose_1()
    {
        mydb_1.close();
        mydb_1.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen_1()
    {
        mydb_1 = QSqlDatabase :: addDatabase("QSQLITE");
        mydb_1.setDatabaseName("C:/qt/Project1/db/username.db");

        if(!mydb_1.open())
        {
            qDebug()<<"Failed to open the username Database";
            return false;
        }
        else
        {
            qDebug()<<"Connected to the username Database";
            return true;
        }
    }

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    afterlogin *afterlogin;
    formembers *formembers;
};
#endif // MAINWINDOW_H
