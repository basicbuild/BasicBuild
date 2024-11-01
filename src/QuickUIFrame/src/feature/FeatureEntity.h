#ifndef FEATUREENTITY_H
#define FEATUREENTITY_H

#include <QObject>

class FeatureEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

public:
    explicit FeatureEntity(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

signals:
    void nameChanged();
private:
    QString m_name;
};

#endif // FEATUREENTITY_H
