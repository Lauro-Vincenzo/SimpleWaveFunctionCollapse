#include "TileImpl.h"

ITilePresenter* TileImpl::GetTilePresenter() const {
    return _presenter.get();
}
