/**
 * @file Vector.h
 * @brief Class for data-holding vector expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"
#include "Matrix.h"

/**
 * Class Definition
 */
template<uint8_t n>
class Vector : public Matrix<n, 1>
{
public:

	/**
	 * @brief Default zero constructor
	 */
	Vector() {}

	/**
	 * @brief Matrix expression constructor
	 */
	Vector(const MatrixExp<n, 1>& mat)
	{
		(*this) = mat;
	}

	/**
	 * @brief Expression assignment operator
	 * @return Self-reference
	 */
	Vector& operator=(const MatrixExp<n, 1>& rhs)
	{
		if (this != &rhs)
		{
			for (uint8_t i = 0; i < n; i++)
			{
				(*this)(i) = rhs.get(i, 0);
			}
		}
		return (*this);
	}

	/**
	 * @brief Constructs 1D vector from scalar
	 */
	Vector(float scalar) : Vector<1>()
	{
		(*this)(0) = scalar;
	}
};
