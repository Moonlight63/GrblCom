import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    id: item1
    property alias textField1: textField1
    property alias button1: button1
    property alias yUp: yUp
    property alias xDown: xDown
    property alias xUp: xUp
    property alias yDown: yDown

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top

        TextField {
            id: textField1
            horizontalAlignment: Text.AlignLeft
            placeholderText: qsTr("Text Field")
        }

        Button {
            id: button1
            text: qsTr("Press Me")
        }
    }

    Item {
        id: xyControls
        width: 130
        height: width + (yUp.height - yUp.width)
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Button {
            id: yUp
            width: 50
            height: 62
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            rotation: 45
            transformOrigin: Item.Center

            Label {
                id: yUpLabel
                text: qsTr("+Y")
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                rotation: -45
                anchors.fill: parent
            }
        }

        Button {
            id: xDown
            width: yUp.width
            height: yUp.height
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            rotation: 45
            transformOrigin: Item.Center
            Label {
                id: xDownLabel
                text: qsTr("-X")
                rotation: -45
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }

        Button {
            id: xUp
            width: yUp.width
            height: yUp.height
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            rotation: 45
            transformOrigin: Item.Center
            Label {
                id: xUpLabel
                text: qsTr("+X")
                rotation: -45
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }

        Button {
            id: yDown
            width: yUp.width
            height: yUp.height
            scale: 1
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            rotation: 45
            transformOrigin: Item.Center
            Label {
                id: yDownLabel
                text: qsTr("-Y")
                scale: 1
                rotation: -45
                verticalAlignment: Text.AlignVCenter
                anchors.topMargin: 5
                anchors.bottomMargin: 5
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
            }
        }
    }
}
