#-------------------------------------------------
#
# Project created 2019-03-06T00:12:01
#
#-------------------------------------------------
TEMPLATE            = app
TARGET              = i18n
PRECOMPILED_HEADER  = i18n_pch.h

I18N_PATH           = $$PWD/i18n/
CATCH_PATH          = $$PWD/catch2/
OUTPUT_PATH         = $$PWD/../../bin/qmake

CONFIG             += c++1z console precompile_header
QMAKE_CXXFLAGS     += -Wall
INCLUDEPATH        += .

DEFINES            += QT_DEPRECATED_WARNINGS \
                      QT_DISABLE_DEPRECATED_BEFORE=0x060000
QT                 -= gui
CONFIG             -= app_bundle

QMAKE_CXXFLAGS     += -DQT_NO_CAST_TO_ASCII        \
                      -DQT_NO_CAST_FROM_BYTEARRAY  \
                      -DQT_USE_QSTRINGBUILDER      \
                      -DD_SCL_SECURE_NO_WARNINGS
SOURCES += \
    main.cpp \
    $$I18N_PATH/classes/finder.cpp \
    $$I18N_PATH/classes/worker.cpp \
    $$I18N_PATH/classes/app.cpp    \
    $$I18N_PATH/classes/list.cpp

HEADERS += \
    $$I18N_PATH/classes/finder.h \
    $$I18N_PATH/classes/worker.h \
    $$I18N_PATH/classes/app.h    \
    $$I18N_PATH/classes/list.h
