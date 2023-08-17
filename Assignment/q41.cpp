/*write a program to create a base class student {name ,roll,age}.derive two classes ug and pg from student .
Design a class semester Ug and Pg student shold have 8 and4  semesters respectively.
Add suitable function*/


#include<bits/stdc++.h>
using namespace std;
class Semester;
class Student;
class UG;
class PG;

class Student
{
    protected:
        string name;
        int roll;
        int age;
        Semester* sem;
    public:
        virtual void get_name() = 0;
        void pg_sem(Semester& s)
        {
            cout << s.pg;
        }
        void ug_sem(Semester& s)
        {
            cout << s.ug;
        }
};

class UG : virtual public Student
{
    public:
        void set_name(string name)
        {
            this -> name = name;
        }
        void set_roll(int roll)
        {
            this -> roll = roll;
        }
        void set_age(int age)
        {
            this -> age = age;
        }

        void get_name()
        {
            cout << name;
        }void get_roll()
        {
            cout << roll;
        }void get_age()
        {
            cout << age;
        }
        
        friend istream& operator>>(istream&,UG&);
        friend ostream& operator<<(ostream&,UG&);
};

class PG : virtual public Student
{
    public:
        void set_name(string name)
        {
            this -> name = name;
        }
        void set_roll(int roll)
        {
            this -> roll = roll;
        }
        void set_age(int age)
        {
            this -> age = age;
        }

        void get_name()
        {
            cout << name;
        }void get_roll()
        {
            cout << roll;
        }void get_age()
        {
            cout << age;
        }
        
        friend istream& operator>>(istream&,PG&);
        friend ostream& operator<<(ostream&,PG&);
};

istream& operator>>(istream&in,PG& pg)
{
    cout << "Enter the name,roll,age";
    in>>pg.name>>pg.roll>>pg.age;
    return in;
}
ostream& operator<<(ostream& out,PG& pg)
{
    cout<< "The details of PG Student is:";
    out << pg.name <<" "<< pg.roll <<" "<<pg.age<< endl;
    return out;
}
istream& operator>>(istream&in,UG& ug)
{
    cout << "Enter the name,roll,age";
    in>>ug.name>>ug.roll>>ug.age;
    return in;
}
ostream& operator<<(ostream& out,UG& ug)
{
    cout<< "The details of UG Student is:";
    out << ug.name <<" "<< ug.roll <<" "<<ug.age<< endl;
    return out;
}

class Semester
{
    protected:
        int ug = 4;
        int pg = 8;
    public:
        int ug_semester()
        {
            return ug;
        }
        int pg_semester()
        {
            return pg;
        }
        friend Student;
       
};


int main()
{
    UG ug1;
    PG pg1;

    Student *student[3];
    student[0] = &ug1;
    student[1] = &pg1;

    cin >> pg1;
    cin >> ug1;
    cout << ug1;
    cout << pg1;
    
    // ug1.set_name("Avi");
    // pg1.set_name("King");

    // ug1.get_name();
    // pg1.get_name();
    // student[1]->get_name();
    // student[0] ->get_name();
}