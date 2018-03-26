import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Dialog {
    width: 512
    height: 360
    id: setForm
    title: "Setting"

    property alias cbbParity: cbbParity
    property alias cbbFollowControl: cbbFollowControl
    property string textFont: "Arial"
    property int textSize: 14

    /* find something from ListModel */
    function find(mylistModel, name){
        for(var i = 0; i < mylistModel.count; i++) {
            if (mylistModel.get(i).text === name) return 1;
        }
        return 0;
    }

    Connections{
        target: accumonitor
        onPortChanged:{

            if (find(cbbPortItems, accumonitor.port) === 0){
                console.log("Post changed: " + accumonitor.port)
                cbbPortItems.insert(cbbPort.currentIndex, {"text": accumonitor.port})
            }
        }
    }
    Connections{
        target: btSetting
        onClicked:{
            console.log("setting clicked")
            cbbPortItems.clear()
            cbbPort.currentIndex = 0
            cbbPortItems.insert(cbbPort.currentIndex, {"text": "Custom"})
            accumonitor.updateSettingInfo()
        }

    }

    onAccepted: {
        accumonitor.port = cbbPort.editText
        accumonitor.baudRate = cbbBauRate.editText
        accumonitor.dataBits = cbbDataBits.editText
        accumonitor.parity = cbbParity.currentIndex
        accumonitor.stopBits = cbbStopBits.editText
        accumonitor.flowControl = cbbFollowControl.currentIndex
        accumonitor.enableEcho = checkBox.checkState

        if(cbbPort.currentIndex == (cbbPort.count - 1)){
            if (find(cbbPortItems, cbbPort.editText) === 0){
                console.log("save port edit")
                cbbPortItems.insert(cbbPort.currentIndex, {"text": cbbPort.editText})
            }
        }
        if(cbbBauRate.currentIndex == (cbbBauRate.count - 1)){
            if (find(cbbBaudRateItems, cbbBauRate.editText) === 0){
                console.log("save bauRate edit")
                cbbBaudRateItems.insert(cbbBauRate.currentIndex, {"text": cbbBauRate.editText})
            }
        }
    }

    Column{
        spacing: 50
        Row{
            spacing: 20
            Rectangle {
                id: uiPort
                x:30
                y:30
                width: (setForm.width/2 -23.0)
                height: setForm.height/1.8
                color: "#e2e2e2"
                radius: 7
                border.color: "#000000"

                ComboBox {
                    id: cbbPort
                    x: 8

                    currentIndex: 0
                    width: 185
                    height: 40

                    model: ListModel {
                        id: cbbPortItems
                        ListElement {
                            text: "pts/17"
                        }
                        ListElement {
                            text: "pts/18"
                        }
                        ListElement {
                            text: "Custom"
                        }
                    }
                    onCurrentIndexChanged: {
                        if(currentIndex === (count-1)){
                            editable = true
                        }
                        else editable = false
                    }
                }

                Text {
                    id: txtPort
                    x: 0
                    y: -17
                    width: 200
                    height: 15
                    text: qsTr("Select serial port")
                    font.family: textFont
                    font.pixelSize: textSize
                }
            }

            Rectangle {
                id: uiParameter
                y: 30
                width: (setForm.width/2 -23.0)
                height: setForm.height/1.8
                color: "#e2e2e2"
                radius: 7
                border.color: "#000000"
                Text {
                    id: txtParameter
                    x: 0
                    y: -17
                    width: 200
                    height: 15
                    text: qsTr("Select Parameters")
                    font.family: "Arial"
                    font.pixelSize: 14
                }
                Column{
                    spacing: (uiParameter.height/10)
                    Text {
                        id: txtBaudRate
                        x: 8
                        y: 20
                        text: qsTr("BaudRate:")
                        font.family: textFont
                        font.pixelSize: textSize

                        ComboBox {
                            id: cbbBauRate
//                            x: 104
//                            y: -4
                            width: 120
                            x: uiParameter.width - cbbBauRate.width - 20
                            y: -4
                            height: 40//25
                            currentIndex: 1

                            model: ListModel {
                                id: cbbBaudRateItems
                                ListElement {
                                    text: "9600"
                                }
                                ListElement {
                                    text: "115200"
                                }
                                ListElement {
                                    text: "Custom"
                                }
                            }
                            onCurrentIndexChanged: {
                                if(currentIndex === (count-1)){
                                    editable = true
                                }
                                else editable = false
                            }
                        }
                    }

                    Text {
                        id: txtDataBits
                        x: 8
                        y: 55
                        text: qsTr("Data Bits:")
                        font.family: textFont
                        font.pixelSize: textSize

                        ComboBox {
                            id: cbbDataBits

                            width: 120
                            x: uiParameter.width - cbbBauRate.width - 20
                            y: -4
                            height: 40
                            currentIndex: 0
                            model: ListModel {
                                id: cbbDataBitsItems
                                ListElement {
                                    text: "8"
                                }
                                ListElement {
                                    text: "7"
                                }
                                ListElement {
                                    text: "6"
                                }
                                ListElement {
                                    text: "5"
                                }
                            }
                        }
                    }

                    Text {
                        id: txtParity
                        x: 8
                        y: 90
                        text: qsTr("Parity:")
                        font.family: textFont
                        font.pixelSize: textSize

                        ComboBox {
                            id: cbbParity
                            width: 120
                            x: uiParameter.width - cbbBauRate.width - 20
                            y: -4
                            height: 40
                            currentIndex: 0
                            model: ListModel {
                                id: cbbParityItems
                                ListElement {
                                    text: "None"
                                }
                                ListElement {
                                    text: "Even"
                                }
                                ListElement {
                                    text: "Odd"
                                }
                                ListElement {
                                    text: "Space"
                                }
                                ListElement {
                                    text: "Mark"
                                }
                            }
                        }
                    }

                    Text {
                        id: txtStopBits
                        x: 8
                        y: 127
                        text: qsTr("Stop Bits:")
                        font.family: textFont
                        font.pixelSize: textSize

                        ComboBox {
                            id: cbbStopBits
                            width: 120
                            x: uiParameter.width - cbbBauRate.width - 20
                            y: -4
                            height: 40

                            currentIndex: 0
                            model: ListModel {
                                id: cbbStopBitsItems
                                ListElement {
                                    text: "1"
                                }
                                ListElement {
                                    text: "2"
                                }
                            }
                        }
                    }

                    Text {
                        id: txtFollowControl
                        x: 8
                        y: 164
                        text: qsTr("Follow Control:")
                        font.family: textFont
                        font.pixelSize: textSize

                        ComboBox {
                            id: cbbFollowControl
                            width: 120
                            x: uiParameter.width - cbbBauRate.width - 20
                            y: -4
                            height: 40
                            currentIndex: 0
                            model: ListModel {
                                id: cbbFollowControlItems
                                ListElement {
                                    text: "None"
                                }
                                ListElement {
                                    text: "RTS/CTS"
                                }
                                ListElement {
                                    text: "XON/XOFF"
                                }
                            }
                        }
                    }
                }
            }
        }
        Rectangle {
            id: uiOption
            width: (setForm.width-25.0)
            height: setForm.height/7.2
            color: "#e2e2e2"
            radius: 7
            border.color: "#000000"

            CheckBox {
                id: checkBox
                anchors.verticalCenter: uiOption.verticalCenter
                width: 140
                height: 21
                text: qsTr("Enable Echo")
                font.family: textFont
                font.pixelSize: textSize
            }
        }
    }
}
