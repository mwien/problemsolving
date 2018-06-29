#include<iostream>
#include<complex>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int t = 0; t < n; ++t) {
	int m;
	cin >> m;
	double old_angle = 90;
	complex<double> pos(0.0, 0.0);
	for(int i = 0; i < m; ++i) {
	    double angle, dist;
	    cin >> angle >> dist;
	    complex<double> add(polar(dist, (angle + old_angle) * 2 * M_PI / 360));
	    pos += add;
	    old_angle += angle;
	}
	cout << fixed << setprecision(6)<< pos.real() << " " << pos.imag() << endl;
    }
} 
