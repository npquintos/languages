/* READ ME FIRST
 *
 * time_out specification could either be:
 *      - hoursQ
 *      - minutesQ
 *      - secondsQ
 *      - millisecondsQ
 *
 * Sample usage:
 *
 *  // example of timer using seconds
 *
 * Qtimer tmr(5);  // assume 5 ticks to time out
 * tmr.start();
 * while (true) {
 *      // Do something ....
 *     std::cout << "doing something seconds ..." << std::endl;
 *     if (tmr.timed_out<secondsQ>()) { // this is where you say 1 tick = 1 second
 *         break;
 *     }
 * }
 * std::cout << "timer timed out!" << std::endl;
 *
 *
 *
 * 
 *  // example of timer using minutes
 * 
 * tmr.set(1);  // assume 1 tick to time out
 * tmr.start();
 * while (true) {
 *      // Do something ....
 *     std::cout << "doing something minutes ..." << std::endl;
 *     if (tmr.timed_out<minutesQ>()) { // this is where you say 1 tick = 1 minute
 *         break;
 *     }
 * }
 * std::cout << "timer timed out!" << std::endl;
 *
 *
 *
 * 
 *  // example of timer using milliseconds
 *
 * tmr.set(5000);  // assume 5,000 ticks to time out
 * tmr.start();
 * while (true) {
 *      // Do something ....
 *     std::cout << "doing something milliseconds ..." << std::endl;
 *     if (tmr.timed_out<millisecondsQ>()) { // this is where you say 1 tick = 1 millisecond
 *         break;
 *     }
 * }
 * std::cout << "timer timed out!" << std::endl;
*/

#include "Qtimer.hpp"

void Qtimer::set(long i)
{
    time_expiration = i;
}

void Qtimer::start()
{
    start_time = std::chrono::system_clock::now();
}

void Qtimer::restart()
{
    start_time = std::chrono::system_clock::now();
}
