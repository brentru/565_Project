#include "MessageHandler.h"

#include <QDebug>

MessageHandler::MessageHandler(QObject *parent) : QObject(parent)
{
    //Enable debugging
    debuggingEnabled = true;

    //Get an instance to the tcp handler
    tcp = TCPHandler::getGlobalInstance();
    connect(tcp, SIGNAL(newDataAvailable(QByteArray)), this, SLOT(handleTCPData(QByteArray)));

    debugMessage("Initialized");
}

MessageHandler *MessageHandler::getGlobalInstance()
{
    if(!globalMessageHandler){
        globalMessageHandler = new MessageHandler();
    }

    return globalMessageHandler;
}

/*
 * Converts a transmit message map into XML and transmits it over the TCP socket
 *
 * For transmitting, the map must be indexed by an integer, so that no prior information
 *  about the structure of the map is needed.
 */
void MessageHandler::sendMessage(TxMessage messageMap)
{
    //Convert message to XML
    QString xml = transmitMapToXML(messageMap);

    //Send message over TCP
    debugMessage("Sending message...");
    tcp->sendData(xml.toUtf8());
}

QString MessageHandler::transmitMapToXML(TxMessage messageMap)
{
    QString xml = "";

    //Create the base document structure the xml
    QDomDocument doc;

    //Create the root element <message>
    QDomElement root = doc.createElement("message");
    doc.appendChild(root);

    //Create the ID element, use a text node to set the value, and append it to the root
    QDomElement idElement = doc.createElement("id");
    QDomText textNode = doc.createTextNode(messageMap[0].value);
    idElement.appendChild(textNode);
    root.appendChild(idElement);

    //Add each data element
    for(int i = 1; i < messageMap.size(); i++){
        QDomElement parameter = doc.createElement("data");
        parameter.setAttribute("type", messageMap[i].dataType);
        parameter.setAttribute("name", messageMap[i].name);

        //Create a QDomText to be the value inside the
        QDomText textNode = doc.createTextNode(messageMap[i].value);
        parameter.appendChild(textNode);

        root.appendChild(parameter);
    }

    //Convert to a string
    xml = doc.toString();

    return xml;
}

TxMessage MessageHandler::createTransmitMap(int id)
{
    TxMessage messageMap;
    messageMap[0].name = "id";
    messageMap[0].value = QString::number(id);
    messageMap[0].dataType = "uint8_t";
    return messageMap;
}

void MessageHandler::handleTCPData(QByteArray newData)
{
    //Buffer new data
    dataBuffer.append(newData);

    //Filter out any messages from the buffer
    filterMessagesFromBuffer();
}

RxMessage MessageHandler::receivedXMLToMap(QString xml)
{
    RxMessage map;

    //Convert the xml text to a document
    QDomDocument doc;
    if(doc.setContent(xml)){
        QDomElement root = doc.firstChildElement();

        int id = getIDFromNode(root);
        map["id"].name = "ID";
        map["id"].value = QString::number(id);
        map["id"].dataType = "uint8_t";

        if(id >= 0){
            //Grab each data field and store in the map
            getDataFromNode(root, map);
        }
        else{
            debugMessage("Failed to decode XML.");
        }

    }
    else{
        debugMessage("Failed to set document by text " + xml);
    }

    return map;
}

void MessageHandler::handoffMessage(RxMessage msg)
{
    debugMessage("New message distributed.");
    emit newMessageAvailable(msg);
}

void MessageHandler::filterMessagesFromBuffer()
{
    while(dataBuffer.contains("<message>") && dataBuffer.contains("</message>")){
        //Get the index of the first message
        int idx = dataBuffer.indexOf("<message>");

        //Remove everything in the buffer up until this message
        dataBuffer.remove(0,idx);
        idx = 0;

        //Get the index of the end of the first message. Add the number of characters to be at the end
        int idx2 = dataBuffer.indexOf("</message>") + QString("</message>").size();

        //Extract the message string
        QString messageString = dataBuffer.left(idx2);
        messageString.chop(idx);

        //Remove the message string from the buffer
        dataBuffer.remove(idx, messageString.size());

        //If the next occurence is a newline, remove that too. Some messages will end with newlines
        if(dataBuffer.indexOf("\n") == 0){
            dataBuffer.remove(0,1);
        }

        //Convert the message to an XML map
        RxMessage map = receivedXMLToMap(messageString);

        //Ship off the message
        handoffMessage(map);
    }
}

int MessageHandler::getIDFromNode(QDomElement root)
{
    int id = -1;

    //Retrieve the ID node
    QDomNodeList idNodeList = root.elementsByTagName("id");
    if(idNodeList.size() > 0){
        QDomNode node = idNodeList.at(0);
        if(node.isElement()){
            QDomElement idElem = node.toElement();
            QString idStr = idElem.text();
            id = idStr.toInt();
        }
        else{
            debugMessage("Get ID Error: ID node is corrupted.");
        }
    }
    else{
        debugMessage("Get ID Error: No ID node detected.");
    }

    return id;
}

void MessageHandler::getDataFromNode(QDomElement root, RxMessage &map)
{
    //Get a list of all data nodes
    QDomNodeList nodeList = root.elementsByTagName("data");

    for(int i = 0; i < nodeList.size(); i++){
        if(nodeList.at(i).isElement()){
            QDomElement elem = nodeList.at(i).toElement();
            QString datatype = elem.attribute("type", "CORRUPTED");
            QString name = elem.attribute("name", "CORRUPTED");
            QString value = elem.text();

            MessageField field;
            field.name = name;
            field.value = value;
            field.dataType = datatype;

            map[name] = field;
        }
    }
}

void MessageHandler::debugMessage(QString message)
{
    if(debuggingEnabled){
        qDebug() << "Message Handler: " << message;
    }
}
