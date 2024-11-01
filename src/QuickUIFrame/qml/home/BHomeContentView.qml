import QtQuick 2.15


Item {


    Rectangle {
        id: id_content_root
        anchors.fill: parent
        color: "grey"
        radius: 5
    }


    Loader {
        id: deviceAddLoader
        parent: id_content_root
        active: false // 初始状态下不加载组件
        onLoaded: {
            if (item != null) {
                item.parent = id_content_root; // 设置父组件
                item.anchors.centerIn =  id_content_root; // 设置位置
            }
        }
    }


    function newPage(featureName, featureDetailName) {
        deviceAddLoader.active = false // 卸载组件
        let page = ""

        if (featureName === "UI") {

        } else if (featureName === "模块") {

        } else if (featureName === "基础") {
            if (featureDetailName === "language") {
                page = "qrc:/qml/home/feature/basic/LanguageBasic.qml"
            } else if (featureDetailName === "exception") {
                page = "qrc:/qml/home/feature/basic/Exception.qml"
            }
        }

        deviceAddLoader.sourceComponent = Qt.createComponent(page)
        deviceAddLoader.active = true // 加载组件
    }

}
