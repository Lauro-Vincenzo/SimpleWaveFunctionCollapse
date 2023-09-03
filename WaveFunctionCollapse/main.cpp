#include "mainwindow.h"
#include "DataStructures.h"

#include <iostream>
#include <memory>

#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include "wfctile.h"

static constexpr Vector2D BUTTON_DEFAULT_SIZE{100,30};
static constexpr Vector2D SOLVE_BUTTON_OFFSET{250,50};
static constexpr Vector2D RESET_BUTTON_OFFSET{125,50};

void InitializeMainWindow(MainWindow* mainWindow);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    InitializeMainWindow(&w);

    w.show();
    return app.exec();
}

void InitializeMainWindow(MainWindow* mainWindow){
    auto resetButton = std::make_unique<QPushButton>("Reset");
    auto solveButton = std::make_unique<QPushButton>("Solve");
    auto mainLabel = std::make_unique<QLabel>();
    mainLabel->setStyleSheet("QLabel { background-color : Ivory; border: 3px solid black;}");

    resetButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);
    solveButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);

    const Vector2D windowSize{mainWindow->size().width(),mainWindow->size().height()};

    const Vector2D screenSize = {windowSize.X - 20, windowSize.Y - 2 * BUTTON_DEFAULT_SIZE.Y - 2};
    mainWindow->AddWidget(std::move(mainLabel), screenSize, {10,5});
    mainWindow->AddWidget(std::move(resetButton), BUTTON_DEFAULT_SIZE, windowSize-RESET_BUTTON_OFFSET);
    mainWindow->AddWidget(std::move(solveButton), BUTTON_DEFAULT_SIZE, windowSize-SOLVE_BUTTON_OFFSET);
}

