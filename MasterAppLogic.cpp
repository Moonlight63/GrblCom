#include "MasterAppLogic.h"
#include <QDebug>
#include <functional>
#include <memory>

MasterAppLogic::MasterAppLogic(MasterEventBroker &ev)
{
    this->eventBroker = &ev;
    this->position = new AppLogic_Position(this);
}
