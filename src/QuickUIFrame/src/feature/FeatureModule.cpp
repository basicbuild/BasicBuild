#include "FeatureModule.h"

FeatureModule::FeatureModule(QObject *parent)
    : QObject{parent}
{
    m_featureDataModel = new FeatureModel();
}

FeatureModule::~FeatureModule()
{
    if (m_featureDataModel) {
        delete m_featureDataModel;
        m_featureDataModel = nullptr;
    }
}

void FeatureModule::switchFeature(const QString &featureName)
{
    m_featureDataModel->switchFeature(featureName);
}

FeatureModel *FeatureModule::featureDataModel() const
{
    return m_featureDataModel;
}

void FeatureModule::setFeatureDataModel(FeatureModel *newFeatureDataModel)
{
    if (m_featureDataModel == newFeatureDataModel)
        return;
    m_featureDataModel = newFeatureDataModel;
    emit featureDataModelChanged();
}
