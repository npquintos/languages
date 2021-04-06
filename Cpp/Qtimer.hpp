#include <chrono>

/* USAGE

#include "Qtimer.hpp"

int main(void)
{
    Qtimer tmr(7); // 7 ticks which could be in msec, sec, min, hr, to be specified later
    tmr.start();
    while (true) {
        if (tmr.timed_out<hoursQ>) // here is where you specify the unit of the ticks; see last paragraph below for other "units"
            break;  // time is up! break out of the loop.
        if (some condition needing to re-start timer)
            tmr.restart(); // you could use tmr.start() also because they are identical but this clarifies the intent.
    }
    return 0;
 }
 
 */

class Qtimer
{
    private:
        std::chrono::time_point<std::chrono::system_clock> start_time;
        long time_expiration;
    public:
        void start(void);       // start the timer
        void restart(void);     // restart the timer; actually same code as start()
        void set(long i);       // set a new value for timer duration in 'ticks'
        template <typename T>
        bool timed_out(void);   // check if timer has timed out; must specify duration of 'ticks'
        Qtimer(int t): time_expiration{t} {} // constructor where 'ticks' to timeout is set
};

template <typename T>
bool Qtimer::timed_out()
{
    T time_past = std::chrono::duration_cast<T> (std::chrono::system_clock::now() - start_time);
    return time_past.count() >= time_expiration;
}

typedef std::chrono::hours hoursQ;
typedef std::chrono::minutes minutesQ;
typedef std::chrono::seconds secondsQ;
typedef std::chrono::milliseconds millisecondsQ;
