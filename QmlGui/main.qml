import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.1
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true

    width: 720
    height: 480

    title: qsTr("GrblCom")

    Material.accent: Material.LightBlue
    Material.theme: Material.Dark

    MainLayout {
        anchors.fill: parent
    }

//    SwipeView {
//        id: swipeView
//        anchors.fill: parent
//        currentIndex: tabBar.currentIndex

//        Page1 {
//        }

//        Page {
//            Label {
//                text: qsTr("Second page")
//                anchors.centerIn: parent
//            }
//        }

//    }

//    footer: TabBar {
//        id: tabBar
//        currentIndex: swipeView.currentIndex
//        TabButton {
//            text: qsTr("First")
//        }
//        TabButton {
//            text: qsTr("Second")
//        }

//    }
}
