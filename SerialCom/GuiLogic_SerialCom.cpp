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

    this->port = new QSerialPort(this->portsMap.at(portName));

    if (this->port->isOpen()) {
        //Handle an error;
    } else {
        if (this->port->open(QSerialPort::ReadWrite)) {
            this->port->setBaudRate(QSerialPort::Baud115200);
            this->port->setFlowControl(QSerialPort::NoFlowControl);
            this->port->setDataBits(QSerialPort::Data8);
            this->port->setParity(QSerialPort::NoParity);
            this->port->setStopBits(QSerialPort::OneStop);

            connect(this->port, &QSerialPort::readyRead, this, &GuiLogic_SerialCom::readData);

            //Set Connected
            this->_connectedToPort = true;
            emit connectedToPortChanged(this->_connectedToPort);

            qDebug() << "Connected to port: " << portName << _connectedToPort;
        } else {
            //handle another error;
        }
    }

}

void GuiLogic_SerialCom::disconnectFromPort() {
    //TODO: DisConnect To Port Logic Here;

    if (this->port->isOpen()) {
        this->port->close();
        delete this->port;

        //Set DisConnected
        this->_connectedToPort = false;
        emit connectedToPortChanged(this->_connectedToPort);

    } else {
        //handle an error
    }

}

void GuiLogic_SerialCom::writeData(const QByteArray &data) {


    if(this->port->isOpen() && this->connectedToPort()){

        if (this->port->write(QByteArray(data).append("\r\n"))) {
            emit serialOutput(QByteArray("Writing to device: ").append(data).append("\r\n"));
        } else {
            //handle error;
        }

    } else {
        //handle error;
    }

}

void GuiLogic_SerialCom::readData() {

    if(this->port->isOpen() && this->connectedToPort()){
        QByteArray data = this->port->readAll();
        emit serialOutput(data);
    } else {
        //handle error;
    }

}
