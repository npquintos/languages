#include <chrono>

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
