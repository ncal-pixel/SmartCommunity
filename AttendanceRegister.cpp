#include "AttendanceRegister.h"
#include "ui_AttendanceRegister.h"

AttendanceRegister::AttendanceRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AttendanceRegister)
{
    ui->setupUi(this);
}

AttendanceRegister::~AttendanceRegister()
{
    delete ui;
}
