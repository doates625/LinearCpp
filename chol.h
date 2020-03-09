/**
 * @file chol.h
 * @brief Function for in-place cholesky decomposition
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include <math.h>
#include "Matrix.h"

/**
 * @brief In-place Cholesky decomposition A = L*L'
 * @param A Symmetric positive definite matrix
 */
template<uint8_t n>
void chol(Matrix<n, n>& A)
{
	// For each column
	for (uint8_t j = 0; j < n; j++)
	{
		// Above diagonal
		for (uint8_t i = 0; i < j; i++)
		{
			A(i, j) = 0.0f;
		}

		// Diagonal
		for (uint8_t k = 0; k < j; k++)
		{
			float Ajk = A(j, k);
			A(j, j) -= Ajk * Ajk;
		}
		A(j, j) = sqrtf(A(j, j));

		// Below diagonal
		const float Ajj_inv = 1.0f / A(j, j);
		for (uint8_t i = j + 1; i < n; i++)
		{
			for (uint8_t k = 0; k < j; k++)
			{
				A(i, j) -= A(i, k) * A(j, k);
			}
			A(i, j) *= Ajj_inv;
		}
	}
}
