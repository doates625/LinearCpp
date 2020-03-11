/**
 * @file dot.h
 * @brief Function for inner products
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"
#include "MatrixTrn.h"
#include "MatrixMul.h"

/**
 * @brief Inner product trace(lhs' * rhs)
 */
template<uint8_t m, uint8_t n>
float dot(const MatrixExp<m, n>& lhs, const MatrixExp<m, n>& rhs)
{
    return trace(trn(lhs) * rhs);
}
