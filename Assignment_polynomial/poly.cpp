#include<iostream>
using namespace std;
class Node;
class Polynomial;
class Term
{
    int exponent;
    double coeff;
    public:
        Term();
        Term(double cof,int exp);
        //Term(const Term& ob);
        friend Term operator+(Term a,Term b);
        friend Term operator*(Term a,Term b);
        friend bool operator>(const Term &a,const Term &b);
        friend bool operator==(const Term &a,const Term &b);
        friend bool operator!=(const Term &a,const Term &b);
        //Term& operator=(const Term& rhs);
        friend istream& operator>>(istream& in, Term&ob);
        friend ostream& operator<<(ostream& out,const Term& ob);
        friend Node;
        friend Polynomial;
};
Term::Term()
{
    this->coeff=0.0;
    this->exponent=0;

}
Term::Term(double cof,int expo)
{
    this->coeff=cof;
    this->exponent=expo;
}
Term operator+(Term a,Term b)
{
    Term res;
    res.coeff=a.coeff+b.coeff;
    res.exponent=a.exponent;
    return res;

}
Term operator*(Term a,Term b)
{
    Term res;
    res.coeff=a.coeff*b.coeff;
    res.exponent=a.exponent+b.exponent;
    return res;
}
bool operator>(const Term &a,const Term &b)
{
    return a.exponent>b.exponent;
}
bool operator==(const Term &a,const Term &b)
{
    
    return ((a.coeff==b.coeff) && (a.exponent==b.exponent));

}
bool operator!=(const Term &a,const Term &b)
{
    return ((a.coeff!=b.coeff) && (a.exponent!=b.exponent));
}
/*Term& Term::operator=(const Term& rhs)
{
    if(this!=&rhs)
    {
        this->coeff=rhs.coeff;
        this->exponent=rhs.exponent;
    }
    return *this;
}*/
istream& operator>>(istream& in, Term&ob)
{
    in >> ob.coeff;
    in >> ob.exponent;
    return in;
}
ostream& operator<<(ostream& out,const Term& ob)
{
    out << ob.coeff << "^" <<  ob.exponent ;
    
    return out;
}
class Node
{
    Term t;
    Node * next;
    public:
        Node(Term in);
        ~Node();
        friend istream& operator>>(istream& in,Node &ob);
        friend ostream& operator<<(ostream & out,const Node& ob);
        friend Polynomial;
        friend istream& operator>>(istream& in,Polynomial &ob);
        friend ostream& operator<<(ostream& out,const Polynomial &ob);


};
Node::Node(Term in)
{
    this->t=in;
    this->next=NULL;
    

}
Node::~Node()
{
    delete next;
}

istream& operator>>(istream& in,Node &ob)
{
    in >> ob.t;
    return in;
}
ostream& operator<<(ostream& out,const Node& ob)
{
    
        out << ob.t;
        return out;
    
}

class Polynomial
{
    
    Node * head=NULL;
    public:
        Polynomial();
        Polynomial(const Polynomial& ob);
        ~Polynomial();
        Polynomial operator+(const Polynomial &ob);
        Polynomial operator+=(const Term& t);
        Polynomial operator+=(const Polynomial &rhs);
        Polynomial operator*(const Term& ob);
        Polynomial operator*(const Polynomial& ob);
        Polynomial& operator=(const Polynomial &rhs);
        friend istream& operator>>(istream& in,Polynomial &ob);
        friend ostream& operator<<(ostream& out,const Polynomial &ob);
    private:
        void del();
};


Polynomial::Polynomial()
{
    this->head=NULL;
}
Polynomial::Polynomial(const Polynomial& ob)
{
    Node *  curr=ob.head,*to=this->head;
    while(curr!=NULL)
    {
        to->t=curr->t;
        curr=curr->next;
        to=to->next;
    }
}
Polynomial Polynomial::operator+=(const Term& t)
{
    Node * add=new Node(t);
    //Node add(ob);
    Node * curr=head;
    if(head==NULL)
    {
        head=add;
        return *this;
    }
    else
    {
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=add;
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& ob)
{
    Node * h1=this->head,*h2=ob.head;
    Polynomial p;
    
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->t>h2->t)
        {
            p+=h1->t;
            h1=h1->next;
        }
        else if(h2->t>h1->t)
        {
            p+=h2->t;
            h2=h2->next;
        }
        else{
            p+=h1->t;
            h1=h1->next;
            h2=h2->next;
        }

    }
    while(h1!=NULL)
    {
        p+=h1->t;
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        p+=h2->t;
        h2=h2->next;
    }
    return p;

}
void Polynomial::del()
{
    Node * h=this->head,*temp;
    while(h!=NULL)
    {
        temp=h->next;
        delete(h);
        h=temp;

    }


}
Polynomial Polynomial::operator*(const Polynomial& ob)
{
    Polynomial temp,res;
    Node * h1=this->head,*h2=ob.head,*curr;
    while(h1!=NULL)
    {
        curr=h2;
        while(curr)
        {
            Term pdt=(h1->t)*(curr->t);
            temp+=pdt;
            curr=curr->next;
        }
        res=res+temp;
        temp.del();
        h1=h1->next;
    }
    return res;



}
Polynomial Polynomial::operator*(const Term& ob)
{
    Node * ptrhead=this->head;
    Polynomial res;
    while(ptrhead!=NULL)
    {
        res+=ptrhead->t*ob;
        ptrhead=ptrhead->next;

    }
    return res;

}
Polynomial& Polynomial::operator=(const Polynomial& rhs)
{
    Node *from=rhs.head,*to=this->head;
    while(from!=NULL)
    {
        to->t=from->t;
        to=to->next;
        from=from->next;
    }
    return *this;

}
Polynomial Polynomial::operator+=(const Polynomial& rhs)
{
    Polynomial& p1=*this;
    p1=p1+rhs;
    return p1;
}
istream& operator>>(istream& in,Polynomial &ob)
{
    int n;
    Term term;
    cout << "enter the no of terms:";
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> term;
        ob+=term;
    }
    return in;
}
ostream& operator<<(ostream& out,const Polynomial &ob)
{
    Node * curr=ob.head;
    while(curr!=NULL)
    {
        out << curr->t <<' ';
        curr=curr->next;
    }
    return out;
}
Polynomial::~Polynomial()
{
    this->del();
}
int main()
{
    Term t1(1,2),t2(2,2);
    Polynomial p1,p2,p3;
    p1+=t1;
    p1+=t2;
    p2+=t1;
    p2+=t2;
    // cin >> p1;
    // cin >> p2;
    p3=p1*p2;
    cout << p3;
    return 0;
}