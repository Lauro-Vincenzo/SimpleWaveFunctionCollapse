#include "mainwindow.h"
#include "DataStructures.h"

#include <iostream>
#include <memory>

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

#include "wfctile.h"

static constexpr Vector2D BUTTON_DEFAULT_SIZE{100,30};
static constexpr Vector2D SOLVE_BUTTON_OFFSET{250,50};
static constexpr Vector2D RESET_BUTTON_OFFSET{125,50};
static constexpr int ROWS_NUM{6};
static constexpr int COLUMNS_NUM{6};

void InitializeMainWindow(MainWindow* mainWindow);
QLabel* CreateMap();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    InitializeMainWindow(&w);

    w.show();
    return app.exec();
}

QLabel* CreateMap(){
    auto mapLabel = new QLabel();
    mapLabel->setStyleSheet("QLabel { background-color : Ivory; border: 3px solid black;}");
    auto gridLayout = new QGridLayout(mapLabel);
    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    const auto layoutGeometry = mapLabel->geometry();

    for(int rowIndex=0; rowIndex<ROWS_NUM; rowIndex++){
        for(int columnIndex=0; columnIndex<COLUMNS_NUM; columnIndex++){
            auto tileButton = new QPushButton("");
            const auto width = layoutGeometry.width()/COLUMNS_NUM;
            const auto height = layoutGeometry.height()/ROWS_NUM;
            tileButton->setFixedSize(width,height);
            gridLayout->addWidget(tileButton, columnIndex, rowIndex);
        }
    }


    return mapLabel;
}

void InitializeMainWindow(MainWindow* mainWindow){
    auto resetButton = new QPushButton("Reset");
    auto solveButton = new QPushButton("Solve");

    auto mapLabel = CreateMap();

    resetButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);
    solveButton->setFixedSize(BUTTON_DEFAULT_SIZE.X,BUTTON_DEFAULT_SIZE.Y);

    const Vector2D windowSize{mainWindow->size().width(),mainWindow->size().height()};
    const Vector2D screenSize = {windowSize.X - 20, windowSize.Y - 2 * BUTTON_DEFAULT_SIZE.Y - 2};
    mainWindow->AddWidget(mapLabel, screenSize, {10,5});
    mainWindow->AddWidget(resetButton, BUTTON_DEFAULT_SIZE, windowSize-RESET_BUTTON_OFFSET);
    mainWindow->AddWidget(solveButton, BUTTON_DEFAULT_SIZE, windowSize-SOLVE_BUTTON_OFFSET);
}

