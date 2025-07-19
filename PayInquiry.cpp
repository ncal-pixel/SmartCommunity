#include "PayInquiry.h"
#include "ui_PayInquiry.h"

PayInquiry::PayInquiry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PayInquiry)
{
    ui->setupUi(this);
}

PayInquiry::~PayInquiry()
{
    delete ui;
}
