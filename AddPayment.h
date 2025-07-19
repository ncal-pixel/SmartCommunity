#ifndef ADDPAYMENT_H
#define ADDPAYMENT_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class AddPayment;
}

class AddPayment : public QDialog
{
    Q_OBJECT

public:
    explicit AddPayment(QWidget *parent = nullptr);
    explicit AddPayment(QString type,QString time,QString money,QWidget *parent = nullptr);
    ~AddPayment();
    QString m_selectedType;
    QString m_selectedTime;
    QString m_selectedAmount;
private:
    Ui::AddPayment *ui;
    QPushButton *btnOK;
    QPushButton *btnCancle;

private slots:
    void onOK();
    void onCancle();
};

#endif // ADDPAYMENT_H
