import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    width: 720
    height: 480

    CommPanel {
        id: commPanel
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    SerialConsole {
        id: serialConsole
        width: 400
        height: 400
        anchors.top: commPanel.bottom
        anchors.topMargin: 24
        anchors.left: parent.left
        anchors.leftMargin: 8
    }

    JoggingPanel {
        id: joggingPanel
        anchors.top: parent.top
        anchors.topMargin: 80
        anchors.left: serialConsole.right
        anchors.leftMargin: 99
    }
}
