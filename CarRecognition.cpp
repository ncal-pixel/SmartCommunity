#include "CarRecognition.h"
#include "ui_CarRecognition.h"

CarRecognition::CarRecognition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CarRecognition)
{
    ui->setupUi(this);
}

CarRecognition::~CarRecognition()
{
    delete ui;
}
