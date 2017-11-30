import QtQuick 2.5
import QtQuick.Controls 2.2
import Qt.labs.platform 1.0

SystemTrayIcon {

    property string folderName: ""
    signal appShow

    menu: Menu {
        MenuItem {
            id: open_folder
            onTriggered: {
                Qt.openUrlExternally(
                            StandardPaths.writableLocation(
                                StandardPaths.PicturesLocation) + "/" + folderName)
            }
        }

        MenuItem {
            id: settings
            onTriggered: appShow()
        }

        MenuItem {
            id: report
            onTriggered: Qt.openUrlExternally(
                             "https://github.com/DmitryBelov/Screenshooter/issues")
        }

        MenuItem {
            id: quit
            shortcut: StandardKey.Close
            onTriggered: Qt.quit()
        }
    }

    function retranslate() {
        open_folder.text = qsTr("Open folder with screenshots")
        settings.text = qsTr("Settings")
        report.text = qsTr("Report bugs")
        quit.text = qsTr("Quit")
    }
}
