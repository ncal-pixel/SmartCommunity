#ifndef SAYHI_H
#define SAYHI_H
#include <QTextStream>
#include <QTime>
#include <QLabel>
#include <QWidget>
class SayHi
{
public:
    SayHi();
    static QString say(QWidget*label);
};

#endif // SAYHI_H
