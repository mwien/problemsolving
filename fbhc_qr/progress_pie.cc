#include<iostream>
#include<complex>
#include<cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
	int P, X, Y;
	cin >> P >> X >> Y;
	double xd = abs(50 - X), yd = abs(50 - Y);
	bool black = true;
	if(xd * xd + yd * yd > 50*50) {
	    black = false;
	} else {
	    complex<double> pp (Y-50, X-50);
	    double angle = arg(pp) * 100 / (2 * M_PI);
	    if(angle > P) {
		black = false;
	    }
	}
	cout << "Case #" << i+1 << ": " << (black ? "black" : "white") << endl;
    }
}
