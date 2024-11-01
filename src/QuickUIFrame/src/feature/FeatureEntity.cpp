#include "FeatureEntity.h"

FeatureEntity::FeatureEntity(QObject *parent)
    : QObject{parent}
{}

QString FeatureEntity::name() const
{
    return m_name;
}

void FeatureEntity::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
