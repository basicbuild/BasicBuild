﻿#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMap>
#include <map>
#include <iostream>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    std::map<std::string, std::string> _map;
    std::cout << "map size:" << _map.size();
    std::string value = _map["key"];
    std::cout << "map size:" << _map.size();

    //   能切换， 和选择是qml还是widget显示
    "QuickUIFrame";
    "WidgetsUIFrame";


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
