#include "RepairEvaluation.h"
#include "ui_RepairEvaluation.h"

RepairEvaluation::RepairEvaluation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RepairEvaluation)
{
    ui->setupUi(this);
}

RepairEvaluation::~RepairEvaluation()
{
    delete ui;
}
