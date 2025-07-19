#include "CarRent.h"
#include "ui_CarRent.h"
#include "database.h"
#include <QMessageBox>
CarRent::CarRent(int spot_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarRent)
{
    //默认无人申请
    status=0;


    //展示车位基本信息
    ui->setupUi(this);
    this->spot_id=spot_id;
    auto&db=database::getInstance();
    QSqlQuery query=db.query("SELECT * FROM parking_spot WHERE id = ?",{spot_id});
    query.next();
    QString location=query.value("location").toString();
    QString floor=query.value("floor").toString();
    QString charge=query.value("is_rechargeable").toString();
    QString size=query.value("size").toString();
    ui->lb_location->setText("位置："+location);
    ui->lb_floor->setText("楼层："+floor);
    ui->lb_charge->setText("是否有充电桩："+charge);
    ui->lb_size->setText("大小："+size);


    //显示最早的匹配的申请记录
    QSqlQuery query1;
    query1.prepare("SELECT * FROM parking_application WHERE "
                              "floor = ? AND is_rechargeable =? AND size=? "
                    "ORDER BY apply_time ASC");
    query1.addBindValue(floor);
    query1.addBindValue(charge);
    query1.addBindValue(size);
    query1.exec();
        if(query1.next())
        {
            owner_id=query1.value("owner_id").toInt();
            outdate=query1.value("outdate").toString();
            ui->lb_owner->setText("业主ID："+QString::number(owner_id));
            ui->lb_outdate->setText("租用到期事件："+ outdate);
            ui->lb_fee->setText("租用费用："+query1.value("fee").toString());


            status=1;
        }


    //绑定按钮和事件
    btnSummit=ui->btnSummit;
    btnExit=ui->btnExit;
    connect(btnSummit,&QPushButton::clicked,this,&CarRent::onSummit);
    connect(btnExit,&QPushButton::clicked,this,&CarRent::onExit);

}

CarRent::~CarRent()
{
    delete ui;
}

void CarRent::onSummit(){
    if(status==0)
    {
        QMessageBox::warning(this,"提示","暂无业主申请该车位，无法出租");
        close();
        return;
    }else{
        auto &db=database::getInstance();
        QSqlQuery query=db.query("UPDATE parking_spot SET outdate = ?,status= ?,owner_id =? WHERE id = ?",{outdate,1,owner_id,
                                 spot_id});
        QSqlQuery query1=db.query("UPDATE owner SET parking_spot_id = ? WHERE id=?",{spot_id,owner_id});
        QMessageBox::information(this,"成功出租","你已成功将该车位出租");
    }
}
void CarRent::onExit(){
    close();
}
