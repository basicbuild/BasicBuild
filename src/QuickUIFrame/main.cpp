#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./src/GuiApplication.h"

#include <QMap>
#include <map>
#include <iostream>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    //QGuiApplication app(argc, argv);

    std::map<std::string, std::string> _map;
    std::cout << "map size:" << _map.size();
    std::string value = _map["key"];
    std::cout << "map size:" << _map.size();


    #pragma omp parallel
    {
        qDebug() << "Hello, World";
    }

    GuiApplication app(argc, argv);
    int ret = app.exec();
    return ret;


    // QQmlApplicationEngine engine;
    // const QUrl url(QStringLiteral("qrc:/main.qml"));
    // QObject::connect(
    //     &engine,
    //     &QQmlApplicationEngine::objectCreated,
    //     &app,
    //     [url](QObject *obj, const QUrl &objUrl) {
    //         if (!obj && url == objUrl)
    //             QCoreApplication::exit(-1);
    //     },
    //     Qt::QueuedConnection);
    // engine.load(url);

    // return app.exec();
}
