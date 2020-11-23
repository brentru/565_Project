/*
 * File: GlobalTypes.h
 * Author: Todd Morehouse
 * Description
 *  Header file containing global data type definitions.
 */

#ifndef GLOBALTYPES_H
#define GLOBALTYPES_H

//Qt Includes
#include <QString>
#include <QMetaType>

struct MessageField{
    QString name = "Empty Message Field";
    QString dataType = "uint8_t";
    QString value = "0";
};

typedef QMap<QString, MessageField> RxMessage;
typedef QMap<int, MessageField> TxMessage;

Q_DECLARE_METATYPE(MessageField);

void initGlobalTypes();

#endif // GLOBALTYPES_H
