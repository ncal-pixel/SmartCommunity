#include "MyCar.h"
#include "ui_MyCar.h"

MyCar::MyCar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyCar)
{
    ui->setupUi(this);
}

MyCar::~MyCar()
{
    delete ui;
}
