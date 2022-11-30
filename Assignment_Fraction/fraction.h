#include<iostream>
using namespace std;

class fraction
{
    int nume;
    int deno;
    public:
        fraction();
        fraction(int,int);
        friend void simplification(fraction&);
        fraction operator+(fraction);
        fraction operator-(fraction);
        fraction operator*(fraction);
        bool operator==(fraction);
        void operator+=(const fraction);
        void operator-=(const fraction);
        void operator*=(const fraction);
        friend istream& operator>>(istream& in,fraction&);
        friend ostream& operator<<(ostream& out,const fraction&);
};