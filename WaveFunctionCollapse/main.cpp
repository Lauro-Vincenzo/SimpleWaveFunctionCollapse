#include <memory>

#include <QApplication>

#include "MapManagerImpl.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::unique_ptr<IMapManager> mapManager = std::make_unique<MapManagerImpl>();
    mapManager->InitializeMap();

    return app.exec();
}


