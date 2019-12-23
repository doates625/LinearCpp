/**
 * @file Vector.h
 * @brief Class for data-holding vector expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "VectorExp.h"

/**
 * Class Definition
 */
template<uint8_t n>
class Vector : public VectorExp<n>
{
public:

	/**
	 * @brief Constructs vector with zero elements
	 */
	Vector()
	{
		for (uint8_t i = 0; i < n; i++)
		{
			data[i] = 0;
		}
	}

	/**
	 * @brief Assignment constructor
	 */
	Vector(const MatrixExp<n, 1>& mat)
	{
		(*this) = mat;
	}

	/**
	 * @brief Reference to element
	 * @param i Vector index [0...n-1]
	 */
	float& operator()(uint8_t i)
	{
		return data[i];
	}
	
	/**
	 * @brief Expression assignment operator
	 */
	Vector& operator=(const MatrixExp<n, 1>& rhs)
	{
		if (this != &rhs)
		{
			for (uint8_t i = 0; i < n; i++)
			{
				data[i] = rhs.get(i, 0);
			}
		}
		return *this;
	}

	/**
	 * @brief Returns element of expression
	 * @param i Vector index [0...n-1]
	 */
	float get(uint8_t i) const override
	{
		return data[i];
	}

	/**
	 * @brief Returns true to indicate evaluation
	 */
	bool evaluated() const override
	{
		return true;
	}

protected:

	// Vector Elements
	float data[n];
};
