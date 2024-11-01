#ifndef WIDGETSUIFRAME_H
#define WIDGETSUIFRAME_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include "WidgetsUIFrame_global.h"

class WIDGETSUIFRAME_EXPORT WidgetUIFrame : public QMainWindow
{
public:
    WidgetUIFrame(QWidget* parent = nullptr);
};

#endif // WIDGETSUIFRAME_H
