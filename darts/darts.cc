#include<iostream>
#include<complex>
#include<algorithm>
#include<vector>

using namespace std;

double EPS = 1e-9;

double cross(const complex<double> &a, const complex<double> &b) { 
    return imag(conj(a) * b); 
}

double ccw(complex<double> &a, complex<double> &b, complex<double> &c) { 
    return cross(b - a, c - b); 
}

bool parallel(complex<double> &a, complex<double> &b, complex<double> &p, complex<double> &q) { 
    return abs(cross(b - a, q - p)) < EPS; 
}

bool collinear(complex<double> &a, complex<double> &b, complex<double> &c) { return abs(ccw(a, b, c)) < EPS; }

bool intersect(complex<double> &a, complex<double> &b, complex<double> &p, complex<double> &q) {
    // NOTE: check for parallel/collinear lines before calling this function
    complex<double> r = b - a, s = q - p;
    double c = cross(r, s), t = cross(p - a, s) / c, u = cross(p - a, r) / c;
    if (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS)
        return false;
    return true;
}

int main()
{
    int N;
    cin >> N;
    for(int t = 0; t < N; ++t) {
	vector<int> p (7);
	for(int i = 0; i < 7; ++i) {
	    p[i] = i;
	}
	vector<complex<double>> d;
	for(int i = 0; i < 7; ++i) {
	    double a, b;
	    cin >> a >> b;
	    d.push_back(complex<double> (a, b));
	}
	double prob;
	cin >> prob;
	do {
	    bool simple = true;
	    for(int i = 0; i < 7; ++i) {
		for(int j = i+2; j < 7; ++j) {
		    if(j == 6 && i == 0) continue;
		    if(parallel(d[p[i]], d[p[i+1]], d[p[j]], d[p[(j+1) % 7]])) continue;
		    if(intersect(d[p[i]], d[p[i+1]], d[p[j]], d[p[(j+1) % 7]])) {
			simple = false;
			break;
		    }
		}
	    }
	    if(simple) {
		double area = 0;
		for(int i = 0; i < 7; ++i) {
		    area += d[p[i]].real() * d[p[(i+1) % 7]].imag();
		    area -= d[p[(i+1) % 7]].real() * d[p[i]].imag();
		    // cout << d[p[i]] << " " <<d[p[(i+1)%7]] << endl;
		    // cout << area << endl;
		}
		area /= 2;
		area = abs(area);
		double cprob = (area / 4) * (area / 4) * (area / 4);
		// for(int i = 0; i < 7; ++i) {
		//     cout << p[i]+1 << " ";
		// }
		// cout << endl;
		// cout << prob << " " << cprob << endl;
		if(abs(cprob - prob) < 1e-5) {
		    // cout << "RES" << endl;
		    for(int i = 0; i < 7; ++i) {
			cout << p[i]+1 << " ";
		    }
		    cout << endl;
		    break;
		}
	    }
	} while(next_permutation(p.begin(), p.end()));
    }
}
