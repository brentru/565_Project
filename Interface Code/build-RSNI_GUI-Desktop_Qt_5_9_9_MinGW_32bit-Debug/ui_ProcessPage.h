/********************************************************************************
** Form generated from reading UI file 'ProcessPage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSPAGE_H
#define UI_PROCESSPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *SensorComboBox;
    QPushButton *StartSensorButton;
    QTableWidget *ProcessTable;

    void setupUi(QWidget *ProcessPage)
    {
        if (ProcessPage->objectName().isEmpty())
            ProcessPage->setObjectName(QStringLiteral("ProcessPage"));
        ProcessPage->resize(888, 528);
        verticalLayout = new QVBoxLayout(ProcessPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(ProcessPage);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        SensorComboBox = new QComboBox(widget);
        SensorComboBox->setObjectName(QStringLiteral("SensorComboBox"));

        horizontalLayout->addWidget(SensorComboBox);

        StartSensorButton = new QPushButton(widget);
        StartSensorButton->setObjectName(QStringLiteral("StartSensorButton"));

        horizontalLayout->addWidget(StartSensorButton);


        verticalLayout->addWidget(widget);

        ProcessTable = new QTableWidget(ProcessPage);
        if (ProcessTable->columnCount() < 7)
            ProcessTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ProcessTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        ProcessTable->setObjectName(QStringLiteral("ProcessTable"));
        ProcessTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ProcessTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ProcessTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(ProcessTable);


        retranslateUi(ProcessPage);

        QMetaObject::connectSlotsByName(ProcessPage);
    } // setupUi

    void retranslateUi(QWidget *ProcessPage)
    {
        ProcessPage->setWindowTitle(QApplication::translate("ProcessPage", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ProcessPage", "Start New Process", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProcessPage", "Sensor to Start", Q_NULLPTR));
        StartSensorButton->setText(QApplication::translate("ProcessPage", "Start Process", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = ProcessTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ProcessPage", "Sensor Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = ProcessTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ProcessPage", "Sensor ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = ProcessTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ProcessPage", "PID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = ProcessTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ProcessPage", "Last Value", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcessPage: public Ui_ProcessPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSPAGE_H
