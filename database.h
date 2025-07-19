#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QVariantList>
#include <QVariant>
#include <QMap>
#include <QVector>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

class database :public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
public:
    static database& getInstance() {
            static database instance;
            return instance;
        }
   QSqlDatabase getDatabase()
   {
      return db;
   }
    explicit database(QObject *parent = nullptr);       //构造函数
    virtual ~database();      //析构函数
    bool openDB(const QString& dbPath);                 //启动数据库
    QSqlQuery getUserByUsername(const QString& username);
    QSqlQuery query(const QString& s1);
    QSqlQuery query(const QString& s1,const QVector<QVariant>&s2);
    QString getUsernameById(const int&id);
    int getPaymentIdByTime(const QString& time);
    int getUserIdByUsername(const QString&username);
    bool addUser(QString userName,QString password,QString role,QString name,QString department,QString position);//,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10
    bool addOwner(QString name,QString tele,QString building,QString unit,QString floor,QString room);
//    bool addFamily(QString name,QString tele,QString re);
    bool updateStaff(int id,QString name,QString department,QString position);
    bool updatePayment(QString type,QString time,QString amount,int status);
    bool updateOwner(int id,QString type,QString time,QString amount,QString floor,QString room);
    bool addpayment(int owner_id,QString type,QString amount,int status,QDateTime creat_time);
    database(const database&) = delete;
    database& operator=(const database&) = delete;
};
#endif // DATABASE_H
