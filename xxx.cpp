#include "xxx.hpp"
#include <iomanip>
using namespace std;
matrix::matrix()
{
    row=0;
    row=0;
}
matrix::matrix (const matrix& mat)
{
    row=mat.row;
    col=mat.col;
    data=mat.data;
}
matrix::matrix(int r,int c,int d[])
{
    row=r;
    col=c;
    data = new int* [row];
    for (int i = 0; i < row; i++)
        data[i] = new int [col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            data[i][j] = d[i * col + j];
    }
}
matrix matrix::operator+  (matrix mat) // Add if same dimensions
{
    int result[row*col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            result[i*col+j]=data[i][j]+mat.data[i][j];
    }
    matrix mat0(row,col,result);
    return mat0;
}
matrix matrix::operator-  (matrix mat) // Sub if same dimensions
{
    int result[row*col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            result[i*col+j]=data[i][j]-mat.data[i][j];
    }
    matrix mat0(row,col,result);
    return mat0;
}
matrix matrix::operator*  (matrix mat) // Multi if col1 == row2
{
    int result[row*mat.col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<mat.col ; j++)
        {
            result[i*mat.col+j]=0;
            for (int k=0 ; k<col ; k++)
                result[i*mat.col+j]+=data[i][k]*mat.data[k][j];
        }
    }
    matrix mat0(row,mat.col,result);
    return mat0;
}
matrix matrix::operator+  (int scalar)  // Add a scalar
{
    int result[row*col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            result[i*col+j]=data[i][j]+scalar;
    }
    matrix mat0(row,col,result);
    return mat0;
}
matrix matrix::operator-  (int scalar)  // Subtract a scalar
{
    int result[row*col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            result[i*col+j]=data[i][j]-scalar;
    }
    matrix mat0(row,col,result);
    return mat0;
}
matrix matrix::operator*  (int scalar)  // Multiple by scalar
{
    int result[row*col];
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            result[i*col+j]=data[i][j]*scalar;
    }
    matrix mat0(row,col,result);
    return mat0;
}
matrix matrix::operator+= (matrix mat) // mat1 changes & return
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]+=mat.data[i][j];
    }
}
matrix matrix::operator-= (matrix mat) // mat1 changes + return new
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]-=mat.data[i][j];
    }
}
matrix matrix::operator+= (int scalar)   // change mat & return new matrix
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]+=scalar;
    }
}
matrix matrix::operator-= (int scalar)   // change mat & return new matrix
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]-=scalar;
    }
}
void   matrix::operator++ ()   	// Add 1 to each element ++mat
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]++;
    }
}
void   matrix::operator-- ()    	// Sub 1 from each element --mat
{
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
            data[i][j]--;
    }
}
bool   matrix::operator== (matrix mat)	// True if identical
{
    bool x = true;
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
        {
            if (data[i][j] != mat.data[i][j])
            {
                x = false;
                break;
            }
        }
    }
    return x;
}
bool   matrix::operator!= (matrix mat) 	// True if not same
{
    bool x = false;
    for (int i=0 ; i<row ; i++)
    {
        for (int j=0 ; j<col ; j++)
        {
            if (data[i][j] != mat.data[i][j])
            {
                x = true;
                break;
            }
        }
    }
    return x;
}
bool   matrix::isSquare   ()  // True if square matrix
{
    bool x = true;
    if (row != col)
        x = false;
    return x;
}
bool   matrix::isSymetric ()  // True if square and symmetric
{
    bool x = false;
    if (isSquare())
    {
        x = true;
        for (int i=0 ; i<row ; i++)
        {
            for (int j=0 ; j<col ; j++)
            {
                if (data[i][j] != data[j][i])
                {
                    x = false;
                    break;
                }
            }
        }
    }
    return x;
}
bool   matrix::isIdentity ()  // True if square and identity
{
    bool x = false;
    if (isSquare())
    {
        x = true;
        for (int i=0 ; i<row ; i++)
        {
            for (int j=0 ; j<col ; j++)
            {
                if (i==j && data[i][j]!=1)
                {
                    x=false;
                    break;
                }
                if (i!=j && data[i][j]!=0)
                {
                    x = false;
                    break;
                }
            }
        }
    }
    return x;
}
matrix matrix::transpose()    // Return new matrix with the transpose
{
    int result[row*col];
    for (int i=0 ; i<col ; i++)
    {
        for (int j=0 ; j<row ; j++)
            result[i*row+j] = data[j][i];
    }
    matrix mat0(col,row,result);
    return mat0;
}
bool matrix::chekDimentions(matrix mat)
{
    if (row==mat.row && col==mat.col)
        return true;
    else
    {
        cout << "The matrices are not equal in dimentions" << endl;
        return false;
    }
}
int matrix::getRow()
{
    return row;
}
int matrix::getCol()
{
    return col;
}
std::istream& operator>> (std::istream& in , matrix& mat)
{
    int r,c;
    cout << "Enter the number of rows and colomns :";
    cin >> r >> c;
    int elements[r*c]={0};
    cout << "Enter the matrix elements" << endl;
    for (int i=0 ; i<r*c ; i++)
        cin >> elements[i];
    mat=matrix(r,c,elements);
    return in;
}
std::ostream& operator<< (std::ostream& out , matrix mat)
{
    for (int i=0 ; i<mat.row ; i++)
    {
        out << "|";
        for (int j=0 ; j<mat.col ; j++)
            out << setw(3) << mat.data[i][j] << " ";
        out << "|" << endl;
    }
    return out;
}
//Supporting functions
void getX_Y (int& x, int& y ,int n)
{
    cout << "Enter the number of matrices you want to use" << endl;
    cout << "X=";
    cin >> x;
    cout << "Y=";
    cin >> y;
    while (x<1 || x>n || y<1 || y>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX_Y(x,y,n);
    }
}
void getX_Scalar (int& x, int& scalar ,int n)
{
    cout << "Enter the number of matrix you want to use and the scalar" << endl;
    cout << "X=";
    cin >> x;
    cout << "scalar=";
    cin >> scalar;
    while (x<1 || x>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX_Scalar(x,scalar,n);
    }
}
void getX (int& x ,int n)
{
    cout << "Enter the number of matrix you want to use" << endl;
    cout << "X=";
    cin >> x;
    while (x<1 || x>n)
    {
        cout << "There is only " << n << " matrices, you must choose from 1 to " << n << endl;
        getX(x,n);
    }
}

