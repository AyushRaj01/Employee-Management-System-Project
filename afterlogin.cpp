#include "afterlogin.h"
#include "ui_afterlogin.h"
#include <QMessageBox>

afterlogin::afterlogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::afterlogin)
{
    ui->setupUi(this);

    if(!connOpen_2())
        qDebug()<<"Failed to open the employeeData Database";
    else
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery * qry = new QSqlQuery(mydb_2);

        qry -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, designation, department, yearsExperience, currentSalary from newTable");

        qry -> exec();
        modal -> setQuery( *qry);
        ui -> tableView -> setModel(modal);
        ui -> tableView_3 -> setModel(modal);
        connClose_2();

        qDebug() << ( modal -> rowCount());
    }

    if(!connOpen_3())
        qDebug()<<"Failed to open the updateRequest Database";
    else
    {
        QSqlQueryModel * modal = new QSqlQueryModel();
        QSqlQuery * qry1 = new QSqlQuery(mydb_3);

        qry1 -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable");

        qry1 -> exec();
        modal -> setQuery( *qry1);
        ui -> tableView_2 -> setModel(modal);
        connClose_3();

        qDebug() << ( modal -> rowCount());
    }
}

afterlogin::~afterlogin()
{
    delete ui;
}

void afterlogin::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void afterlogin::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void afterlogin::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void afterlogin::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void afterlogin::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void afterlogin::on_pushButton_2_clicked()    //Save Button **************************************
{
    afterlogin conn;
    QString name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary;
    name = ui -> lineEdit -> text();
    DOB = ui -> lineEdit_a -> text();
    gender = ui -> comboBox -> currentText();
    bloodGroup = ui -> comboBox_12 -> currentText();
    contactNo = ui -> lineEdit_3 -> text();
    emailID = ui -> lineEdit_2 -> text();
    address = ui -> lineEdit_4 -> text();
    employeeID = ui -> lineEdit_5 -> text();
    joiningTime = ui -> lineEdit_c -> text();
    designation = ui -> comboBox_3 -> currentText();
    department = ui -> comboBox_4 -> currentText();
    yearsExperience = ui -> comboBox_5 -> currentText();
    currentSalary = ui -> lineEdit_6 -> text();

    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("insert into newTable (name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary) values ('"+name+"', '"+DOB+"', '"+gender+"', '"+bloodGroup+"', '"+contactNo+"', '"+emailID+"', '"+address+"', '"+employeeID+"', '"+joiningTime+"', '"+designation+"', '"+department+"', '"+yearsExperience+"', '"+currentSalary+"')");

    if(qry.exec())
    {
        QMessageBox :: information ( this, tr("Save"), tr("Saved    "));
        qDebug()<<"Saved to employeeData Database";

        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery * qry = new QSqlQuery(conn.mydb_2);

        qry -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable");

        qry -> exec();
        modal -> setQuery( *qry);
        ui -> tableView -> setModel(modal);
        ui -> tableView_3 -> setModel(modal);
        conn.connClose_2();

        qDebug() << ( modal -> rowCount());
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}

void afterlogin::on_pushButton_3_clicked()   //Update Button *****************************************
{
    afterlogin conn;
    QString name, DOB, gender, bloodGroup, contactNo, emailID, address, designation, department, yearsExperience, currentSalary;
    name = ui -> lineEdit_7 -> text();
    DOB = ui -> lineEdit_b -> text();
    gender = ui -> comboBox_11 -> currentText();
    bloodGroup = ui -> comboBox_9 -> currentText();
    contactNo = ui -> lineEdit_12 -> text();
    emailID = ui -> lineEdit_13 -> text();
    address = ui -> lineEdit_11 -> text();
    designation = ui -> comboBox_10 -> currentText();
    department = ui -> comboBox_8 -> currentText();
    yearsExperience = ui -> comboBox_7 -> currentText();
    currentSalary = ui -> lineEdit_14 -> text();

    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("update newTable set name = '"+name+"', DOB = '"+DOB+"', gender = '"+gender+"', bloodGroup = '"+bloodGroup+"', contactNo = '"+contactNo+"', emailID = '"+emailID+"', address = '"+address+"', designation = '"+designation+"', department = '"+department+"', yearsExperience = '"+yearsExperience+"', currentSalary = '"+currentSalary+"' where name = '"+name+"'");

    if(qry.exec())
    {
        QMessageBox :: information ( this, tr("Update"), tr("Updated   "));
        qDebug()<<"Updated to employeeData Database";

        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery * qry = new QSqlQuery(conn.mydb_2);

        qry -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, designation, department, yearsExperience, currentSalary from newTable");

        qry -> exec();
        modal -> setQuery( *qry);
        ui -> tableView -> setModel(modal);
        ui -> tableView_3 -> setModel(modal);

        qDebug() << ( modal -> rowCount());

        conn.connClose_2();
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());

}

void afterlogin::on_tableView_activated(const QModelIndex &index)   //To Display selected row **********************
{
    QString val = ui -> tableView -> model() -> data(index).toString();

    afterlogin conn;
    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    conn.connOpen_2();
    QSqlQuery qry;
    qry.prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, department, designation, yearsExperience, currentSalary from newTable where name = '"+val+"' or DOB = '"+val+"' or gender = '"+val+"' or bloodGroup = '"+val+"' or contactNo = '"+val+"' or emailID = '"+val+"' or address = '"+val+"' or designation = '"+val+"' or department = '"+val+"' or yearsExperience = '"+val+"' or currentSalary = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui -> lineEdit_7 -> setText(qry.value(0).toString());
            ui -> lineEdit_b -> setText(qry.value(1).toString());
            ui -> comboBox_11 -> setItemText(0,qry.value(2).toString());
            ui -> comboBox_9 -> setItemText(0,qry.value(3).toString());
            ui -> lineEdit_12 -> setText(qry.value(4).toString());
            ui -> lineEdit_13 -> setText(qry.value(5).toString());
            ui -> lineEdit_11 -> setText(qry.value(6).toString());
            ui -> comboBox_8 -> setItemText(0,qry.value(7).toString());
            ui -> comboBox_10 -> setItemText(0,qry.value(8).toString());
            ui -> comboBox_7 -> setItemText(0,qry.value(9).toString());
            ui -> lineEdit_14 -> setText(qry.value(10).toString());
        }
        conn.connClose_2();
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}

void afterlogin::on_tableView_3_activated(const QModelIndex &index)
{
    afterlogin conn;
    QString val = ui -> tableView_3 -> model() -> data(index).toString();

    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable where name = '"+val+"' or DOB = '"+val+"' or gender = '"+val+"' or bloodGroup = '"+val+"' or contactNo = '"+val+"' or emailID = '"+val+"' or address = '"+val+"' or employeeID = '"+val+"' or joiningTime = '"+val+"' or designation = '"+val+"' or department = '"+val+"' or yearsExperience = '"+val+"' or currentSalary = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui -> lineEdit_unique -> setText(qry.value(7).toString());
        }
        connClose_2();
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}

void afterlogin::on_pushButton_12_clicked()  // Delete Button ******************************
{
    afterlogin conn;
    QString employeeID;
    employeeID = ui -> lineEdit_unique -> text();

    if(!connOpen_2())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("Delete from newTable where employeeID = '"+employeeID+"'");

    if(qry.exec())
    {
        QMessageBox :: information ( this, tr("Delete"), tr("Deleted   "));
        qDebug()<<"Deleted from employeeData Database";

        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery * qry = new QSqlQuery(conn.mydb_2);

        qry -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable");

        qry -> exec();
        modal -> setQuery( *qry);
        ui -> tableView -> setModel(modal);
        ui -> tableView_3 -> setModel(modal);
        conn.connClose_2();

        qDebug() << ( modal -> rowCount());
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}

void afterlogin::on_pushButton_13_clicked()   // Delete Button for requests *************************
{
    afterlogin conn;
    QString employeeID;
    employeeID = ui -> lineEdit_unique_2 -> text();

    if(!connOpen_3())
    {
        qDebug()<<"Failed to open the employeeData Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("Delete from newTable where employeeID = '"+employeeID+"'");

    if(qry.exec())
    {
        QMessageBox :: information ( this, tr("Delete"), tr("Deleted   "));
        qDebug()<<"Deleted from updateRequest Database";

        QSqlQueryModel * modal = new QSqlQueryModel();

        QSqlQuery * qry1 = new QSqlQuery(conn.mydb_3);

        qry1 -> prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable");

        qry1 -> exec();
        modal -> setQuery( *qry1);
        ui -> tableView_2 -> setModel(modal);
        connClose_3();

        qDebug() << ( modal -> rowCount());
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}


void afterlogin::on_tableView_2_activated(const QModelIndex &index)
{
    afterlogin conn;
    QString val = ui -> tableView_2 -> model() -> data(index).toString();

    if(!connOpen_3())
    {
        qDebug()<<"Failed to open the updateRequest Database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("select name, DOB, gender, bloodGroup, contactNo, emailID, address, employeeID, joiningTime, designation, department, yearsExperience, currentSalary from newTable where name = '"+val+"' or DOB = '"+val+"' or gender = '"+val+"' or bloodGroup = '"+val+"' or contactNo = '"+val+"' or emailID = '"+val+"' or address = '"+val+"' or employeeID = '"+val+"' or joiningTime = '"+val+"' or designation = '"+val+"' or department = '"+val+"' or yearsExperience = '"+val+"' or currentSalary = '"+val+"'");

    if(qry.exec())
    {
        while(qry.next())
        {
            ui -> lineEdit_unique_2 -> setText(qry.value(7).toString());
        }
        connClose_3();
    }
    else
        QMessageBox :: critical ( this, tr("Error"), qry.lastError().text());
}
