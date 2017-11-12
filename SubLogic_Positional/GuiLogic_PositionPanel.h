#ifndef GUILOGIC_POSITIONPANEL_H
#define GUILOGIC_POSITIONPANEL_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QTimerEvent>

//Forward Declare our parent
class MasterGuiLogic;

class GuiLogic_PositionPanel : public QObject
{
    Q_OBJECT
public:

    MasterGuiLogic *parent;
    explicit GuiLogic_PositionPanel(MasterGuiLogic *parent = nullptr);

private:

    QTimer *appClock = new QTimer(this);
    void loop ();

    int holdingXUpTimer = 0;
    int holdingXDownTimer = 0;
    int holdingYUpTimer = 0;
    int holdingYDownTimer = 0;

signals:

public slots:

    void testComm(const QString &str);

    void xUp ();
    void xDown ();
    void yUp ();
    void yDown ();

    void yUpHold();
    void yUpReleased();
    void yDownHold();
    void yDownReleased();
    void xUpHold();
    void xUpReleased();
    void xDownHold();
    void xDownReleased();

protected:
    void timerEvent(QTimerEvent *event);

};

#endif // GUILOGIC_POSITIONPANEL_H
