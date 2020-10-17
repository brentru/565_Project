#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

//Qt Includes
#include <QObject>
#include <QMap>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomText>

//Project Includes
#include "GlobalTypes.h"
#include "TCPHandler.h"

class MessageHandler : public QObject
{
    Q_OBJECT
public:
    explicit MessageHandler(QObject *parent = nullptr);
    static MessageHandler* getGlobalInstance();
    void sendMessage(TxMessage messageMap);
    QString transmitMapToXML(TxMessage messageMap);
    static TxMessage createTransmitMap(int id);

public slots:
    void handleTCPData(QByteArray newData);

signals:
    void newMessageAvailable(RxMessage msg);

private:
    struct ClassHook{
        void *context;
        void (*pFcn)(void *fcnContext, RxMessage data);
    };

    TCPHandler *tcp = nullptr;
    bool debuggingEnabled = false;
    QByteArray dataBuffer;

    RxMessage receivedXMLToMap(QString xml);
    void handoffMessage(RxMessage msg);
    void filterMessagesFromBuffer();
    int getIDFromNode(QDomElement root);
    void getDataFromNode(QDomElement root, RxMessage &map);
    void debugMessage(QString message);
};

static MessageHandler *globalMessageHandler = nullptr;

#endif // MESSAGEHANDLER_H
