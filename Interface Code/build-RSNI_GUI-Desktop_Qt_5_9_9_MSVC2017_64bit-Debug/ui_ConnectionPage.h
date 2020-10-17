/********************************************************************************
** Form generated from reading UI file 'ConnectionPage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONPAGE_H
#define UI_CONNECTIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionPage
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *RawTextInput;
    QPushButton *RawTextSend;
    QCheckBox *LoopbackCheck;
    QFrame *line_2;
    QLabel *StatusLabel;
    QLineEdit *IPAddressInput;
    QSpinBox *PortInput;
    QPushButton *ConnectButton;
    QLabel *label;
    QFrame *line;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QTextEdit *IncomingText;

    void setupUi(QWidget *ConnectionPage)
    {
        if (ConnectionPage->objectName().isEmpty())
            ConnectionPage->setObjectName(QStringLiteral("ConnectionPage"));
        ConnectionPage->resize(622, 421);
        gridLayout = new QGridLayout(ConnectionPage);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(ConnectionPage);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        widget = new QWidget(ConnectionPage);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        RawTextInput = new QLineEdit(widget);
        RawTextInput->setObjectName(QStringLiteral("RawTextInput"));

        horizontalLayout->addWidget(RawTextInput);

        RawTextSend = new QPushButton(widget);
        RawTextSend->setObjectName(QStringLiteral("RawTextSend"));

        horizontalLayout->addWidget(RawTextSend);

        LoopbackCheck = new QCheckBox(widget);
        LoopbackCheck->setObjectName(QStringLiteral("LoopbackCheck"));

        horizontalLayout->addWidget(LoopbackCheck);


        gridLayout->addWidget(widget, 4, 0, 1, 4);

        line_2 = new QFrame(ConnectionPage);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 6, 0, 1, 4);

        StatusLabel = new QLabel(ConnectionPage);
        StatusLabel->setObjectName(QStringLiteral("StatusLabel"));

        gridLayout->addWidget(StatusLabel, 2, 2, 1, 1);

        IPAddressInput = new QLineEdit(ConnectionPage);
        IPAddressInput->setObjectName(QStringLiteral("IPAddressInput"));

        gridLayout->addWidget(IPAddressInput, 0, 1, 1, 2);

        PortInput = new QSpinBox(ConnectionPage);
        PortInput->setObjectName(QStringLiteral("PortInput"));
        PortInput->setButtonSymbols(QAbstractSpinBox::NoButtons);
        PortInput->setMaximum(20000);
        PortInput->setValue(7000);

        gridLayout->addWidget(PortInput, 1, 1, 1, 2);

        ConnectButton = new QPushButton(ConnectionPage);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));

        gridLayout->addWidget(ConnectButton, 2, 0, 1, 1);

        label = new QLabel(ConnectionPage);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line = new QFrame(ConnectionPage);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 3, 1);

        label_2 = new QLabel(ConnectionPage);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        widget_2 = new QWidget(ConnectionPage);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(12);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_5);

        IncomingText = new QTextEdit(widget_2);
        IncomingText->setObjectName(QStringLiteral("IncomingText"));
        IncomingText->setReadOnly(true);

        verticalLayout->addWidget(IncomingText);


        gridLayout->addWidget(widget_2, 7, 0, 1, 4);


        retranslateUi(ConnectionPage);

        QMetaObject::connectSlotsByName(ConnectionPage);
    } // setupUi

    void retranslateUi(QWidget *ConnectionPage)
    {
        ConnectionPage->setWindowTitle(QApplication::translate("ConnectionPage", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConnectionPage", "Status", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConnectionPage", "Send Raw Text", Q_NULLPTR));
        RawTextSend->setText(QApplication::translate("ConnectionPage", "Send", Q_NULLPTR));
        LoopbackCheck->setText(QApplication::translate("ConnectionPage", "Loopback Tx", Q_NULLPTR));
        StatusLabel->setText(QApplication::translate("ConnectionPage", "Not Connected", Q_NULLPTR));
        IPAddressInput->setText(QApplication::translate("ConnectionPage", "127.0.0.1", Q_NULLPTR));
        ConnectButton->setText(QApplication::translate("ConnectionPage", "Connect", Q_NULLPTR));
        label->setText(QApplication::translate("ConnectionPage", "IP Address", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConnectionPage", "Port", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConnectionPage", "Received Text", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionPage: public Ui_ConnectionPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONPAGE_H
