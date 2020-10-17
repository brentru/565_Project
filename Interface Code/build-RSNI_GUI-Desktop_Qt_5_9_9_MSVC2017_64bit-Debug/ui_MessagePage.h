/********************************************************************************
** Form generated from reading UI file 'MessagePage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEPAGE_H
#define UI_MESSAGEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessagePage
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTableWidget *FieldTableWidget;
    QPushButton *RemoveFieldButton;
    QPushButton *SendMessageButton;
    QPushButton *AddFieldButton;
    QSpinBox *MessageIDInput;

    void setupUi(QWidget *MessagePage)
    {
        if (MessagePage->objectName().isEmpty())
            MessagePage->setObjectName(QStringLiteral("MessagePage"));
        MessagePage->resize(628, 470);
        gridLayout = new QGridLayout(MessagePage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(MessagePage);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        FieldTableWidget = new QTableWidget(MessagePage);
        if (FieldTableWidget->columnCount() < 3)
            FieldTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        FieldTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        FieldTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        FieldTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        FieldTableWidget->setObjectName(QStringLiteral("FieldTableWidget"));
        FieldTableWidget->horizontalHeader()->setStretchLastSection(true);
        FieldTableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(FieldTableWidget, 2, 0, 1, 4);

        RemoveFieldButton = new QPushButton(MessagePage);
        RemoveFieldButton->setObjectName(QStringLiteral("RemoveFieldButton"));

        gridLayout->addWidget(RemoveFieldButton, 1, 3, 1, 1);

        SendMessageButton = new QPushButton(MessagePage);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));

        gridLayout->addWidget(SendMessageButton, 0, 3, 1, 1);

        AddFieldButton = new QPushButton(MessagePage);
        AddFieldButton->setObjectName(QStringLiteral("AddFieldButton"));

        gridLayout->addWidget(AddFieldButton, 1, 2, 1, 1);

        MessageIDInput = new QSpinBox(MessagePage);
        MessageIDInput->setObjectName(QStringLiteral("MessageIDInput"));
        MessageIDInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
        MessageIDInput->setMinimum(1);

        gridLayout->addWidget(MessageIDInput, 0, 1, 1, 1);


        retranslateUi(MessagePage);

        QMetaObject::connectSlotsByName(MessagePage);
    } // setupUi

    void retranslateUi(QWidget *MessagePage)
    {
        MessagePage->setWindowTitle(QApplication::translate("MessagePage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("MessagePage", "Message ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = FieldTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MessagePage", "Field Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = FieldTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MessagePage", "Data Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = FieldTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MessagePage", "Value", Q_NULLPTR));
        RemoveFieldButton->setText(QApplication::translate("MessagePage", "Remove Field", Q_NULLPTR));
        SendMessageButton->setText(QApplication::translate("MessagePage", "Send Message", Q_NULLPTR));
        AddFieldButton->setText(QApplication::translate("MessagePage", "Add Field", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessagePage: public Ui_MessagePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEPAGE_H
