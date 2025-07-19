#ifndef REPAIREVALUATION_H
#define REPAIREVALUATION_H

#include <QWidget>

namespace Ui {
class RepairEvaluation;
}

class RepairEvaluation : public QWidget
{
    Q_OBJECT

public:
    explicit RepairEvaluation(QWidget *parent = nullptr);
    ~RepairEvaluation();

private:
    Ui::RepairEvaluation *ui;
};

#endif // REPAIREVALUATION_H
