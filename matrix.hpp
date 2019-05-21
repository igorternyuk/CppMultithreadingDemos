/* 
 * File:   matrix.hpp
 * Author: Igor Ternyuk <xmonad100 at gmail.com>
 *
 * Created on 21 мая 2019 г., 18:02
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include <cstdlib>

using Matrix = std::vector<std::vector<double>>;

Matrix matrixMultiply(const Matrix& first, const Matrix& second,
        size_t numOfThreads = 2);
void matrixPrint(const Matrix& matrix);

#endif /* MATRIX_HPP */

