import QtQuick 2.15

Timer {
    // objectName needs to be set
    onRunningChanged: {
        console.log("BTimer.qml===child===timer===objectName: ",
                    objectName, "===running: ", (running ? "start" : "stop"))
    }
}

