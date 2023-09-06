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
static constexpr Vector2D BUTTON_CONTAINER_POSITION{250,50};
static constexpr int ROWS_NUM{12};
static constexpr int COLUMNS_NUM{12};

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
    gridLayout->setGeometry(QRect(0,0,mapLabel->width(), mapLabel->height()));

    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);

    gridLayout->setContentsMargins(0,0,0,0);

    for(int rowIndex=0; rowIndex<ROWS_NUM; rowIndex++){
        for(int columnIndex=0; columnIndex<COLUMNS_NUM; columnIndex++){
            auto tileButton = new QPushButton("");

            //TODO FIXME: Adjust this hardcoded value.
            const auto height = mapLabel->height()/ROWS_NUM + 3;
            tileButton->setFixedHeight(height);
            gridLayout->addWidget(tileButton, columnIndex, rowIndex);
        }
    }

    return mapLabel;
}

void InitializeMainWindow(MainWindow* mainWindow){
    const Vector2D totalWindowSize = {mainWindow->width(),mainWindow->height()};
    auto mapLabel = CreateMap();

    auto resetButton = new QPushButton("Reset");
    auto solveButton = new QPushButton("Solve");

    auto buttonContainerWidget = new QWidget();
    auto buttonVBox = new QVBoxLayout(buttonContainerWidget);
    buttonVBox->addWidget(resetButton);
    buttonVBox->addWidget(solveButton);

    const auto squaredMapSide = mainWindow->width()*0.75;

    const Vector2D screenSize = {squaredMapSide,squaredMapSide};
    const Vector2D buttonSize = {squaredMapSide*0.25,squaredMapSide};
    const Vector2D buttonPosition = {screenSize.X,0};

    mainWindow->AddWidget(mapLabel, screenSize, {0,0});
    mainWindow->AddWidget(buttonContainerWidget, buttonSize, buttonPosition);
}

