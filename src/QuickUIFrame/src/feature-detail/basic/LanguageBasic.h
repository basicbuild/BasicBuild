#ifndef LANGUAGEBASIC_H
#define LANGUAGEBASIC_H
#include <QObject>
#include <memory>
#include "LanguageBasic/STLBasic.h"
#include "LanguageBasic/TypeConversionBasic.h"

namespace Internal {
class LanguageBasicPrivate;
}

class LanguageBasic : public QObject
{
    Q_OBJECT
public:
    explicit LanguageBasic(QObject* parent = nullptr);

public: // 标准模板库
    std::shared_ptr<STLBasic> stlBasic();

public: // C++类型转换
    std::shared_ptr<TypeConversionBasic> typeConversionBasic();

signals:

private:
    Internal::LanguageBasicPrivate* d = nullptr;
};

#endif // LANGUAGEBASIC_H
