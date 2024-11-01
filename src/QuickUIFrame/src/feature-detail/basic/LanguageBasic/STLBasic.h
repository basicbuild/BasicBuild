#ifndef STLBASIC_H
#define STLBASIC_H

#include <QObject>

class STLBasic : public QObject
{
    Q_OBJECT
public:
    explicit STLBasic(QObject *parent = nullptr);

signals:
};

#endif // STLBASIC_H
