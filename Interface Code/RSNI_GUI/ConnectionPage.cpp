#include "ConnectionPage.h"
#include "ui_ConnectionPage.h"

#include <QDebug>

ConnectionPage::ConnectionPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionPage)
{
    ui->setupUi(this);

    //Enable debug messages
    debugEnabled = true;

    //Grab an instance of the TCP Handler
    this->tcp = TCPHandler::getGlobalInstance();
    connect(tcp, SIGNAL(TCPStatusChanged(bool)), this, SLOT(handleTCPStatusChange(bool)));
    connect(tcp, SIGNAL(newDataAvailable(QByteArray)), this, SLOT(handleNewTCPData(QByteArray)));

    //Default status to disconnected
    handleTCPStatusChange(false);

    //Debugging
    ui->LoopbackCheck->setChecked(true);
    tcp->enableLoopback(true);
    debugMessage("Initialized");
}

ConnectionPage::~ConnectionPage()
{
    delete ui;
}

void ConnectionPage::handleTCPStatusChange(bool isConnected)
{
    if(isConnected){
        ui->ConnectButton->setText("Disconnect");
        ui->StatusLabel->setText("Connected");
        ui->StatusLabel->setStyleSheet("color: green;");
        debugMessage("TCP Status Change, connected");
    }
    else{
        ui->ConnectButton->setText("Connect");
        ui->StatusLabel->setText("Disconnected");
        ui->StatusLabel->setStyleSheet("color: red;");
        debugMessage("TCP Status Change, disconnected");
    }
}

void ConnectionPage::handleNewTCPData(QByteArray data)
{
    QDateTime local(QDateTime::currentDateTime());

    QString hr = QString::number(local.time().hour());
    QString min = QString::number(local.time().minute());
    QString sec = QString::number(local.time().second());

    //Append extra zeros if needed to ensure even padding.
    if(local.time().hour() < 10){
        hr  = "0" + hr;
    }

    if(local.time().minute() < 10){
        min = "0" + min;
    }

    if(local.time().second() < 10){
        sec = "0" + sec;
    }

    QString timestamp = hr + ":" + min + ":" + sec;

    QString msgText = timestamp + ":\t" + data;
    ui->IncomingText->append(msgText);
}

void ConnectionPage::on_ConnectButton_released()
{
    if(tcp->isConnected()){
        ui->ConnectButton->setText("Connecting");
        tcpDisconnect();
    }
    else{
        ui->ConnectButton->setText("Disconnecting");
        tcpConnect();
    }
}

void ConnectionPage::tcpConnect()
{
    debugMessage("Attempting connection...");
    QString ipaddr = ui->IPAddressInput->text();
    int port = ui->PortInput->value();
    tcp->connectToSocket(ipaddr, port);
}

void ConnectionPage::tcpDisconnect()
{
    debugMessage("Attempting to disconnect...");
    tcp->disconnectFromSocket();
}

void ConnectionPage::debugMessage(QString message)
{
    if(debugEnabled){
        qDebug() << "Connection Page: " << message;
    }
}

void ConnectionPage::on_RawTextSend_released()
{
    QString txt = ui->RawTextInput->text();
    debugMessage("Sending " + txt);
    tcp->sendData(txt.toUtf8());
}

void ConnectionPage::on_LoopbackCheck_released()
{
    bool state = ui->LoopbackCheck->isChecked();
    tcp->enableLoopback(state);
}
