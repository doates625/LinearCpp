# LinearCpp
Light-weight C++ linear algebra library for embedded systems  
Written by Dan Oates (WPI Class of 2020)

### Description
I developed this library due to the lack of easily-installable and well-documented linear algebra libraries targeted for embedded systems. It is loosely based on [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) but heavily simplified for embedded systems, using 8-bit indices to save memory and 32-bit floating-point elements to reduce template complexity. The library uses only static memory and achieves variable-size matrices and vectors via dimension templates, which also enforce dimension rules for functions and operators at compilation. Efficient lazy evaluation of nesteded expressions is implemented via a polymorphic expression class structure.

This library currently only supports simple matrix-vector arithmetic such as addition, multiplication, and dot products. I plan to eventually add more advanced features including system solvers, inverse and pseudo-inverse, QR and LU decompositions, Gaussian elimination, determinant, rank, and Gram-Schmidt orthogonalization. All new features are unit tested before release on master.

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
```
