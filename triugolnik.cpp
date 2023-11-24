#include<iostream>

using namespace std;

class A1
{
protected:
    int a1;
public:
    A1(int V1 = 0)
    {
        a1 = V1;
        cout << "\nClass A1 constructor";
    }

    virtual void print()
    {
        cout << "\nA1";
    }

    virtual void show()
    {
        cout << "\na1 = " << a1;
    }
};

class B1 : virtual public A1
{
protected:
    int b1;
public:
    B1(int Z1 = 0, int Z2 = 0) : A1(Z1), b1(Z2)
    {
        cout << "\nClass B1 constructor";
    }

    void print() override
    {
        cout << "\nB1";
    }

    void show() override
    {
        cout << "\nb1 = " << b1 << ", a1 = " << a1;
    }
};

class B2 : virtual public A1
{
protected:
    int b2;
public:
    B2(int Z1 = 0, int Z2 = 0) : A1(Z1), b2(Z2)
    {
        cout << "\nClass B2 constructor";
    }

    void print() override
    {
        cout << "\nB2";
    }

    void show() override
    {
        cout << "\nb2 = " << b2 << ", a1 = " << a1;
    }
};

class C1 : virtual public B1, virtual public B2 {
protected:
    int c1;
public:
    C1(int Z1 = 0, int Z2 = 0, int Z3 = 0, int Z4 = 0, int Z5 = 0) : B1(Z1, Z2), B2(Z3, Z4), c1(Z5)
    {

    }

    void print() override
    {
        cout << "\nC1";
    }

    void show() override
    {
        cout << "\nb1 = " << b1 << ", b2 = " << b2 << ", c1 = " << c1;
    }
};

class C2 : public B1, public B2 {
protected:
    int c2;
public:
    C2(int Z1 = 0, int Z2 = 0, int Z3 = 0, int Z4 = 0, int Z5 = 0) : B1(Z1, Z2), B2(Z3, Z4), c2(Z5) {}

    void print() override
    {
        cout << "\nC2";
    }

    void show() override
    {
        cout << "\nb1 = " << b1 << ", b2 = " << b2 << ", c2 = " << c2;
    }
};


int main() {
    A1* a = new A1{ 4 };
    A1* b1 = new B1{ 6, 9 };
    A1* b2 = new B2{ 1, 3 };
    A1* c1 = new C1{ 7, 9, 0, 8, 1 };
    A1* c2 = new C2{ 4, 5, 4, 3, 0 };

    cout << "\n";
    a->print();
    a->show();

    cout << "\n";
    b1->print();
    b1->show();

    cout << "\n";
    b2->print();
    b2->show();

    cout << "\n";
    c1->print();
    c1->show();

    cout << "\n";
    c2->print();
    c2->show();


    return 0;
}