import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window
{
    id: mainroot
    minimumWidth: 1000
    minimumHeight: 700
    maximumHeight: minimumHeight
    maximumWidth: minimumWidth
    title: "Chess"
    //visible: true

    Rectangle
    {
        id: root
        color: "light gray"
        anchors.fill: parent
        LoginWindow
        {
            id: lg
            onNameset:
            {
                mainroot.visible = true
            }
        }
        CloseWindow
        {
            id: cw
            onGame_exited:
            {
                console.log("hello")
                mainroot.visible = false
            }
        }
        Rectangle
        {
            id: board
            width: brdimg.width + 20
            height: brdimg.height + 20
            anchors.horizontalCenter: root.horizontalCenter
            color: "light gray"
            border.color: "gray"
            border.width: 2


            Image
            {
                id: brdimg
                width: 0.48 * implicitWidth
                height: 0.48 * implicitHeight
                source: "qrc:/Frame 22.png"
                visible: true
                anchors.centerIn: parent
            }
        }
        Rectangle
        {
            id: attacked_piece
            color: "light gray"
            border.color: "gray"
            border.width: 2
            anchors
            {
                top: board.bottom
                left: board.left
                right: root.right
                bottom: root.bottom
            }
            Rectangle
            {
                color: "gray"
                opacity: 0.5
                width: parent.width - 100
                height: 2
                anchors.centerIn: parent
            }
        }
        Rectangle
        {
            id: point_title
            color: "light gray"
            border.color: "gray"
            border.width: 2
            anchors
            {
                top: root.top
                left: board.right
                right: root.right
            }
            height: 120
            Text
            {
                text: "امتیاز ها"
                font.pixelSize: 40


                anchors.centerIn: parent
            }
        }
        Rectangle
        {
            id: player1_point
            color: "light gray"
            border.color: "gray"
            border.width: 2
            anchors
            {
                top: point_title.bottom
                left: board.right
                right: root.right
            }
            height: (root.height - attacked_piece.height - point_title.height) / 2

            Text
            {
                text: "امتیاز " + lg._wPlayer_name + " : "
                anchors
                {
                    top: player1_point.top
                    topMargin: 20
                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 20
            }
            Text
            {
                text: "امتیاز منفی " + lg._wPlayer_name + " : "
                anchors
                {
                    top: player1_point.verticalCenter

                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 20
            }
        }
        Rectangle
        {
            id: player2_point
            color: "light gray"
            border.color: "gray"
            border.width: 2
            anchors
            {
                top: player1_point.bottom
                left: board.right
                right: root.right
                bottom: attacked_piece.top
            }
            Text
            {
                text: "امتیاز " + lg._bPlayer_name + " : "
                anchors
                {
                    top: player2_point.top
                    topMargin: 20
                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 20
            }
            Text
            {
                text: "امتیاز منفی " + lg._bPlayer_name + " : "
                anchors
                {
                    top: player2_point.verticalCenter

                    horizontalCenter: parent.horizontalCenter
                }
                font.pixelSize: 20
            }
        }
        Rectangle
        {
            id: left_section
            color: "light gray"
            border.color: "gray"
            anchors
            {
                top: root.top
                bottom: root.bottom
                left:root.left
                right: board.left
            }
            Text
            {
                id: game_title
                text: "اسم بازی " + " : "
                anchors
                {
                    top: left_section.top
                    topMargin: 20
                    horizontalCenter: left_section.horizontalCenter
                }
                font.pixelSize: 30

            }
            Text
            {
                text: lg._game_name
                font.pixelSize: 30
                anchors
                {
                    top: game_title.bottom
                    topMargin : 20
                    horizontalCenter: left_section.horizontalCenter
                }
            }
            Rectangle
            {
                id: line1
                color: "gray"
                opacity: 0.5
                width: parent.width - 50
                height: 2
                anchors.horizontalCenter: parent.horizontalCenter
                y: 150
            }
            Rectangle
            {
                id: line2
                color: "gray"
                opacity: 0.5
                width: parent.width - 50
                height: 2
                anchors.horizontalCenter: parent.horizontalCenter
                y: 400
            }
            Image
            {
                id: restart_icon
                source: "qrc:/Assets /Frame 4.png"
                width: 0.3 * implicitWidth
                height: 0.3 * implicitHeight
                opacity: mouse1.containsMouse ? 0.8 : 1
                anchors
                {
                    top: line2.bottom
                    topMargin: 30
                    horizontalCenter: left_section.horizontalCenter
                }
                MouseArea
                {
                    id: mouse1
                    hoverEnabled: true
                    anchors.fill: parent
                    onClicked: {
                        //..............
                    }
                }
            }
            Image
            {
                id: quit_icon
                source: "qrc:/Assets /Frame 2.png"
                width: 0.4 * implicitWidth
                height: 0.4 * implicitHeight
                opacity: mouse2.containsMouse ? 0.8 : 1
                anchors
                {
                    top: restart_icon.bottom
                    topMargin: 30
                    horizontalCenter: left_section.horizontalCenter
                }
                MouseArea
                {
                    id: mouse2
                    hoverEnabled: true
                    anchors.fill: parent
                    onClicked: {
                        //..............
                    }
                }
            }
            Image
            {
                id: exit_icon
                source: "qrc:/Assets /Frame 5.png"
                width: 0.4 * implicitWidth
                height: 0.4 * implicitHeight
                opacity: mouse3.containsMouse ? 0.8 : 1
                anchors
                {
                    top: quit_icon.bottom
                    topMargin: 30
                    horizontalCenter: left_section.horizontalCenter
                }
                MouseArea
                {
                    id: mouse3
                    hoverEnabled: true
                    anchors.fill: parent
                    onClicked: {
                        cw.visible = true
                    }
                }
            }
        }
    }
}
