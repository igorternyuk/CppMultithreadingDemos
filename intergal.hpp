/* 
 * File:   intergal.hpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 10:12
 */

#ifndef INTERGAL_HPP
#define INTERGAL_HPP

#include <iostream>
#include <queue>
#include <cstdlib>
#include <mutex>
#include <functional>
#include <thread>
#include <cmath>
#include <boost/any.hpp>

using Task = std::function<void()>;

struct Executor
{
    void operator()() const;
};

struct Integrator
{
    Integrator(std::function<double(double)> func, double left, double right,
    double eps): func(func), left(left), right(right), eps(eps)
    {}
    
    void operator()() const;
    
    std::function<double(double)> func;
    double left;
    double right;
    double eps;
};

double integrate();

#endif /* INTERGAL_HPP */

