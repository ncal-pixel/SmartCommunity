#ifndef CARRENT_H
#define CARRENT_H

#include <QDialog>

namespace Ui {
class CarRent;
}

class CarRent : public QDialog
{
    Q_OBJECT

public:
    explicit CarRent(int spot_id,QWidget *parent = nullptr);
    ~CarRent();

private:
    Ui::CarRent *ui;
    int spot_id;
    QPushButton*btnSummit;
    QPushButton*btnExit;
    int status;
    int owner_id;
    QString outdate;
private slots:
    void onSummit();
    void onExit();
};

#endif // CARRENT_H
