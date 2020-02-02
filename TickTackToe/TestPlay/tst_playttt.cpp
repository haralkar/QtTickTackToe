#include <QtTest>

// add necessary includes here

#include <play.h>

class playTTT : public QObject
{
    Q_OBJECT

public:
    playTTT();
    ~playTTT();

private slots:
    //void initTestCase();
    //void cleanupTestCase();

    void test_case1();
    void test_is_spot_empty();
    void test_set_spot_isnt_empty();
    void test_get_mark();

    void test_find_best_spot_empty();

};

playTTT::playTTT()
{

}

playTTT::~playTTT()
{

}

/*
void playTTT::initTestCase()
{
    ttt = Play{};
}

void playTTT::cleanupTestCase()
{
    ;
}
*/

void playTTT::test_case1()
{
    Play ttt{};
    QTEST_ASSERT(!ttt.isFinished());
}

void playTTT::test_is_spot_empty()
{

    Spot spot{Spot::Center()};
    QVERIFY(spot.GetIndex() < 9);

    Play ttt{};
    QVERIFY(ttt.isEmpty(spot));
}


void playTTT::test_set_spot_isnt_empty()
{
    Spot spot{Spot::Center()};

    Play ttt{};
    ttt.setSpot(spot,Mark::X);
    QVERIFY(!ttt.isEmpty(spot));
}

void playTTT::test_get_mark()
{
    Spot spot{Spot::Center()};

    Play ttt{};
    ttt.setSpot(spot,Mark::X);
    QVERIFY(ttt.getSpot(spot) == Mark::X);

}

void playTTT::test_find_best_spot_empty()
{
    Play ttt{};

    Spot spot{ttt.findBestMove()};
    QVERIFY( spot.cross_ == Side::Center && spot.down_ == Side::Center);
}
/* // */
QTEST_APPLESS_MAIN(playTTT)

#include "tst_playttt.moc"
