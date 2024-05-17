#ifndef FEATUREMODEL_H
#define FEATUREMODEL_H

#include <QObject>
#include "BaseListModel.h"

class FeatureModel : public BaseListModel
{
    Q_PROPERTY(BaseListModel* featureDetailModel READ featureDetailModel WRITE setFeatureDetailModel NOTIFY featureDetailModelChanged FINAL)
    Q_OBJECT
public:
    explicit FeatureModel();
    ~FeatureModel();

    void initData();

    BaseListModel *featureDetailModel() const;
    void setFeatureDetailModel(BaseListModel *newFeatureDetailModel);


signals:
    void featureDetailModelChanged();

private:
    BaseListModel *m_featureDetailModel = nullptr;
};

#endif // FEATUREMODEL_H
