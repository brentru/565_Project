/*
 * File: ProcessPage.h
 * Author: Todd Morehouse
 * Description
 *  Class for creating and handling the GUI for the process page.
 */

#ifndef PROCESSPAGE_H
#define PROCESSPAGE_H

//Qt includes
#include <QWidget>

#define SENSOR_NAME_COLUMN      0
#define SENSOR_ID_COLUMN        1
#define SENSOR_PID_COLUMN       2
#define SENSOR_VAL_COLUMN       3
#define SENSOR_STATUS_COLUMN    4
#define SENSOR_STOP_COLUMN      5
#define SENSOR_PAUSE_COLUMN     6
#define SENSOR_RESTART_COLUMN   7
#define SENSOR_POLL_COLUMN      8

//Project includes
#include "GlobalTypes.h"
#include "MessageHandler.h"
#include "Messages.h"
#include "TablePushButton.h"
#include "TCPHandler.h"

namespace Ui {
class ProcessPage;
}

class ProcessPage : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessPage(QWidget *parent = nullptr);
    ~ProcessPage();

    void initializeSensorList();

public slots:
    void processMessage(RxMessage msg);
    void resetProcesses();

private slots:
    void stopProcessButtonPressed(int sensorID);
    void pauseProcessButtonPressed(int sensorID);
    void resetProcessButtonPressed(int sensorID);
    void requestStatusProcessButtonPressed(int sensorID);

private slots:
    void on_StartSensorButton_released();

private:
    struct Sensor{
        Sensor(){
            this->sensorID = -1;
            this->name = "Undefined Sensor";
        }

        Sensor(int id, QString name){
            this->sensorID = id;
            this->name = name;
        }

        int sensorID            = -1;
        uint32_t PID            = -1;
        QString name            = "Undefined Sensor";
        bool inUse              = false;
        bool isRunning          = false;
        QString value           = "N/A";
    };

    Ui::ProcessPage *ui;
    MessageHandler *msgHandler = nullptr;
    bool debuggingEnabled = true;
    QList<Sensor> sensors;

    void refreshSensorComboBox();
    void refreshTable();
    Sensor getComboboxSensor();
    int getSensorIdx(int sensorID);
    int getSensorIdxByPID(uint32_t pid);
    void setCellText(int row, int col, QString txt);
    void debugMessage(QString message);

    //Message callbacks
    void cb_startProcessResponse(RxMessage msg);
    void cb_killProcessResponse(RxMessage msg);
    void cb_pauseProcessResponse(RxMessage msg);
    void cb_resetProcessResponse(RxMessage msg);
    void cb_processStatusResponse(RxMessage msg);
    void cb_processResumeResponse(RxMessage msg);
};

#endif // PROCESSPAGE_H
