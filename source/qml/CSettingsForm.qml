import QtQuick 2.9
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Window 2.0

Column {

    property var array: [1, 2, "3", "4"]
    property string sequence: ""

    signal languageChanged(int value)

    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 30
    padding: 20

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        width: parent.width - 20

        Label {
            id: save_folder_label
        }

        TextField {
            id: save_folder
            width: parent.width
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        width: parent.width - 20

        Label {
            id: launch_checkbox_label
        }

        CheckBox {
            id: launch_checkbox
        }
    }

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10
        width: parent.width - 20

        Label {
            id: language_label
        }

        ComboBox {
            id: language
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
            model: ListModel {
                id: model
                ListElement {
                    text: qsTr("English")
                }
                ListElement {
                    text: qsTr("Russian")
                }
            }
            onCurrentIndexChanged: {
                languageChanged(currentIndex)
            }
        }
    }

    Column {
        spacing: 10
        width: parent.width - 20
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: text_hotkey_label
        }

        RowLayout {
            width: parent.width
            spacing: 10

            Label {
                id: text_hotkey_fill_label
            }

            TextField {
                id: text_hotkey
                Layout.fillWidth: true

                Keys.onPressed: {
                    switch (event.key) {
                    case Qt.Key_Shift:
                        console.log("Shift")
                        sequence += "Shift"
                        break
                    case Qt.Key_Control:
                        console.log("Control")
                        sequence += "Ctrl"
                        break
                    case Qt.Key_Alt:
                        console.log("Alt")
                        break
                    case Qt.Key_Meta:
                        console.log("Meta")
                        break
                    default:
                        console.log(event.text)
                        break
                    }
                    console.log(sequence)
                }
                Keys.onReleased: {
                    switch (event.key) {
                    case Qt.Key_Shift:
                        console.log("Key_Shift released")
                        break
                    case Qt.Key_Control:
                        console.log("Key_Control  released")
                        break
                    case Qt.Key_Alt:
                        console.log("Key_Alt  released")
                        break
                    case Qt.Key_Meta:
                        console.log("Key_Meta  released")
                        break
                    default:
                        console.log(event.text + " released")
                        break
                    }
                    console.log(sequence)
                }
            }
        }
    }

    function setAutorun(value) {
        launch_checkbox.checked = parseInt(value)
        array[0] = parseInt(value)
    }
    function setLanguage(value) {
        language.currentIndex = parseInt(value)
        array[1] = parseInt(value)
    }
    function setPath(value) {
        save_folder.text = value
        array[2] = value
    }
    function setShortcut(value) {
        text_hotkey.text = value
        array[3] = value
    }

    function getInfo() {
        var launch = launch_checkbox.checked ? 1 : 0
        return launch + "|" + language.currentIndex.toString(
                    ) + "|" + save_folder.text + "|" + text_hotkey.text
    }
    function reset() {
        launch_checkbox.checked = array[0]
        language.currentIndex = array[1]
        save_folder.text = array[2]
        text_hotkey.text = array[3]
    }
    function retranslate() {
        save_folder_label.text = qsTr("Save screenshots to")
        launch_checkbox_label.text = qsTr("Startup and nitification")
        launch_checkbox.text = qsTr("Launch application on computer startup")
        language_label.text = qsTr("Language")

        //language.get(currentIndex).text
        text_hotkey_label.text = qsTr(
                    "To change a keybord shortcut, select it and enter a new one")
        text_hotkey_fill_label.text = qsTr("Fullscreen")
    }
}
