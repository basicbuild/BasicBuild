#include "GuiApplication.h"
#include <QQuickView>

#include "GlobalTools.h"

namespace Internal {
class GuiApplicationPrivate
{
public:
    GuiApplicationPrivate(GuiApplication *ptr);
    ~GuiApplicationPrivate();
    int exec();

    /**
     * @brief 用于初始化业务类
     *
     * @return
     */
    void initClass();

    /**
     * @brief 用于初始化UI
     *
     * @return
     */
    void initUi();

private:
    GuiApplication *q_ptr = nullptr;
    QQuickView* m_pView = new QQuickView();
    QQuickView* m_pSelectView = new QQuickView(); // 选择框，用于选择quick窗口或者widgets窗口

};
} // namespace Internal

using namespace Internal;

GuiApplicationPrivate::GuiApplicationPrivate(GuiApplication *ptr)
    : q_ptr(ptr)
{
    initClass();
    initUi();
    m_pSelectView->show();
}

GuiApplicationPrivate::~GuiApplicationPrivate()
{
    if (m_pView) {
        m_pView->deleteLater();
        m_pView = nullptr;
    }

    if (m_pSelectView) {
        m_pSelectView->deleteLater();
        m_pSelectView = nullptr;
    }
}

int GuiApplicationPrivate::exec()
{
    auto erroCode = QGuiApplication::exec();
    return erroCode;
}

void GuiApplicationPrivate::initClass()
{
    Q_ASSERT(nullptr != m_pView);
    // systemBase 需要先注册
    //m_pView->rootContext()->setContextProperty("globalTools", GLOBALTOOLS);
    //GLOBALTOOLS->aaaa();

}

void GuiApplicationPrivate::initUi()
{
    m_pSelectView->setSource(QUrl(QStringLiteral("qrc:/select.qml")));
    m_pSelectView->setResizeMode(QQuickView::SizeViewToRootObject);
    m_pSelectView->setMinimumSize(QSize(400, 300));
    m_pSelectView->setMaximumSize(QSize(400, 300));


    m_pView->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    m_pView->setResizeMode(QQuickView::SizeRootObjectToView);
    //m_pView->setFlags(Qt::FramelessWindowHint);
    //m_pView->setColor(QColor(0,0,0,0));
}


GuiApplication::GuiApplication(int& argc, char** argv)
    : QGuiApplication(argc, argv)
    , d(new GuiApplicationPrivate(this))
{

}

GuiApplication::~GuiApplication()
{
    if (d) {
        delete d;
        d = nullptr;
    }

}

int GuiApplication::exec()
{
    return d->exec();
}


