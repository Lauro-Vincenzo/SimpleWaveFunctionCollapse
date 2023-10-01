#ifndef TILEIMPL_H
#define TILEIMPL_H

#include <memory>

#include "TileInterface.h"
//#include "ITilePresenter.h"

class TileImpl : public ITile{
public:
    ITilePresenter* GetTilePresenter() const;
private:
    //std::unique_ptr<ITilePresenter> _presenter{nullptr};
};

#endif // TILEIMPL_H
