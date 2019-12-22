/**
 * @file MatrixSum.h
 * @brief Class for matrix summation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class MatrixSum : public MatrixExp<m, n>
{
public:

	/**
	 * @brief Friend constructor
	 * @param lhs Lhs matrix to add
	 * @param rhs Rhs matrix to add
	 */
	MatrixSum(const MatrixExp<m, n>& lhs, const MatrixExp<m, n>& rhs)
	{
		this->lhs = &lhs;
		this->rhs = &rhs;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return lhs->get(i, j) + rhs->get(i, j);
	}

protected:
	
	// Matrix pointers
	const MatrixExp<m, n>* lhs;
	const MatrixExp<m, n>* rhs;
};

/**
 * @brief Matrix summation operator (lhs + rhs)
 */
template<uint8_t m, uint8_t n>
MatrixSum<m, n> operator+(
	const MatrixExp<m, n>& lhs,
	const MatrixExp<m, n>& rhs)
{
	return MatrixSum<m, n>(lhs, rhs);
}
