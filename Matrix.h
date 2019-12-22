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
	 * @brief Constructs matrix with zero elements
	 */
	Matrix()
	{
		for (uint8_t i = 0; i < m; i++)
		{
			for (uint8_t j = 0; j < n; j++)
			{
				data[i][j] = 0.0f;
			}
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
	 * @brief Returns row count
	 */
	uint8_t get_m() const
	{
		return m;
	}

	/**
	 * @brief Returns col count
	 */
	uint8_t get_n() const
	{
		return n;
	}

	/**
	 * @brief Reference to element
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float& operator()(uint8_t i, uint8_t j)
	{
		return data[i][j];
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
					data[i][j] = rhs.get(i, j);
				}
			}
		}
		return *this;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return data[i][j];
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
	float data[m][n];
};
