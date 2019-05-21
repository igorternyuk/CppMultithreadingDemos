/* 
 * File:   bank_account.hpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 12:54
 */

#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <thread>
#include <mutex>
#include <string>
#include <chrono>
#include <ctime>

class Bank
{
public:
    explicit Bank();
    void getMoney(int id, double withdrawal);
    std::string getTime();
    void testWithdraw();
private:
    double accountBalance;
    std::mutex accountLock;
    bool checkIfEnoughMoney() const;
};


#endif /* BANK_ACCOUNT_HPP */

