#include "time_demo.hpp"

int getRandom(int max, int min)
{
    return min + rand() % (max - min);
}

void executeThread(int id)
{
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    tm myLocalTime = *localtime(&sleepTime);
    std::cout << "Thread id = " << id << " Sleep time = " << std::ctime(&sleepTime) << std::endl;
    std::cout << "Day " << myLocalTime.tm_mday << std::endl;
    std::cout << "Mounth " << myLocalTime.tm_mon << std::endl;
    std::cout << "Year " << (myLocalTime.tm_year + 1900) << std::endl;
    std::cout << "Hour " << myLocalTime.tm_hour << std::endl;
    std::cout << "Min " << myLocalTime.tm_min << std::endl;
    std::cout << "Sec " << myLocalTime.tm_sec << std::endl;
    
    int randPeriod = getRandom(10);
    auto sleepingPeriod = std::chrono::seconds(randPeriod);
    std::this_thread::sleep_for(sleepingPeriod);
    std::cout << "Sleeping for " << randPeriod << std::endl;
    nowTime = std::chrono::system_clock::now();
    auto awakeTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread id = " << id << " Awake time = " << std::ctime(&awakeTime) << std::endl;
}

void testThreads()
{
    srand(time(NULL));
    std::vector<std::thread> threads(5);
    for(int i = 0; i < threads.size(); ++i)
    {
        threads[i] = std::thread(executeThread, i + 1);
    }
    
    for(int i = 0; i < threads.size(); ++i)
    {
        threads[i].join();
    }
}