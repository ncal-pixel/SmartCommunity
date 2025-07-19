#ifndef PAYINQUIRY_H
#define PAYINQUIRY_H

#include <QWidget>

namespace Ui {
class PayInquiry;
}

class PayInquiry : public QWidget
{
    Q_OBJECT

public:
    explicit PayInquiry(QWidget *parent = nullptr);
    ~PayInquiry();

private:
    Ui::PayInquiry *ui;
};

#endif // PAYINQUIRY_H
