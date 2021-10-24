// Program for Implementation of Constructor abd Destructor.

#include<iostream>

using namespace std;

class addition
{
    int a,b;

public:

  addition(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void add()
    {
        cout<<"\nAddition of "<< a << "+" << b <<" is " << a+b;
    }
    ~addition()
    {
        cout<<"\nDestructor of addition executes\n";
    }
};

class subtraction
{
    int a,b;

public:

    subtraction(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void sub()
    {
        cout<<"\nAddition of "<< a << "-" << b <<" is " << a-b;
    }
    ~subtraction()
    {
        cout<<"\nDestructor of subtraction executes\n";
    }
};

int main()
{
    addition x(6,5);
    subtraction y(11,6);

    x.add();
    y.sub();

    return 0;
}
