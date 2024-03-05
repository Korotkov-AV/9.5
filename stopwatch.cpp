#include "stopwatch.h"

StopWatch::StopWatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    QObject::connect(timer,  &QTimer::timeout, this, &StopWatch::timerSlot);
}

void StopWatch::start()
{
    timer->start(100);
}

void StopWatch::stop()
{
    timer->stop();
}

void StopWatch::circle()
{
    emit sig_CIRCLE(circles_ms, circles_s, circles_m);
    circles_ms = 0;
    circles_m = 0;
    circles_s = 0;
}

void StopWatch::clear()
{
    circles_ms = 0;
    circles_m = 0;
    circles_s = 0;
    ms = 0;
    s = 0;
    m = 0;
}

StopWatch::~StopWatch()
{
    delete timer;
}

void StopWatch::timerSlot()
{
    ms++;
    if (ms>=10){
        ms = 0;
        s++;
    }
    if (s>=60){
        s=0;
        m++;
    }
    circles_ms++;
    if (circles_ms>=10){
        circles_ms = 0;
        circles_s++;
    }
    if (circles_s>=60){
        circles_s=0;
        circles_m++;
    }
    emit sig_TIMER(ms,s,m);
}
