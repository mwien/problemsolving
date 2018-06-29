#include<iostream>
#include<cmath>
#include<complex>

using namespace std;

complex<double> p[1000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	int a, b;
	cin >> a >> b;
	p[i] = complex<double> (a, b);
    }
    double bst = 0;
    int bsti = -1;
    for(int k = 3; k <= 8; ++k) {
	double mn = 1e15, mx = 0;
	for(int i = 0; i < n; ++i) {
	    double ang = arg(p[i]);
	    ang = fmod(ang+2*M_PI, 2*M_PI/k);
	    double circ = abs(p[i]) * cos(ang-M_PI/k) / cos(M_PI/k);
	    if(circ < mn) mn = circ;
	    if(circ > mx) mx = circ;
	}
	double mnar = 0.5*k*mn*mn*sin(2*M_PI/k);
	double mxar = 0.5*k*mx*mx*sin(2*M_PI/k);
	double nbst = mnar/mxar;
	if(nbst > bst) {
	    bst = nbst;
	    bsti = k;
	}
    }
    cout << bsti << " ";
    printf("%.10f\n", bst);
}
