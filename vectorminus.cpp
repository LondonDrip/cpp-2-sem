#include<iostream>

using namespace std;
class vector
{
private:
    int x;
    int y;
    int z;
public:
    vector() { x = 1; y = 2; z = 3; }
    vector(int X) { x = X; y = 2; z = 3; }
    vector(int X, int Y) { x = X; y = Y; z = 3; }
    vector(int X, int Y, int Z) { x = X; y = Y; z = Z; }
    vector(const vector& P) { x = P.x; y = P.y; z = P.z; }
    vector operator-(vector P)
    {
        vector N;
        {
            N.x = x - P.x;
            N.y = y - P.y;
            N.z = z - P.z;
            return N;
        }

    }
    void print()
    {
        cout << "(" << x << "," << y << "," << z << ")";
    }
};


int main()
{
    vector V1(3, 6, 9);
    vector V2(2, 4, 8);
    vector V = V1 - V2;
    V.print();
    char j; cin >> j;
    return 0;
}