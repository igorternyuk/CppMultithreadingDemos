/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <iostream>
#include "bank_account.hpp"

Bank::Bank():
accountBalance(1000)
{

}

void Bank::getMoney(int id, double withdrawal) {
    std::lock_guard<std::mutex> lock(accountLock);
    std::cout << "Thread with id = " << id << " tries to withraw $" << withdrawal << std::endl;
    std::cout << "Thread ID = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if(checkIfEnoughMoney()){
        std::cout << "Success!" << std::endl;
        this->accountBalance -= withdrawal;
        std::cout << "New balance: $" << accountBalance << std::endl;
    } else {
        std::cout << "Not enough money!" << std::endl;
        std::cout << "Current balance: $" << accountBalance << std::endl;
    }
}

std::string Bank::getTime() {
    auto nowTime = std::chrono::system_clock::now();
    time_t currTime = std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&currTime);
}

bool Bank::checkIfEnoughMoney() const {
    return this->accountBalance > 0;
}

void Bank::testWithdraw() {
    std::vector<std::thread> pool(11);
    //pool.reserve(20);
    for(int i = 0; i < pool.size(); ++i)
    {
        pool[i] = std::thread(&Bank::getMoney, this, i + 1, 100.f);
    }
    for(int i = 0; i < pool.size(); ++i)
    {
        pool[i].join();
    }
}


