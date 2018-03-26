import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import AccuMonitor 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Accu Monitor")

    property alias btConnect: btConnect
    property alias btDisconnect: btDisconnect
    property alias btSetting: btSetting
    property alias txtConsole: txtConsole
    property alias uiScreen: uiScreen
    property alias txtEdit: txtEdit
    property alias txtStatus: txtStatus
    property alias settingDialog: settingDialog
    property bool  isConnected: false
    property bool  isEcho: false

    property string textFont: "Arial"
    property int textSize: 14
    property real bt_height: 30
    property real bt_width: 110


    SettingDiag {
        width: 520
        height: 360
        id: settingDialog
        visible: false
    }


    Connections{
        target: accumonitor
        onEnableEchoChanged:{
            console.log("onEnableEchoChanged")
            isEcho = accumonitor.enableEcho
        }
        onConsoleDataChanged:{
            console.log("console data changed")
            console.log(accumonitor.consoleData)
            txtEdit.text = txtEdit.text + accumonitor.consoleData
        }
    }

    Rectangle {
        id: uiSettingBar
        radius: 3
        anchors.left: parent.left
        anchors.right: parent.right
        height: 30
        border.width: 1
        border.color: "#aba2a2"

        Row{
            anchors.left: parent.left
            anchors.leftMargin: 5
            spacing: 10
            Button {
                id: btConnect
                width: bt_width
                height: bt_height
//                anchors.left: parent.left
                text: "Connected"
                onClicked: {
                    if(isConnected == false){
                        txtStatus.text = "Connecting..."
                        var tmp
                        tmp = accumonitor.consoleConnect()
                        console.log(tmp)
                        if (tmp === true){
                            isConnected = true
                            txtStatus.text = "Conneted: " + accumonitor.port + ", " + accumonitor.baudRate + "bps, " +
                                    accumonitor.dataBits + "bits, " + settingDialog.cbbParity.currentText + " parity, "+
                                    accumonitor.stopBits + " bits stop, " + settingDialog.cbbFollowControl.currentText + "FolowControl "
                            sttColor.color = "green"
                            /* active focus to text console */
                            txtConsole.forceActiveFocus()
                        }
                        else{
                            if (accumonitor.port === ""){
                                txtStatus.text = "Please check setting!"
                                sttColor.color = "red"
                            }
                            else{
                                txtStatus.text = "Can't connect to port: " + accumonitor.port + ", " + accumonitor.baudRate + "bps, " +
                                        accumonitor.dataBits + "bits, " + settingDialog.cbbParity.currentText + " parity, "+
                                        accumonitor.stopBits + " bits stop, " + settingDialog.cbbFollowControl.currentText + "FolowControl "
                                sttColor.color = "red"
                            }
                        }
                    }
                }
            }
            Button {
                id: btDisconnect
//                anchors: btConnect.right
                width: bt_width
                height: bt_height
                text: qsTr("Disconnect")
                onClicked: {
                    isConnected = false;
                    txtStatus.text = "Disconnected"
                    sttColor.color = "blue"
                    accumonitor.consoleDisconnect()
                }
            }
            Button {
                id: btSetting
                width: bt_width
                height: bt_height
                text: qsTr("Setting")

                onClicked: {
                    if(isConnected === false){
                        settingDialog.visible = true
                        txtStatus.text = "Setting mode"
                    }
                    else {
                        sttColor.color = "red"
                        txtStatus.text = "Unable to setting when connecting!"
                    }
                }
            }
        }
    }

    Rectangle {
        id: uiDev
        color: "#ffffff"
        radius: 3
        border.color: "#211e1e"

        anchors.top: uiSettingBar.bottom
        anchors.left: parent.left
        anchors.right: uiUser.left
        anchors.bottom: uiStatus.top

        anchors.leftMargin: 5
        anchors.rightMargin: 5
        anchors.topMargin: 5
        anchors.bottomMargin: 5

        Rectangle {
            id: uiScreen
            color: "#00000000"
            radius: 3
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: uiConsole.top
            anchors.bottomMargin: 1
            border.width: 1

            ScrollView {
                id: scrollView
                enabled: true
                rotation: 0

                spacing: 1
                contentWidth: parent.width
                contentHeight: (txtEdit.contentHeight + 10.0)

                /* set ScrollBar */
                ScrollBar.horizontal.policy: ScrollBar.AlwaysOff
                ScrollBar.vertical.policy: ScrollBar.AlwaysOn
                ScrollBar.vertical.position: txtEdit.contentHeight

                clip: true
                anchors.fill: parent
                font.pixelSize: 12

                TextEdit {
                    id: txtEdit

                    anchors.fill: parent
                    clip: true

                    leftPadding: 5
                    topPadding: 6
                    bottomPadding: 20
                    font.pixelSize: 12
                }
            }
        }
        MouseArea{
            anchors.fill: parent
            anchors.rightMargin: 15
            onReleased:  {
                txtConsole.forceActiveFocus()
            }
        }

        Rectangle {
            id: uiConsole
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: 15
            color: "#00000000"
            radius: 3
            border.color: "#000000"

            TextInput {
                id: txtConsole
                anchors.fill: parent

                font.capitalization: Font.AllLowercase
                leftPadding: 5
                topPadding: 2
                font.pixelSize: 12
                onAccepted: {
                    if (isConnected){
                        // Echo
                        if (isEcho){
                            txtEdit.text += txtConsole.text + "\n" // + txtConsole.text + "\n";
                        }
                        txtConsole.text = txtConsole.text + "\n";

                        // Call Funciton
                        accumonitor.consoleData = txtConsole.text;
                        txtConsole.text = "";
                    }
                    else{
//                        txtEdit.text = "Connect Error. Please check settting\n";
                    }
                }
            }
        }
    }
    Rectangle {
        id: uiUser
        radius: 3
        border.color: "#020202"
        anchors.top: uiSettingBar.bottom
        anchors.right: parent.right
        anchors.bottom: uiStatus.top

        anchors.leftMargin: 5
        anchors.rightMargin: 5
        anchors.topMargin: 5
        anchors.bottomMargin: 5



        width: 300
        color: "#ffffff"

        Dialog{
            id:userSttDialog

            title: "Notify"
            standardButtons: Dialog.Ok

            width: uiUser.width
            height: 150
            visible: false

            Label {
                id: txtUserStt
            }
        }

        Grid{
            rows: 5
//            columns: 2
            anchors.left: uiUser.left
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            spacing: 10

            Button{
                id: btClear
                width: uiUser.width/2.2
                text: "Clear Screen"
                onClicked: {
                        txtConsole.clear()
                        txtEdit.clear()
                }
            }
            Button{
                id: btAmpCheck
                width: uiUser.width/2.2
                text: "Check Amper"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nAMPER CHECKING...\n"
                        }
                        accumonitor.consoleData = "accu a\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btVoltCheck
                width: uiUser.width/2.2
                text: "Check Volt"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nVOLT CHECKING...\n"
                        }
                        accumonitor.consoleData = "accu v\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btTransmissionCheck
                width: uiUser.width/2.2
                text: "Check RS485"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nRS485 CHECKING...\n"
                        }
                        accumonitor.consoleData = "accu c\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btVoltCheck1
                width: uiUser.width/2.2
                text: "ACCU Group 1"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nGROUP 1...\n"
                        }
                        accumonitor.consoleData = "accu v0\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btVoltCheck2
                width: uiUser.width/2.2
                text: "ACCU Group 2"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nGROUP 2...\n"
                        }
                        accumonitor.consoleData = "accu v1\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btVoltCheck3
                width: uiUser.width/2.2
                text: "ACCU Group 3"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nGROUP 3...\n"
                        }
                        accumonitor.consoleData = "accu v2\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btVoltCheck4
                width: uiUser.width/2.2
                text: "ACCU Group 4"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nGROUP 4...\n"
                        }
                        accumonitor.consoleData = "accu v3\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }

            Rectangle{
                width: uiUser.width/2.2
                color: "black"
                border.color: "black"


            }
            Button{
                id: btClearStt
                width: uiUser.width/2.2
                text: "CLEAR STT"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nCLEAR ALL STT...\n"
                        }
                        accumonitor.consoleData = "accu r\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
            Button{
                id: btCalibration
                width: uiUser.width/2.2
                text: "CALIB SENSORS"
                onClicked: {
                    if (isConnected){
                        if(isEcho){
                            txtEdit.text += "\nSENSORS CALIBRATING...\n"
                        }
                        accumonitor.consoleData = "accu ac\n"
                    }
                    else{
                        txtUserStt.text = "Check Connection, Please!"
                        userSttDialog.visible = true
                    }
                }
            }
        }
    }


    Rectangle {
        id: uiStatus
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        anchors.leftMargin: 5
        anchors.rightMargin: 5
        anchors.topMargin: 5
        anchors.bottomMargin: 5

        height: 15
        color: "#ffffff"
        radius: 3
        border.color: "#020202"

        Row{
            Rectangle{
                id: sttColor
                width: uiStatus.height
                height: uiStatus.height
                color: "blue"
                border.color: "#020202"
            }

            Text {
                id: txtStatus

                text: qsTr("Disconnected.")
                rightPadding: 3
                leftPadding: 3
                font.pixelSize: 12
            }
        }
    }
}
