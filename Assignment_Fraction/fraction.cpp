#include "fraction.h"

fraction :: fraction()
{
    nume = deno = 0;
}

fraction :: fraction(int n,int d)
{
    nume = n;
    deno = d;
}

fraction fraction :: operator+(fraction f)
{
    fraction f3;
    f3.nume = (this -> nume * f.deno) + (f.nume * this -> deno);
    f3.deno = this -> deno * f.deno;
    return f3;
}

fraction fraction :: operator-(fraction f)
{
    fraction f3;
    f3.nume = (this -> nume * f.deno) - (f.nume * this -> deno);
    f3.deno = this -> deno * f.deno;
    return f3;
}

fraction fraction :: operator*(fraction f)
{
    fraction f3;
    f3.nume = (this -> nume * f.nume);
    f3.deno = this -> deno * f.deno;
    return f3;
}

bool fraction :: operator==(fraction f)
{
    if(this -> nume == f.nume && this -> deno == f.deno)
    {
        cout << "Yes, The fraction are equal";
        return true;
    }
    else 
    {
        cout << "No, The fraction are not equal";
        return false;
    }
}

void fraction :: operator+=(fraction f)
{
    this -> nume = (this->nume * f.deno) + (f.nume * this -> deno); 
    this -> deno = (this -> deno * f.deno);
}

void fraction :: operator-=(fraction f)
{
    this -> nume =(this -> nume * f.deno) - (f.nume * this -> deno);
    this -> deno = (this -> deno * f.deno);
}

void fraction :: operator*=(fraction f)
{
    this -> nume = this-> nume * f.nume;
    this -> deno = this ->deno * f.deno;
}

// void fraction :: simplification()
// {
//     int n,d;
//     bool e = true;
//     for (int i = (this ->nume * this -> deno); i > 1;i--)
//     { 
//         if ((this -> nume % i == 0) && (this -> deno % i == 0))
//         {
//             n = this -> nume / i;
//             d = this -> deno / i;
//         }
//         else
//         {
//             e = false;
//         }
//     }
//     cout << "simplest form=" << n << "/" << d << endl;
// }

void simplification(fraction& f)
{
    int n,d;
    bool e = true;
    for (int i = (f.nume * f.deno); i > 1;i--)
    { 
        if ((f.nume % i == 0) && (f.deno % i == 0))
        {
            f.nume = f.nume / i;
            f.deno = f.deno / i;
        }
        else
        {
            e = false;
        }
    }
}

ostream& operator<<(ostream& out,const fraction& f)
{
    out << f.nume << "/" << f.deno;
    return out;
}

istream& operator>>(istream& in,fraction& f)
{
    in >> f.nume >>f.deno;
    return in;
}