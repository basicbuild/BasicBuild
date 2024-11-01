#include "FeatureModel.h"
#include "Common.h"
#include "FeatureEntity.h"
#include "FeatureDetailEntity.h"

FeatureModel::FeatureModel(QObject* parent)
    : BaseListModel(parent)
{
    initData();
}

FeatureModel::~FeatureModel()
{
    this->clearData();
    m_featureDetailModel->clearData();
}

void FeatureModel::switchFeature(const QString& featureName)
{
    std::map<QString, std::vector<QString>>::iterator iter = m_mapFeatureDetail.find(featureName);
    if (iter != m_mapFeatureDetail.end()) {
        m_featureDetailModel->clearData();
        std::vector<QString> _vec = iter->second;

        foreach (const auto& item, _vec) {
            FeatureDetailEntity* entityItem = new FeatureDetailEntity;
            entityItem->setName(item);
            m_featureDetailModel->addItem(entityItem);
        }
        emit m_featureDetailModel->itemCountChanged();
    }
}

void FeatureModel::initData()
{
    m_featureDetailModel = new BaseListModel();

    /// 功能 vector
    std::vector<QString> vecFeature;
    vecFeature.push_back(FeatureDefine::FEATURE_UI);
    vecFeature.push_back(FeatureDefine::FEATURE_MODULE);
    vecFeature.push_back(FeatureDefine::FEATURE_BASIC);

    /// 功能详情 map
    // ui
    std::vector<QString> vecFeatureUI;
    vecFeatureUI.push_back(FeatureDefine::FEATURE_DETAIL_UI_BUTTON);
    vecFeatureUI.push_back(FeatureDefine::FEATURE_DETAIL_UI_LABEL);
    vecFeatureUI.push_back(FeatureDefine::FEATURE_DETAIL_UI_IMAGE);

    // module
    std::vector<QString> vecFeatureModule;
    vecFeatureModule.push_back(FeatureDefine::FEATURE_DETAIL_MODULE_DATABASE);
    vecFeatureModule.push_back(FeatureDefine::FEATURE_DETAIL_MODULE_HTTP);
    vecFeatureModule.push_back(FeatureDefine::FEATURE_DETAIL_MODULE_DOWNLOAD);
    vecFeatureModule.push_back(FeatureDefine::FEATURE_DETAIL_MODULE_OBSERVER);
    vecFeatureModule.push_back(FeatureDefine::FEATURE_DETAIL_MODULE_WEBSOCKET);

    // basic
    std::vector<QString> vecFeatureBasic;
    vecFeatureBasic.push_back(FeatureDefine::FEATURE_DETAIL_BASIC_1);
    vecFeatureBasic.push_back(FeatureDefine::FEATURE_DETAIL_BASIC_2);
    vecFeatureBasic.push_back(FeatureDefine::FEATURE_DETAIL_BASIC_3);


    m_mapFeatureDetail.insert(std::pair(FeatureDefine::FEATURE_UI, vecFeatureUI));
    m_mapFeatureDetail.insert(std::pair(FeatureDefine::FEATURE_MODULE, vecFeatureModule));
    m_mapFeatureDetail.insert(std::pair(FeatureDefine::FEATURE_BASIC, vecFeatureBasic));

    foreach (const auto& item, vecFeature) {
        FeatureEntity* entityItem = new FeatureEntity;
        entityItem->setName(item);
        addItem(entityItem);
    }

    switchFeature(FeatureDefine::FEATURE_BASIC);
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
