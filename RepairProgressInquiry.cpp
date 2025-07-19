#include "RepairProgressInquiry.h"
#include "ui_RepairProgressInquiry.h"

RepairProgressInquiry::RepairProgressInquiry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RepairProgressInquiry)
{
    ui->setupUi(this);
}

RepairProgressInquiry::~RepairProgressInquiry()
{
    delete ui;
}
