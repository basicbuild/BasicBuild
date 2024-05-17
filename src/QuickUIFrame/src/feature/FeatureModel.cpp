#include "FeatureModel.h"

FeatureModel::FeatureModel() {}

FeatureModel::~FeatureModel()
{

}

void FeatureModel::initData()
{

}

BaseListModel *FeatureModel::featureDetailModel() const
{
    return m_featureDetailModel;
}

void FeatureModel::setFeatureDetailModel(BaseListModel *newFeatureDetailModel)
{
    if (m_featureDetailModel == newFeatureDetailModel)
        return;
    m_featureDetailModel = newFeatureDetailModel;
    emit featureDetailModelChanged();
}
