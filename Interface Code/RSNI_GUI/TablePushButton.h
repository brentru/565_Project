/*
 * File: TablePushButton.h
 * Author: Todd Morehouse
 * Description
 *  A custom implementation of QPushButton specifically to be used in a table. This adds an identifier
 *  to a push button, and a signal that relays this ID when the button is released.
 */

#ifndef TABLEPUSHBUTTON_H
#define TABLEPUSHBUTTON_H

#include <QPushButton>


class TablePushButton : public QPushButton
{
    Q_OBJECT
public:
    TablePushButton(int sensorID, QString txt);

signals:
    void buttonReleased(int sensorID);

private slots:
    void internalButtonHandler();

private:
    int sensorID = -1;
};

#endif // TABLEPUSHBUTTON_H
