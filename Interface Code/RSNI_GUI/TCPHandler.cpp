#include "TCPHandler.h"

#include <QDebug>

TCPHandler::TCPHandler(QObject *parent) : QObject(parent)
{
    //Enable debugging
    debugEnabled = true;

    //Initialize the timeout timer
    tcpTimeoutTimer = new QTimer(this);
    connect(tcpTimeoutTimer, SIGNAL(timeout()), this, SLOT(handleTCPTimeout()));

    //Initialize the socket
    socket = new QTcpSocket(this);

    //Connect all "connected" signals
    connect(socket, SIGNAL(connected()), this, SLOT(handleTCPConnect()));

    //Connect all "disconnected" signals
    connect(socket, SIGNAL(disconnected()), this, SLOT(handleTCPDisconnect()));

    //Connect data read
    connect(socket, SIGNAL(readyRead()), this, SLOT(readData()));

    debugMessage("Initialized");
}

TCPHandler *TCPHandler::getGlobalInstance()
{
    //If the global variable has not been instantiated, then do it
    if(!globalTCPHandler){
        globalTCPHandler = new TCPHandler();
    }

    return globalTCPHandler;
}

bool TCPHandler::isConnected()
{
    if(socket->state() == QAbstractSocket::ConnectedState){
        return true;
    }
    else{
        return false;
    }
}

void TCPHandler::connectToSocket(QString IPAddress, int port)
{
    debugMessage("Connecting to " + IPAddress + ", " + QString::number(port));
    startTimeoutTimer();
    socket->connectToHost(IPAddress, port);
}

void TCPHandler::disconnectFromSocket()
{
    debugMessage("Disconnecting from socket");
    socket->disconnectFromHost();
}

void TCPHandler::sendData(QByteArray data)
{
    if(isConnected()){
        socket->write(data);
    }

    //Loopback text if enabled
    //Do this regardless of connection status, since it allows debugging offline
    if(loopbackEnabled){
        emit newDataAvailable(data);
    }
}

void TCPHandler::handleTCPConnect()
{
    debugMessage("Socket connected");
    isTCPConnecting = false;
    emit TCPStatusChanged(true);
}

void TCPHandler::handleTCPDisconnect()
{
    debugMessage("Socket disconnected");
    isTCPConnecting = false;
    emit TCPStatusChanged(false);
}

void TCPHandler::enableLoopback(bool state)
{
    this->loopbackEnabled = state;
}

void TCPHandler::readData()
{
    QByteArray data = socket->readAll();

    emit newDataAvailable(data);
}

void TCPHandler::handleTCPTimeout()
{
    //If we were in the middle of trying to connect to TCP, timeout the connection.
    if(this->isTCPConnecting){
        socket->disconnectFromHost();
        emit TCPStatusChanged(false);
        debugMessage("TCP connection timed out.");
    }
    tcpTimeoutTimer->stop();
}

void TCPHandler::startTimeoutTimer()
{
    //Start the timeout timer and set the tracking variable
    isTCPConnecting = true;
    tcpTimeoutTimer->start(TCP_TIMEOUT_PERIOD);
}

void TCPHandler::debugMessage(QString message)
{
    if(debugEnabled){
        qDebug() << "TCPHandler: " << message;
    }
}
