#ifndef GLOBALTOOLS_H
#define GLOBALTOOLS_H

#include <QObject>
#include "Singleton.h"

class GlobalTools : public QObject
{
    Q_OBJECT
public:
    explicit GlobalTools(QObject *parent = nullptr);
    void aaaa() {}

    Q_INVOKABLE void showQuickUIFrame() {
        emit sigShowQuickUIFrame();
    }

    Q_INVOKABLE void showWidgetsUIFrame() {
        emit sigShowWidgetsUIFrame();
    }

signals:
    void sigShowQuickUIFrame();    // 显示Quick ui frame
    void sigShowWidgetsUIFrame();  // 显示Widgets ui frame
};

#define GLOBALTOOLS QuSingleton<GlobalTools>::instance()

#endif // GLOBALTOOLS_H
