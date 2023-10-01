#ifndef TILEINTERFACE_H
#define TILEINTERFACE_H

#include "ITilePresenter.h"

class ITile{
public:
    virtual ~ITile() = default;
    virtual ITilePresenter* GetTilePresenter() const = 0;
};

#endif // TILEINTERFACE_H
