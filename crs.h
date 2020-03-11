/**
 * @file crs.h
 * @brief Function for vector cross products
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "Matrix.h"
#include "Vector.h"

/**
 * Function declaration
 */
Vector<3> crs(const Matrix<3, 1>& lhs, const Matrix<3, 1>& rhs);
