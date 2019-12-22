/**
 * @file VectorMul.h
 * @brief Class for matrix-vector multiplication expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "VectorExp.h"
#include "Matrix.h"
#include "Vector.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class VectorMul: public VectorExp<m>
{
public:

	/**
	 * @brief Friend constructor (mat * vec)
	 */
	VectorMul(const MatrixExp<m, n>& mat, const VectorExp<n>& vec) :
		mat_ptr(&mat),
		vec_ptr(&vec)
	{
		// Conditionally copy vector
		if (!vec.evaluated() && m > 1)
		{
			vec_copy = vec;
			vec_ptr = &vec_copy;
		}
	}

	/**
	 * @brief Returns element of expression
	 * @param i Vector index [0...m-1]
	 */
	float get(uint8_t i) const override
	{
		float sum = 0.0f;
		for (uint8_t j = 0; j < n; j++)
		{
			sum += mat_ptr->get(i, j) * vec_ptr->get(j);
		}
		return sum;
	}

protected:
	
	// Operand pointers
	const MatrixExp<m, n>* mat_ptr;
	const VectorExp<n>* vec_ptr;

	// Internal vector copy
	Vector<n> vec_copy;
};

/**
 * @brief Matrix-vector product operator (mat * vec)
 */
template<uint8_t m, uint8_t n>
VectorMul<m, n> operator*(const MatrixExp<m, n>& mat, const VectorExp<n>& vec)
{
	return VectorMul<m, n>(mat, vec);
}
