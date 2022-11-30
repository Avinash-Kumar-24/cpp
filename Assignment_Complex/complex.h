#include<iostream>
using namespace std;

class complex
{
    int real;
    int imag;

    public:
        complex();
        complex(int ,int);
        void set_real(int);
        void set_imaginary(int);
        void get_real();
        void get_imaginary();
        complex operator-(complex);
        complex operator+(complex);
        complex operator*(complex);
        bool operator==(complex);
        friend istream& operator>>(istream&,complex&);
        friend ostream& operator<<(ostream&,const complex&);
        // friend complex operator+(complex ,complex);
        // friend complex operator-(complex,complex);
};