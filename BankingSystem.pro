QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/credentialsreader.cpp \
    controller/decrypter.cpp \
    controller/encrypter.cpp \
    controller/loginhandler.cpp \
    controller/registerhandler.cpp \
    controller/transactionhandler.cpp \
    controller/transactionreader.cpp \
    main.cpp \
    model/csvmodel.cpp \
    model/customer.cpp \
    model/date.cpp \
    model/transaction.cpp \
    utils.cpp \
    view/deposit.cpp \
    view/history.cpp \
    view/leaderboard.cpp \
    view/login.cpp \
    view/menu.cpp \
    view/registeracc.cpp \
    view/title.cpp \
    view/transfer.cpp \
    view/withdraw.cpp

HEADERS += \
    controller/credentialsreader.h \
    controller/decrypter.h \
    controller/encrypter.h \
    controller/loginhandler.h \
    controller/registerhandler.h \
    controller/transactionhandler.h \
    controller/transactionreader.h \
    model/csvmodel.h \
    model/customer.h \
    model/date.h \
    model/transaction.h \
    utils.h \
    view/deposit.h \
    view/history.h \
    view/leaderboard.h \
    view/login.h \
    view/menu.h \
    view/registeracc.h \
    view/title.h \
    view/transfer.h \
    view/withdraw.h

FORMS += \
    view/deposit.ui \
    view/history.ui \
    view/leaderboard.ui \
    view/login.ui \
    view/menu.ui \
    view/registeracc.ui \
    view/title.ui \
    view/transfer.ui \
    view/withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    controller/README.md \
    data/README.md \
    data/customers.csv \
    data/users.txt \
    model/README.md
