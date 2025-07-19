#ifndef ATTENDANCEREGISTER_H
#define ATTENDANCEREGISTER_H

#include <QWidget>

namespace Ui {
class AttendanceRegister;
}

class AttendanceRegister : public QWidget
{
    Q_OBJECT

public:
    explicit AttendanceRegister(QWidget *parent = nullptr);
    ~AttendanceRegister();

private:
    Ui::AttendanceRegister *ui;
};

#endif // ATTENDANCEREGISTER_H
