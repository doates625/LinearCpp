/**
 * @brief MatrixEye.h
 * @brief Class for matrix identity expressions
 */
#pragma once
#include "LinearCpp.h"

/**
 * Class Definition
 */
template<uint8_t n>
class MatrixEye : public MatrixExp<n, n>
{
public:

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	virtual float get(uint8_t i, uint8_t j) const
	{
		return (i == j) ? 1.0f : 0.0f;
	}

	/**
	 * @brief Returns true indicating expression is fully evaluated
	 */
	virtual bool evaluated() const
	{
		return true;
	}
};

/**
 * @brief Returns n x n identity matrix
 */
template<uint8_t n>
MatrixEye<n> eye()
{
	return MatrixEye<n>();
}
