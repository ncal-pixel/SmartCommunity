#ifndef REPAIRPROGRESSINQUIRY_H
#define REPAIRPROGRESSINQUIRY_H

#include <QWidget>

namespace Ui {
class RepairProgressInquiry;
}

class RepairProgressInquiry : public QWidget
{
    Q_OBJECT

public:
    explicit RepairProgressInquiry(QWidget *parent = nullptr);
    ~RepairProgressInquiry();

private:
    Ui::RepairProgressInquiry *ui;
};

#endif // REPAIRPROGRESSINQUIRY_H
