#include "RepairProcess.h"
#include "ui_RepairProcess.h"

RepairProcess::RepairProcess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RepairProcess)
{
    ui->setupUi(this);
}

RepairProcess::~RepairProcess()
{
    delete ui;
}
