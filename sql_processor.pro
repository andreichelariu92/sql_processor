TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/main.c \
    src/sql_processor.c \
    src/simple_string.c \
    src/reference_counter.c

HEADERS += \
    src/sql_processor.h \
    src/simple_string.h \
    src/reference_counter.h

LIBS += -lsqlite3
