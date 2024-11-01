#ifndef COMMON_H
#define COMMON_H
#include <QObject>

namespace FeatureDefine {
static const QString FEATURE_UI = QStringLiteral("UI");           // UI
static const QString FEATURE_MODULE = QStringLiteral("模块");     // 功能模块
static const QString FEATURE_BASIC = QStringLiteral("基础");      // 基础

// ui
static const QString FEATURE_DETAIL_UI_BUTTON = QStringLiteral("Button");
static const QString FEATURE_DETAIL_UI_LABEL = QStringLiteral("Label");
static const QString FEATURE_DETAIL_UI_IMAGE = QStringLiteral("Image");

// module
static const QString FEATURE_DETAIL_MODULE_DATABASE = QStringLiteral("数据库");
static const QString FEATURE_DETAIL_MODULE_HTTP = QStringLiteral("网络");
static const QString FEATURE_DETAIL_MODULE_DOWNLOAD = QStringLiteral("下载");
static const QString FEATURE_DETAIL_MODULE_OBSERVER = QStringLiteral("观察者");
static const QString FEATURE_DETAIL_MODULE_WEBSOCKET = QStringLiteral("Websocket");

// basic
static const QString FEATURE_DETAIL_BASIC_1 = QStringLiteral("language");
static const QString FEATURE_DETAIL_BASIC_2 = QStringLiteral("exception");
static const QString FEATURE_DETAIL_BASIC_3 = QStringLiteral("n1");


} // namespace FeatureDefine

#endif // COMMON_H
