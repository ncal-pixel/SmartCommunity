#-------------------------------------------------
#
# Project created by QtCreator 2025-07-12T20:54:17
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartCommunity
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    database.cpp \
    PageLogin.cpp \
    MainWindow/StaffWindow.cpp \
    MainWindow/OwnerWindow.cpp \
    admin/StaffManage.cpp \
    admin/LeaveApprove.cpp \
    admin/MonthAttendance.cpp \
    admin/Setting.cpp \
    MainWindow/AdminWindow.cpp \
    SayHi.cpp \
    staff/CarManage.cpp \
    staff/MemberRegister.cpp \
    staff/OwnerManage.cpp \
    staff/PaymentManage.cpp \
    staff/PriceManage.cpp \
    staff/PropertyRegister.cpp \
    staff/RepairInquiry.cpp \
    staff/StaffPayInquiry.cpp \
    owner/CarRecognition.cpp \
    owner/FaultReport.cpp \
    owner/MyCar.cpp \
    owner/PayInquiry.cpp \
    owner/RepairEvaluation.cpp \
    owner/RepairProgressInquiry.cpp \
    staff/RepairProcess.cpp \
    staff/LeaveManage.cpp \
    staff/AttendanceRegister.cpp \
    AddCar.cpp \
    CarRent.cpp \
    AddPayment.cpp \
    AddProperty.cpp

HEADERS += \
        mainwindow.h \
    database.h \
    PageLogin.h \
    MainWindow/OwnerWindow.h \
    MainWindow/StaffWindow.h \
    admin/StaffManage.h \
    admin/LeaveApprove.h \
    admin/MonthAttendance.h \
    admin/Setting.h \
    MainWindow/AdminWindow.h \
    SayHi.h \
    staff/CarManage.h \
    staff/LeaveManage.h \
    staff/MemberRegister.h \
    staff/OwnerManage.h \
    staff/PaymentManage.h \
    staff/PriceManage.h \
    staff/PropertyRegister.h \
    staff/RepairInquiry.h \
    staff/StaffPayInquiry.h \
    owner/CarRecognition.h \
    owner/FaultReport.h \
    owner/MyCar.h \
    owner/PayInquiry.h \
    owner/RepairEvaluation.h \
    owner/RepairProgressInquiry.h \
    staff/RepairProcess.h \
    staff/LeaveManage.h \
    staff/AttendanceRegister.h \
    AddCar.h \
    CarRent.h \
    AddPayment.h \
    AddProperty.h

FORMS += \
        mainwindow.ui \
    widget.ui \
    MainWindow/OwnerWindow.ui \
    MainWindow/StaffWindow.ui \
    admin/Setting.ui \
    admin/LeaveApprove.ui \
    admin/MonthAttendance.ui \
    admin/StaffManage.ui \
    MainWindow/AdminWindow.ui \
    staff/CarManage.ui \
    staff/LeaveManage.ui \
    staff/MemberRegister.ui \
    staff/OwnerManage.ui \
    staff/PaymentManage.ui \
    staff/PriceManage.ui \
    staff/PropertyRegister.ui \
    staff/RepairInquiry.ui \
    staff/StaffPayInquiry.ui \
    owner/CarRecognition.ui \
    owner/FaultReport.ui \
    owner/MyCar.ui \
    owner/PayInquiry.ui \
    owner/RepairEvaluation.ui \
    owner/RepairProgressInquiry.ui \
    staff/RepairProcess.ui \
    staff/LeaveManage.ui \
    staff/AttendanceRegister.ui \
    AddCar.ui \
    CarRent.ui \
    AddPayment.ui \
    AddProperty.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc \
    qss.qrc
