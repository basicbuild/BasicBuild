import QtQuick 2.15
import "../text"

BButtonBase {
    id: id_button_bg
    implicitHeight: 80
    radius: height/2
    color: "#F03A4C"

    property int pixelSize: 28
    property alias text: id_button_tip.text
    property alias textColor: id_button_tip.color
    property alias textWidth: id_button_tip.contentWidth
    property alias font: id_button_tip.font
    property alias lineHeight: id_button_tip.lineHeight
    property alias lineHeightMode: id_button_tip.lineHeightMode

    BTextMedium {
        id: id_button_tip
        anchors.centerIn: parent
        font.pixelSize: parent.pixelSize !== 28 ? parent.pixelSize : font.pixelSize
    }
}
