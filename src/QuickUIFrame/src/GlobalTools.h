#ifndef GLOBALTOOLS_H
#define GLOBALTOOLS_H

#include <QObject>
#include "utils/common/Singleton.h"

class GlobalTools : public QObject
{
    Q_OBJECT
public:
    explicit GlobalTools(QObject *parent = nullptr);
    void aaaa() {}

signals:
};

#define GLOBALTOOLS Singleton<GlobalTools>::instance()

#endif // GLOBALTOOLS_H
