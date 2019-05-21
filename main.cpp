/* 
 * File:   main.cpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 10:09
 */

#include "intergal.hpp"
#include "time_demo.hpp"
#include "bank_account.hpp"
#include "primes.hpp"
#include "matrix.hpp"
/*
 * 
 */
int main(int argc, char** argv) {
    //integrate();
    //testThreads();
    //Bank bank;
    //bank.testWithdraw();
    //testPrimesWithThreads();
    
    Matrix a {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    Matrix b {
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2}
    };
    
    Matrix c = matrixMultiply(a, b, 3);
    matrixPrint(c);
    return 0;
}

