#include<iostream>

using namespace std;

char g[35][35];
pair<long long, long long> r[35];
long long T[35][35];

int main()
{
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    cin >> g[i+1][j+1];
	}
    }
    
    for(int i = 1; i <= n; ++i) {
	int hi = 0;
	int lo = m+1;
	for(int j = 1; j <= m; ++j) {
	    if(g[j][i] == 'B' && j > hi) hi = j;
	    if(g[j][i] == 'R' && j < lo) lo = j;
	}
	r[i].first = hi;
	r[i].second = lo-1;
    }
    long long mx = 0;
    for(int i = n; i > 0; --i) {
	mx = max(mx, r[i].first);
	r[i].first = mx;
    }
    long long mn = m;
    for(int i = 1; i <= n; ++i) {
	mn = min(mn, r[i].second);
	r[i].second = mn;
    }
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
	for(int j = r[i].second; j >= r[i].first; --j) {
	    if(i == 1) {
		T[j][i] = 1;
	    } else {
		long long nmx = 0;
		for(int k = j; k <= m; ++k) {
		    nmx += T[k][i-1];
		}
		T[j][i] = nmx;
	    }
	}
    }

    for(int i = 0; i <= m; ++i) {
	sum += T[i][n];
    }
    // for(int i = 1; i <= m; ++i) {
    //  	for(int j = 1; j <= n; ++j) {
    //  	    cout << T[i][j] << " ";
    //  	}
    //  	cout << endl;
    // }
    cout << sum << endl;
}
