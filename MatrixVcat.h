/**
 * @file MatrixVcat.h
 * @brief Class for matrix vertical concatenation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m_lhs, uint8_t m_rhs, uint8_t n>
class MatrixVcat: public MatrixExp<m_lhs + m_rhs, n>
{
public:

	/**
	 * @brief Friend constructor [lhs; rhs]
	 */
	MatrixVcat(const MatrixExp<m_lhs, n>& lhs, const MatrixExp<m_rhs, n>& rhs)
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
		return (i < m_lhs) ? lhs->get(i, j) : rhs->get(i - m_lhs, j);
	}

protected:
	
	// Matrix pointers
	const MatrixExp<m_lhs, n>* lhs;
	const MatrixExp<m_rhs, n>* rhs;
};

/**
 * @brief Matrix vertical concatenation [lhs; rhs]
 */
template<uint8_t m_lhs, uint8_t m_rhs, uint8_t n>
MatrixVcat<m_lhs, m_rhs, n> vcat(
	const MatrixExp<m_lhs, n>& lhs,
	const MatrixExp<m_rhs, n>& rhs)
{
	return MatrixVcat<m_lhs, m_rhs, n>(lhs, rhs);
}
