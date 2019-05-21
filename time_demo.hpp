/* 
 * File:   time_demo.hpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 11:58
 */

#ifndef TIME_DEMO_HPP
#define TIME_DEMO_HPP

#include <vector>
#include <chrono>
#include <ctime>
#include <cmath>
#include <thread>
#include <mutex>
#include <iostream>
#include <sstream>

int getRandom(int max, int min = 0);
void executeThread(int id);
void testThreads();

#endif /* TIME_DEMO_HPP */

