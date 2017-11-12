#include "AppLogic_Position.h"
#include "MasterAppLogic.h"

AppLogic_Position::AppLogic_Position(MasterAppLogic *parent)
{
    this->parent = parent;

    this->parent->eventBroker->events_position->Position_XUP.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: XDOWN -> " << amount;
        this->parent->eventBroker->events_position->Position_X.set(this->parent->eventBroker->events_position->Position_X.get() - amount);
        }
    );
    this->parent->eventBroker->events_position->Position_XDOWN.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: XDOWN -> " << amount;
        this->parent->eventBroker->events_position->Position_X.set(this->parent->eventBroker->events_position->Position_X.get() - amount);
        }
    );
    this->parent->eventBroker->events_position->Position_YUP.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: YUP -> " << amount;
        this->parent->eventBroker->events_position->Position_Y.set(this->parent->eventBroker->events_position->Position_Y.get() + amount);
        }
    );
    this->parent->eventBroker->events_position->Position_YDOWN.connect(
        [&](float amount) {
            //qDebug() << "Got Signal: YDOWN -> " << amount;
        this->parent->eventBroker->events_position->Position_Y.set(this->parent->eventBroker->events_position->Position_Y.get() - amount);
        }
    );
}
