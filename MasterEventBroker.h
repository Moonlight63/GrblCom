#ifndef MASTEREVENTBROKER_H
#define MASTEREVENTBROKER_H

#include "SignalsLib/signal.h"
#include "SignalsLib/property.h"

#include "SubLogic_Positional/Events_Position.h"

class MasterEventBroker
{
public:
    MasterEventBroker();

    Events_Position *events_position;

};

#endif // MASTEREVENTBROKER_H
