/**
 * @file MatrixHcat.h
 * @brief Class for matrix horizontal concatenation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n_lhs, uint8_t n_rhs>
class MatrixHcat: public MatrixExp<m, n_lhs + n_rhs>
{
public:

	/**
	 * @brief Friend constructor [lhs, rhs]
	 */
	MatrixHcat(const MatrixExp<m, n_lhs>& lhs, const MatrixExp<m, n_rhs>& rhs)
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
		return (j < n_lhs) ? lhs->get(i, j) : rhs->get(i, j - n_lhs);
	}

protected:
	
	// Matrix pointers
	const MatrixExp<m, n_lhs>* lhs;
	const MatrixExp<m, n_rhs>* rhs;
};

/**
 * @brief Matrix horizontal concatenation [lhs, rhs]
 */
template<uint8_t m, uint8_t n_lhs, uint8_t n_rhs>
MatrixHcat<m, n_lhs, n_rhs> hcat(
	const MatrixExp<m, n_lhs>& lhs,
	const MatrixExp<m, n_rhs>& rhs)
{
	return MatrixHcat<m, n_lhs, n_rhs>(lhs, rhs);
}
