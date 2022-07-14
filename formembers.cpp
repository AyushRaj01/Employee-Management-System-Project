#include "formembers.h"
#include "ui_formembers.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern QString globaldata;

formembers::formembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::formembers)
{
    ui->setupUi(this);

    if(!connOpen_2())
        qDebug()<<"Failed to open the employeeData Database";
    else
    {
        ui->lineEdit_5->setText(globaldata);

        QSqlQuery qry;
        qry.prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, department, designation, yearsExperience, currentSalary from newTable where password = '"+globaldata+"'");

        if(qry.exec())
        {
            while(qry.next())
            {
                ui -> lineEdit -> setText(qry.value(0).toString());
                ui -> lineEdit_7 -> setText(qry.value(1).toString());
                ui -> lineEdit_9 -> setText(qry.value(2).toString());
                ui -> lineEdit_10 -> setText(qry.value(3).toString());
                ui -> lineEdit_3 -> setText(qry.value(4).toString());
                ui -> lineEdit_2 -> setText(qry.value(5).toString());
                ui -> lineEdit_4 -> setText(qry.value(6).toString());
                ui -> lineEdit_5 -> setText(qry.value(7).toString());
                ui -> lineEdit_8 -> setText(qry.value(8).toString());
                ui -> lineEdit_12 -> setText(qry.value(9).toString());
                ui -> lineEdit_11 -> setText(qry.value(10).toString());
                ui -> lineEdit_13 -> setText(qry.value(11).toString());
                ui -> lineEdit_6 -> setText(qry.value(12).toString());
            }
            connClose_2();
        }
        else
            QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
    }



        qDebug()<<"Connected to the employeeData Database";

    if(!connOpen_3())
        qDebug()<<"Failed to open the updateRequest Database";
    else
        qDebug()<<"Connected to the updateRequest Database";
}

formembers::~formembers()
{
    delete ui;
}

void formembers::on_pushButton_2_clicked()  // Send Request Button *******************************************
{
    formembers conn;
    QString name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary;
    name = ui -> lineEdit -> text();
    DOB = ui -> lineEdit_7 -> text();
    gender = ui -> lineEdit_9 -> text();
    bloodGroup = ui -> lineEdit_10 -> text();
    contactNo = ui -> lineEdit_3 -> text();
    emailID = ui -> lineEdit_2 -> text();
    address = ui -> lineEdit_4 -> text();
    employeeID = ui -> lineEdit_5 -> text();
    joiningTime = ui -> lineEdit_8 -> text();
    designation = ui -> lineEdit_12 -> text();
    department = ui -> lineEdit_11 -> text();
    yearsExperience = ui -> lineEdit_13 -> text();
    currentSalary = ui -> lineEdit_6 -> text();

    if(!connOpen_3())
    {
        qDebug()<<"Failed to open the updateRequest Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("insert into newTable (name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary) values ('"+name+"', '"+DOB+"', '"+gender+"', '"+bloodGroup+"', '"+contactNo+"', '"+emailID+"', '"+address+"', '"+employeeID+"', '"+joiningTime+"', '"+designation+"', '"+department+"', '"+yearsExperience+"', '"+currentSalary+"')");

    if(qry.exec())
    {
        QMessageBox :: information ( this, tr("Update Request"), tr("Update Request Sent    "));
        qDebug()<<"Saved to updateRequest Database";
        conn.connClose_3();
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}

