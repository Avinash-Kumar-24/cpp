#include "stack.h"

stack :: stack(const stack &ob)
{
    this -> size = ob.size;
    this -> tos = ob.tos;
    int i = size - 1;
    while(i--)
    {
        this -> arr[i] = ob.arr[i];
    }
}

stack :: ~stack()
{
    while(!isempty())
    {
        pop();
    }
}

stack :: stack()
{
    arr = new int[5];
    size = 5;
    tos = -1;
}
stack :: stack(int size)
{
    arr = new int[size];
    this -> size = size;
    tos = -1;
}

bool stack :: isempty()
{
    if(tos == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool stack :: isfull()
{
    if(tos == size -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack :: push(int element)
{
    if(isfull())
    {
        cout << "Sorry, Stack is already full,I am unable to put" << " : "<< element <<",inside the stack" << endl;
    }
    else
    {
        arr[++tos] = element;
    }
}

void stack :: pop()
{
    if(isempty())
    {
        cout << "Sorry, Stack is having nothing in it" << endl;
    }
    else
    {
        arr[tos--];
    }
}

int stack :: peek()
{
    if(isempty())
    {
        cout << "There is nothing inside it" << endl;
    }
    else
    {
        return arr[tos];
    }
    return 0;
}

