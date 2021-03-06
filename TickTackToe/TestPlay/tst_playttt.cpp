#include <QtTest>


#include <iostream>

// add necessary includes here

#include <play.h>
#include <mark.h>
#include <mark.cpp>

class playTTT : public QObject
{
    Q_OBJECT

    Spot const br{Side::Right, Side::Right};
    Play ttt{};
    Spot center{Spot::Center()};
public:
    playTTT();
    ~playTTT();

    void cleanup(){ttt.clear();}
    void setTlCc();

private slots:
    void initTestCase();
    void cleanupTestCase();

    void test_clear_works();
    void test_isFinished();
    void test_is_spot_empty();
    void test_set_spot_isnt_empty();
    void test_get_mark();

    void test_find_best_spot_empty();
    void test_find_best_spot_a_corner();

    void test_opposed_corners_side_up();

    void test_is_winning_move_tl_diag();
    void test_is_winning_move_empty_but_out_of_line();
    void test_is_winning_move_invalids_are_not();

    void test_blocking_move_isnt_winning_move_tl_diag();

    void test_find_the_best_winning_move();
    void test_find_the_best_blocking_move();
    void test_find_winning_b4_blocking_moveII();
    void test_find_winning_b4_blocking_move();

    void test_corner_othe_side_stategy();


    void test_mark_flips_to_and_fro();
};

playTTT::playTTT()
{

}

playTTT::~playTTT()
{

}

void playTTT::setTlCc()
{
    ttt.setSpot(Spot::Center(), Mark::X);
    ttt.setSpot(Spot{Side::Left,Side::Left}, Mark::X);
}

//*
void playTTT::initTestCase()
{
    std::cerr << "stuff\n";
}

void playTTT::cleanupTestCase()
{
    ttt.clear();
    std::cerr << "cleaned\n";
}
// */

void playTTT::test_clear_works()
{
    for (int i = 0 ; i < 9 ; i++ )
    {
        ttt.setSpot(Spot::FromIndex(i), Mark::X);
    }
    cleanup();
    QTEST_ASSERT(!ttt.isFinished());
}
void playTTT::test_isFinished()
{
    cleanup();
    for (int i = 0 ; i < 9 ; i++ )
    {
        ttt.setSpot(Spot::FromIndex(i), Mark::X);
    }
    QTEST_ASSERT(ttt.isFinished());
}

void playTTT::test_is_spot_empty()
{
    cleanup();

    QVERIFY(center.GetIndex() < 9);

    QVERIFY(ttt.isEmpty(center));
}


void playTTT::test_set_spot_isnt_empty()
{
    cleanup();

    ttt.setSpot(center,Mark::X);
    QVERIFY(!ttt.isEmpty(center));
}

void playTTT::test_get_mark()
{
    cleanup();

    ttt.setSpot(center,Mark::X);
    QVERIFY(ttt.getSpot(center) == Mark::X);

}

void playTTT::test_find_best_spot_empty()
{
    cleanup();

    Spot spot{ttt.findBestMove(Mark::X)};
    QVERIFY( spot.cross_ == Side::Center && spot.down_ == Side::Center);
}

void playTTT::test_find_best_spot_a_corner()
{
    cleanup();

    Spot spot{ttt.findMove(Mark::X)};
    ttt.setSpot(spot, Mark::X);

    Spot nextSpot{ttt.findMove(Mark::O)};
    QVERIFY( nextSpot.cross_ == Side::Left && nextSpot.down_ == Side::Left);
}

void playTTT::test_opposed_corners_side_up()
{
    cleanup();
    ttt.setSpot(Spot::FromIndex(0), Mark::X); // X
    ttt.setSpot(Spot::FromIndex(4), Mark::O); //  O
    ttt.setSpot(Spot::FromIndex(8), Mark::X); //  oX
    auto spot {ttt.findBestMove(Mark::O) };

    std::cerr << "picked: " << spot.GetIndex() << "\n";
    QVERIFY(spot == Spot::FromIndex(1)); // 7
}

void playTTT::test_is_winning_move_invalids_are_not()
{
    cleanup();

    ttt.setSpot(center, Mark::X);
    QVERIFY(!ttt.isWinningMove(center, Mark::X));
}

void playTTT::test_mark_flips_to_and_fro()
{
    cleanup();

    Mark x{Mark::X};
    Mark o = x;
    o++;
    QVERIFY( o != x);

    Mark back = o;
    back++;
    QVERIFY( back == Mark::X);

    Mark same = ++Mark::Empty;
    QVERIFY( same == Mark::Empty);
}
void playTTT::test_is_winning_move_tl_diag()
{
    cleanup();

    setTlCc();

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Left}, Mark::X));
    QVERIFY(!ttt.isWinningMove(Spot{Side::Center,Side::Right}, Mark::X));
    QVERIFY(ttt.isWinningMove(Spot{Side::Right,Side::Right}, Mark::X));
}

void playTTT::test_blocking_move_isnt_winning_move_tl_diag()
{
    cleanup();

    setTlCc();

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Right}, Mark::O));
}


void playTTT::test_find_the_best_winning_move()
{
    cleanup();

    setTlCc();

    auto spot = ttt.findBestMove(Mark::X);
    QVERIFY(spot == br);
}

void playTTT::test_find_the_best_blocking_move()
{
    cleanup();

    setTlCc();

    auto spot = ttt.findBestMove(Mark::X);

    QVERIFY(spot == br);

}

void playTTT::test_find_winning_b4_blocking_moveII()
{
    cleanup();

    ttt.setSpot(Spot::FromIndex(0), Mark::X); // X12
    ttt.setSpot(Spot::FromIndex(3), Mark::X); // XO5
    ttt.setSpot(Spot::FromIndex(4), Mark::O); // o78

    Spot shouldPick(Spot::FromIndex(6));
    QVERIFY(ttt.isWinningMove(shouldPick, Mark::X));

    auto spot = ttt.findBestMove(Mark::O);
    std::cerr << " picked: " << (int)spot.down_ << -(int)spot.cross_ << "\n";
    QVERIFY(spot == shouldPick);
}


void playTTT::test_find_winning_b4_blocking_move()
{
    cleanup();

    ttt.setSpot(Spot::FromIndex(0), Mark::X);
    ttt.setSpot(Spot::FromIndex(6), Mark::X); // XO
    ttt.setSpot(Spot::FromIndex(1), Mark::O); // x
    ttt.setSpot(Spot::FromIndex(7), Mark::O); // XO
    auto spot = ttt.findBestMove(Mark::X);

    QVERIFY(spot == Spot::FromIndex(3));
}

//*
void playTTT::test_corner_othe_side_stategy()
{
    cleanup();

    ttt.setSpot(Spot::FromIndex(8), Mark::X); // o
    ttt.setSpot(Spot::FromIndex(4), Mark::O); // XO
    ttt.setSpot(Spot::FromIndex(3), Mark::X); //   X
    auto spot = ttt.findBestMove(Mark::O);

    std::cerr << "picked " << spot.GetIndex() << "}\n";
    QVERIFY(spot == Spot::FromIndex(6));
}
// */

void playTTT::test_is_winning_move_empty_but_out_of_line()
{
    cleanup();
    setTlCc();

    QVERIFY(!ttt.isWinningMove(Spot{Side::Right,Side::Center}, Mark::X));
}


/* // */
QTEST_APPLESS_MAIN(playTTT)

#include "tst_playttt.moc"
