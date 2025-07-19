#include "LeaveApprove.h"
#include "ui_LeaveApprove.h"

LeaveApprove::LeaveApprove(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeaveApprove)
{
    ui->setupUi(this);
}

LeaveApprove::~LeaveApprove()
{
    delete ui;
}
