#include "database.h"
#include <QSqlRecord>
#include <QtDebug>

database::database(QObject *parent)
{
    openDB("sql1.db");
}
database::~database(){
    if(db.isOpen())
    {
        db.close();
    }
}
bool database::openDB(const QString& dbPath){
    if(db.open())return true;
    {
       db=QSqlDatabase::addDatabase("QSQLITE");
       db.setDatabaseName(dbPath);
    }
    if(!db.open()){
        qWarning() <<"Failed to open database:"<<db.lastError().text();
    return false;
    }
    return true;
}
//方法使用默认连接的数据库
// 使用引用类型参数提高性能，避免复制
QSqlQuery database::getUserByUsername(const QString& username){
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE username = ?");
    query.addBindValue(username);  //筛选记录，与?占位符对应
    query.exec();   //用于执行sql语句
    return query;
}
QSqlQuery database::query(const QString&s1,const QVector<QVariant>&s2)
{
    QSqlQuery query;
    query.prepare(s1);
    for(QVariant i:s2)
    {
        query.addBindValue(i);
    }
    query.exec();
    return query;
}
QSqlQuery database::query(const QString&s1)
{
    QSqlQuery query;
    query.prepare(s1);
    query.exec();
    return query;
}
bool database::addUser(QString userName,QString password,QString role,QString name,QString department,QString position)
{
    QSqlQuery query=getUserByUsername(userName);
    if(query.next())
    {
        return false;
    }
    else {
     QSqlQuery queryAdd;
     queryAdd.prepare("INSERT INTO Users (userName,password,role,name,department,position) VALUES (?,?,?,?,?,?)");
     queryAdd.addBindValue(userName);
     queryAdd.addBindValue(password);
     queryAdd.addBindValue(role);
     queryAdd.addBindValue(name);
     queryAdd.addBindValue(department);
     queryAdd.addBindValue(position);
     queryAdd.exec();
        return true;
    }
}//, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10

bool database::addOwner(QString name, QString tele, QString building, QString unit, QString floor, QString room)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM owner WHERE telephone = ?");
    query.addBindValue(tele);  //筛选记录，与?占位符对应
    query.exec();   //用于执行sql语
    if(query.next())
    {
        qDebug()<<"错误";
        return false;
    }
    else {
     qDebug()<<"正确";
     QSqlQuery queryAdd;
     queryAdd.prepare("INSERT INTO owner (name, telephone, building_number, unit_number, floor_number, room_number) VALUES (?,?,?,?,?,?)");
 //    queryAdd.prepare("INSERT INTO owner (application_for_real_estate_registration, identity_proof_materials, documents_on_the_origin_and_proof_of_real_estate_ownership, materials_on_real_estate_boundaries, spatial_limits, area, explanatory_materials_on_stakeholder_relationships_with_others, commercial_housing_sales_contract, tax_payment_certificate, tax_payment_certificate) VALUES (0,0,0,0,0,0,0,0,0,0)");
     queryAdd.addBindValue(name);
     queryAdd.addBindValue(tele);
     queryAdd.addBindValue(building);
     queryAdd.addBindValue(unit);
     queryAdd.addBindValue(floor);
     queryAdd.addBindValue(room);
//     queryAdd.addBindValue(0);
//     queryAdd.addBindValue("0");
//     queryAdd.addBindValue(0);
//     queryAdd.addBindValue(0);
//     queryAdd.addBindValue(0);
//     queryAdd.addBindValue(0);
//     queryAdd.exec();
     if (!queryAdd.exec()) {
         qDebug() << "Error inserting owner:" << queryAdd.lastError().text();
         return false;
     }
        return true;
    }
}

//bool database::addFamily(QString name, QString tele, QString re)
//{
//    QSqlQuery query;
//    query.prepare("SELECT * FROM owner_family WHERE telephone = ?");
//    query.addBindValue(tele);
//    query.exec();
//    if(query.next())
//    {
//        qDebug()<<"错误";
//        return false;
//    }
//    else {
//     qDebug()<<"正确";
//     QSqlQuery queryAdd;
//     queryAdd.prepare("INSERT INTO owner_family (name, telephone, relationship_owner) VALUES (?,?,?)");
//     queryAdd.addBindValue(name);
//     queryAdd.addBindValue(tele);
//     queryAdd.addBindValue(re);
//     if (!queryAdd.exec()) {
//         qDebug() << "Error inserting owner:" << queryAdd.lastError().text();
//         return false;
//     }
//        return true;
//    }
//}

bool database::addpayment(int owner_id, QString type, QString amount, int status, QDateTime create_time){
    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO payment (owner_id, type, amount, status, create_time) VALUES (?,?,?,?,?)");
    queryAdd.addBindValue(owner_id);
    queryAdd.addBindValue(type);
    queryAdd.addBindValue(amount);
    queryAdd.addBindValue(status);
    queryAdd.addBindValue(create_time);
    if (queryAdd.exec()) {
        return true;
    } else {
        // 记录详细的错误信息，便于调试
        qDebug() << "添加支付记录失败:" << queryAdd.lastError().text();
        qDebug() << "SQL:" << queryAdd.lastQuery();
        return false;
    }
}

 bool database::updateStaff(int id,QString name,QString department,QString position)
 {
     QSqlQuery query;
     query.prepare("UPDATE Users SET name=?,department=?,position=? WHERE id=?");
     query.addBindValue(name);
     query.addBindValue(department);
     query.addBindValue(position);
     query.addBindValue(id);
     query.exec();            //检查是否执行更新成功
     return true;
 }

 bool database::updateOwner(int id,QString tele, QString building, QString unit, QString floor, QString room)
 {
     QSqlQuery query;
     query.prepare("UPDATE owner SET telephone=?, building_number=?, unit_number=?, floor_number=?, room_number=? WHERE id=?");
     query.addBindValue(tele);
     query.addBindValue(building);
     query.addBindValue(unit);
     query.addBindValue(floor);
     query.addBindValue(room);
     query.addBindValue(id);
     query.exec();            //检查是否执行更新成功
     return true;
 }

 bool database::updatePayment(QString type,QString time,QString amount,int status)
 {
     status = 1;
     QSqlQuery query;
     query.prepare("UPDATE payment SET status = :status "
                   "WHERE type = :type AND create_time = :time AND amount = :amount");

     query.bindValue(":status", status);
     query.bindValue(":type", type);
     query.bindValue(":time", time);
     query.bindValue(":amount", amount);
     query.exec();            //检查是否执行更新成功
     return true;
 }

 QString database::getUsernameById(const int&id)
 {
     QSqlQuery query;
     query.prepare("SELECT * FROM Users WHERE id = ?");
     query.addBindValue(id);  //筛选记录，与?占位符对应
     query.exec();   //用于执行sql语句
     query.next();
     return query.value("username").toString();
 }
 int database::getUserIdByUsername(const QString &username)
 {
     QSqlQuery query;
     query.prepare("SELECT id FROM Users WHERE username = ? ");
     query.addBindValue(username);
     query.exec();
     query.next();
     return query.value("id").toInt();
 }
 int database::getPaymentIdByTime(const QString &time){
     QSqlQuery query;
     query.prepare("SELECT id FROM payment WHERE create_time = ? ");
     query.addBindValue(time);
     query.exec();
     query.next();
     return query.value("id").toInt();
 }
