#ifndef EVENTS_POSITION_H
#define EVENTS_POSITION_H

#include "..\SignalsLib\signal.h"
#include "..\SignalsLib\property.h"

//Forward Declare our parent
class MasterEventBroker;


class Events_Position
{
public:
    MasterEventBroker *parent;
    Events_Position(MasterEventBroker *parent);

    Property<float> Position_X = 0;
    Property<float> Position_Y = 0;

    Signal<float> Position_YUP;
    Signal<float> Position_YDOWN;
    Signal<float> Position_XUP;
    Signal<float> Position_XDOWN;
};

#endif // EVENTS_POSITION_H
