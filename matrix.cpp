#include "matrix.hpp"
#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

std::mutex mutex;

Matrix matrixMultiply(const Matrix& a, const Matrix& b, size_t numOfThreads)
{
    const size_t rowCount = a.at(0).size();
    const size_t colCount = b.size();
    
    Matrix res;
    for(size_t row = 0; row < rowCount; ++row)
    {
        std::vector<double> line(colCount);
        res.push_back(line);
    }
    
    std::vector<std::thread> threads(numOfThreads);
    
    for(size_t k = 0; k < numOfThreads; ++k)
    {
        threads[k] = std::thread([&a, &b, &res, k, rowCount, colCount, numOfThreads](){
            const size_t rowMin = k * rowCount / numOfThreads;
            const size_t rowMax = rowMin + rowCount / numOfThreads;
            for(size_t row = rowMin; row < rowMax; ++row)
            {
                for(size_t col = 0; col < colCount; ++col)
                {            
                    std::lock_guard<std::mutex> matrixElementLock(mutex);  
                    for(size_t n = 0; n < rowCount; ++n)
                    {
                        res[row][col] += a[row][n] * b[n][col];
                    }  
                }
            }
        });

    }
    
    
    for(auto& t: threads)
    {
        t.join();
    }
    
    return res;
}



void matrixPrint(const Matrix& matrix)
{
    for(size_t row = 0; row < matrix.size(); ++row)
    {
        std::cout << std::endl;
        for(size_t col = 0; col < matrix.at(0).size(); ++col)
        {
            std::cout << matrix[row][col] << " ";
        }
        std::cout << std::endl;
    }
}