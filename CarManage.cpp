#include "CarManage.h"
#include "ui_CarManage.h"

CarManage::CarManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarManage)
{
    ui->setupUi(this);
}

CarManage::~CarManage()
{
    delete ui;
}
