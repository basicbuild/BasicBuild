#ifndef GUIAPPLICATION_H
#define GUIAPPLICATION_H

#include <QGuiApplication>

namespace Internal {
class GuiApplicationPrivate;
}

class GuiApplication : public QGuiApplication
{
public:
    GuiApplication(int& argc, char** argv);
    ~GuiApplication();
    int exec();

private:
    Internal::GuiApplicationPrivate *d = nullptr;

};

#endif // GUIAPPLICATION_H
