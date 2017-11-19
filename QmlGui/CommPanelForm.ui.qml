import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {

    id: commPanel
    width: childrenRect.width
    height: childrenRect.height
    property alias comPort: comPort
    property alias connectCom: connectCom

    ComboBox {
        id: comPort
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    Button {
        id: connectCom
        text: qsTr("Connect")
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: comPort.right
        anchors.leftMargin: 25
    }
}
