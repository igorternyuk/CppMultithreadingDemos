/* 
 * File:   primes.hpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 13:48
 */

#ifndef PRIMES_HPP
#define PRIMES_HPP

#include <cstdlib>

void findPrimes(unsigned int start, unsigned int end);
void findPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numOfThreads);
void testPrimes();
void testPrimesWithThreads();
#endif /* PRIMES_HPP */

