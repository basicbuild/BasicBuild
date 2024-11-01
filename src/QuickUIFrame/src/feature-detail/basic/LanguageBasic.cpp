#include "LanguageBasic.h"

namespace Internal {
class LanguageBasicPrivate
{
public:
    LanguageBasicPrivate(LanguageBasic* ptr);
    ~LanguageBasicPrivate();

public:
    friend class LanguageBasic;

public: // 标准模板库
    std::shared_ptr<STLBasic> stlBasic();

public: // C++类型转换
    std::shared_ptr<TypeConversionBasic> typeConversionBasic();

private:
    LanguageBasic* m_ptr = nullptr;

    std::shared_ptr<STLBasic> m_stlBasic = nullptr;
    std::shared_ptr<TypeConversionBasic> m_typeConversionBasic = nullptr;

};
} // namespace Internal
using namespace Internal;

LanguageBasicPrivate::LanguageBasicPrivate(LanguageBasic* ptr)
    : m_ptr (ptr)
{
    m_stlBasic = std::make_shared<STLBasic>();
    m_typeConversionBasic = std::make_shared<TypeConversionBasic>();
}

LanguageBasicPrivate::~LanguageBasicPrivate()
{

}

std::shared_ptr<STLBasic> LanguageBasicPrivate::stlBasic()
{
    return m_stlBasic;
}

LanguageBasic::LanguageBasic(QObject *parent)
    : QObject{parent}
    , d (new LanguageBasicPrivate(this))
{}

std::shared_ptr<STLBasic> LanguageBasic::stlBasic()
{
    return d->stlBasic();
}

