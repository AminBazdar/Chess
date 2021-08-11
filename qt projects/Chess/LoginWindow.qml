import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Window 2.3
Window
{
    signal nameset
    property string _wPlayer_name
    property string _bPlayer_name
    property string _game_name
    id: setplayer
    minimumWidth: 500
    minimumHeight: 200
    maximumHeight: minimumHeight
    maximumWidth: minimumWidth
    visible: true
    title: "Set Players"
    Rectangle
    {
        id: root
        anchors.fill: parent
        color: "light gray"
        Rectangle
        {
            id: rect1
            color: "white"
            width: txt1.width + 20
            height: txt1.height + 20
            anchors
            {
                right: root.right
                top: root.top
                topMargin: 40
                rightMargin: 20
            }
            radius: 30
            Text
            {
                id: txt1
                text: "بازیکن سفید" + ":"
                font.pixelSize: 25
                anchors.centerIn: parent
            }
        }
        TextField
        {
            id: txtf1
            width: 150
            height: rect1.height - 10
            anchors
            {
                verticalCenter: rect1.verticalCenter
                right: rect1.left
                rightMargin: 10
            }
            text: "بازیکن 1"
            color: activeFocus ? "black" : "gray"
        }
        Rectangle
        {
            id: rect2
            color: "black"
            width: rect1.width
            height: rect1.height
            anchors
            {
                right: root.right
                top: rect1.bottom
                topMargin: 20
                rightMargin: 20
            }
            radius: 30
            Text
            {
                id: txt2
                text: "بازیکن سیاه" + ":"
                color: "white"
                font.pixelSize: 25
                anchors.centerIn: parent
            }
        }
        TextField
        {
            id: txtf2
            width: 150
            height: rect2.height - 10
            anchors
            {
                verticalCenter: rect2.verticalCenter
                right: rect2.left
                rightMargin: 10
            }
            text: "بازیکن 2"
            color: activeFocus ? "blakc" : "gray"
        }
        Rectangle
        {
            x: 0
            y: 0
            color: "#9E9E9E"
            height: setplayer.height
            anchors
            {
                left: root.left
                right: txtf2.left
                rightMargin: 15

            }
            opacity: 0.5


        }
        Image
        {
            id: taeed
            width: 0.25* implicitWidth
            height: 0.25 * implicitHeight
            y: 100
            anchors
            {
                horizontalCenter: txt3.horizontalCenter
            }
            opacity: mouse1.containsMouse ? 0.8 : 1
            source: "qrc:/Assets /Frame 3.png"
            MouseArea
            {
                id: mouse1
                hoverEnabled: true
                anchors.fill: parent
                onClicked:
                {
                    _wPlayer_name = txtf1.text
                    _bPlayer_name = txtf2.text
                    _game_name = txtf3.text
                    nameset()
                    setplayer.close()

                }
            }
        }
        Text
        {
            id: txt3
            text: "نام بازی"
            x: 40
            y: 20
            font.pixelSize: 20
        }
        TextField
        {
            id: txtf3
            width: 120
            height: 30
            anchors
            {
                topMargin: 10
                top: txt3.bottom
                horizontalCenter: txt3.horizontalCenter
            }
            text: "بی نام"
            color: activeFocus ? "black" : "gray"
        }

    }
}
