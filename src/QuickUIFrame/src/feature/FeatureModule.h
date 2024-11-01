#ifndef FEATUREMODULE_H
#define FEATUREMODULE_H

#include <QObject>
#include "FeatureModel.h"
#include "./common/Singleton.h"

class FeatureModule : public QObject
{
    Q_PROPERTY(FeatureModel* featureDataModel READ featureDataModel WRITE setFeatureDataModel NOTIFY featureDataModelChanged FINAL)

    Q_OBJECT
public:
    explicit FeatureModule(QObject *parent = nullptr);
    ~FeatureModule();

    Q_INVOKABLE void switchFeature(const QString& featureName);

    FeatureModel *featureDataModel() const;
    void setFeatureDataModel(FeatureModel *newFeatureDataModel);

signals:
    void featureDataModelChanged();

private:
    FeatureModel *m_featureDataModel = nullptr;
};

#define FEATUREMODULE QuSingleton<FeatureModule>::instance()
#endif // FEATUREMODULE_H
