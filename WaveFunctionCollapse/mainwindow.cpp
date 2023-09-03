#include "mainwindow.h"
#include <QLayout>
#include <QDesktopWidget>
#include "./ui_mainwindow.h"
#include "DataStructures.h"

static constexpr float APP_RELATIVE_SIZE{0.5};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(QDesktopWidget().availableGeometry(this).size() * APP_RELATIVE_SIZE);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddWidget(std::unique_ptr<QWidget> widgetToAdd, const Vector2D& size ,const Vector2D& position){
    widgetToAdd->setGeometry(position.X,position.Y, size.X, size.Y);
    storedWidgets.push_back(std::shared_ptr<QWidget>(std::move(widgetToAdd)));

    layout()->addWidget(storedWidgets.back().get());
}

