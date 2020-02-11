#include <QtTest>

#include <iostream>

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
    void test_isFinished();
    void test_is_spot_empty();
    void test_set_spot_isnt_empty();
    void test_get_mark();

    void test_find_best_spot_empty();
    void test_find_best_spot_a_corner();

    void test_is_winning_move_tl_diag();
    void test_is_winning_move_empty_but_out_of_line();
    void test_is_winning_move_invalids_are_not();

    void test_blocking_move_isnt_winning_move_tl_diag();

    void test_find_the_best_winning_move();
    void test_find_the_best_blocking_move();


    void test_mark_flips_to_and_fro();
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
void playTTT::test_isFinished()
{
    Play ttt{};
    for (int i = 0 ; i < 9 ; i++ )
    {
        ttt.setSpot(Spot::FromIndex(i), Mark::X);
    }
    QTEST_ASSERT(ttt.isFinished());
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

    Spot spot{ttt.findMove(Mark::X)};
    QVERIFY( spot.cross_ == Side::Center && spot.down_ == Side::Center);
}

void playTTT::test_find_best_spot_a_corner()
{
    Play ttt{};

    Spot spot{ttt.findMove(Mark::X)};
    ttt.setSpot(spot, Mark::X);

    Spot nextSpot{ttt.findMove(Mark::X)};
    QVERIFY( nextSpot.cross_ == Side::Left && nextSpot.down_ == Side::Left);
}

void playTTT::test_is_winning_move_invalids_are_not()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    QVERIFY(!ttt.isWinningMove(Spot::Center(), Mark::X));
}

void playTTT::test_mark_flips_to_and_fro()
{
    Mark x{Mark::X};
    Mark o = ++x;
    QVERIFY( o == Mark::O);

    Mark back = ++o;
    QVERIFY( back == Mark::X);

    Mark same = ++Mark::Empty;
    QVERIFY( same == Mark::Empty);
}
void playTTT::test_is_winning_move_tl_diag()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left, Side::Left}, Mark::X);

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Left}, Mark::X));
    QVERIFY(!ttt.isWinningMove(Spot{Side::Center,Side::Right}, Mark::X));
    QVERIFY(ttt.isWinningMove(Spot{Side::Right,Side::Right}, Mark::X));
}

void playTTT::test_blocking_move_isnt_winning_move_tl_diag()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left, Side::Left}, Mark::X);

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Right}, Mark::O));
}

//*
void playTTT::test_find_the_best_winning_move()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left,Side::Left}, Mark::X);
    Spot const br{Side::Right, Side::Right};

    auto spot = ttt.findBestMove(Mark::X);
    std::cerr << "Spot: " << (int)spot.down_ << ", " << (int)spot.cross_ << "\n";
    QVERIFY(spot == br);
}

void playTTT::test_find_the_best_blocking_move()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left,Side::Left}, Mark::X);
    Spot const br{Side::Right, Side::Right};

    auto spot = ttt.findBestMove(Mark::X);

    std::cerr << "Spot: " << (int)spot.down_ << ", " << (int)spot.cross_ << "\n";
    QVERIFY(spot == br);

}
// */
void playTTT::test_is_winning_move_empty_but_out_of_line()
{
    Play ttt{};
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left, Side::Left}, Mark::X);

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Center}, Mark::X));

}


/* // */
QTEST_APPLESS_MAIN(playTTT)

#include "tst_playttt.moc"
