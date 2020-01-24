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

    QVERIFY(ttt.isEmpty(spot));
}

QTEST_APPLESS_MAIN(playTTT)

#include "tst_playttt.moc"
