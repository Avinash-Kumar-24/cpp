#include "matrix.h"


matrix :: matrix()
{
    row = 3;
    col = 3;

    mat = new int*[row];
    for(int i = 0;i<row;i++)
    {
        mat[i] = new int[col];
    }
}

matrix :: matrix(int r,int c)
{
    row = r;
    col = c;
    mat = new int*[r];
    for(int i = 0;i<r;i++)
    {
        mat[i] = new int[c];
    }
}

matrix matrix :: operator+(matrix m)
{
    matrix res;
    res.row = row;
    res.col = col;

    for(int i = 0;i< row;i++)
    {
        for(int j = 0;j < col; j++)
        {
            res.mat[i][j] = this->mat[i][j] + m.mat[i][j];
        }
    }
    return res;
}

matrix matrix :: operator*(matrix m)
{
    matrix res;
    res.col = m.col;
    res.row = row;
    for(int i = 0;i< this -> row;i++)
    {
        for(int j = 0;j < m.col;j++)
        {
            res.mat[i][j] = 0;
            for(int k = 0;k < m.row;k++)
            {
                res.mat[i][j] += this -> mat[i][k] * m.mat[k][j];
            }
        }
    }
    return res;
}

matrix matrix :: transpose()
{
    matrix res;
    res.row = col;
    res.col = row;
    for(int i = 0;i < row ;i++)
    {
        for(int j = 0;j < col;j++)
        {
            res.mat[i][j] = this -> mat[j][i];
        }
    }
    return res;
}

istream& operator>>(istream& in,matrix& a)
{
    for(int i = 0;i< a.row;i++)
    {
        for(int j = 0;j< a.col; j++)
        {
            in >> a.mat[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out,const matrix& a)
{
    for(int i = 0;i< a.row;i++)
    {
        for(int j = 0;j< a.col; j++)
        {
            out << a.mat[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}