#include<iostream>
#include<vector>

using namespace std;

long long pre[20][12];

int pd(long long z)
{
    while(z >= 10) {
	long long y = 1;
	while(z > 0) {
	    if(z % 10 > 0) y *= z % 10;
	    z /= 10;
	}
	z = y;
    }
    return z;
}

long long tenth(int a)
{
    long long res = 1;
    for(int i = 0; i < a; ++i) {
	res *= 10;
    }
    return res;
}

void solve(long long x, vector<long long> &fill)
{
    long long offset = 1;
    for(int st = 15; st >= 0; --st) {
	int idx = x / tenth(st);
	for(int j = 1; j <= 9; ++j) {
	    for(int k = 0; k < idx; ++k) {
		fill[pd(offset * 100 + j * 10 + k)] += pre[st][j];
	    }
	}
	offset = pd(offset * 10 + idx);
	x -= idx * tenth(st);
	cout << st << " " << idx << endl;
	for(int i = 1; i <= 9; ++i) {
	    cout << fill[i] << " ";
	}
	cout << endl;
    }
    ++fill[pd(offset)];
}

int main()
{
    long long L, R;
    cin >> L >> R;
    pre[0][1] = 1;
    for(int i = 1; i <= 15; ++i) {
	for(int j = 1; j <= 9; ++j) {
	    for(int k = 0; k <= 9; ++k) {
		pre[i][pd(j * 10 + k)] += pre[i-1][j];
	    }
	}
    }

    vector<long long> l (10), r (10);
    solve(L-1, l);
    solve(R, r);

    for(int i = 1; i <= 9; ++i) {
	cout << l[i] << " ";
    }
    cout << endl;

    for(int i = 1;  i <= 9; ++i) {
	cout << r[i] << " ";
    }
    cout << endl;
    
    for(int i = 1; i <= 9; ++i) {
	cout << r[i] - l[i] << " ";
    }
    cout << endl;
}
