#include <QtTest>

#include "bcttt.h"

// add necessary includes here

class TestTTT : public QObject
{
    Q_OBJECT

    BcTTT ttt{};

public:
    TestTTT();
    ~TestTTT();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_empy_isnt_finished();
    void test_is_spot_empty();
    void test_setting_spot_unempties();

};

TestTTT::TestTTT()
{

}

TestTTT::~TestTTT()
{

}

void TestTTT::initTestCase()
{
    ttt = BcTTT{};
}

void TestTTT::cleanupTestCase()
{

}


void TestTTT::test_empy_isnt_finished()
{
    QVERIFY(!ttt.isFinished());
}

void TestTTT::test_is_spot_empty()
{
    QVERIFY(ttt.isEmpty(Coord::center()));
}

void TestTTT::test_setting_spot_unempties()
{
    ttt.setSpot(Coord::center(), MarkType::X);
    QVERIFY(!ttt.isEmpty(Coord::center()));
}

QTEST_APPLESS_MAIN(TestTTT)

#include "tst_tickTackToe.moc"
