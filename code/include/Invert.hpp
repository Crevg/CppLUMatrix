/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: 
 * @Date  : 03.03.2018
 */

#include <cmath>
#include <limits>
#include <functional>
#include <iostream>
#include <algorithm>

#include "Matrix.hpp"
#include "SolveLU.hpp"

#ifndef ANPI_INVERT_HPP
#define ANPI_INVERT_HPP

namespace anpi
{


template <typename T>
void invert(const anpi::Matrix<T> &A, anpi::Matrix<T> &Ai){
    std::vector<T> Aj;
    std::vector<T> ij = std::vector<T>(A.rows(), 0.0);
    int n = A.rows();
    Ai = anpi::Matrix<T>(n, n, 0.0);
    for (int j = 0; j < n; ++j){
        ij = std::vector<T>(A.rows(), 0.0);
        ij[j] = 1;
        solveLU(A, Aj, ij);
        for (int i = 0; i < n; ++i ){
            Ai[i][j] = Aj[i];
        }
    }
    
}

} //anpi

#endif
