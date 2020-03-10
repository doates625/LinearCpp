/**
 * @file div.h
 * @brief Functions for matrix division
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "Matrix.h"
#include "MatrixTrn.h"
#include "chol.h"
#include "bsub.h"

/**
 * @brief Solve A*X = B in place with Cholesky decomposition
 * @param A Symmetric PD matrix
 * @param B Solution matrix B -> X
 */
template<uint8_t m, uint8_t n>
void divl_chol(const MatrixExp<m, m>& A, Matrix<m, n>& B)
{
	Matrix<m, m> L = A;
	chol(L);			// A = L * L'
    bsubl(L, B);		// Solve L * Y = B
	bsubu(trn(L), B);	// Solve L' * X = Y
}

/**
 * @brief Solve X*A = B with Cholesky decomposition
 * @param A Symmetric PD matrix
 * @param B Target matrix
 */
template<uint8_t m, uint8_t n>
Matrix<m, n> divr_chol(const MatrixExp<n, n>& A, const MatrixExp<m, n>& B)
{
	Matrix<n, m> trn_X = trn(B);
	divl_chol(A, trn_X);	// X' = A \ B'
	return trn(trn_X);
}
