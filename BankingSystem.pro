QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/credentialsreader.cpp \
    controller/reader.cpp \
    controller/transactionreader.cpp \
    main.cpp \
    mainwindow.cpp \
    model/customer.cpp \
    model/date.cpp

HEADERS += \
    controller/credentialsreader.h \
    controller/reader.h \
    controller/transactionreader.h \
    mainwindow.h \
    model/customer.h \
    model/date.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    controller/README.md \
    data/README.md \
    data/users.txt \
    model/README.md
