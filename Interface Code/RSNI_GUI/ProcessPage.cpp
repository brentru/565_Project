#include "ProcessPage.h"
#include "ui_ProcessPage.h"

#include <QDebug>

ProcessPage::ProcessPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProcessPage)
{
    ui->setupUi(this);

    //Enable debugging
    debuggingEnabled = true;

    //Initialize sensors
    initializeSensorList();

    //Create the message handler
    msgHandler = MessageHandler::getGlobalInstance();
    connect(msgHandler, SIGNAL(newMessageAvailable(RxMessage)), this, SLOT(processMessage(RxMessage)));

    //Connect to the TCP Handler's status changed, so we know when a new device is connected
    TCPHandler *tcp = TCPHandler::getGlobalInstance();
    connect(tcp, SIGNAL(TCPStatusChanged(bool)), this, SLOT(resetProcesses()));

    debugMessage("Initialized");
}

ProcessPage::~ProcessPage()
{
    delete ui;
}

void ProcessPage::initializeSensorList()
{
    //We are currently just assuming the sensor IDs.
    //We may include a method for getting a list of sensor IDs in the future.
    sensors.append(Sensor(1, "Temperature Sensor"));
    sensors.append(Sensor(2, "Humidity Sensor"));
    sensors.append(Sensor(3, "CPU Usage"));
    sensors.append(Sensor(4, "CPU Temp"));
    sensors.append(Sensor(5, "Dummy Sensor"));

    //Refresh the combo box to show all the new sensors
    refreshSensorComboBox();
}

void ProcessPage::on_StartSensorButton_released()
{
    //Grab the sensor ID
    int sensorID = getComboboxSensor().sensorID;
    if(sensorID != -1){
        //Grab the parameters
        int messageID = Messages::StartProcessID;

        //Construct the transmit map
        TxMessage messageMap = MessageHandler::createTransmitMap(messageID);
        messageMap[1].name = "sensorid";
        messageMap[1].dataType = "uint8_t";
        messageMap[1].value = QString::number(sensorID);

        //Send the message
        msgHandler->sendMessage(messageMap);
    }
    else{
        debugMessage("Failed to grab sensor ID");
    }
}

void ProcessPage::processMessage(RxMessage msg)
{
    int id = msg["id"].value.toInt();
    switch(id){
        case Messages::StartProcessResponseID:
            cb_startProcessResponse(msg);
            break;
        case Messages::KillProcessResponseID:
            cb_killProcessResponse(msg);
            break;
        case Messages::ResetProcessResponseID:
            cb_resetProcessResponse(msg);
            break;
        case Messages::PauseProcessResponseID:
            cb_pauseProcessResponse(msg);
            break;
        case Messages::ProcessStatusResponseID:
            cb_processStatusResponse(msg);
            break;
        case Messages::ResumeProcessResponseID:
            cb_processResumeResponse(msg);
            break;
        default:
            //We don't care about this message
            break;
    }
}

void ProcessPage::resetProcesses()
{
    for(int i = 0; i < sensors.size(); i++){
        Sensor s = sensors[i];
        s.PID = -1;
        s.inUse = false;
        s.value = "N/A";
        s.isRunning = false;
        sensors[i] = s;
    }

    this->refreshSensorComboBox();
    this->refreshTable();
}

void ProcessPage::stopProcessButtonPressed(int sensorID)
{
    debugMessage("Killing sensor (" + QString::number(sensorID) + ")");
    TxMessage msg;
    msg[0].name = "id";
    msg[0].dataType = "uint8_t";
    msg[0].value = QString::number(Messages::KillProcessID);

    //Get the sensor
    int sensorIdx = getSensorIdx(sensorID);
    if(sensorIdx >= 0){
        Sensor sensor = sensors[sensorIdx];

        msg[1].name = "pid";
        msg[1].dataType = "uint32_t";
        msg[1].value = QString::number(sensor.PID);

        msgHandler->sendMessage(msg);
    }
}

void ProcessPage::pauseProcessButtonPressed(int sensorID)
{
    int sensorIdx = getSensorIdx(sensorID);
    if(sensorIdx >= 0){
        Sensor sensor = sensors[sensorIdx];
        TxMessage msg;
        msg[0].name = "id";
        msg[0].dataType = "uint8_t";

        if(sensor.isRunning){
            //Pause
            debugMessage("Pausing sensor (" + QString::number(sensorID) + ")");
            msg[0].value = QString::number(Messages::PauseProcessID);
        }
        else{
            //Resume
            debugMessage("Resuming sensor (" + QString::number(sensorID) + ")");
            msg[0].value = QString::number(Messages::ResumeProcessID);
        }

        msg[1].name = "pid";
        msg[1].dataType = "uint32_t";
        msg[1].value = QString::number(sensor.PID);

        msgHandler->sendMessage(msg);
    }
}

void ProcessPage::resetProcessButtonPressed(int sensorID)
{
    debugMessage("Resetting sensor (" + QString::number(sensorID) + ")");
    TxMessage msg;
    msg[0].name = "id";
    msg[0].dataType = "uint8_t";
    msg[0].value = QString::number(Messages::ResetProcessID);

    //Get the sensor
    int sensorIdx = getSensorIdx(sensorID);
    if(sensorIdx >= 0){
        Sensor sensor = sensors[sensorIdx];

        msg[1].name = "pid";
        msg[1].dataType = "uint32_t";
        msg[1].value = QString::number(sensor.PID);

        msgHandler->sendMessage(msg);
    }
}

void ProcessPage::requestStatusProcessButtonPressed(int sensorID)
{
    debugMessage("Requesting status of sensor (" + QString::number(sensorID) + ")");
    TxMessage msg;
    msg[0].name = "id";
    msg[0].dataType = "uint8_t";
    msg[0].value = QString::number(Messages::ProcessStatusID);

    //Get the sensor
    int sensorIdx = getSensorIdx(sensorID);
    if(sensorIdx >= 0){
        Sensor sensor = sensors[sensorIdx];

        msg[1].name = "pid";
        msg[1].dataType = "uint32_t";
        msg[1].value = QString::number(sensor.PID);

        msgHandler->sendMessage(msg);
    }
}

void ProcessPage::refreshSensorComboBox()
{
    ui->SensorComboBox->clear();

    for(int i = 0; i < sensors.size(); i++){
        if(!sensors[i].inUse){
            ui->SensorComboBox->addItem(sensors[i].name);
        }
    }
}

void ProcessPage::refreshTable()
{
    //Empty the table
    ui->ProcessTable->setRowCount(0);

    //For each sensor in use create a row
    for(Sensor s : sensors){
        if(s.inUse){
            int nRows = ui->ProcessTable->rowCount();
            ui->ProcessTable->insertRow(nRows);

            //Populate the data fields
            QString isRunningText = s.isRunning ? "Running" : "Paused";
            setCellText(nRows, SENSOR_NAME_COLUMN, s.name);
            setCellText(nRows, SENSOR_ID_COLUMN, QString::number(s.sensorID));
            setCellText(nRows, SENSOR_PID_COLUMN, QString::number(s.PID));
            setCellText(nRows, SENSOR_VAL_COLUMN, s.value);
            setCellText(nRows, SENSOR_STATUS_COLUMN, isRunningText);

            //Create each button
            TablePushButton *killButton = new TablePushButton(s.sensorID, "Stop");
            connect(killButton, SIGNAL(buttonReleased(int)), this, SLOT(stopProcessButtonPressed(int)));
            ui->ProcessTable->setCellWidget(nRows,SENSOR_STOP_COLUMN,killButton);

            QString pauseButtonText = s.isRunning ? "Pause" : "Resume";
            TablePushButton *pauseButton = new TablePushButton(s.sensorID, pauseButtonText);
            connect(pauseButton, SIGNAL(buttonReleased(int)), this, SLOT(pauseProcessButtonPressed(int)));
            ui->ProcessTable->setCellWidget(nRows,SENSOR_PAUSE_COLUMN,pauseButton);

            TablePushButton *resetButton = new TablePushButton(s.sensorID, "Reset");
            connect(resetButton, SIGNAL(buttonReleased(int)), this, SLOT(resetProcessButtonPressed(int)));
            ui->ProcessTable->setCellWidget(nRows,SENSOR_RESTART_COLUMN,resetButton);

            TablePushButton *pollButton = new TablePushButton(s.sensorID, "Poll");
            connect(pollButton, SIGNAL(buttonReleased(int)), this, SLOT(requestStatusProcessButtonPressed(int)));
            ui->ProcessTable->setCellWidget(nRows,SENSOR_POLL_COLUMN,pollButton);
        }
    }
}

ProcessPage::Sensor ProcessPage::getComboboxSensor()
{
    Sensor sensor;

    //Get the combobox text and check if it is in the existing sensors.
    QString sensorName = ui->SensorComboBox->currentText();
    for(int i = 0; i < sensors.size(); i++){
        if(sensorName == sensors[i].name){
            sensor = sensors[i];
            break;
        }
    }

    return sensor;
}

int ProcessPage::getSensorIdx(int sensorID)
{
    int idx = -1;

    for(int i = 0; i < sensors.size(); i++){
        if(sensors[i].sensorID == sensorID){
            idx = i;
            break;
        }
    }

    return idx;
}

int ProcessPage::getSensorIdxByPID(uint32_t pid)
{
    int idx = -1;

    for(int i = 0; i < sensors.size(); i++){
        if(sensors[i].PID == pid){
            idx = i;
            break;
        }
    }

    return idx;
}

void ProcessPage::setCellText(int row, int col, QString txt)
{
    ui->ProcessTable->setItem(row, col, new QTableWidgetItem(txt));
}

void ProcessPage::debugMessage(QString message)
{
    if(debuggingEnabled){
        qDebug() << "Process Page: " + message;
    }
}

void ProcessPage::cb_startProcessResponse(RxMessage msg)
{
    int sensorID = msg["sensorid"].value.toInt();
    int result = msg["result"].value.toInt();
    uint32_t pid = msg["pid"].value.toUInt();

    debugMessage("New sensor process started (" + QString::number(sensorID) + ")");

    if(result){
        //New process has been spawned. Record its PID and mark it as in use
        int sensorIdx = getSensorIdx(sensorID);

        //If the sensor does not exist, create a new entry
        if(sensorIdx < 0){
            Sensor sensor(sensorID, "Sensor " + QString::number(sensorID));
            sensors.append(sensor);
            sensorIdx = sensors.size() - 1;
        }

        //Set the sensor to in use
        sensors[sensorIdx].inUse        = true;
        sensors[sensorIdx].PID          = pid;
        sensors[sensorIdx].isRunning    = true;

        //Update the GUI
        refreshSensorComboBox();
        refreshTable();
    }
    else{
        debugMessage("Process failed to start with sensor ID " + QString::number(sensorID));
    }
}

void ProcessPage::cb_killProcessResponse(RxMessage msg)
{
    //Get the result
    int result = msg["result"].value.toInt();

    if(result){
        //Get the sensor ID
        int pid = msg["pid"].value.toInt();
        int sensorIdx = getSensorIdxByPID(pid);
        if(sensorIdx >= 0){
            //Set the sensors state to not in use
            sensors[sensorIdx].inUse = false;
            sensors[sensorIdx].value = "N/A";

            //Refresh the GUI
            refreshSensorComboBox();
            refreshTable();
        }
    }
}

void ProcessPage::cb_pauseProcessResponse(RxMessage msg)
{
    //Grab the PID and result
    int pid = msg["pid"].value.toInt();
    int result = msg["result"].value.toInt();

    if(result){
        int sensorIdx = getSensorIdxByPID(pid);
        if(sensorIdx >= 0){
            //Update the sensor
            sensors[sensorIdx].isRunning = false;

            //Refresh the GUI
            refreshTable();
        }
    }
}

void ProcessPage::cb_resetProcessResponse(RxMessage msg)
{
    //Grab the PID and result
    int oldPID = msg["oldpid"].value.toInt();
    int result = msg["result"].value.toInt();

    if(result){
        int sensorIdx = getSensorIdxByPID(oldPID);
        if(sensorIdx >= 0){
            //Get the new PID
            int newPID = msg["pid"].value.toInt();

            //Update the sensor
            sensors[sensorIdx].PID = newPID;
            sensors[sensorIdx].isRunning = true;

            //Refresh the GUI
            refreshTable();
        }
    }
}

void ProcessPage::cb_processStatusResponse(RxMessage msg)
{
    //Get sensor ID
    int pid = msg["pid"].value.toInt();
    int sensorIdx = getSensorIdxByPID(pid);
    if(sensorIdx >= 0){
        //Set the new value
        QString val = msg["value"].value;
        sensors[sensorIdx].value = val;

        //Refresh the GUI
        refreshTable();
    }
}

void ProcessPage::cb_processResumeResponse(RxMessage msg)
{
    //Get sensor ID
    int pid = msg["pid"].value.toInt();
    int result = msg["result"].value.toInt();
    int sensorIdx = getSensorIdxByPID(pid);
    if(sensorIdx >= 0 && result){
        //Update the status
        sensors[sensorIdx].isRunning = true;

        //Refresh the GUI
        refreshTable();
    }
}
