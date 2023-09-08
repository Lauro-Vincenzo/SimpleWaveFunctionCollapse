#ifndef IMAPMANAGER_H
#define IMAPMANAGER_H


class IMapManager
{
public:
    virtual void InitializeMap() = 0;
    virtual void SetMapSize(const int xExtent, const int yExtent) = 0;
};

#endif // IMAPMANAGER_H
