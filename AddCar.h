#ifndef ADDCAR_H
#define ADDCAR_H

#include <QDialog>
#include <QPushButton>
namespace Ui {
class AddCar;
}

class AddCar : public QDialog
{
    Q_OBJECT

public:
    explicit AddCar(QWidget *parent=nullptr) ;
    explicit AddCar(int spot_id,QString location,QString floorStr,QString sizeStr,QString ChargeStr,QWidget *parent = nullptr);
    ~AddCar();

private:
    Ui::AddCar *ui;
    QString location;
    int size;
    int isRechargeable;
    int floor;
    int spot_id;
    QPushButton* btnSummit;
    QPushButton* btnExit;
    int option;
private slots:
    void onSummit();
    void onExit();
};

#endif // ADDCAR_H
