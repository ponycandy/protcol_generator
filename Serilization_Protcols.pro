QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    char_type.cpp \
    complex_type.cpp \
    float_type.cpp \
    int_type.cpp \
    main.cpp \
    mainfilegenerator.cpp \
    meta_struct_list.cpp \
    name_pair.cpp \
    short_type.cpp \
    struct_database.cpp \
    struct_description.cpp \
    struct_editor.cpp \
    tulple_type.cpp \
    vector_type.cpp \
    windowmanager.cpp \
    writer_manage.cpp

HEADERS += \
    char_type.h \
    complex_type.h \
    float_type.h \
    int_type.h \
    mainfilegenerator.h \
    meta_struct_list.h \
    metafile.h \
    name_pair.h \
    short_type.h \
    struct_database.h \
    struct_description.h \
    struct_editor.h \
    structmetatype.h \
    tulple_type.h \
    typelist.h \
    vector_type.h \
    windowmanager.h \
    writer_manage.h \
    f_manager.h

FORMS += \
    struct_editor.ui

