import QtQuick 2.4

SerialConsoleForm {

    sendCommand.onClicked: {
        MasterGuiLogic.serialCom.writeData(commandEntry.text)
        commandEntry.clear()
    }

    commandEntry.onAccepted: {
        sendCommand.clicked()
    }

    serialOutput.onTextChanged: {
        serialOutput.cursorPosition = serialOutput.length-1;
    }

    Connections {
        target: MasterGuiLogic.serialCom
        onSerialOutput: {
            serialOutput.append(data);
        }
        onConnectedToPortChanged: {
            if (MasterGuiLogic.serialCom.connectedToPort === true) {
                serialOutput.clear();
            }
        }
    }

}
