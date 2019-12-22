/**
 * @file VectorExp.h
 * @brief Superclass for vector expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "LinearCpp.h"

/**
 * Class Definition
 */
template<uint8_t n>
class VectorExp : public MatrixExp<n, 1>
{
public:

	/**
	 * @brief Vector dot product
	 */
	friend float dot(
		const VectorExp<n>& lhs,
		const VectorExp<n>& rhs)
	{
		float sum = 0.0f;
		if (&lhs == &rhs)
		{
			// Dot product with self
			for (uint8_t i = 0; i < n; i++)
			{
				float elem = lhs.get(i);
				sum += elem * elem;
			}
		}
		else
		{
			// Unique dot product
			for (uint8_t i = 0; i < n; i++)
			{
				sum += lhs.get(i) * rhs.get(i);
			}
		}
		return sum;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Vector index [0...n-1]
	 */
	virtual float get(uint8_t i) const
	{
		return 0.0f;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Row index [0...m-1]
	 * @param j Col index [0...n-1]
	 */
	float get(uint8_t i, uint8_t j) const override
	{
		return get(i);
	}

protected:

	/**
	 * @brief Default constructor made protected to preclude use
	 */
	VectorExp()
	{
		return;
	}
};
