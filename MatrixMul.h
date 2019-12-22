/**
 * @file MatrixMul.h
 * @brief Class for matrix multiplication expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"
#include "Matrix.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t p, uint8_t n>
class MatrixMul: public MatrixExp<m, n>
{
public:

	/**
	 * @brief Friend constructor (lhs * rhs)
	 */
	MatrixMul(const MatrixExp<m, p>& lhs, const MatrixExp<p, n>& rhs) :
		lhs_ptr(&lhs),
		rhs_ptr(&rhs)
	{
		// Conditionally copy lhs
		if (!lhs.evaluated() && n > 1)
		{
			lhs_copy = lhs;
			lhs_ptr = &lhs_copy;
		}

		// Conditionally copy rhs
		if (!rhs.evaluated() && m > 1)
		{
			rhs_copy = rhs;
			rhs_ptr = &rhs_copy;
		}
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		float sum = 0.0f;
		for (uint8_t k = 0; k < p; k++)
		{
			sum += lhs_ptr->get(i, k) * rhs_ptr->get(k, j);
		}
		return sum;
	}

protected:
	
	// Matrix pointers
	const MatrixExp<m, p>* lhs_ptr;
	const MatrixExp<p, n>* rhs_ptr;

	// Internal matrix copies
	Matrix<m, p> lhs_copy;
	Matrix<p, n> rhs_copy;
};

/**
 * @brief Matrix product operator (lhs * rhs)
 */
template<uint8_t m, uint8_t p, uint8_t n>
MatrixMul<m, p, n> operator*(
	const MatrixExp<m, p>& lhs,
	const MatrixExp<p, n>& rhs)
{
	return MatrixMul<m, p, n>(lhs, rhs);
}
