/**
 * @file Matrix.h
 * @brief Class for data-holding matrix expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class Matrix : public MatrixExp<m, n>
{
public:

	/**
	 * @brief Constructs matrix of zeros
	 */
	Matrix()
	{
		for (uint8_t k = 0; k < m*n; k++)
		{
			(*this)(k) = 0.0f;
		}
	}

	/**
	 * @brief Assignment constructor
	 */
	Matrix(const MatrixExp<m, n>& mat)
	{
		(*this) = mat;
	}

	/**
	 * @brief Constructs 1 x 1 matrix from scalar
	 */
	Matrix(float scalar) : Matrix<1, 1>()
	{
		(*this)(0) = scalar;
	}

	/**
	 * @brief Subscripted element reference
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float& operator()(uint8_t i, uint8_t j)
	{
		return data[i + m * j];
	}

	/**
	 * @brief Indexed element reference
	 * @param k Index (colum-major) [0...m*n-1]
	 */
	float& operator()(uint8_t k)
	{
		return data[k];
	}

	/**
	 * @brief Expression assignment operator
	 * @return Self-reference
	 */
	Matrix& operator=(const MatrixExp<m, n>& rhs)
	{
		if (this != &rhs)
		{
			for (uint8_t i = 0; i < m; i++)
			{
				for (uint8_t j = 0; j < n; j++)
				{
					(*this)(i, j) = rhs.get(i, j);
				}
			}
		}
		return (*this);
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return data[i + m * j];
	}

	/**
	 * @brief Returns true to indicate evaluation
	 */
	bool evaluated() const override
	{
		return true;
	}

protected:

	// Matrix Elements
	float data[m * n];
};
