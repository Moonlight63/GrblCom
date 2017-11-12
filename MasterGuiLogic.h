#ifndef MASTERGUILOGIC_H
#define MASTERGUILOGIC_H

#include <QObject>
#include <QTimer>

#include "MasterEventBroker.h"
#include "SubLogic_Positional/GuiLogic_PositionPanel.h"

class MasterGuiLogic : public QObject
{
    Q_OBJECT
    Q_PROPERTY(GuiLogic_PositionPanel* positionPanel READ positionPanel)
public:
    MasterEventBroker *eventBroker;



    explicit MasterGuiLogic(MasterEventBroker &ev, QObject *parent = nullptr);

    GuiLogic_PositionPanel* positionPanel() const {
        return Gui_PositionPanel;
    }

private:

    GuiLogic_PositionPanel *Gui_PositionPanel;

signals:

public slots:

protected:

};

#endif // MASTERGUILOGIC_H
