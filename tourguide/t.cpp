#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>

using namespace std;

complex<double> pos[10];
complex<double> mv[10];

double solve(double vx, double vy, double v, double r, double s)
{
    double a = vx * vx + vy * vy - v * v;
    double b = 2 * r * vx + 2 * s * vy;
    double c = r * r + s * s;
    double first = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double second = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);
    return first >= 0 ? first : second;
}

int main()
{
    while(true) {
	int n;
	cin >> n;
	if(n == 0) break;
	double v;
	cin >> v;
	for(int i = 0; i < n; ++i) {
	    double x, y, a, b;
	    cin >> x >> y >> a >> b;
	    pos[i] = complex<double> (x,y);
	    mv[i] = polar(a,b);
	}
	vector<int> perm;
	for(int i = 0; i < n; ++i) {
	    perm.push_back(i);
	}
	double latest = 1e7;
	do {
	    double backtime = 0;
	    complex<double> cpos (0,0);
	    double t = 0;
	    for(int i = 0; i < n; ++i) {
		complex<double> tpos = pos[perm[i]] + t * mv[perm[i]];
		t += solve(mv[perm[i]].real(), mv[perm[i]].imag(), v, tpos.real() - cpos.real(), tpos.imag() - cpos.imag());
		complex<double> meet = pos[perm[i]] + t * mv[perm[i]];
		backtime = max(backtime, t + abs(meet) / abs(mv[perm[i]]));
		cpos = meet;
	    }
	    latest = min(latest, backtime);
	} while(next_permutation(perm.begin(), perm.end()));
	cout << (int) (latest + 0.5) << endl;
    }
}
