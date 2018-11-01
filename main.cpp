// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 1 - (Problem 0 in assignment I)
// Program: yyy.cpp
// Purpose: Matrices calculator
// Author:  Kareem Ahmed Eltemsah 20170195 / Kerolos Farah Adeeb 20170201
// Date:    25 October 2018
// Version: 1.0

#include "xxx.hpp"
#include <iostream>
using namespace std;
int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int n=3;
    matrix *mat;
    mat=new matrix[20];
    mat[0]=matrix(4,2,data1);
    mat[1]=matrix(2,3,data2);
    mat[2]=matrix(4,2,data3);
    // The next code will not work until you write the functions
    cout << "The program have 3 matrices in defualt" << endl;
    cout << "Mat1" << endl << mat[0] << endl;
    cout << "Mat2" << endl << mat[1] << endl;
    cout << "Mat3" << endl << mat[2] << endl;
    while (1==1)
    {
        string choice;
        cout << "The program now have " << n << " matrices\nWhat do you want to do" << endl << endl;
        cout << "Student #1" << endl;
        cout << "1- MatX + MatY\n2- MatX - MatY\n3- MatX * MatY\n4- MatX + scalar\n5- MatX - scalar\n6- MatX * scalar" << endl;
        cout << "Student #2" << endl;
        cout << "7- MatX += MatY\n8- MatX -= MatY\n9- MatX += scalar\n10- MatX -= scalar\n11- ++MatX\n12- --MatX\n13- Enter a new matrix" << endl;
        cout << "Student #3" << endl;
        cout << "14- Print MatX\n15- MatX == MatY\n16- MatX != MatY\n17- MatX is square\n18- MatX is symetric\n19- MatX is identity\n20- Transpose Matx" << endl;
        cout << "\n21- Show all the stored matrices\n22-Copy matX in matY or a new matrix\n0- Close the program" << endl;
        cin >> choice;
        int x,y,scalar;
        bool chek;
        if (choice=="1")//MatX + MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
                cout << (mat[x-1]+mat[y-1]);
        }
        else if (choice=="2")//MatX - MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
                cout << (mat[x-1]-mat[y-1]);
        }
        else if (choice=="3")//MatX * MatY
        {
            getX_Y(x,y,n);
            int c,r;
            c=mat[x-1].getCol();
            r=mat[y-1].getRow();
            if (c==r)
                cout << (mat[x-1]*mat[y-1]);
            else
                cout << "Number of col in MatX must equal number of row in MatY" << endl;
        }
        else if (choice=="4")//MatX + n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]+scalar);
        }
        else if (choice=="5")//MatX - n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]-scalar);
        }
        else if (choice=="6")//MatX * n
        {
            getX_Scalar(x,scalar,n);
            cout << (mat[x-1]*scalar);
        }
        else if (choice=="7")//MatX += MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
            {
                mat[x-1]+=mat[y-1];
                cout << mat[x-1];
            }
        }
        else if (choice=="8")//MatX -= MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
            {
                mat[x-1]-=mat[y-1];
                cout << mat[x-1];
            }
        }
        else if (choice=="9")//MatX += n
        {
            getX_Scalar(x,scalar,n);
            mat[x-1]+=scalar;
            cout << mat[x-1];
        }
        else if (choice=="10")//MatX -= n
        {
            getX_Scalar(x,scalar,n);
            mat[x-1]-=scalar;
            cout << mat[x-1];
        }
        else if (choice=="11")//++MatX
        {
            getX(x,n);
            ++mat[x-1];
            cout << mat[x-1];
        }
        else if (choice=="12")//--MatX
        {
            getX(x,n);
            --mat[x-1];
            cout << mat[x-1];
        }
        else if (choice=="13")//Enter new matrix
        {
            ++n;
            cin >> mat[n-1];
            cout << "Mat" << n << endl << mat[n-1] << endl;
        }
        else if (choice=="14")//Print MatX
        {
            getX(x,n);
            cout << mat[x-1];
        }
        else if (choice=="15")//MatX == MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
                cout << (mat[x-1] == mat[y-1]) <<endl;
        }
        else if (choice=="16")//MatX != MatY
        {
            getX_Y(x,y,n);
            if (mat[x-1].chekDimentions(mat[y-1]))
                cout << (mat[x-1] != mat[y-1]) <<endl;
        }
        else if (choice=="17")//MatX is square
        {
            getX(x,n);
            cout << (mat[x-1].isSquare()) <<endl;
        }
        else if (choice=="18")//MatX is symetric
        {
            getX(x,n);
            cout << (mat[x-1].isSymetric()) <<endl;
        }
        else if (choice=="19")//MatX is identity
        {
            getX(x,n);
            cout << (mat[x-1].isIdentity()) <<endl;
        }
        else if (choice=="20")//Transpose MatX
        {
            getX(x,n);
            cout << (mat[x-1].transpose());
        }
        else if (choice=="21")//Show all the stored matrices
        {
            for (int i=0 ; i<n ; i++)
                cout << "Mat" << i+1 << endl << mat[i] << endl;
        }
        else if (choice=="22")//Show all the stored matrices
        {
            getX(x,n);
            cout << "You want to copy mat" << x << " in\n1-MatY\n2-New mat" << endl;
            char copyChoice;
            cin >> copyChoice;
            if (copyChoice=='1')
                getX(y,n);
            else if (copyChoice=='2')
            {
                n++;
                y=n;
            }
            else
                cout << "error" << endl;
            mat[y-1]=matrix(mat[x-1]);
            cout << mat[y-1] << endl;
        }
        else if (choice=="0")//Close the program
            return 0;
        else
            cout << "Please choose from 0 to 21 only" << endl;
    }
    return 0;
}
