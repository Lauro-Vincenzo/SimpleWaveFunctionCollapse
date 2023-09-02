#ifndef TILEPRESENTER_H
#define TILEPRESENTER_H

#include "ITilePresenter.h"

class TilePresenter : public ITilePresenter
{
public:
    TilePresenter(const float length, const float height);
};

#endif // TILEPRESENTER_H
