/*
 * File: TCPHandler.h
 * Author: Todd Morehouse
 * Description
 *  A singleton class that will handle all communication over a TCP socket. This class is intended
 *  to be used as the only way to communicate over TCP.
 */
#ifndef TCPHANDLER_H
#define TCPHANDLER_H

#define TCP_TIMEOUT_PERIOD      5000    //Time in milliseconds to attempt tcp connection before timeout

//Qt Includes
#include <QObject>
#include <QTcpSocket>
#include <QTimer>

//Project includes

/*
 * This class is designed to be used as a singleton. You can instantiate multiple copies of it,
 * however it would be better to use it as a singleton so that a single TCP socket can be shared
 * across multiple classes easily.
 */

class TCPHandler : public QObject
{
    Q_OBJECT
public:
    explicit TCPHandler(QObject *parent = nullptr);

    static TCPHandler* getGlobalInstance();

    bool isConnected();
    void connectToSocket(QString IPAddress, int port);
    void disconnectFromSocket();
    void sendData(QByteArray data);

signals:
    void TCPStatusChanged(bool isConnected);
    void newDataAvailable(QByteArray data);

public slots:
    void handleTCPConnect();
    void handleTCPDisconnect();
    void enableLoopback(bool state);

private slots:
    void readData();
    void handleTCPTimeout();

private:
    QTcpSocket *socket      = nullptr;
    bool debugEnabled       = false;
    QTimer *tcpTimeoutTimer = nullptr;
    bool isTCPConnecting    = false;
    bool loopbackEnabled    = false;

    void startTimeoutTimer();
    void debugMessage(QString message);

};

static TCPHandler* globalTCPHandler = nullptr;
#endif // TCPHANDLER_H
