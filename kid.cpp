#include<iostream>
using namespace std;

class vector
{
private:
    double x;
    double y;
    double z;
public:
    vector() { x = 1; y = 2; z = 3; }
    vector(double X) { x = X; y = 2; z = 3; }
    vector(double X, double Y) { x = X; y = Y; z = 3; }
    vector(double X, double Y, double Z) { x = X; y = Y; z = Z; }
    vector(const vector& P) { x = P.x; y = P.y; z = P.z; }

    void print()
    {
        cout << "(" << x << "," << y << "," << z << ")";
    }

    friend vector operator+(double a, vector P);
};
vector operator+(double a, vector P)
{
    vector M;

    M.x = a + P.x;
    M.y = a + P.y;
    M.z = a + P.z;
    return M;
}


int main()
{
    vector V1(3, 6, 9);
    double F = -2.5;
    vector V = F + V1;
    V.print();
    char j; cin >> j;
    return 0;
}