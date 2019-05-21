/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "intergal.hpp"

std::mutex result_mutex;
double result = 0;

std::mutex task_mutex;
std::queue<Task> tasks;

void Executor::operator()() const
{
    while(true)
    {
        Task t;
        std::lock_guard<std::mutex> lock(task_mutex);
        if(!tasks.empty())
        {
            t = tasks.front();
            tasks.pop();
        }

        if(t)
        {
            t();
            std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;
        }
        else
        {
            break;
        }
    }
}

 void Integrator::operator()() const
    {
        double res = 0;
        for(double x = left; x < right; x += eps)
        {
            res += (0.5f * (func(x) + func(x + eps)) * eps);
        }
        
        std::lock_guard<std::mutex> guard(result_mutex);
        result += res;
        
    }

double integrate()
{
    double eps = 1e-6;
    auto func = [](double x){ return 1 / (1 + x * x);};
    for(int x = -10; x <= 10; ++x)
    {
        tasks.push(Integrator(func, x, x + 1, eps));
    }
    
    std::vector<std::thread> threads(5);
    for(auto& thread : threads)
    {
        thread = std::thread(Executor());
    }
    
    for(auto& thread : threads)
    {
        thread.join();
    }
    
    std::cout << "Result = " << result << std::endl;
}

