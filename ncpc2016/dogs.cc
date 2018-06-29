#include<iostream>
#include<complex>

using namespace std;

#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)

typedef complex<double> point;

double dot(P(a), P(b)) { 
    return real(conj(a) * b); 
}

point closest_point(L(a, b), P(c)) {
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}

int main()
{
    int n;
    cin >> n;
    vector<point> x;
    for(int i = 0; i < n; ++i) {
	double a, b;
	cin >> a >> b;
	x.push_back(complex(a, b));
    }
    int m;
    cin >> m;
    vector<point> y;
    for(int i = 0; i < m; ++i) {
	double a, b;
	cin >> a >> b;
	y.push_back(complex(a, b));
    }
    double xt = 0, yt = 0;
    int i = 0, j = 0;
    while(i < n || j < m) {
	
    }
}
