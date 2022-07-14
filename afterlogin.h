#ifndef AFTERLOGIN_H      //#ifndef directive allows for conditional compilation.The preprocessor determines if the provided macro does not exist before including the subsequent code in the compilation process.
#define AFTERLOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

namespace Ui
{
class afterlogin;
}

class afterlogin : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb_2;    //employee data
    QSqlDatabase mydb_3;   //update request

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
    explicit afterlogin(QWidget *parent = nullptr);
    ~afterlogin();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_pushButton_4_clicked();

    void on_tableView_activated(const QModelIndex &index);

    //void on_pushButton_5_clicked();

    //void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_tableView_3_activated(const QModelIndex &index);

    void on_pushButton_13_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

private:
    Ui::afterlogin *ui;
};

#endif // AFTERLOGIN_H
