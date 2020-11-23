/*
 * File: MainWindow.h
 * Author: Todd Morehouse
 * Description
 *  The mainwindow class, responsible for renderring the mainwindow and controlling each individual page.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_h

//Standard includes

//Qt includes
#include <QMainWindow>

//Project includes
#include "ConnectionPage.h"
#include "ProcessPage.h"
#include "MessagePage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initializePages();

private slots:
    void on_ConnectionPageButton_released();

    void on_ProcessPagebutton_released();

    void on_MessagePageButton_released();

private:
    Ui::MainWindow *ui;

    QList<QWidget*> pages;
    int currentPage = 0;
    void setCurrentPage(int page);
};
#endif // MAINWINDOW_H
