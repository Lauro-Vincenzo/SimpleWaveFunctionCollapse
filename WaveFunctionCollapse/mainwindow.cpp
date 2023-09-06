#include "mainwindow.h"
#include <QLayout>
#include <QDesktopWidget>
#include "./ui_mainwindow.h"
#include "DataStructures.h"

static constexpr float SPAWN_X{50};
static constexpr float SPAWN_Y{50};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const auto uiWidth = QDesktopWidget().availableGeometry(this).width()*0.35;
    const auto uiHeight = QDesktopWidget().availableGeometry(this).height()*0.5;
    setFixedSize(uiWidth, uiHeight);
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

