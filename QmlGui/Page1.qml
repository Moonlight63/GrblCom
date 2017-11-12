import QtQuick 2.7
//import GrblCom 1.0

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

    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
    }
}
