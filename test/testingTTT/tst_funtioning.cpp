#include <QtTest>

#include "bcttt.h"

// add necessary includes here

class funtioning : public QObject
{
    Q_OBJECT

    BcTTT ttt{};

public:
    funtioning();
    ~funtioning();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_empy_isnt_finished();
    void test_is_spot_empty();
    void test_setting_spot_unempties();

};

funtioning::funtioning()
{

}

funtioning::~funtioning()
{

}

void funtioning::initTestCase()
{

}

void funtioning::cleanupTestCase()
{

}


void funtioning::test_empy_isnt_finished()
{
    QVERIFY(!ttt.isFinished());
}

void funtioning::test_is_spot_empty()
{
    QVERIFY(ttt.isEmpty(Coord::center()));
}

void funtioning::test_setting_spot_unempties()
{

    ttt.setSpot(Coord::center(), MarkType::X);
    QVERIFY(!ttt.isEmpty(Coord::center()));
}

QTEST_APPLESS_MAIN(funtioning)

#include "tst_funtioning.moc"
