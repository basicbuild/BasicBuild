import QtQuick 2.15
import QtQuick.Controls 2.15
import "../commons"
import "../commons/text"

Item {
    width: parent.width

    Rectangle {
        anchors.fill: parent
        color: "#35303D"
        radius: 5
    }


    BTextMedium {
        anchors.left: parent.left
        anchors.top: parent.top

    }

    ListView {
        id: horizontalListView
        width: parent.width
        height: 100
        anchors.centerIn: parent
        orientation: Qt.Horizontal
        model: 10  // 模型包含10个项目

        delegate: Item {
            width: 100
            height: 100

            Rectangle {
                width: 80
                height: 80
                color: "lightblue"
                radius: 10
                anchors.centerIn: parent

                Text {
                    text: index + 1  // 显示项目索引
                    anchors.centerIn: parent
                    font.pointSize: 20
                }
            }
        }

        // 添加水平滚动条
        ScrollBar.horizontal: ScrollBar {
            policy: ScrollBar.AlwaysOn
        }
    }
}
