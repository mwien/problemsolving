#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long c[20005];
long long T[20005][50][2];
long long hn[50];

int main()
{
    long long n, m;
    cin >> n >> m;
    for(int i = 1;  i <= n; ++i) {
	cin >> c[i];
    }
    long long mm = m;
    int ind = 0;
    while(mm != 0) {
	hn[ind] = mm;
	mm = (mm * 2) / 3;
	++ind;
    }
    for(int i = 1; i <= n; ++i) {
	long long mx = 0;
	for(int j = 0; j <= ind; ++j) {
	    mx = max(mx, T[i-1][j][1]);
	}
	T[i][0][0] = mx;
	for(int j = 1; j <= ind; ++j) {
	    T[i][j][0] = max(T[i-1][j-1][0] + min(c[i], hn[j-1]), T[i-1][j-1][1] + min(c[i], hn[j-1])); 
	}
	for(int j = 0; j <= ind; ++j) {
	    T[i][j][1] = max(T[i-1][j+1][0], T[i-1][j+1][1]);
	}
    }
    long long mx = 0;
    for(int j = 0; j <= ind; ++j) {
	for(int k = 0; k < 2; ++k) {
	    mx = max(mx, T[n][j][k]);
	}
    }
    //for(int i = 0; i <= n; ++i) {
    //for(int j = 0; j < ind; ++j) {
    //cout << "(" << T[i][j][0] << ", " << T[i][j][1] << "), ";
    //}
    //cout << endl;
    //}
    cout << mx << endl;
}
