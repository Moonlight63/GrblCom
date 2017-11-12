#include "GuiLogic_PositionPanel.h"
#include <QObject>
#include <QDebug>
#include <QString>
#include <QTimer>
#include <QTimerEvent>
#include "MasterGuiLogic.h"

GuiLogic_PositionPanel::GuiLogic_PositionPanel(MasterGuiLogic *parent) : QObject(qobject_cast<QObject *>(parent))
{
    this->parent = parent;

    this->parent->eventBroker->events_position->Position_X.on_change().connect(
                [&](float amount) {
                    qDebug() << "POS X -> " << amount;
                });
    this->parent->eventBroker->events_position->Position_Y.on_change().connect(
                [&](float amount) {
                    qDebug() << "POS Y -> " << amount;
                });
}

void GuiLogic_PositionPanel::timerEvent(QTimerEvent *event)
{

    if(holdingYUpTimer == event->timerId()){
        yUp();
    }

    if(holdingYDownTimer == event->timerId()){
        yDown();
    }

    if(holdingXUpTimer == event->timerId()){
        xUp();
    }

    if(holdingXDownTimer == event->timerId()){
        xDown();
    }
}

void GuiLogic_PositionPanel::testComm(const QString &str) {
    qDebug() << str;
}

void GuiLogic_PositionPanel::xUp() {
    this->parent->eventBroker->events_position->Position_XUP.post(1);
}

void GuiLogic_PositionPanel::xDown() {
    this->parent->eventBroker->events_position->Position_XDOWN.post(1);
}

void GuiLogic_PositionPanel::yUp() {
    this->parent->eventBroker->events_position->Position_YUP.post(1);
}

void GuiLogic_PositionPanel::yDown() {
    this->parent->eventBroker->events_position->Position_YDOWN.post(1);
}


void GuiLogic_PositionPanel::yUpHold() {
    holdingYUpTimer = startTimer(50);
}

void GuiLogic_PositionPanel::yUpReleased(){
    if (holdingYUpTimer != 0) {
        killTimer(holdingYUpTimer);
        holdingYUpTimer = 0;
    }
}

void GuiLogic_PositionPanel::xUpHold() {
    holdingXUpTimer = startTimer(50);
}

void GuiLogic_PositionPanel::xUpReleased(){
    if (holdingXUpTimer != 0) {
        killTimer(holdingXUpTimer);
        holdingXUpTimer = 0;
    }
}

void GuiLogic_PositionPanel::yDownHold() {
    holdingYDownTimer = startTimer(50);
}

void GuiLogic_PositionPanel::yDownReleased(){
    if (holdingYDownTimer != 0) {
        killTimer(holdingYDownTimer);
        holdingYDownTimer = 0;
    }
}

void GuiLogic_PositionPanel::xDownHold() {
    holdingXDownTimer = startTimer(50);
}

void GuiLogic_PositionPanel::xDownReleased(){
    if (holdingXDownTimer != 0) {
        killTimer(holdingXDownTimer);
        holdingXDownTimer = 0;
    }
}

