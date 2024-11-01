#ifndef FEATUREDETAILENTITY_H
#define FEATUREDETAILENTITY_H

#include <QObject>

class FeatureDetailEntity : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)

public:
    explicit FeatureDetailEntity(QObject *parent = nullptr);

    QString name() const;
    void setName(const QString &newName);

signals:
    void nameChanged();
private:
    QString m_name;
};

#endif // FEATUREDETAILENTITY_H
