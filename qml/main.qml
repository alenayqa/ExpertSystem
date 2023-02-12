import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import "components"

Window {
    id: root;
    width: 640;
    height: 480;
    visible: true;
    title: qsTr("Hello World");

    Workspace {}

    Rectangle {
        id: headerRect;
        anchors {
            left: parent.left;
            right: parent.right;
            top: parent.top;
        }
        height: root.height / 4;
        color: "#2D2B2B";

        CustomText {
            anchors.fill: parent;
            text: "Expert Systems"
            pixelSize: 54;
        }
    }

    Rectangle {
        id: workspaceRect;
        anchors {
            left: parent.left;
            right: parent.right;
            top: headerRect.bottom;
            bottom: parent.bottom;
        }

        color: "#505050";
        Row {
            anchors.verticalCenter: parent.verticalCenter;
            anchors.horizontalCenter: parent.horizontalCenter;
            height: parent.height / 2.3;
            spacing: 20;
            Rectangle {
                height: parent.height;
                width: height * 4 / 3;
                color: "#2D2B2B";
                radius: 5;

                CustomText {
                    anchors.fill: parent;
                    text: "Открыть"
                    pixelSize: 28;
                }

            }
            Rectangle {
                height: parent.height;
                width: height * 4 / 3;
                color: "#2D2B2B";
                radius: 5;

                CustomText {
                    anchors.fill: parent;
                    text: "Создать"
                    pixelSize: 28;
                }
            }
        }
    }
}
