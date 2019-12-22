/**
 * @file MatrixTrn.h
 * @brief Class for matrix transpose expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"

/**
 * Class Definition
 */
template<uint8_t m, uint8_t n>
class MatrixTrn : public MatrixExp<n, m>
{
public:

	/**
	 * @brief Friend constructor
	 * @param mat Matrix to transpose
	 */
	MatrixTrn(const MatrixExp<m, n>& mat)
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
		return mat->get(j, i);
	}

	/**
	 * @brief Returns evaluation status of inner matrix
	 * 
	 * Simple index-flipping is not enough to justify copying matrix
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
 * @brief Matrix transpose operator
 */
template<uint8_t m, uint8_t n>
MatrixTrn<m, n> trn(const MatrixExp<m, n>& mat)
{
	return MatrixTrn<m, n>(mat);
}
