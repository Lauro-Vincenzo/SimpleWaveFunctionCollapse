#include <QtTest>

#include <memory>

#include "TileInterface.h"
#include "ITilePresenter.h"


//Impl includes
#include "TileImpl.h"

class WFCTests : public QObject
{
    Q_OBJECT

public:
    WFCTests();
    ~WFCTests();

private slots:
    void test_spawnTile();

};

WFCTests::WFCTests()
{

}
WFCTests::~WFCTests()
{

}

void WFCTests::test_spawnTile()
{
    std::unique_ptr<ITile> tile = std::make_unique<TileImpl>();
    //auto tilePresenter = tile->GetTilePresenter();

    //QCOMPARE(tilePresenter, nullptr);
}

QTEST_APPLESS_MAIN(WFCTests)

#include "tst_wfctests.moc"
