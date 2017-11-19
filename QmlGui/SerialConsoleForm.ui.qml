import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: serialConsole
    width: 400
    height: 400
    property alias serialScroll: serialScroll
    property alias sendCommand: sendCommand
    property alias commandEntry: commandEntry
    property alias serialOutput: serialOutput

    TextField {
        id: commandEntry
        placeholderText: "Enter Serial Command"
        width: 278
        height: 48
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.top: parent.top
        anchors.topMargin: 8
    }

    ScrollView {
        id: serialScroll
        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.top: commandEntry.bottom
        anchors.topMargin: 6

        TextArea {
            id: serialOutput
            text: qsTr("")
            readOnly: true
        }
    }

    Button {
        id: sendCommand
        x: 292
        width: 100
        height: 48
        text: qsTr("Send")
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
    }
}
