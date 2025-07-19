#include "PageLogin.h"
//#include "ui_PageLogin.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>

PageLogin::PageLogin(QWidget *parent) :
    QDialog (parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label_user_name->setScaledContents(true);   //图片自适应label大小
    ui->label_pwd->setScaledContents(true);         //图片自适应label大小

    ui->lineE_pwd->setEchoMode(QLineEdit::Password);//设置为小黑点
    m_usernameEdit = ui->lineE_user_name;
    m_pwdEdit = ui -> lineE_pwd;

}

QPushButton* btn;
void PageLogin::set_style()
{
    btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
    QString filePath;
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}

PageLogin::~PageLogin()
{
    delete ui;
}

void PageLogin::on_radioButton_toggled(bool checked)
{
    if (checked){
        ui->label_pwd_2->setPixmap(QPixmap(":/res/pic/PwShow.png").scaled(20,20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lineE_pwd->setEchoMode(QLineEdit::Normal);
    } else {
        // 隐藏密码：切换图标为闭眼，输入框密文显示
        ui->label_pwd_2->setPixmap(QPixmap(":/res/pic/PwHide.png").scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->lineE_pwd->setEchoMode(QLineEdit::Password);
    }
}


void PageLogin::on_btn_login_clicked()
{
    QString username = ui -> lineE_user_name -> text().trimmed();
    QString password = ui -> lineE_pwd ->text();
    if(username.isEmpty()||password.isEmpty())
    {
        QMessageBox::warning(this,"提示","请输入用户名和密码");
        return;
    }
    auto&db=database::getInstance();
    QSqlQuery query=db.getUserByUsername(username);
    if(query.next())
    {
        QString dbPassword=query.value("password").toString();
        if(dbPassword!=password)
        {
            QMessageBox::warning(this,"登录失败","密码错误！");
            return;
        }
        //成功登录
        int userId=query.value("id").toInt();
        int role=query.value("role").toInt();
        QString userName=query.value("username").toString();
        emit succeedLoginSignal(userId,role,userName);

    }
    else
        {
        QMessageBox::warning(this,"登录失败","用户名不存在");
        return;
    }
    close();
}
