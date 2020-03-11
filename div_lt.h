/**
 * @file div_lt.h
 * @brief Functions for in-place lower-triangular matrix division
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "MatrixExp.h"
#include "Matrix.h"

/**
 * @brief Solve L*X = B in-place
 * @param L Lower-triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void ldiv_lt(const MatrixExp<m, m>& L, Matrix<m, n>& B)
{
	// For each row of B
	for (uint8_t i = 0; i < m; i++)
	{
		// Diagonal inverse
		const float Lii_inv = 1.0f / L.get(i, i);

		// For each column of B
		for (uint8_t j = 0; j < n; j++)
		{
			for (uint8_t k = 0; k < i; k++)
			{
				B(i, j) -= L.get(i, k) * B(k, j);
			}
			B(i, j) *= Lii_inv;
		}
	}
}

/**
 * @brief Solve X*L = B in-place
 * @param B Solution matrix B -> X
 * @param L Lower-triangular matrix
 */
template<uint8_t m, uint8_t n>
void rdiv_lt(Matrix<m, n>& B, const MatrixExp<n, n>& L)
{
	// For each col of B
	for (uint8_t jr = 0; jr < n; jr++)
	{
		// Diagonal inverse
		const uint8_t j = n - 1 - jr;
		const float Ljj_inv = 1.0f / L.get(j, j);

		// For each row of B
		for (uint8_t i = 0; i < m; i++)
		{
			for (uint8_t k = j + 1; k < n; k++)
			{
				B(i, j) -= L.get(k, j) * B(i, k);
			}
			B(i, j) *= Ljj_inv;
		}
	}
}
