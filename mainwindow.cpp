#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "afterlogin.h"
#include "formembers.h"

QString globaldata;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(!connOpen_1())
        qDebug()<<"Failed to open the username Database";
    else
        qDebug()<<"Connected to the username Database";

    if(!connOpen_2())
        qDebug()<<"Failed to open the employeeData Database";
    else
        qDebug()<<"Connected to the employeeData Database";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username, password;
    username = ui -> username -> text();
    password = ui -> password -> text();

    if(!connOpen_1())
    {
        qDebug()<<"Failed to open the username Database";
        ui -> label_3 -> setText ("Failed to open the Database");
        return;
    }

    connOpen_1();

    QSqlQuery qry1;

    qry1.prepare("select * from newTable where username = '"+ username +"' and password = '"+ password +"'");

    if(qry1.exec())
    {
        int count = 0;
        while (qry1.next())
        {
            count++;
        }
        if (count == 1)
        {
            connClose_1();
            this->hide();
            afterlogin = new class afterlogin(this);
            afterlogin->show();
        }
        if (count > 1)
        {
            ui -> label_3 -> setText ("Welcome... ( Duplicate username and/or password ");
            this->hide();
            afterlogin = new class afterlogin(this);
            afterlogin->show();
        }
        if (count < 1)
            ui -> label_3 -> setText ("Incorrect username and/or password ");
    }
    else
        qDebug()<<"Failed to executed Query";
}



void MainWindow::on_pushButton_2_clicked()
{
    QString username, password;
    username = ui -> username -> text();
    password = ui -> password -> text();

    globaldata = ui->password->text();

    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        ui -> label_3 -> setText ("Failed to open the Database");
        return;
    }

    connOpen_2();

    QSqlQuery qry2;

    qry2.prepare("select * from newTable where username = '"+ username +"' and password = '"+ password +"'");

    if(qry2.exec())
    {
        int count = 0;
        while (qry2.next())
        {
            count++;
        }
        if (count == 1)
        {
            connClose_2();
            this->hide();
            formembers = new class formembers(this);
            formembers->show();
        }
        if (count > 1)
        {
            ui -> label_3 -> setText ("Welcome... ( Duplicate username and/or password ");
            this->hide();
            formembers = new class formembers(this);
            formembers->show();
        }
        if (count < 1)
            ui -> label_3 -> setText ("Incorrect username and/or password ");
    }
    else
        qDebug()<<"Failed to executed Query";
}

