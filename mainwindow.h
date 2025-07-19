#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainWindow/AdminWindow.h"
#include "MainWindow/StaffWindow.h"
#include "MainWindow/OwnerWindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int userId;
    int role;
};

#endif // MAINWINDOW_H
