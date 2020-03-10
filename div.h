/**
 * @file div.h
 * @brief Functions for matrix division
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "Matrix.h"
#include "MatrixTrn.h"
#include "chol.h"

/**
 * @brief In-place lower-triangular L*X = B
 * @param L Lower-triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void divl_lt(const MatrixExp<m, m>& L, Matrix<m, n>& B)
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
 * @brief In-place lower-triangular X*L = B
 * @param L Lower-triangular matrix
 * @param B Solution matrix B -> X
 * 
 * TODO optimize to prevent copies
 */
template<uint8_t m, uint8_t n>
void divr_lt(const MatrixExp<n, n>& L, Matrix<m, n>& B)
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

/**
 * @brief In-place upper-triangular U*X = B
 * @param U Upper-triangular matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void divl_ut(const MatrixExp<m, m>& U, Matrix<m, n>& B)
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
 * @brief In-place upper-triangular X*U = B
 * @param U Upper-triangular matrix
 * @param B Solution matrix B -> X
 * 
 * TODO optimize to prevent copies
 */
template<uint8_t m, uint8_t n>
void divr_ut(const MatrixExp<n, n>& U, Matrix<m, n>& B)
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

/**
 * @brief In-place A*X = B with Cholesky 
 * @param A Symmetric PD matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void divl_chol(const MatrixExp<m, m>& A, Matrix<m, n>& B)
{
	Matrix<m, m> L = A;
	chol(L);			// A = L * L'
    divl_lt(L, B);		// Solve L * Y = B
	divl_ut(trn(L), B);	// Solve L' * X = Y
}

/**
 * @brief Solve X*A = B with Cholesky decomposition
 * @param A Symmetric PD matrix
 * @param B Target matrix
 */
template<uint8_t m, uint8_t n>
Matrix<m, n> divr_chol(const MatrixExp<n, n>& A, const MatrixExp<m, n>& B)
{
	Matrix<n, n> L = A;
	chol(L);			// A = L * L'
	divr_ut(trn(L), B);	// Solve Y * L' = B
	divr_lt(L, B);		// Solve X * L = Y
}
