#ifndef CARRECOGNITION_H
#define CARRECOGNITION_H

#include <QWidget>

namespace Ui {
class CarRecognition;
}

class CarRecognition : public QWidget
{
    Q_OBJECT

public:
    explicit CarRecognition(QWidget *parent = nullptr);
    ~CarRecognition();

private:
    Ui::CarRecognition *ui;
};

#endif // CARRECOGNITION_H
