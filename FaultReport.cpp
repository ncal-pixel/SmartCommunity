#include "FaultReport.h"
#include "ui_FaultReport.h"

FaultReport::FaultReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaultReport)
{
    ui->setupUi(this);
}

FaultReport::~FaultReport()
{
    delete ui;
}
