#include "stack.h"


int main()
{
    stack s1,s2;
   
    s1.push(2);
    s1.push(8);
    s1.push(6);
    s1.push(9);
    s1.push(105);
    s2 = s1;
    cout << "The Element at tos is:" <<s1.peek() << endl;
   
    cout << "The Element at tos is:" <<s2.peek() << endl;
     s2.pop();
    // s1.~stack();
    cout << "The Element at tos is:" <<s2.peek() << endl;
    return 0;
}