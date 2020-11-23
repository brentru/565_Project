/*
 * File: ConnectionPage.h
 * Author: Todd Morehouse
 * Description
 *  This class handles displaying the connection page GUI, as well as handling user input from the GUI.
 */

#ifndef CONNECTIONPAGE_H
#define CONNECTIONPAGE_H

//Qt Includes
#include <QWidget>
#include <QDateTime>

//Project includes
#include "TCPHandler.h"

namespace Ui {
class ConnectionPage;
}

class ConnectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionPage(QWidget *parent = nullptr);
    ~ConnectionPage();

public slots:
    void handleTCPStatusChange(bool isConnected);
    void handleNewTCPData(QByteArray data);

private slots:
    void on_ConnectButton_released();

    void on_RawTextSend_released();

    void on_LoopbackCheck_released();

private:
    Ui::ConnectionPage *ui;
    TCPHandler* tcp = nullptr;

    bool debugEnabled = false;

    void tcpConnect();
    void tcpDisconnect();

    void debugMessage(QString message);
};

#endif // CONNECTIONPAGE_H
