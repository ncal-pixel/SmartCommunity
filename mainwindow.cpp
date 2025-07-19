#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PageLogin.h"
#include <QDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PageLogin* pageLogin=new PageLogin();
    pageLogin->show();
    auto f=[&](int id,int r,QString Name){
        userId=id;
        role=r;

        if(role==0)//管理界面
        {
              AdminWindow * w=new AdminWindow(userId,Name);
              w->show();
        }
        else if(role==1)  //工作人员
        {
            StaffWindow * w=new StaffWindow(userId,Name);
            w->show();
        }
        else if(role==2)
        {
             OwnerWindow * w=new OwnerWindow(userId,Name);
            w->show();
        }
        else{
            QMessageBox::warning(this,"进入失败","用户身份不符");
        }
    };
    connect(pageLogin,&PageLogin::succeedLoginSignal,this,f);
}

MainWindow::~MainWindow()
{
    delete ui;
}
