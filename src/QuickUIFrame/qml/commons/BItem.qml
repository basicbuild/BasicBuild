import QtQuick 2.15

Item {
    function formatQmlPath(qmlName){
        return ("qrc:/qml/%1.qml").arg(qmlName)
    }
    function qmlCreateComponent(qmlName) {
        return Qt.createComponent(formatQmlPath(qmlName))
    }
}
