QT -= gui

TEMPLATE = lib
DEFINES += BASE_LIBRARY
CONFIG += c++17
DEBUG_NAME = Based
RELEASE_NAME = Base

#######################通用配置#########################
# $$PWD .pro或.pri所在的路径
BUILD_DIR = $$PWD/../build
OUTPUT_DIR = $$PWD/../output

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
    Base.cpp

HEADERS += \
    Base_global.h \
    Base.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
