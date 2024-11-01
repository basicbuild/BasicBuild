import QtQuick 2.15
import ".."

Rectangle {
    id: id_button_bg
    opacity: id_button.pressed || !enabled ? 0.6 : 1
    smooth: true

    property alias mouseAreaMargins: id_button.anchors.margins
    property alias mouseAreaLeftMargin: id_button.anchors.leftMargin
    property alias mouseAreaTopMargin: id_button.anchors.topMargin
    property alias mouseAreaRightMargin: id_button.anchors.rightMargin
    property alias mouseAreaBottomMargin: id_button.anchors.bottomMargin
    property alias clickable: id_button.enabled
    property alias pressed: id_button.pressed

    property alias hotAreaTesting: id_button.hotAreaTesting
    property alias id_button: id_button
    property bool hoverEnabled: false

    // 选中属性
    property bool checkable: false
    property bool isSelected: false

    signal clicked()
    signal validClicked()
    signal pressAndHold()
    signal btnpressed()
    signal btnreleased()
    signal selectedChanged()

    BMouseArea {
        id: id_button
        hoverEnabled: id_button_bg.hoverEnabled
        anchors.fill: parent
        onClicked: {
            id_button_bg.clicked()
            if (!id_button_timer.running) {
                validClicked()

                if (checkable) {
                    isSelected = !isSelected
                    parent.selectedChanged()
                }

            }
            id_button_timer.restart()
        }
        onPressAndHold: {
            parent.pressAndHold()
        }
        objectName: "BButtonBase.qml_id_button"
        onPressed: {
            parent.btnpressed();
        }
        onReleased: {
            parent.btnreleased();
        }
    }

    BTimer {
        id: id_button_timer
        interval: 360
        objectName: "BButtonBase.qml_id_button_timer"
    }
}
