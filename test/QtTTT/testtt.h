#ifndef TESTTT_H
#define TESTTT_H

#include <QObject>
#inlcude <QTest/QTest>

class TestTt : public QObject
{
    Q_OBJECT
public:
    explicit TestTt(QObject *parent = nullptr);
private slots:
    void emptyIsntFinished();
};

#endif // TESTTT_H
