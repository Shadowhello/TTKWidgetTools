#include "ttkansplashscreenproperty.h"
#include "ttkansplashscreen.h"

#include <QToolButton>

TTKAnSplashScreenProperty::TTKAnSplashScreenProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    m_item = new QToolButton(this);
    connect(m_item, SIGNAL(clicked()), SLOT(showWidget()));
    //
    m_label = nullptr;
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, MStatic_cast(TTKAnSplashScreen*, m_label)->getClassName());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    objectItem->addSubProperty(activityItem);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    m_browser->addProperty(objectItem);
}

TTKAnSplashScreenProperty::~TTKAnSplashScreenProperty()
{

}

void TTKAnSplashScreenProperty::showWidget()
{
    delete m_label;
    TTKAnSplashScreen *widget = new TTKAnSplashScreen(this);
    m_label = widget;

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    mainWidget->resize(300, 300);

    widget->setWidget(mainWidget);
    widget->setLoadTime(5);
    widget->start();

}
