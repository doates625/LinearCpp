/**
 * @file MatrixNeg.h
 * @brief Class for matrix negation expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class MatrixNeg : public MatrixExp<m, n>
{
public:

	/**
	 * @brief Friend constructor
	 * @param mat Matrix to negate
	 */
	MatrixNeg(const MatrixExp<m, n>& mat)
	{
		this->mat = &mat;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return -(mat->get(i, j));
	}

	/**
	 * @brief Returns evaluation status of inner matrix
	 * 
	 * Simple negation is not enough to justify copying matrix
	 * under repeated get() call conditions.
	 */
	bool evaluated() const
	{
		return mat->evaluated();
	}

protected:
	
	// Matrix pointer
	const MatrixExp<m, n>* mat;
};

/**
 * @brief Matrix negation operator
 */
template<uint8_t m, uint8_t n>
MatrixNeg<m, n> operator-(const MatrixExp<m, n>& mat)
{
	return MatrixNeg<m, n>(mat);
}
