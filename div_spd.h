/**
 * @file div_spd.h
 * @brief Functions for in-place symmetric positive-definite matrix division
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "Matrix.h"
#include "MatrixTrn.h"
#include "chol.h"

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
