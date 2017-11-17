#include "GuiLogic_SerialCom.h"

#include "MasterGuiLogic.h"

#include <QSerialPort>
#include <QSerialPortInfo>

GuiLogic_SerialCom::GuiLogic_SerialCom(MasterGuiLogic *parent) : QObject(qobject_cast<QObject *>(parent))
{
    this->parent = parent;


    QList<QSerialPortInfo> allPorts = QSerialPortInfo::availablePorts();

    for (int i = 0; i < allPorts.size(); ++i) {
        this->_portNames.append(allPorts.at(i).portName());
        this->portsMap[allPorts.at(i).portName()] = allPorts.at(i);
    }

    for (int i = 0; i < _portNames.size(); ++i) {
        qDebug() << "COM Port Name: " << _portNames.at(i);
    }

    emit portNamesChanged(_portNames);

}

void GuiLogic_SerialCom::connectToPort(const QString &portName) {
    //TODO: Connect To Port Logic Here;

    //Set Connected
    this->_connectedToPort = true;
    emit connectedToPortChanged(this->_connectedToPort);

    qDebug() << "Connected to port: " << portName << _connectedToPort;
}

void GuiLogic_SerialCom::disconnectFromPort(const QString &portName) {
    //TODO: DisConnect To Port Logic Here;

    //Set DisConnected
    this->_connectedToPort = false;
    emit connectedToPortChanged(this->_connectedToPort);

    qDebug() << "Disconnected from port: " << portName << _connectedToPort;
}
