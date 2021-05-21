#ifndef __TIMER_H__
#define __TIMER_H__

#include "common.h"

using namespace std::chrono;
class Timer
{
public:
    Timer() : m_begin(high_resolution_clock::now()) {}
    void reset() { m_begin = high_resolution_clock::now(); }
    //默认输出秒
    double elapsed() const
    {
        return duration_cast<duration<double>>(high_resolution_clock::now() - m_begin).count();
    }

    //微秒
    int64_t elapsed_micro() const
    {
        return duration_cast<chrono::microseconds>(high_resolution_clock::now() - m_begin).count();
    }

    inline void printElapsed()
    {
        auto m_end = elapsed();
        cout << "耗时: " << m_end << "s" << endl;
        reset();
    }

private:
    time_point<high_resolution_clock> m_begin;
};
#endif