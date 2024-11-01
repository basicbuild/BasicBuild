QT += quick widgets core gui  #core5compat

CONFIG += c++17
DEBUG_NAME = QuickUIFramed
RELEASE_NAME = QuickUIFrame

# Conditionally add definitions based on Qt version
greaterThan(QT_MAJOR_VERSION, 5):DEFINES += USING_QT6 # Qt版本大于5，则定义 USING_QT6

#######################通用配置#########################
# $$PWD .pro或.pri所在的路径
BUILD_DIR = $$PWD/../../build                      # 临时文件生成的根目录
OUTPUT_DIR = $$PWD/../../output                    # 目标文件生成的根目录

# @brief 配置临时文件和生成文件位置
win32:CONFIG(debug, debug|release){
    MOC_DIR = $$BUILD_DIR/debug/$$TARGET/build_moc       # 指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
    UI_DIR = $$BUILD_DIR/debug/$$TARGET/build_uic        # 指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
    RCC_DIR = $$BUILD_DIR/debug/$$TARGET/build_rcc       # 指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
    OBJECTS_DIR = $$BUILD_DIR/debug/$$TARGET/build_obj   # 指定目标文件(obj)的存放目录
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
# @brief 库的引用
win32:CONFIG(debug, debug|release){
    LIBS += -L$$OUTPUT_DIR/debug/ -lBased
    LIBS += -L$$OUTPUT_DIR/debug/ -lWidgetsUIFramed
}
win32:CONFIG(release, debug|release){
    LIBS += -L$$OUTPUT_DIR/release/ -lBase
    LIBS += -L$$OUTPUT_DIR/release/ -lWidgetsUIFrame
}

# @brief 包含路径
INCLUDEPATH += $$PWD/../Base \
               $$PWD/../Base/utils \
               $$PWD/../Base/utils/common \
               $$PWD/../WidgetsUIFrame \

INCLUDEPATH += .\
               ./src/common \
               ./src/feature \

# @brief 依赖路径
DEPENDPATH += $$PWD/../Base \                           # DEPENDPATH 是指定那些文件在修改后需要重新运行 qmake 的路径
              $$PWD/../WidgetsUIFrame

#####################################################

HEADERS += \
    src/common/Common.h \
    src/feature-detail/basic/LanguageBasic.h \
    src/feature-detail/basic/LanguageBasic/STLBasic.h \
    src/feature-detail/basic/LanguageBasic/TypeConversionBasic.h \
    src/feature/FeatureDetailEntity.h \
    src/feature/FeatureEntity.h \
    src/feature/FeatureModel.h \
    src/GlobalTools.h \
    src/GuiApplication.h \
    src/common/Singleton.h \
    src/feature/FeatureModule.h

SOURCES += \
        main.cpp \
        src/feature-detail/basic/LanguageBasic.cpp \
        src/feature-detail/basic/LanguageBasic/STLBasic.cpp \
        src/feature-detail/basic/LanguageBasic/TypeConversionBasic.cpp \
        src/feature/FeatureDetailEntity.cpp \
        src/feature/FeatureEntity.cpp \
        src/feature/FeatureModel.cpp \
        src/GlobalTools.cpp \
        src/GuiApplication.cpp \
        src/feature/FeatureModule.cpp

RESOURCES += qml.qrc \
    resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=


