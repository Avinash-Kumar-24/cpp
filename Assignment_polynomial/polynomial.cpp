#include "polynomial.h"

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

polynomial :: polynomial(const polynomial& ob)
{
    node* cur = ob.head;
    node* rescur = head;
    while(cur -> next != NULL)
    {
        rescur -> t = cur-> t;
        rescur = rescur -> next;
        cur = cur -> next;
    }
}

polynomial :: ~polynomial()
{
    node* cur = head;
    while(cur -> next != NULL)
    {
        node* temp = cur;
        cur = cur -> next;
        delete temp;
    }
    // node* t = cur;
    // cur = cur -> next;
    // delete t;
}

void polynomial :: del()
{
    node* cur = head;
    while(cur -> next != NULL)
    {
        node* temp = cur;
        cur = cur -> next;
            delete temp;
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

polynomial polynomial :: operator+=(const polynomial &ob)
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
    this -> head = res.head;

    return *this;
}

polynomial polynomial :: operator*(const term& ob)
{
    polynomial res;
    while(head != NULL)
    {
        res += head->t * ob;
        head = head -> next;
    }
    return res;
}

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

polynomial polynomial :: operator=(const polynomial& ob)
{
    node *cur = ob.head;
    while(cur -> next != NULL)
    {
        head -> t = cur ->t;
        cur = cur -> next;
        head = head -> next;
    }
    return *this;
}

ostream& operator<<(ostream& out,const polynomial& ob)
{
    node* cur = ob.head;
    while(cur -> next != NULL)
    {
        out << "The polynomial is:" << cur -> t;
        cur = cur -> next;
    }
    return out;
}

istream& operator>>(istream& in,polynomial& ob)
{
    node* cur = ob.head;
    while(cur -> next!= NULL)
    {
        in>>cur->t.cof >>cur ->t.exp;
        cur = cur -> next;
    }
    return in;
}