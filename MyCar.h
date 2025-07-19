#ifndef MYCAR_H
#define MYCAR_H

#include <QWidget>

namespace Ui {
class MyCar;
}

class MyCar : public QWidget
{
    Q_OBJECT

public:
    explicit MyCar(QWidget *parent = nullptr);
    ~MyCar();

private:
    Ui::MyCar *ui;
};

#endif // MYCAR_H
