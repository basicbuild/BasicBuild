﻿import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15  // 引入 Material 风格

Item {
    width: 440
    height: 300
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "#000000"
    }

    Button {
        id: id_btn_quick
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 50
        width: 100
        height: 50
        layer.enabled: true

        // 自定义Button样式，添加圆角
        contentItem: Text {
            text: "Quick"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
        }

        background: Rectangle {
            radius: 5 // 设置圆角半径
            color: id_btn_quick.pressed ? "lightgray" : "white"
        }

        onClicked: {
            globalTools.sigShowQuickUIFrame()

        }
    }

    Button {
        id: id_btn_widgets
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: 100
        height: 50
        layer.enabled: true

        // 自定义Button样式，添加圆角
        contentItem: Text {
            text: "Widgets"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
        }

        background: Rectangle {
            radius: 5 // 设置圆角半径
            color: id_btn_widgets.pressed ? "lightgray" : "white"
        }

        onClicked: {
            globalTools.sigShowWidgetsUIFrame()

        }
    }

    Button {
        id: id_btn_base
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 50
        width: 100
        height: 50
        layer.enabled: true

        // 自定义Button样式，添加圆角
        contentItem: Text {
            text: "Base"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "black"
        }

        background: Rectangle {
            radius: 5 // 设置圆角半径
            color: id_btn_base.pressed ? "lightgray" : "white"
        }

        onClicked: {
            //globalTools.sigShowWidgetsUIFrame()

        }
    }

}
