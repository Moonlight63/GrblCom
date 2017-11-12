#include "MasterEventBroker.h"

MasterEventBroker::MasterEventBroker()
{
    this->events_position = new Events_Position(this);
}
