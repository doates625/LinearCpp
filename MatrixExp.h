/**
 * @file MatrixExp.h
 * @brief Superclass for matrix expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <stdint.h>
#include <math.h>

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class MatrixExp
{
public:

	/**
	 * @brief Tests matrix equality
	 * @return True if expression is equal to rhs
	 */
	bool operator==(const MatrixExp<m, n>& rhs)
	{
		for (uint8_t i = 0; i < m; i++)
		{
			for (uint8_t j = 0; j < n; j++)
			{
				if (get(i, j) != rhs.get(i, j))
				{
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * @brief Tests matrix inequality
	 * @return True if expression is not equal to rhs
	 */
	bool operator!=(const MatrixExp<m, n>& rhs)
	{
		return !((*this) == rhs);
	}

	/**
	 * @brief Trace of square matrices
	 */
	friend float trace(const MatrixExp<m, n>& mat)
	{
		float sum = 0.0f;
		for (uint8_t i = 0; i < m; i++)
		{
			sum += mat.get(i, i);
		}
		return sum;
	}

	/**
	 * @brief Euclydian norm of matrices
	 */
	friend float norm(const MatrixExp<m, n>& mat)
	{
		float sum = 0.0f;
		for (uint8_t i = 0; i < m; i++)
		{
			for (uint8_t j = 0; j < n; j++)
			{
				float elem = mat.get(i, j);
				sum += elem * elem;
			}
		}
		return sqrtf(sum);
	}

	/**
	 * @brief Casts 1 x 1 matrix expression to float
	 */
	operator float()
	{
		return get(0, 0);
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	virtual float get(uint8_t i, uint8_t j) const
	{
		return 0.0f;
	}

	/**
	 * @brief Returns true if expression is fully evaluated
	 */
	virtual bool evaluated() const
	{
		return false;
	}

protected:

	/**
	 * @brief Default constructor made protected to preclude use
	 */
	MatrixExp()
	{
		return;
	}
};
