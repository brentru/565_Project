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
