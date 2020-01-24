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
    void test_case1();
    void test_is_spot_empty();
    void test_set_spot_isnt_empty();
    void test_get_mark();

};

playTTT::playTTT()
{

}

playTTT::~playTTT()
{

}

void playTTT::test_case1()
{
    Play ttt{};

    QTEST_ASSERT(!ttt.isFinished());
}

void playTTT::test_is_spot_empty()
{
    Play ttt{};
    Spot spot{Spot::Center()};
    QVERIFY(spot.GetIndex() < 9);

    QVERIFY(ttt.isEmpty(spot));
}


void playTTT::test_set_spot_isnt_empty()
{
    Play ttt{};
    Spot spot{Spot::Center()};

    ttt.setSpot(spot,Mark::X);
    QVERIFY(!ttt.isEmpty(spot));
}

void playTTT::test_get_mark()
{
    Play ttt{};
    Spot spot{Spot::Center()};

    ttt.setSpot(spot,Mark::X);
    QVERIFY(ttt.getSpot(spot) == Mark::X);

}
/* // */
QTEST_APPLESS_MAIN(playTTT)

#include "tst_playttt.moc"
