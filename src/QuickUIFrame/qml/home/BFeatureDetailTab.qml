import QtQuick 2.15
import QtQuick.Controls 2.15

import "../commons"
import "../commons/button"

Item {
    width: 120

    property var buttons: []

    signal featureDetailSelected(var name)

    Rectangle {
        anchors.fill: parent
        color: "#35303D"
        radius: 5
    }

    BaseListView {
        id: id_item_list
        anchors.fill: parent
        model: featureModule ? featureModule.featureDataModel.featureDetailModel : null
        spacing: 2
        clip: true
        visible: id_item_list.count > 0

        header: Item{
            implicitHeight: 0
            anchors.left: parent.left
            anchors.right: parent.right
        }

        delegate: BButton {
            id: id_button
            text: model.modelData.name
            checkable: true
            width: id_item_list.width
            height: 60
            radius: 5
            color: isSelected ? "#5D5864" : "#35303D"
            textColor: isSelected ? "#FFFFFF" : "#BBBBBB"
            font.pixelSize: 18

            Component.onCompleted: {
                buttons.push(id_button)
                id_button.selectedChanged.connect(makeFunction(buttons.length - 1))
            }
        }

        footer: Item {
            width: parent.width
            height: 20
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

                    featureDetailSelected(buttons[j].text);
                } else {
                    buttons[j].isSelected = false;
                    buttons[j].color = "#35303D"
                    buttons[j].textColor = "#BBBBBB"
                }
            }
        }
    }

    function getFeatureDetailName() {
        for (var j = 0; j < buttons.length; j++) {
            if (!buttons[j].checkable)
                continue

            if (buttons[j].isSelected === true) {
                return buttons[j].text
            }
        }

    }
}
