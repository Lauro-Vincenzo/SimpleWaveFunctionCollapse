#include "mainwindow.h"
#include "DataStructures.h"

#include <iostream>
#include <memory>

#include <QApplication>
#include <QPushButton>

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

    //const auto tile = std::make_unique<WFCTile>(100,100,"/home/vincenzo/Documents/C++/WaveFunctionCollapse/WaveFunctionCollapse/chopper.png");
    //w.layout()->addWidget(tile->GetPresenter().get());

    w.show();
    return app.exec();
}

void InitializeMainWindow(MainWindow* mainWindow){
    auto resetButton = std::make_unique<QPushButton>("Reset");
    auto solveButton = std::make_unique<QPushButton>("Solve");

    resetButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);
    solveButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);

    const Vector2D windowSize{mainWindow->size().width(),mainWindow->size().height()};

    mainWindow->AddWidget(std::move(resetButton), BUTTON_DEFAULT_SIZE, windowSize-RESET_BUTTON_OFFSET);
    mainWindow->AddWidget(std::move(solveButton), BUTTON_DEFAULT_SIZE, windowSize-SOLVE_BUTTON_OFFSET);
}

