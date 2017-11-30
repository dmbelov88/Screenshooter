import QtQuick 2.5
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2
import Qt.labs.platform 1.0

ApplicationWindow {
    id: application
    visible: false
    width: 420
    height: 400
    x: Screen.desktopAvailableWidth / 2 - width / 2
    y: Screen.desktopAvailableHeight / 2 - height / 2
    minimumWidth: 420
    minimumHeight: 400
    maximumWidth: 500
    maximumHeight: 500

    signal saveSettings

    Connections {
        target: CSettingsHelper
        onSetSettings: {
            var array = CSettingsHelper.info.split("|")
            settingsForm.setAutorun(array[0])
            settingsForm.setLanguage(array[1])
            settingsForm.setPath(array[2])
            settingsForm.setShortcut(array[3])
            systemTrayMenu.folderName = array[2]
        }
        onRetranslateUi: {
            retranslate()
        }
    }

    onClosing: {
        application.hide()
    }

    Column {
        id: column
        anchors.fill: parent

        CSettingsForm {
            id: settingsForm
            width: parent.width

            onLanguageChanged: {
                CSettingsHelper.setLocaleId(value)
            }
        }
    }

    Row {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.rightMargin: 10
        anchors.bottomMargin: 10
        spacing: 10

        Button {
            id: ok_button
            onClicked: {
                CSettingsHelper.setInfo(settingsForm.getInfo())
                CSettingsHelper.saveSettings()
                application.hide()
            }
        }

        Button {
            id: cancel_button
            onClicked: {
                application.hide()
                settingsForm.reset()
            }
        }
    }

    CSystemTrayMenu {
        id: systemTrayMenu
        iconSource: "qrc:/favicon.png"
        visible: true
        onAppShow: application.show()
    }

    function retranslate() {
        systemTrayMenu.retranslate()
        settingsForm.retranslate()
        ok_button.text = qsTr("Ok")
        cancel_button.text = qsTr("Cancel")
    }
}
