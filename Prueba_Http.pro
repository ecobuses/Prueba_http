QT += quick network

CONFIG += c++17

SOURCES += \
    hilo.cpp \
    main.cpp \
    servidor.cpp \
    util.cpp

HEADERS += \
    hilo.h \
    servidor.h \
    util.h

QML_IMPORT_PATH += $$PWD/qml

RESOURCES += qml.qrc
