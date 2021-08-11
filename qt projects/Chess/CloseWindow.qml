import QtQuick 2.0

Window
{
    signal game_exited
    id: mainroot
    minimumWidth: 500
    minimumHeight: 200
    maximumHeight: minimumHeight
    maximumWidth: minimumWidth
    title: "close window"

    Rectangle
    {
        id: root
        anchors.fill: parent
        color: "light gray"
        Text
        {
            text: "آیا میخواهید خارج شوید؟"
            anchors
            {
                horizontalCenter: root.horizontalCenter
                bottom: root.verticalCenter
                bottomMargin: 30
            }
            font.pixelSize: 40
        }

        Image
        {
            source: "qrc:/Assets /Frame 5.png"
            width: 0.3 * implicitWidth
            height: 0.3 * implicitHeight
            anchors
            {
                left: root.horizontalCenter
                leftMargin: 40
            }
            y: 100
            opacity: cmouse1.containsMouse ? 0.8 : 1
            MouseArea
            {
                id: cmouse1
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    game_exited()
                    mainroot.close()
                }
            }
        }
        Image
        {
            source: "qrc:/Assets /Frame 2.png"
            width: 0.3 * implicitWidth
            height: 0.3 * implicitHeight
            anchors
            {
                right: root.horizontalCenter
                rightMargin: 40
            }
            y: 100
            opacity: cmouse2.containsMouse ? 0.8 : 1
            MouseArea
            {
                id: cmouse2
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    mainroot.close()
                }
            }
        }
    }
}
