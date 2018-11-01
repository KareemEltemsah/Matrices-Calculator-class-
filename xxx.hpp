#ifndef _xxx_hpp
#define _xxx_hpp
#include <iostream>
class matrix
{
private:
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row;
    int col;
public:
    matrix ();
    matrix (const matrix& mat);
    matrix (int r,int c,int d[]);
    matrix operator+  (matrix mat); // Add if same dimensions
    matrix operator-  (matrix mat); // Sub if same dimensions
    matrix operator*  (matrix mat); // Multi if col1 == row2
    matrix operator+  (int scalar);  // Add a scalar
    matrix operator-  (int scalar);  // Subtract a scalar
    matrix operator*  (int scalar);  // Multiple by scalar

    // Student #2 with the middle ID (e.g., 20170082)
    // The last operator >> takes an istream and a matrix and return the
    // the same istream so it is possible to cascade input like
    // cin >> matrix1 >> matrix2 << endl;
    matrix operator+= (matrix mat); // mat1 changes & return
					    // new matrix with the sum
    matrix operator-= (matrix mat); // mat1 changes + return new
					     // matrix with difference
    matrix operator+= (int scalar);   // change mat & return new matrix
    matrix operator-= (int scalar);   // change mat & return new matrix
    void   operator++ ();   	// Add 1 to each element ++mat
    void   operator-- ();    	// Sub 1 from each element --mat
    friend std::istream& operator>> (std::istream& in , matrix& mat);
    // Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
    // and return istream to allow cascading input

    //Student #3 with the biggest ID (e.g., 20170089)
    friend std::ostream& operator<< (std::ostream& out , matrix mat);
    // Print matrix  as follows (2 x 3)			4	 6 	  8
    // and return ostream to cascade printing	9	12  	123
    bool   operator== (matrix mat);	// True if identical
    bool   operator!= (matrix mat); 	// True if not same
    bool   isSquare   ();  // True if square matrix
    bool   isSymetric ();  // True if square and symmetric
    bool   isIdentity ();  // True if square and identity
    matrix transpose();    // Return new matrix with the transpose
    bool chekDimentions(matrix mat);

    int getRow();
    int getCol();
};
std::istream& operator>> (std::istream& in , matrix& mat);
std::ostream& operator<< (std::ostream& out , matrix mat);
//Supporting functions
void getX_Y (int& x, int& y ,int n);
void getX_Scalar (int& x, int& scalar ,int n);
void getX (int& x ,int n);
#endif
