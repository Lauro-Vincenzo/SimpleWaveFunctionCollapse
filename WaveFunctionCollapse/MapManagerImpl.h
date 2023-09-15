#ifndef MAPMANAGERIMPL_H
#define MAPMANAGERIMPL_H

#include "IMapManager.h"
#include "mainwindow.h"

class QWidget;
class QGridLayout;
class QLabel;

class MapManagerImpl : public IMapManager
{
public:
    MapManagerImpl();
    void InitializeMap() override;

private:
    std::unique_ptr<MainWindow> _window{nullptr}; //TODO: probably this should be removed from here.
    QLabel* _createMapLabel();
    void _initializeMapGrid(QWidget* parentWidget);
    void _fillMapGrid(QGridLayout* gridLayout);

};

#endif // MAPMANAGERIMPL_H
