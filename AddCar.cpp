#include "AddCar.h"
#include "ui_AddCar.h"
#include "database.h"
#include <QMessageBox>
AddCar::AddCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCar)
{
    option=1;
    ui->setupUi(this);
    btnSummit=ui->btnSummit;
    btnExit=ui->btnExit;
    connect(btnSummit,&QPushButton::clicked,this,&AddCar::onSummit);
    connect(btnExit,&QPushButton::clicked,this,&AddCar::onExit);
}
AddCar::AddCar(int spot_id,QString location,QString floorStr,QString ChargeStr,QString sizeStr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCar)
{
    this->spot_id=spot_id;
    option=0;
    ui->setupUi(this);
    btnSummit=ui->btnSummit;
    btnExit=ui->btnExit;
    connect(btnSummit,&QPushButton::clicked,this,&AddCar::onSummit);
    connect(btnExit,&QPushButton::clicked,this,&AddCar::onExit);
    ui->editloaction->setText(location);
    ui->comboFloor->setCurrentText(floorStr);
    ui->comboSize->setCurrentText(sizeStr);
    qDebug()<<ChargeStr;
    qDebug()<<floorStr;
    ui->comboCharge->setCurrentText(ChargeStr);
}
AddCar::~AddCar()
{
    delete ui;
}
void AddCar::onSummit(){
    location=ui->editloaction->text();
    int floor=ui->comboFloor->currentText().toInt();
    QString sizeStr=ui->comboSize->currentText();
    if(sizeStr=="大")size=1;
    else size=0;
    QString isRechargeableStr=ui->comboCharge->currentText();
    if(isRechargeableStr=="有") isRechargeable=1;
    else isRechargeable=0;
    auto& db = database::getInstance();
     QSqlQuery query;
    if(option)
    {
         query.prepare("INSERT INTO parking_spot (location,floor, size,is_rechargeable,status,owner_id) VALUES (?,?,?,?,0,0)");
         query.addBindValue(location);
         query.addBindValue(floor);
         query.addBindValue(size);
         query.addBindValue(isRechargeable);
         query.exec();
         QMessageBox::information(this,"添加成功","已完成车位添加");
    }
    else {
        qDebug()<<spot_id;
        query.prepare("UPDATE parking_spot SET location=?,floor=?, size=?,is_rechargeable=?,status=?,owner_id=?"
                      "WHERE id = ?");
        query.addBindValue(location);
        query.addBindValue(floor);
        query.addBindValue(size);
        query.addBindValue(isRechargeable);
        query.addBindValue(0);
        query.addBindValue(0);
        query.addBindValue(spot_id);
        query.exec();
        QMessageBox::information(this,"修改成功","已完成车位修改");
    }
}
void AddCar::onExit(){
    close();
}
