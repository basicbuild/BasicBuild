#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H

#include <QGuiApplication>
#include <QApplication>

namespace Internal {
class GuiApplicationPrivate;
}

class GuiApplication : public QApplication
{
    Q_OBJECT
public:
    GuiApplication(int& argc, char** argv);
    ~GuiApplication();
    int exec();

private:
    Internal::GuiApplicationPrivate *d = nullptr;

};

#endif // GUIAPPLICATION_H
