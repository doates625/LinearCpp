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

/**
 * @brief Solve S*X = B in-place
 * @param S Symmetric positive definite matrix S -> L
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void ldiv_spd(Matrix<m, m>& S, Matrix<m, n>& B)
{
	chol(S);			// S = L * L'
    ldiv_lt(S, B);		// Solve L * Y = B
	ldiv_ut(trn(S), B);	// Solve L' * X = Y
}

/**
 * @brief Solve S*A = B in-place
 * @param S Symmetric positive definite matrix S -> L
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void rdiv_spd(Matrix<m, n>& B, Matrix<n, n>& S)
{
	chol(S);			// A = L * L'
	rdiv_ut(B, trn(S));	// Solve Y * L' = B
	rdiv_lt(B, S);		// Solve X * L = Y
}
