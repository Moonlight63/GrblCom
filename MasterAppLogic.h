#ifndef MASTERAPPLOGIC_H
#define MASTERAPPLOGIC_H

#include "MasterEventBroker.h"

#include "SubLogic_Positional/AppLogic_Position.h"

class MasterAppLogic
{
public:
    MasterEventBroker *eventBroker;

    MasterAppLogic(MasterEventBroker &ev);

    AppLogic_Position *position;
};

#endif // MASTERAPPLOGIC_H
