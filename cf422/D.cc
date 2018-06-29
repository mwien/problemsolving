#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

const int n = 5000005;
const int mod = 1000000007;
long long T[n];
long long Tt[n];
long long P[n];

int pairs(long long n) {
    return (((n * (n-1)) % mod)  * 500000004) % mod;
}

int main()
{
    long long t, l, r;
    cin >> t >> l >> r;
    for(int i = 2; i < n; ++i) {
	T[i] = -1;
    }
    for(long long i = 0; i < n; ++i) {
	P[i] = pairs(i);
    }
    for(long long i = 2; i < n; ++i) {
	if( i <= 20) 
	if(T[i] == -1) {
	    T[i] = P[i];
	    for(long long j = i; j < n; j+= i) {
		if(T[j] == -1) {
		    T[j] = (i*P[j/i] + T[i]) % mod;
		    
		} else {
		    T[j] = min((i*P[j/i] + T[i]) % mod, T[j]);
		}
	    }
	}
    }
    Tt[0] = 1;
    for(long long i = 1; i <= r-l; ++i) {
	Tt[i] = (Tt[i-1] * t) % mod;
    }
    long long res = 0;
    for(int i = l; i <= r; ++i) {
	res = (res + (Tt[i-l] * T[i]) % mod) % mod;
    }
    cout << res << endl;
}
