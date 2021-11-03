#include<iostream>

using namespace std;

long long a[1000005];
long long mod = 1000000007;
long long T[1000005][5];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
	cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
	for(int j = 1; j <= 3; ++j) {
	    T[i][j] = T[i-1][j];
	}
	if(a[i] == 1) {
	    T[i][a[i]] = (T[i-1][a[i]] + 1) % mod;
	}
	if(a[i] == 2) {
	    T[i][a[i]] = (2*T[i-1][a[i]] + T[i-1][1]) % mod;
	}
	if(a[i] == 3) {
	    T[i][a[i]] = (T[i-1][3] + T[i-1][2]) % mod;
	}
    }
    cout << T[n][3] << endl;
}
