#-------------------------------------------------
#
# Project created by QtCreator 2017-04-08T00:09:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    snake.cpp \
    gamefield.cpp \
    drawfieldmanager.cpp \
    wgt_pages/page_menu.cpp \
    wgt_pages/page_field.cpp \
    wgt_pages/page_configuration.cpp \
    wgt_pages/page_highscores.cpp \
    wgt_pages/page_score.cpp \
    wgt_pages/page_settings.cpp \
    wgt_pages/page_welcomescreen.cpp \
    wgt_pages/dialog_property.cpp

HEADERS  += mainwindow.h \
    snake.h \
    gamefield.h \
    drawfieldmanager.h \
    wgt_pages/page_menu.h \
    wgt_pages/page_field.h \
    wgt_pages/page_configuration.h \
    wgt_pages/page_highscores.h \
    wgt_pages/page_score.h \
    wgt_pages/page_settings.h \
    wgt_pages/page_welcomescreen.h \
    wgt_pages/dialog_property.h

FORMS    += mainwindow.ui \
    wgt_pages/page_menu.ui \
    wgt_pages/page_field.ui \
    wgt_pages/page_configuration.ui \
    wgt_pages/page_highscores.ui \
    wgt_pages/page_score.ui \
    wgt_pages/page_settings.ui \
    wgt_pages/page_welcomescreen.ui \
    wgt_pages/dialog_property.ui


