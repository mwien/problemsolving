#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<complex>

using namespace std;

int main()
{
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    cout << 3 << endl;
    complex<int> a (ax, ay), b (bx, by), c (cx, cy);
    complex<int> f, s, t;
    f = (b - a) + (c);
    s = (b - c) + (a);
    t = (c- b) + (a);
    cout << f.real() << " " << f.imag() << endl;
    cout << s.real() << " " << s.imag() << endl;
    cout << t.real() << " " << t.imag() << endl;
}
