#include "mainwindow.h"
#include "DataStructures.h"

#include <iostream>
#include <memory>

#include <QApplication>
#include <QPushButton>
 #include <QToolButton>
#include <QLabel>
#include <QGridLayout>

#include "wfctile.h"

static constexpr Vector2D BUTTON_CONTAINER_POSITION{250,50};
static constexpr Vector2D TOPLEFT_STARTPOINT{0,0};

static constexpr double MAP_WIDTH_FILL_FACTOR{0.70};
static constexpr int ROWS_NUM{12};
static constexpr int COLUMNS_NUM{12};

static const char* PLACEHOLDER_IMAGE_PATH{"/home/vincenzo/Documents/C++/WaveFunctionCollapse/WaveFunctionCollapse/chopper.png"};

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
            auto widget = new QWidget();
            auto tileButton = new QPushButton(widget);

            const auto* icon = new QIcon(PLACEHOLDER_IMAGE_PATH);

            tileButton->setIcon(*icon);
            tileButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            const auto& buttonSize = tileButton->size();

            tileButton->setIconSize(buttonSize);
            gridLayout->addWidget(tileButton, columnIndex, rowIndex);
        }
    }

    return mapLabel;
}

void InitializeMainWindow(MainWindow* mainWindow){
    const auto& mapLabel = CreateMap();

    const auto& buttonContainerWidget = new QWidget();
    const auto& buttonVBox = new QVBoxLayout(buttonContainerWidget);

    const auto& resetButton = new QPushButton("Reset");
    const auto& solveButton = new QPushButton("Solve");
    buttonVBox->addWidget(resetButton);
    buttonVBox->addWidget(solveButton);

    const int& squaredMapSide = mainWindow->width()*MAP_WIDTH_FILL_FACTOR;

    const Vector2D screenSize = {squaredMapSide,squaredMapSide};

    const Vector2D buttonSize = {int(squaredMapSide*0.25),squaredMapSide};
    const Vector2D buttonPosition = {squaredMapSide,0};

    mainWindow->AddWidget(mapLabel, screenSize, TOPLEFT_STARTPOINT);
    mainWindow->AddWidget(buttonContainerWidget, buttonSize, buttonPosition);
}

