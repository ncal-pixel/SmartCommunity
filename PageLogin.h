#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QLineEdit>

#include "QTextStream"
#include "database.h"

namespace Ui {
class Widget;
}

class PageLogin : public QDialog
{
    Q_OBJECT

public:
    explicit PageLogin(QWidget *parent = 0);
    ~PageLogin();

public slots:
    void set_style();
    void on_radioButton_toggled(bool checked);
    void on_btn_login_clicked();

signals:
    void  succeedLoginSignal(int userId,int role,QString userName);

private:
    Ui::Widget *ui;
    QLineEdit* m_usernameEdit;
    QLineEdit* m_pwdEdit;
};

#endif // WIDGET_H
