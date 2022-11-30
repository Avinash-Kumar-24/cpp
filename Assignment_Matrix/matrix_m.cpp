#include "matrix.h"



int main()
{
    matrix m1(2,2),m2(2,2);
    matrix m3,m5;

    cout <<"Enter the value in matrix 1:"<<endl;
    cin >> m1;
    cout <<"Enter the value in matrix 2:"<<endl;
    cin >> m2;
    cout << "Multiplication of two matrices:"<<endl;
    m3 = m1* m2;
    cout << m3;
    cout <<"Sum of two matrices:"<<endl;
    m5 = m1 + m2;
    cout << m5;
    matrix m4;
    cout <<"Transpose of matrix m3"<<endl;
    m4 = m3.transpose();
    cout << m4;
}