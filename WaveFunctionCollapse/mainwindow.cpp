#include "mainwindow.h"
#include <QLayout>
#include <QDesktopWidget>
#include "./ui_mainwindow.h"
#include "DataStructures.h"

static constexpr float WIDTH_SCALE_FACTOR{0.35};
static constexpr float HEIGHT_SCALE_FACTOR{0.45};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    const auto uiWidth = QDesktopWidget().availableGeometry(this).width()*WIDTH_SCALE_FACTOR;
    const auto uiHeight = QDesktopWidget().availableGeometry(this).height()*HEIGHT_SCALE_FACTOR;
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

