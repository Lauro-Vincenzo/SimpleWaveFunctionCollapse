#ifndef TILEIMPL_H
#define TILEIMPL_H
#include <memory>

#include "TileInterface.h"

class TileImpl : public ITile
{
public:
    ITilePresenter* GetTilePresenter() const override;

private:
    std::unique_ptr<ITilePresenter> _presenter{nullptr};

};

#endif // TILEIMPL_H
