#include "SayHi.h"

SayHi::SayHi()
{

}
QString SayHi::say(QWidget*label)
{
    QTime currentTime = QTime::currentTime();

    // 获取小时和分钟
    int hour = currentTime.hour();
    int minute = currentTime.minute();
    if(hour<=12&&hour>=6)
    {
        label->setStyleSheet("image: url(:/res/pic/sun.png);");
        return "上午好!";
    }
    else if(hour<=18)
    {
        label->setStyleSheet("image: url(:/res/pic/sun.png);");
        return "下午好!";
    }
    else {
        label->setStyleSheet("image: url(:/res/pic/moon.png);");
        return "晚上好!";
    }
}
