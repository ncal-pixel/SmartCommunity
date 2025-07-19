#ifndef REPAIRINQUIRY_H
#define REPAIRINQUIRY_H

#include <QWidget>

namespace Ui {
class RepairInquiry;
}

class RepairInquiry : public QWidget
{
    Q_OBJECT

public:
    explicit RepairInquiry(QWidget *parent = nullptr);
    ~RepairInquiry();

private:
    Ui::RepairInquiry *ui;
};

#endif // REPAIRINQUIRY_H
