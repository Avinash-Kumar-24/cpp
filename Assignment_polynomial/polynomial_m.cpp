#include "polynomial.h"

int main()
{
    term t1(2,3),t2(3,3);
    term t3;
   
    polynomial p1,p2;
    p1 += t1;
    p1 += t2;
    cout << p1;
    return 0;
}