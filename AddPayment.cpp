#include "AddPayment.h"
#include "ui_AddPayment.h"
#include "database.h"
#include <QMessageBox>

AddPayment::AddPayment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPayment)
{
    ui->setupUi(this);
}

AddPayment::AddPayment(QString type,QString time, QString amount, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPayment)
    , m_selectedType(type)
    , m_selectedTime(time)
    , m_selectedAmount(amount)
{
    ui->setupUi(this);

    connect(ui->btnOK, &QPushButton::clicked, this, &AddPayment::onOK);
    connect(ui->btnCancle,&QPushButton::clicked,this,&AddPayment::onCancle);
}

AddPayment::~AddPayment()
{
    delete ui;
}

void AddPayment::onOK(){
    QMessageBox::warning(this,"","是否确认缴费?");
    auto& db=database::getInstance();
    db.openDB("sql1.db");
    int status=1;
    bool success=db.updatePayment(m_selectedType, m_selectedTime, m_selectedAmount,status);
    success=1;
    if(success)QMessageBox::warning(this,"","恭喜您,缴费成功！");
    close();
}

void AddPayment::onCancle(){
    QMessageBox::warning(this,"","是否取消支付?");
    close();
}
