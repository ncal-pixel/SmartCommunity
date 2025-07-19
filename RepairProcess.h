#ifndef REPAIRPROCESS_H
#define REPAIRPROCESS_H

#include <QWidget>

namespace Ui {
class RepairProcess;
}

class RepairProcess : public QWidget
{
    Q_OBJECT

public:
    explicit RepairProcess(QWidget *parent = nullptr);
    ~RepairProcess();

private:
    Ui::RepairProcess *ui;
};

#endif // REPAIRPROCESS_H
