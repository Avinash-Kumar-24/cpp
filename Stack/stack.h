#include<iostream>
using namespace std;

struct stack
{
    int *arr;
    int size;
    int tos;
    public:
        stack();
        stack(int);
        stack(const stack &ob);
        ~stack();
        void push(int);
        void pop();
        int peek();
        bool isfull();
        bool isempty();
};