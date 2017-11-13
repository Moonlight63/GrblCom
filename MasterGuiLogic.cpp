#include "MasterGuiLogic.h"

MasterGuiLogic::MasterGuiLogic(MasterEventBroker &ev, QObject *parent) : QObject(parent)
{
    this->eventBroker = &ev;
    this->Gui_PositionPanel = new GuiLogic_PositionPanel(this);
    this->Gui_SerialCom = new GuiLogic_SerialCom(this);
}

