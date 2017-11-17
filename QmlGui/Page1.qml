import QtQuick 2.7

Page1Form {


    yDown.onClicked: {
        MasterGuiLogic.positionPanel.yDown();
    }
    xDown.onClicked: {
        MasterGuiLogic.positionPanel.xDown();
    }
    yUp.onClicked: {
        MasterGuiLogic.positionPanel.yUp();
    }
    xUp.onClicked: {
        MasterGuiLogic.positionPanel.xUp();
    }

    yDown.onPressAndHold: {
        MasterGuiLogic.positionPanel.yDownHold();
    }
    xDown.onPressAndHold: {
        MasterGuiLogic.positionPanel.xDownHold();
    }
    yUp.onPressAndHold: {
        MasterGuiLogic.positionPanel.yUpHold();
    }
    xUp.onPressAndHold: {
        MasterGuiLogic.positionPanel.xUpHold();
    }

    yDown.onReleased: {
        MasterGuiLogic.positionPanel.yDownReleased();
    }
    xDown.onReleased: {
        MasterGuiLogic.positionPanel.xDownReleased();
    }
    yUp.onReleased: {
        MasterGuiLogic.positionPanel.yUpReleased();
    }
    xUp.onReleased: {
        MasterGuiLogic.positionPanel.xUpReleased();
    }

    comPort.model: MasterGuiLogic.serialCom.portNames;

    connectCom.onClicked: {
        if (MasterGuiLogic.serialCom.connectedToPort === false) {
            MasterGuiLogic.serialCom.connectToPort(comPort.currentText);
        } else {
            MasterGuiLogic.serialCom.disconnectFromPort(comPort.currentText);
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


    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
}
