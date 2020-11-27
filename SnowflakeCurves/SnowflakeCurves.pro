QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    graphics.cpp \
    main.cpp \
    maindialog.cpp \
    mainwindow.cpp \
    matrix.cpp \
    point.cpp \
    rand.cpp \
    snowflake.cpp \
    viewscreen.cpp

HEADERS += \
    flake.h \
    graphics.h \
    maindialog.h \
    mainwindow.h \
    matrix.h \
    misc.h \
    point.h \
    rand.h \
    snowflake.h \
    viewscreen.h

FORMS += \
    maindialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  Resource.qrc
