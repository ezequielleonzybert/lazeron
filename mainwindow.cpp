#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    btnLoad = new QPushButton("Load", this);
    btnLoad->setGeometry(10, 10, 40, 40);

    connect(btnLoad, &QPushButton::clicked, this, &MainWindow::onButtonClicked);

    this->showMaximized();
}

MainWindow::~MainWindow() {}

void MainWindow::onButtonClicked()
{
}
