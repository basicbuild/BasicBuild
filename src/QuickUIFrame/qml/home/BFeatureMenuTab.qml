import QtQuick 2.15
import QtQuick.Controls 2.15

import "../commons"
import "../commons/button"

Item {
    height: 60

    property var buttons: []

    signal featureSelected(var name)

    Rectangle {
        anchors.fill: parent
        color: "#35303D"
        radius: 5
    }

    BaseListView {
        id: id_item_list
        anchors.fill: parent
        model: featureModule ? featureModule.featureDataModel : null
        spacing: 2
        clip: true
        visible: id_item_list.count > 0
        orientation: ListView.Horizontal

        header: Item{
            implicitWidth: 0
            anchors.top: parent.top
            anchors.bottom: parent.bottom
        }

        delegate: BButton {
            id: id_button
            text: model.modelData.name
            checkable: true
            width: 150
            height: parent.height
            radius: 5
            color: isSelected ? "#5D5864" : "#35303D"
            textColor: isSelected ? "#FFFFFF" : "#BBBBBB"
            font.pixelSize: 22

            onClicked: {
                featureModule.switchFeature(model.modelData.name)
            }

            Component.onCompleted: {
                buttons.push(id_button)
                id_button.selectedChanged.connect(makeFunction(buttons.length - 1))
            }
        }

        footer: Item {
            height: parent.height
            width: 20
            visible: id_item_list.count > 0
        }
    }

    function makeFunction(index) {
        return function() {
            for (var j = 0; j < buttons.length; j++) {
                if (!buttons[j].checkable)
                    continue

                if (index === j) {
                    buttons[j].isSelected = true;
                    buttons[j].color = "#5D5864"
                    buttons[j].textColor = "#FFFFFF"

                    featureSelected(buttons[j].text)

                } else {
                    buttons[j].isSelected = false;
                    buttons[j].color = "#35303D"
                    buttons[j].textColor = "#BBBBBB"
                }
            }
        }
    }

    function getFeatureName() {
        for (var j = 0; j < buttons.length; j++) {
            if (!buttons[j].checkable)
                continue

            if (buttons[j].isSelected === true) {
                return buttons[j].text
            }
        }

    }

    Component.onDestruction: {
        id_item_list.model = null
    }
}
