#include <QtTest>

// add necessary includes here

class funtioning : public QObject
{
    Q_OBJECT

public:
    funtioning();
    ~funtioning();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_empy_isnt_finished();
    void test_is_spot_empty();

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

#include "bcttt.h"

void funtioning::test_empy_isnt_finished()
{
    BcTTT ttt{};
    QVERIFY(!ttt.isFinished());
}

void funtioning::test_is_spot_empty()
{
    BcTTT ttt{};
    QVERIFY(ttt.isEmpty(Coord::center()));
}

QTEST_APPLESS_MAIN(funtioning)

#include "tst_funtioning.moc"
