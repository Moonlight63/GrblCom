#ifndef MASTERGUILOGIC_H
#define MASTERGUILOGIC_H

#include <QObject>
#include <QTimer>

#include "MasterEventBroker.h"
#include "SubLogic_Positional/GuiLogic_PositionPanel.h"
#include "SerialCom/GuiLogic_SerialCom.h"

class MasterGuiLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(GuiLogic_PositionPanel* positionPanel READ positionPanel CONSTANT)
    Q_PROPERTY(GuiLogic_SerialCom* serialCom READ serialCom CONSTANT)
public:
    MasterEventBroker *eventBroker;



    explicit MasterGuiLogic(MasterEventBroker &ev, QObject *parent = nullptr);

    GuiLogic_PositionPanel* positionPanel() const {
        return Gui_PositionPanel;
    }

    GuiLogic_SerialCom* serialCom() const {
        return Gui_SerialCom;
    }

private:

    GuiLogic_PositionPanel *Gui_PositionPanel;
    GuiLogic_SerialCom *Gui_SerialCom;

signals:

public slots:

protected:

};

#endif // MASTERGUILOGIC_H
