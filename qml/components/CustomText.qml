import QtQuick

Item {
    property alias text: txt.text;
    property alias pixelSize: txt.font.pixelSize;

    Text {
        id: txt;
        anchors.fill: parent;
        verticalAlignment: Text.AlignVCenter;
        horizontalAlignment: Text.AlignHCenter;
        font.pixelSize: 10;
        text: "some text"
        color: "white"
    }
}
