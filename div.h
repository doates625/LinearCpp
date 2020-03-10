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
 * @brief Solve A*X = B in place with cholesky decomposition
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
