#include "mainwindow.h"
#include <QLayout>
#include <QDesktopWidget>
#include "./ui_mainwindow.h"
#include "DataStructures.h"

static constexpr float APP_RELATIVE_WIDTH{0.888};
static constexpr float APP_RELATIVE_HEIGHT{0.5};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setFixedSize(QDesktopWidget().availableGeometry(this).width(),QDesktopWidget().availableGeometry(this).height());
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddWidget(QWidget* widgetToAdd, const Vector2D& size ,const Vector2D& position){
    widgetToAdd->setGeometry(position.X,position.Y, size.X, size.Y);
    layout()->addWidget(widgetToAdd);
}

