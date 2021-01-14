#-------------------------------------------------
#
# Project created by QtCreator 2019-06-08T18:34:12
#
#-------------------------------------------------

QT       += core gui widgets multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = polymadness
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        audio.cpp \
        game.cpp \
        gameshop.cpp \
        generator.cpp \
        healthbar.cpp \
        klaxlife.cpp \
        languagesre.cpp \
        main.cpp \
        menu.cpp \
        money.cpp \
        playmode.cpp \
        polyar_copy.cpp \
        polyn69.cpp \
        qaesencryption.cpp \
        rett.cpp \
        save.cpp \
        scale.cpp \
        score.cpp \
        settings.cpp \
        sound.cpp \
        statistics.cpp \
        stats.cpp \
        widget.cpp \
        window.cpp

HEADERS += \
    audio.h \
    game.h \
    gameshop.h \
    generator.h \
    healthbar.h \
    klaxlife.h \
    languagesre.h \
    menu.h \
    money.h \
    playmode.h \
    polyar_copy.h \
    polyn69.h \
    qaesencryption.h \
    rett.h \
    save.h \
    scale.h \
    score.h \
    settings.h \
    sound.h \
    statistics.h \
    stats.h \
    widget.h \
    window.h

FORMS +=

CONFIG += mobility
MOBILITY = 


RESOURCES += \
    res.qrc

DISTFILES += \
    audio/sounds48/boom.wav \
    audio/sounds48/button.wav \
    audio/sounds48/click.wav \
    audio/sounds48/miss.wav \
    icons/classic_new.png \
    icons/shopHP.png

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/res/values/libs.xml
}
