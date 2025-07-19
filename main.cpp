#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "owner/PayInquiry.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/res/qss/style-2.qss");/*QSS文件所在的路径*/

    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    a.setStyleSheet(stylesheet);
    file.close();
    MainWindow w;
    PayInquiry *p=new PayInquiry(1);
    p->show();
//    w.show();
    return a.exec();
}
