#ifndef FAULTREPORT_H
#define FAULTREPORT_H

#include <QWidget>

namespace Ui {
class FaultReport;
}

class FaultReport : public QWidget
{
    Q_OBJECT

public:
    explicit FaultReport(QWidget *parent = nullptr);
    ~FaultReport();

private:
    Ui::FaultReport *ui;
};

#endif // FAULTREPORT_H
