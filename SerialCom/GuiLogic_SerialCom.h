#ifndef GUILOGIC_SERIALCOM_H
#define GUILOGIC_SERIALCOM_H

#include <QObject>
#include <QDebug>
#include <map>
#include <QList>
#include <QString>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>

//Forward Declare our parent
class MasterGuiLogic;

class GuiLogic_SerialCom : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList portNames READ portNames NOTIFY portNamesChanged)
    Q_PROPERTY(bool connectedToPort READ connectedToPort NOTIFY connectedToPortChanged)
public:

    MasterGuiLogic *parent;

    std::map<QString, QSerialPortInfo> portsMap;

    QSerialPort *port;


    explicit GuiLogic_SerialCom(MasterGuiLogic *parent = nullptr);

    QStringList portNames() {
        return _portNames;
    }

    bool connectedToPort() {
        return _connectedToPort;
    }

private:

    QStringList _portNames;
    bool _connectedToPort = false;


signals:

    void portNamesChanged(const QStringList &);
    void connectedToPortChanged(bool connected);

    void serialOutput(const QByteArray &data);

public slots:

    void connectToPort(const QString &portName);
    void disconnectFromPort();

    void writeData(const QByteArray &data);
    void readData();

};

#endif // GUILOGIC_SERIALCOM_H
