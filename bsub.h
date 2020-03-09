/**
 * @file bsub.h
 * @brief Functions for in-place backsubstitution
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <math.h>
#include "Matrix.h"

/**
 * @brief In-place lower-triangular back-substitution L*X = B
 * @param L Lower triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void bsubl(const MatrixExp<m, m>& L, Matrix<m, n>& B)
{
	// For each row
	for (uint8_t i = 0; i < m; i++)
	{
		// Diagonal inverse
		const float Lii_inv = 1.0f / L.get(i, i);

		// For each column
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
 * @brief In-place upper-triangular back-substitution U*X = B
 * @param U Upper triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void bsubu(const MatrixExp<m, m>& U, Matrix<m, n>& B)
{
	// For each row
	for (uint8_t ir = 0; ir < m; ir++)
	{
		// Diagonal inverse
		const uint8_t i = m - 1 - ir;
		const float Uii_inv = 1.0f / U.get(i, i);

		// For each column
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
