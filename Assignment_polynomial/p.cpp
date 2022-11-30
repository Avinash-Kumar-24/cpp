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
        polynomial operator+=(const term &ob);
        polynomial operator+(const polynomial& ob);
        polynomial operator*(const polynomial& ob);
        // polynomial& operator=(const polynomial& ob);
        // polynomial operator*(const term& ob);
        void del();
        friend ostream& operator<<(ostream& out,const polynomial& ob);
        friend istream& operator>>(istream& in,polynomial& ob);
        friend node;
        friend term;
};

term :: term()
{
    cof = exp = 0;
}

term :: term(double c,int e)
{
    cof = c;
    exp = e;
}

term :: term(const term& ob)
{
    cof = ob.cof;
    exp = ob.exp;
}

term  term :: operator+(const term& ob)
{
    term res;
    if(exp == ob.exp)
    {
        res.cof = cof + ob.cof;
        res .exp = exp;
        return res;
    }
    else
    {
        cout << "The exponent of both the term are not equal!";
        return res;
    }
}

term term :: operator*(const term &ob)
{
    term res;
    
    res.cof = cof * ob.cof;
    res.exp = exp + ob.exp;

    return res;
}

bool term :: operator>(const term& ob)
{
    if(exp > ob.exp)
        return true;
    else
        return false;
}

bool term :: operator<(const term& ob)
{
    if(exp > ob.exp)
        return false;
    else
        return true;
}

bool term :: operator==(const term& ob)
{
    if(exp == ob.exp)
        return true;
    else 
        return false;
}

bool term :: operator!=(const term& ob)
{
    if(exp != ob.exp)
        return true;
    else
        return false;
}

term& term :: operator=(const term& ob)
{
    cof = ob.cof;
    exp = ob.exp;

    return *this;
}

ostream& operator<<(ostream& out,const term& ob)
{
    out << ob.cof <<"X^" <<ob.exp;
    return out;
}

istream& operator>>(istream& in,term& ob)
{
    in >> ob.cof >> ob.exp;
    return in;
}


node :: node()
{
    next = NULL;
}

node :: node(term in)
{
    t = in;
    next = NULL;
}

polynomial :: polynomial()
{
    head = NULL;
}

polynomial polynomial :: operator+=(const term& t)
{
    node* add = new node(t);
    node* cur = head;
    if(head == NULL)
    {
        head  = add;
        return *this;
    }
    else
    {
        while(cur -> next != NULL)
        {
            cur = cur -> next;
        }
        cur -> next  = add;
    }
    return *this;
}

void polynomial :: del()
{
    node* cur = head;
    while(cur != NULL)
    {
        node* temp = cur;
        cur = cur -> next;
        delete[] temp;
    }
    // node* t = cur;
    // cur = cur -> next;
    //     delete t;
}

polynomial polynomial :: operator+(const polynomial& ob)
{
    polynomial res;
    node* cur = ob.head;

    while(head != NULL && cur != head)
    {    
        if(head -> t.exp > cur -> t.exp)
        {
            res += head -> t;
            // res.head = res.head -> next;
            head = head -> next;
        }
        else if(head -> t.exp < cur -> t.exp)
        {
            res += cur -> t;
            // res.head = res.head ->next;
            cur = cur -> next;
        }
        else
        {
            res += (head -> t + cur -> t);
            // res.head = res.head -> next;
            head = head -> next;
            cur = cur -> next;
        }
    }

    while(head  != NULL)
    {
        res += head -> t;
        // res.head = res.head -> next;
        head = head -> next;
    }

    while(cur  != NULL)
    {
        res += cur -> t;
        // res.head = res.head -> next;
        cur = cur -> next;
    }

    return res;
}

// polynomial& polynomial :: operator=(const polynomial& ob)
// {
//     node *cur = ob.head;
//     while(cur != NULL)
//    {
//         head->t.cof = cur ->t.cof;
//         head -> t.exp = cur -> t.exp;
//         cur = cur -> next;
//         head = head -> next;
//     }
//     return *this;
// }

// polynomial polynomial :: operator*(const term& ob)
// {
//     polynomial res;
//     node* cur = head;
//     while(cur != NULL)
//     {
//         res += cur->t * ob;
//         cur = cur -> next;
//     }
//     return res;
// }

polynomial polynomial :: operator*(const polynomial& ob)
{
    polynomial res;
    polynomial tmp;
    node* cur = ob.head;
    node* curr = head;
    while(cur != NULL)
    {  
        curr = head;
        while(curr != NULL)
        {
           tmp += (curr -> t * cur -> t);
            // res.head = res.head -> next;
            curr = curr -> next;
        }
        res = res + tmp;
        cur = cur -> next;
        // tmp.del();
    }
    return res;
}

ostream& operator<<(ostream& out,const polynomial& ob)
{
    node* cur = ob.head;
    while(cur != NULL)
    {
        out <<cur -> t << " + ";
        cur = cur -> next;
    }
    return out;
}

int main()
{
    term t1(2,5),t2(5,4),t3;
    t3 = t1 * t2;
    polynomial p1,p2,p3;
    p1 += t1;
    p1 += t2;
    // p1 += t3;
    // cout << p1;
    
    p2 += t1;
    p2 += t2;
    // cout << p2;
    // p2 += t3;
    // cout << t3;
    p1 = p1*t1;
    cout << p3;

    return 0;
}