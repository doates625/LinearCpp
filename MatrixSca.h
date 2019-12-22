/**
 * @file MatrixSca.h
 * @brief Class for matrix-scalar product expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class MatrixSca : public MatrixExp<m, n>
{
public:

	/**
	 * @brief Friend constructor
	 * @param scalar Scalar multiplier
	 * @param mat Matrix to scale
	 */
	MatrixSca(float scalar, const MatrixExp<m, n>& mat)
	{
		this->mat = &mat;
		this->scalar = scalar;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return scalar * mat->get(i, j);
	}

protected:
	
	// Expression members
	float scalar;
	const MatrixExp<m, n>* mat;
};

/**
 * @brief Matrix scaling operator
 */
template<uint8_t m, uint8_t n>
MatrixSca<m, n> operator*(float scalar, const MatrixExp<m, n>& mat)
{
	return MatrixSca<m, n>(scalar, mat);
}
