import QtQuick 2.7

CommPanelForm {

    comPort.model: MasterGuiLogic.serialCom.portNames;

    connectCom.onClicked: {
        if (MasterGuiLogic.serialCom.connectedToPort === false) {
            MasterGuiLogic.serialCom.connectToPort(comPort.currentText);
        } else {
            MasterGuiLogic.serialCom.disconnectFromPort();
        }
    }


    Connections {
        target: MasterGuiLogic.serialCom;
        onConnectedToPortChanged: {
            if (MasterGuiLogic.serialCom.connectedToPort === true) {
                connectCom.text = "Disconnect";
                comPort.enabled = false;
            } else {
                connectCom.text = "Connect";
                comPort.enabled = true;
            }
        }
    }

}
