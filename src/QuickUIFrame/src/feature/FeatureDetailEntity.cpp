#include "FeatureDetailEntity.h"

FeatureDetailEntity::FeatureDetailEntity(QObject *parent)
    : QObject{parent}
{}

QString FeatureDetailEntity::name() const
{
    return m_name;
}

void FeatureDetailEntity::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}
