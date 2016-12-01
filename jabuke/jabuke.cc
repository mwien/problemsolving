#include<iostream>
#include<complex>
#include<cmath>
#include<iomanip>

using namespace std;

int t_area(complex<int> a, complex<int> b) {
    return abs(a.real()*b.imag() - a.imag()*b.real());
}

int main()
{
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    complex<int> a(ax, ay), b(bx, by), c(cx, cy);
    int d_area = t_area((b - a), (c - a));
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; ++i) {
	int tx, ty;
	cin >> tx >> ty;
	complex<int> t(tx, ty);
	int d_sum = t_area((a - t), (b - t)) + t_area((b - t), (c - t)) + t_area((a - t), (c - t));
	if(d_sum == d_area) ++cnt;
    }
    cout << fixed << setprecision(1) << d_area / 2.0;
    cout << " " << cnt << endl;
}
