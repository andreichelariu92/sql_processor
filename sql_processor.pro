TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.c \
    src/sql_processor.c

HEADERS += \
    src/sql_processor.h

LIBS += -lsqlite3
