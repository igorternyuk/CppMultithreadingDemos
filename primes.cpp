#include "primes.hpp"
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>
#include <iostream>

std::mutex vectLock;
std::vector<unsigned int> vectPrimes;

void findPrimes(unsigned int start, unsigned int end)
{
    if(start == 0 || (start % 2 == 0 && start > 1)){
        ++start;
    }
    for(unsigned int x = start; x <= end; x += 2)
    {
        for(unsigned int y = 2; y < x; ++y){
            if((x % y) == 0){
                break;
            } else if((y + 1) == x) {
                std::lock_guard<std::mutex> lock(vectLock);
                vectPrimes.push_back(x);
            }
        }
    }
}

void findPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numOfThreads)
{
    std::vector<std::thread> threads(numOfThreads);
    unsigned int threadSpread = (end - start) / numOfThreads;
    std::cout << "threadSpread = " << threadSpread << std::endl;
    unsigned int newStart = start;
    std::cout << "newStart = " << newStart << std::endl;
    unsigned int newEnd = newStart + threadSpread - 1;
    std::cout << "newEnd = " << newEnd << std::endl;
    for(int i = 0; i < threads.size(); ++i)
    {
        threads[i] = std::thread(findPrimes, newStart, newEnd);
        newStart += threadSpread;
        newEnd += threadSpread;
    }
    
    for(auto& t: threads)
    {
        t.join();
    }
}

void testPrimes()
{
    vectPrimes.clear();
    std::cout << "Finding prime numbers without threads" << std::endl;
    auto startTime = clock();
    findPrimes(1, 100000);
    auto endTime = clock();
    for(auto& number: vectPrimes)
    {
        std::cout << number << std::endl;
    }
    std::cout << "Total primes: " << vectPrimes.size() << std::endl;
    std::cout << "Execution time = " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
}

void testPrimesWithThreads()
{
    vectPrimes.clear();
    std::cout << "Finding prime numbers with threads" << std::endl;
    auto startTime = clock();
    findPrimesWithThreads(1, 100000, 5);
    auto endTime = clock();
    for(auto& number: vectPrimes)
    {
        std::cout << number << std::endl;
    }
    std::cout << "Total primes: " << vectPrimes.size() << std::endl;
    std::cout << "Execution time = " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
}