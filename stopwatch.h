#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class StopWatch : public QObject
{
    Q_OBJECT
public:
    explicit StopWatch(QObject *parent = nullptr);
    void start();
    void stop();
    void circle();
    void clear();
    ~StopWatch();
private:
    int ms = 0;
    int s = 0;
    int m = 0;

    int circles_ms = 0;
    int circles_s = 0;
    int circles_m = 0;

    QTimer *t;
signals:
    void sig_TIMER(int ms, int s, int m);
    void sig_CIRCLE(int ms, int s, int m);
public slots:
    void timerSlot();
};

#endif // STOPWATCH_H
