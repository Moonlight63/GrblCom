#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "MasterEventBroker.h"
#include "MasterGuiLogic.h"
#include "MasterAppLogic.h"

#include "SubLogic_Positional/GuiLogic_PositionPanel.h"
#include "SerialCom/GuiLogic_SerialCom.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    MasterEventBroker *MainEventBroker = new MasterEventBroker();
    MasterAppLogic *MainAppLogic = new MasterAppLogic(*MainEventBroker);
    MasterGuiLogic *MainGuiLogic = new MasterGuiLogic(*MainEventBroker);

    //qmlRegisterUncreatableType<GuiLogic_PositionPanel>("GrblCom", 1, 0, "GuiLogic_PositionPanel", "");
    //qmlRegisterUncreatableType<GuiLogic_SerialCom>("GrblCom", 1, 0, "GuiLogic_SerialCom", "");

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();

    context->setContextProperty("MasterGuiLogic", MainGuiLogic);

    engine.load(QUrl(QLatin1String("qrc:/QmlGui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
