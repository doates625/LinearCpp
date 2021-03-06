# LinearCpp
Light-weight C++ linear algebra library for embedded systems  
Written by Dan Oates (WPI Class of 2020)

### Description
I developed this library due to the lack of easily-installable and well-documented linear algebra libraries targeted for embedded systems. It is loosely based on [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) but heavily simplified for embedded systems, using 8-bit indices to save memory and 32-bit floating-point elements to reduce template complexity. The library uses only static memory and achieves variable-size matrices and vectors via dimension templates, which also enforce dimension rules for functions and operators at compilation. Efficient evaluation of nesteded expressions is implemented via polymorphic expression classes.

This library currently only supports simple matrix-vector arithmetic such as addition, multiplication, and dot products. I plan to eventually add more advanced features including system solvers, inverse and pseudo-inverse, QR and LU decompositions, Gaussian elimination, determinant, rank, and Gram-Schmidt orthogonalization. All new features are unit tested.

### API Summary
#### Matrices and Vectors
The fundamental units of LinearCpp are matrices and vectors. They are constructed with dimensions as templates:
```
#include <LinearCpp.h>	// LinearCpp header file
Matrix<m, n> mat;	// Construct m x n zero matrix
Vector<n> vec;		// Construct n x 1 zero vector
```
Matrix and vector elements can be accessed and modified via parenthesis operators:
```
s1 = mat(i, j);		// Get matrix entry at row i col j (i = 0...m-1, j = 0...n-1)
mat(i, j) = s2;		// Assign matrix entry at (i, j)
s3 = vec(i);		// Get vector entry at index i (i = 0...n-1)
vec(i) = s4;		// Assign vector entry at (i)
```
#### Operators and Functions
The full list of library operators and functions is shown below. All matrix operations also apply to vectors of appropriate dimensions. However, instances of Matrix<n, 1> must be explicitely cast to Vector<n> for vector functions such as dot and cross products.
```
// Matrix-Vector Operators
Matrix<m, n> + Matrix<m, n>	// Addition
Matrix<m, n> - Matrix<m, n>	// Subtraction
Matrix<m, p> * Matrix<p, n>	// Matrix multiplication
Matrix<m, n> * Vector<n>	// Vector multiplication
scalar * Matrix<m, n>		// Scalar multiplication
Matrix<m, n> / scalar		// Scalar division
-Matrix<m, n>			// Negation

// Matrix-Vector Functions
Matrix<n, m> trn(Matrix<m, n>)				// Transposition
Vector<3> crs(Vector<3>, Vector<3>)			// Cross-product
Matrix<m, n1+n2> hcat(Matrix<m, n1>, Matrix<m, n2>)	// Horizontal concatenation
Matrix<m1+m2, n> vcat(Matrix<m1, n>, Matrix<m2, n>)	// Vectical concatenation
Matrix<n, n> eye<n>()					// Identity

// Scalar Functions
float trace(Matrix<n, n>)	// Trace
float norm(Matrix<n, n>)	// Euclydian norm
float dot(Vector<n>, Vector<n>)	// Dot product

// Typecast Operators
operator float(Matrix<1, 1>)	// Cast matrix to scalar
Matrix<1, 1>(float)		// Cast scalar to matrix
Vector<1>(float)		// Cast scalar to vector

// In-Place Solvers and Decomposers
// L = Lower-triangular
// U = Upper-triangular
// S = Symmetric positive-definite

// Matrix Decompositions
chol(Matrix<n, n>)	// Cholesky decomposition

// System Solvers
ldiv_lt(L<m,m>, B<m,n>)		// Solve LX = B
rdiv_lt(B<m,n>, L<n,n>)		// Solve XL = B
ldiv_ut(U<m,m>, B<m,n>)		// Solve UX = B
rdiv_ut(B<m,n>, U<n,n>)		// Solve XU = B
ldiv_spd(S<m,m>, B<m,n>)	// Solve SX = B
rdiv_spd(B<m,n>, S<n,n>)	// Solve XS = B
```

#### Circular Self-Assignment
Due to the use of expressions to avoid copying, assignment operations with self-reference may lead to undefined behavior. For example, the following multiplication will yield an incorrect result:
```
Matrix<3, 3> mat;
// Assign matrix entries...
mat = mat * mat;
```
This problem can be easily solved by forcing hard evaluation of the expression before assignment:
```
mat = Matrix<3, 3>(mat * mat);
```