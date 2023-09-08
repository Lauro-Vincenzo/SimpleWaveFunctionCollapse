#include "MapManagerImpl.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

#include "DataStructures.h"

static constexpr Vector2D BUTTON_CONTAINER_POSITION{250,50};
static constexpr Vector2D TOPLEFT_STARTPOINT{0,0};

static constexpr double MAP_WIDTH_FILL_FACTOR{0.70};
static constexpr int SIDE_CELL_NUM{4};

static const char* PLACEHOLDER_IMAGE_PATH{"/home/vincenzo/Documents/C++/WaveFunctionCollapse/WaveFunctionCollapse/chopper.png"};


MapManagerImpl::MapManagerImpl()
{
    _window = std::make_unique<MainWindow>();
    _window->show();
}

void MapManagerImpl::SetMapSize(const int xExtent, const int yExtent){

}

void MapManagerImpl::InitializeMap(){
    const auto& mapLabel = _createMapLabel();

    const auto& buttonContainerWidget = new QWidget();
    const auto& buttonVBox = new QVBoxLayout(buttonContainerWidget);

    const auto& resetButton = new QPushButton("Reset");
    const auto& solveButton = new QPushButton("Solve");
    buttonVBox->addWidget(resetButton);
    buttonVBox->addWidget(solveButton);

    const int& squaredMapSide = _window->width()*MAP_WIDTH_FILL_FACTOR;

    const Vector2D screenSize = {squaredMapSide,squaredMapSide};

    const Vector2D buttonSize = {int(squaredMapSide*0.25),squaredMapSide};
    const Vector2D buttonPosition = {squaredMapSide,0};

    _window->AddWidget(mapLabel, screenSize, TOPLEFT_STARTPOINT);
    _window->AddWidget(buttonContainerWidget, buttonSize, buttonPosition);
}

QLabel* MapManagerImpl::_createMapLabel(){
    auto mapLabel = new QLabel();
    mapLabel->setStyleSheet("QLabel { background-color : Ivory; border: 3px solid black;}");

    _initializeMapGrid(mapLabel);

    return mapLabel;
}

void MapManagerImpl::_initializeMapGrid(QWidget* parentWidget){
    auto gridLayout = new QGridLayout(parentWidget);

    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    gridLayout->setContentsMargins(0,0,0,0);

    _fillMapGrid(gridLayout);
}

void MapManagerImpl::_fillMapGrid(QGridLayout* gridLayout) {
    for(int rowIndex=0; rowIndex<SIDE_CELL_NUM; rowIndex++){
        for(int columnIndex=0; columnIndex<SIDE_CELL_NUM; columnIndex++){

            gridLayout->setColumnMinimumWidth(columnIndex,0);
            gridLayout->setRowMinimumHeight(rowIndex,0);

            auto widget = new QWidget();
            auto tileButton = new QPushButton(widget);
            tileButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            gridLayout->addWidget(tileButton, columnIndex, rowIndex);

            const auto* icon = new QIcon(PLACEHOLDER_IMAGE_PATH);
            tileButton->setIcon(*icon);
            tileButton->setIconSize(tileButton->size());
        }
    }
}

