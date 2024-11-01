QT += widgets gui core

TEMPLATE = lib
DEFINES += WIDGETSUIFRAME_LIBRARY
CONFIG += c++17
DEBUG_NAME = WidgetsUIFramed
RELEASE_NAME = WidgetsUIFrame

#######################通用配置#########################
# $$PWD .pro或.pri所在的路径
BUILD_DIR = $$PWD/../../build
OUTPUT_DIR = $$PWD/../../output

# @brief 配置临时文件和生成文件位置
win32:CONFIG(debug, debug|release){
    MOC_DIR = $$BUILD_DIR/debug/$$TARGET/build_moc
    UI_DIR = $$BUILD_DIR/debug/$$TARGET/build_uic
    RCC_DIR = $$BUILD_DIR/debug/$$TARGET/build_rcc
    OBJECTS_DIR = $$BUILD_DIR/debug/$$TARGET/build_obj
}
win32:CONFIG(release, debug|release){
    MOC_DIR = $$BUILD_DIR/release/$$TARGET/build_moc
    UI_DIR = $$BUILD_DIR/release/$$TARGET/build_uic
    RCC_DIR = $$BUILD_DIR/release/$$TARGET/build_rcc
    OBJECTS_DIR = $$BUILD_DIR/release/$$TARGET/build_obj
}

# @brief 配置目标文件生成位置
# DESTDIR 目标文件路径
win32:CONFIG(debug, debug|release){
    DESTDIR = $$OUTPUT_DIR/debug
}
win32:CONFIG(release, debug|release){
    DESTDIR = $$OUTPUT_DIR/release
}

# @brief 指定生成的应用程序名
win32:CONFIG(debug, debug|release){
    TARGET  = $$DEBUG_NAME
}
win32:CONFIG(release, debug|release){
    TARGET  = $$RELEASE_NAME
}

#######################个性配置#########################

#####################################################
SOURCES += \
    WidgetsUIFrame.cpp

HEADERS += \
    WidgetsUIFrame_global.h \
    WidgetsUIFrame.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
