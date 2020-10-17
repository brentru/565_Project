#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Remote Sensor Node Interface");
    initializePages();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Initializes all pages and stores a pointer to them
 */
void MainWindow::initializePages()
{
    //Connection page
    ConnectionPage *connpage = new ConnectionPage(this);
    pages.append(connpage);
    ui->PageDisplay->addWidget(connpage);

    //Process page
    ProcessPage *procpage = new ProcessPage(this);
    pages.append(procpage);
    ui->PageDisplay->addWidget(procpage);

    //Message page
    MessagePage *messpage = new MessagePage(this);
    pages.append(messpage);
    ui->PageDisplay->addWidget(messpage);
}

void MainWindow::setCurrentPage(int page)
{
    this->currentPage = page;
    ui->PageDisplay->setCurrentIndex(currentPage);
}

void MainWindow::on_ConnectionPageButton_released()
{
    setCurrentPage(0);
}

void MainWindow::on_ProcessPagebutton_released()
{
    setCurrentPage(1);
}

void MainWindow::on_MessagePageButton_released()
{
    setCurrentPage(2);
}
