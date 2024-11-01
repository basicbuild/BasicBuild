#ifndef FEATUREMODEL_H
#define FEATUREMODEL_H

#include <QObject>
#include "BaseListModel.h"

class FeatureModel : public BaseListModel
{
    Q_PROPERTY(BaseListModel* featureDetailModel READ featureDetailModel WRITE setFeatureDetailModel NOTIFY featureDetailModelChanged FINAL)
    Q_OBJECT
public:
    explicit FeatureModel(QObject* parent = nullptr);
    ~FeatureModel();

    void switchFeature(const QString& featureName);

    BaseListModel *featureDetailModel() const;
    void setFeatureDetailModel(BaseListModel *newFeatureDetailModel);

private:
    void initData();

signals:
    void featureDetailModelChanged();

private:
    BaseListModel *m_featureDetailModel = nullptr;

    std::map<QString, std::vector<QString>> m_mapFeatureDetail;
};

#endif // FEATUREMODEL_H
