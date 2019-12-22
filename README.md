# LinearCpp
Light-weight C++ linear algebra library with static memory and lazy evaluation for embedded systems  
Written by Dan Oates (WPI Class of 2020)

### Description
I developed this library due to the lack of easily-installable and well-documented linear algebra libraries targeted for embedded systems. It is loosely based on [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) but heavily simplified for embedded systems, using 8-bit indices to save memory and 32-bit floating-point elements to reduce template complexity. It currently only supports simple matrix-vector arithmetic such as addition, scalar multiplication, dot and cross products. I plan to eventually add more advanced features including system solvers, inverse and pseudo-inverse, QR and LU decompositions, Gaussian elimination, determinant, rank, and Gram-Schmidt orthogonalization. This library has no dependencies beyond standard C includes. The library uses only static memory and achieves variable-size matrices and vectors via dimension templates, which also enforce dimension rules for addition and multiplication at compilation. Efficient lazy evaluation of nesteded expressions is implemented via a polymorphic expression class structure. All features are unit tested.

### API Summary
#### Matrices and Vectors
The fundamental units of LinearCpp are matrices and vectors. They are created with dimensions as templates:
```
Matrix<m, n> mat;	// Construct m x n zero matrix
Vector<n> vec;		// Construct n x 1 zero vector
```
Matrix and vector elements can be accessed and modified via the () operator:
```
s1 = mat(i, j);	// Get matrix entry at row i col j (i = 0...m-1, j = 0...n-1)
mat(i, j) = s2;	// Assign matrix entry at (i, j)
s3 = vec(i);	// Get vector entry at index i (i = 0...n-1)
vec(i) = s4;	// Assign vector entry at (i)
```
#### Operations
TODO