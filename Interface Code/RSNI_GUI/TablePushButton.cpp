#include "TablePushButton.h"

TablePushButton::TablePushButton(int sensorID, QString txt)
{
    this->sensorID = sensorID;
    connect(this, SIGNAL(released()), this, SLOT(internalButtonHandler()));
    this->setText(txt);

    //Style it
    QString style = ""
                    "TablePushButton{"
                    "   background-color: rgb(225,225,225);"
                    "   color: black;"
                    "   border-color: gray;"
                    "   border-style: solid;"
                    "   border-width: 1px;"
                    "   font: bold;"
                    "   max-width: 60px;"
                    "   padding: 6px;"
                    "   margin-left: 10px;"
                    "   margin-right: 10px;"
                    "   margin-top: 2px;"
                    "   margin-bottom: 2px;"
                    "   opacity: 1;"
                    "}"
                    ""
                    "TablePushButton:hover{"
                    "   border-color: black;"
                    "}"
                    ""
                    "TablePushButton:pressed{"
                    "   background-color: rgb(200,200,200);"
                    "}";

    this->setStyleSheet(style);
}

void TablePushButton::internalButtonHandler()
{
    emit buttonReleased(sensorID);
}
