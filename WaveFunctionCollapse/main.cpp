#include "mainwindow.h"
#include <iostream>

#include <QApplication>
#include <QLayout>

#include "wfctile.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    const auto tile = std::make_unique<WFCTile>(100,100,"/home/vincenzo/Documents/C++/WaveFunctionCollapse/WaveFunctionCollapse/chopper.png");
    w.layout()->addWidget(tile->GetPresenter().get());

    w.show();
    return app.exec();
}
