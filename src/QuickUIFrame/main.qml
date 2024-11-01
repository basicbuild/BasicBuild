import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "./qml/home"

Item {
    width: 1080
    height: 920
    visible: true
    //title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "white"
    }

    // 功能tab菜单
    BFeatureMenuTab {
        id: id_tab_menu
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 1

        onFeatureSelected: {
            console.log("feature_name:", id_tab_menu.getFeatureName())
            console.log("feature_detail_name:", id_tab_detail.getFeatureDetailName())

        }
    }

    // 详细内容tab菜单
    BFeatureDetailTab {
        id: id_tab_detail
        anchors.left: parent.left
        anchors.top: id_tab_menu.bottom
        anchors.bottom: parent.bottom
        anchors.margins: 1

        onFeatureDetailSelected: {
            console.log("feature_name:", id_tab_menu.getFeatureName())
            console.log("feature_detail_name:", id_tab_detail.getFeatureDetailName())

            id_content.newPage(id_tab_menu.getFeatureName(), id_tab_detail.getFeatureDetailName())
        }
    }

    // 内容
    BHomeContentView {
        id: id_content
        anchors.left: id_tab_detail.right
        anchors.right: parent.right
        anchors.top: id_tab_menu.bottom
        anchors.bottom: parent.bottom
        anchors.margins: 1
    }
}
