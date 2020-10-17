/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *PageChooser;
    QVBoxLayout *verticalLayout;
    QPushButton *ConnectionPageButton;
    QPushButton *ProcessPagebutton;
    QPushButton *MessagePageButton;
    QSpacerItem *verticalSpacer;
    QStackedWidget *PageDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(870, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PageChooser = new QWidget(centralwidget);
        PageChooser->setObjectName(QStringLiteral("PageChooser"));
        PageChooser->setStyleSheet(QLatin1String("#PageChooser{\n"
"	border-right: 1px solid black;\n"
"}"));
        verticalLayout = new QVBoxLayout(PageChooser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ConnectionPageButton = new QPushButton(PageChooser);
        ConnectionPageButton->setObjectName(QStringLiteral("ConnectionPageButton"));

        verticalLayout->addWidget(ConnectionPageButton);

        ProcessPagebutton = new QPushButton(PageChooser);
        ProcessPagebutton->setObjectName(QStringLiteral("ProcessPagebutton"));

        verticalLayout->addWidget(ProcessPagebutton);

        MessagePageButton = new QPushButton(PageChooser);
        MessagePageButton->setObjectName(QStringLiteral("MessagePageButton"));

        verticalLayout->addWidget(MessagePageButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(PageChooser);

        PageDisplay = new QStackedWidget(centralwidget);
        PageDisplay->setObjectName(QStringLiteral("PageDisplay"));

        horizontalLayout->addWidget(PageDisplay);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 870, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ConnectionPageButton->setText(QApplication::translate("MainWindow", "Connection Page", Q_NULLPTR));
        ProcessPagebutton->setText(QApplication::translate("MainWindow", "Process Page", Q_NULLPTR));
        MessagePageButton->setText(QApplication::translate("MainWindow", "Message Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
