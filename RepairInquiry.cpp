#include "RepairInquiry.h"
#include "ui_RepairInquiry.h"

RepairInquiry::RepairInquiry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RepairInquiry)
{
    ui->setupUi(this);
}

RepairInquiry::~RepairInquiry()
{
    delete ui;
}
