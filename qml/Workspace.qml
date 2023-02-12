import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import "components"

Window {
    width: 640;
    height: 480;
    visible: true;

    color: "#505050";
    Item {
        id: headerRect;
        height: 50;
        anchors {
            top: parent.top;
            left: parent.left;
            right: parent.right;
        }

        TabBar {
            id: bar;
            width: parent.width / 2;
            anchors {
                top: parent.top;
                bottom: parent.bottom;
                left: parent.left;
            }

            TabButton {
                anchors {
                    top: parent.top;
                    bottom: parent.bottom;
                }
                text: "Правила";
            }

            TabButton {
                anchors {
                    top: parent.top;
                    bottom: parent.bottom;
                }
                text: "Переменные";
            }

            TabButton {
                anchors {
                    top: parent.top;
                    bottom: parent.bottom;
                }
                text: "Домены";
            }
        }

        Rectangle {
            id: consultButton;
            anchors {
                top: parent.top;
                bottom: parent.bottom;
                left: bar.right;
                right: parent.right;
                margins: 5;
            }


            height: 50;
            width: ;
            color: "#2D2B2B";
            radius: 5;

            CustomText {
                anchors.fill: parent;
                text: "Консультация"
                pixelSize: 28;
            }
        }
    }



    StackLayout {
        id: stackLayout;
        width: parent.width;
        height: parent.height / 1.5;
        currentIndex: bar.currentIndex
        anchors.top: headerRect.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;

        CustomText {
            text: "t1";
            pixelSize: 54;
        }

        CustomText {
            text: "t2";
            pixelSize: 54;
        }

        CustomText {
            text: "t3";
            pixelSize: 54;
        }
    }


}
