/**
 * @file div_ut.h
 * @brief Functions for in-place upper-triangular matrix division
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"
#include "Matrix.h"

/**
 * @brief Solve U*X = B in-place
 * @param U Upper-triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void ldiv_ut(const MatrixExp<m, m>& U, Matrix<m, n>& B)
{
	// For each row of B
	for (uint8_t ir = 0; ir < m; ir++)
	{
		// Diagonal inverse
		const uint8_t i = m - 1 - ir;
		const float Uii_inv = 1.0f / U.get(i, i);

		// For each col of B
		for (uint8_t j = 0; j < n; j++)
		{
			for (uint8_t k = i + 1; k < m; k++)
			{
				B(i, j) -= U.get(i, k) * B(k, j);
			}
			B(i, j) *= Uii_inv;
		}
	}
}

/**
 * @brief Solve X*U = B in-place
 * @param B Solution matrix B -> X
 * @param U Upper-triangular matrix
 */
template<uint8_t m, uint8_t n>
void rdiv_ut(Matrix<m, n>& B, const MatrixExp<n, n>& U)
{
	// For each col of B
	for (uint8_t j = 0; j < n; j++)
	{
		// Diagonal inverse
		const float Ujj_inv = 1.0f / U.get(j, j);

		// For each row of B
		for (uint8_t i = 0; i < m; i++)
		{
			for (uint8_t k = 0; k < j; k++)
			{
				B(i, j) -= U.get(k, j) * B(i, k);
			}
			B(i, j) *= Ujj_inv;
		}
	}
}
