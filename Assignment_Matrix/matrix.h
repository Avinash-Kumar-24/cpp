#include<iostream>
using namespace std;

class matrix
{
    int **mat;
    int row;
    int col;
    public:
        matrix();
        matrix(int,int);
        matrix operator+(matrix);
        matrix operator*(matrix);
        matrix transpose();
        friend istream& operator>>(istream& in,matrix&);
        friend ostream& operator<<(ostream& out,const matrix&);
};