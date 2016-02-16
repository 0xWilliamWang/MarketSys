#-------------------------------------------------
#
# Project created by QtCreator 2015-09-30T22:57:42
#
#-------------------------------------------------

QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SuperMarketManagemantSystem
TEMPLATE = app


SOURCES += main.cpp\
    base_tab.cpp \
    base_user.cpp \
    user_register.cpp \
    user_alter.cpp \
    user_login.cpp \
    window_admin.cpp \
    window_sale.cpp \
    tab_setting.cpp \
    tab_commodity.cpp \
    tab_user.cpp \
    user_add.cpp \
    user_del.cpp \
    tab_customer.cpp

HEADERS  += \
    commonfile.h \
    base_tab.h \
    base_user.h \
    user_register.h \
    user_alter.h \
    user_login.h \
    window_admin.h \
    window_sale.h \
    tab_setting.h \
    tab_commodity.h \
    tab_user.h \
    user_add.h \
    user_del.h \
    tab_customer.h

RESOURCES += \
    resource.qrc
