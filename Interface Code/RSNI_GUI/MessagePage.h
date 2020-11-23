/*
 * File: MessagePage.h
 * Author: Todd Morehouse
 * Description
 *  The class for creating, displaying, and handling the message page gui.
 */

#ifndef MESSAGEPAGE_H
#define MESSAGEPAGE_H

//Qt Includes
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QComboBox>

//Project Includes
#include "GlobalTypes.h"
#include "MessageHandler.h"

namespace Ui {
class MessagePage;
}

class MessagePage : public QWidget
{
    Q_OBJECT

public:
    explicit MessagePage(QWidget *parent = nullptr);
    ~MessagePage();

private slots:
    void on_AddFieldButton_released();

    void on_RemoveFieldButton_released();

    void on_SendMessageButton_released();

private:
    Ui::MessagePage *ui;
    bool debugEnabled = false;
    MessageHandler *msgHandler = nullptr;

    void debugMessage(QString message);
    QComboBox* createDatatypeBox();
    QString getRowDatatype(int row);
    void setCellText(int row, int col, QString txt);
};

#endif // MESSAGEPAGE_H
