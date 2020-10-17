#include "MessagePage.h"
#include "ui_MessagePage.h"

#include <QDebug>

MessagePage::MessagePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessagePage)
{
    //Enable debugging
    debugEnabled = true;

    //Setup UI
    ui->setupUi(this);

    //Message Handler
    msgHandler = MessageHandler::getGlobalInstance();

    debugMessage("Initialized");
}

MessagePage::~MessagePage()
{
    delete ui;
}

void MessagePage::on_AddFieldButton_released()
{
    debugMessage("Inserting new row.");
    int nRows = ui->FieldTableWidget->rowCount();
    ui->FieldTableWidget->insertRow(nRows);

    //Initialize the name and value fields to empty strings
    setCellText(nRows, 0, "");
    setCellText(nRows, 2, "");

    //Initialize the data type field
    QComboBox *combobox = createDatatypeBox();
    ui->FieldTableWidget->setCellWidget(nRows,1,combobox);
}

void MessagePage::debugMessage(QString message)
{
    if(debugEnabled){
        qDebug() << "Message Page: " << message;
    }
}

QComboBox *MessagePage::createDatatypeBox()
{
    QComboBox *box = new QComboBox();
    box->addItem("uint8_t");
    box->addItem("uint16_t");
    box->addItem("uint32_t");
    box->addItem("string");
    box->addItem("float32");
    return box;
}

QString MessagePage::getRowDatatype(int row)
{
    QString str = "";

    auto box = dynamic_cast<QComboBox*>(ui->FieldTableWidget->cellWidget(row, 1));
    str = box->currentText();

    return str;
}

void MessagePage::setCellText(int row, int col, QString txt)
{
    ui->FieldTableWidget->setItem(row, col, new QTableWidgetItem(txt));
}

void MessagePage::on_RemoveFieldButton_released()
{
    int row = ui->FieldTableWidget->currentRow();

    if(row >= 0){
        debugMessage("Removing row" + QString::number(row));
        ui->FieldTableWidget->removeRow(row);
    }
}

void MessagePage::on_SendMessageButton_released()
{
    //Debug
    debugMessage("Sending message.");

    //Construct the message map
    //For transmit, the map must be indexed by an integer so that
    // all fields can be known without knowing any prior information
    // about the message.
    TxMessage map;

    //Store message id
    int id = ui->MessageIDInput->value();
    map[0].name = "id";
    map[0].value = QString::number(id);
    map[0].dataType = "uint8_t";

    //Store each data field
    for(int i = 0; i < ui->FieldTableWidget->rowCount(); i++){
        QString name = ui->FieldTableWidget->item(i, 0)->text();
        QString dataType = getRowDatatype(i);
        QString value = ui->FieldTableWidget->item(i, 2)->text();
        map[i + 1].name = name;
        map[i + 1].dataType = dataType;
        map[i + 1].value = value;
    }

    //Send the message handler
    msgHandler->sendMessage(map);
}
