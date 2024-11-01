import QtQuick 2.15

Loader {
    asynchronous: true
    active: false

    readonly property bool isLoaded: status === BLoader.Ready
}
