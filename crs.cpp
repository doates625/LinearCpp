/**
 * @file crs.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "crs.h"

/**
 * @brief Vector cross product lhs x rhs
 */
Vector<3> crs(const Matrix<3, 1>& lhs, const Matrix<3, 1>& rhs)
{
	Vector<3> ret;
	ret(0) = lhs.get(1, 0) * rhs.get(2, 0) - lhs.get(2, 0) * rhs.get(1, 0);
	ret(1) = lhs.get(2, 0) * rhs.get(0, 0) - lhs.get(0, 0) * rhs.get(2, 0);
	ret(2) = lhs.get(0, 0) * rhs.get(1, 0) - lhs.get(1, 0) * rhs.get(0, 0);
	return ret;
}
