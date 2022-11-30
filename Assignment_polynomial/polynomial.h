#include<iostream>
using namespace std;

class node;
class polynomial;
class term;

class term
{
    int exp;
    double cof;
    public:
        term();
        term(double ,int);
        term(const term&);
        term operator+(const term&);
        term operator*(const term&);
        bool operator>(const term&);
        bool operator<(const term&);
        bool operator==(const term&);
        bool operator!=(const term&);
        term& operator=(const term&);
        friend ostream& operator<<(ostream &out,const term&);
        friend istream& operator>>(istream &in ,term&);
        friend polynomial;
        friend node;
        friend ostream& operator<<(ostream& out,const polynomial& ob);
        friend istream& operator>>(istream& in,polynomial& ob);

};

class node
{
    node* next;
    term t;
    public:
        node();
        node(term in);

        friend polynomial;
        friend term;
        friend ostream& operator<<(ostream& out,const polynomial& ob);
        friend istream& operator>>(istream& in,polynomial& ob);
};

class polynomial
{
    node* head = NULL;
    public:
        polynomial();
        polynomial(const polynomial&);
        ~polynomial();
        void del();
        polynomial operator+(const polynomial& ob);
        polynomial operator+=(const polynomial & ob);
        polynomial operator+=(const term &ob);
        polynomial operator*(const term& ob);
        polynomial operator*(const polynomial& ob);
        polynomial operator=(const polynomial& ob);
        friend ostream& operator<<(ostream& out,const polynomial& ob);
        friend istream& operator>>(istream& in,polynomial& ob);
        friend node;
        friend term;
};
