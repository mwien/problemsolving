#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int n, X;
double v;
int l[105];
int r[105];
double vi[105];

double walk(double mid) {
    double x = v*cos(mid);
    double y = v*sin(mid);
    double res = X*tan(mid);
    for(int i = 0; i < n; ++i) {
	res -= (r[i] - l[i]) / x * vi[i];
    }
    return res;
}

int main()
{
    cin >> n >> X >> v;
    for(int i = 0; i < n; ++i) {
	cin >> l[i] >> r[i] >> vi[i];
    }
    double lo = -acos(0.5);
    double hi = acos(0.5);
    while(hi - lo > 1e-12) {
	double mid = (hi + lo) / 2;
	if(walk(mid) > 0) {
	    hi = mid;
	} else {
	    lo = mid;
	}
    }
    if(abs(walk(lo)) < 1e-6) {
	cout << setprecision(3) << fixed;
	cout << X/(v*cos(lo)) << endl;
    } else {
	cout << "Too hard" << endl;
    }
}
