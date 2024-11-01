#include "GuiApplication.h"

#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

#ifdef USING_QT6
#include <QStringConverter>
#else
#include <QTextCodec>
#endif

#include "GlobalTools.h"
#include "FeatureModule.h"

#include "WidgetsUIFrame.h"

namespace Internal {
class GuiApplicationPrivate
{
public:
    GuiApplicationPrivate(GuiApplication *ptr);
    ~GuiApplicationPrivate();

    /**
     * @brief view展示及基类exec调用
     *
     * @return
     */
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
    WidgetUIFrame* m_widgetUIFrame = new WidgetUIFrame();
    QQuickView* m_pSelectView = new QQuickView(); // 选择框，用于选择quick窗口或者widgets窗口

};
} // namespace Internal

using namespace Internal;

GuiApplicationPrivate::GuiApplicationPrivate(GuiApplication *ptr)
    : q_ptr(ptr)
{
    //QCoreApplication::setOrganizationName(QStringLiteral("NeteaseYoudao"));
    //QCoreApplication::setOrganizationDomain(QStringLiteral("youdao.com"));
    //QCoreApplication::setApplicationName(QStringLiteral("YoudaoApollo"));

#ifndef USING_QT6
    QTextCodec::setCodecForLocale(QTextCodec::codecForName(QByteArrayLiteral("UTF-8")));
#endif

    // Qt事件循环的默认行为：当最后一个窗口关闭时，应用程序将调用“退出”操作
    // 以下将阻止Qt在最后一个窗口关闭时结束应用程序
    q_ptr->setQuitOnLastWindowClosed(false);

    initClass();
    initUi();
    m_pSelectView->show();
}

GuiApplicationPrivate::~GuiApplicationPrivate()
{
    // 这里不能用 deleteLater, 会崩溃
    if (m_pView) {
        delete m_pView;
        m_pView = nullptr;
    }

    if (m_pSelectView) {
        delete m_pSelectView;
        m_pSelectView = nullptr;
    }

    if (m_widgetUIFrame) {
        delete m_widgetUIFrame;
        m_widgetUIFrame = nullptr;
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
    m_pSelectView->rootContext()->setContextProperty("globalTools", GLOBALTOOLS);

    m_pView->rootContext()->setContextProperty("featureModule", FEATUREMODULE);
}

void GuiApplicationPrivate::initUi()
{
    m_pSelectView->setSource(QUrl(QStringLiteral("qrc:/select.qml")));
    m_pSelectView->setResizeMode(QQuickView::SizeViewToRootObject);
    m_pSelectView->setMinimumSize(QSize(440, 300));
    m_pSelectView->setMaximumSize(QSize(440, 300));
    m_pSelectView->setTitle("BasicBuild - selector");

    m_widgetUIFrame->resize(QSize(640, 480));
    m_widgetUIFrame->setWindowTitle("BasicBuild - WidgetUIFrame");


    m_pView->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    m_pView->setResizeMode(QQuickView::SizeRootObjectToView);
    m_pView->setTitle("BasicBuild - QuickUIFrame");
    //m_pView->setFlags(Qt::FramelessWindowHint);
    //m_pView->setColor(QColor(0,0,0,0));

    QObject::connect(GLOBALTOOLS, &GlobalTools::sigShowQuickUIFrame, [this](){
        //m_pSelectView->hide();
        m_widgetUIFrame->hide();
        m_pView->show();
    });

    QObject::connect(GLOBALTOOLS, &GlobalTools::sigShowWidgetsUIFrame, [this](){
        //m_pSelectView->hide();
        m_pView->hide();
        m_widgetUIFrame->show();
    });

    QObject::connect(m_pSelectView, &QWindow::visibleChanged, [&](bool isVisible){
        if (!isVisible){
            q_ptr->exit();
        }
    });
}


GuiApplication::GuiApplication(int& argc, char** argv)
    : QApplication(argc, argv)
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


