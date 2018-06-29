#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    while(b > 0) {
	int tmp = b;
	b = a % b;
	a = tmp;
    }
    return a;
}

long long modexp(long long b, long long e, long long mod) {
    long long res = 1;
    b = b % mod;
    while(e > 0) {
	if(e & 1) res = (res * b) % mod;
	b = (b * b) % mod;
	e >>= 1;
    }
    return res;
}

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    long long res = 0;
    long long mod = 1e9+7;
    long long faces = modexp(c, n*n, mod);
    for(int i = 0; i < m; ++i) {
	res = (res + modexp(faces, gcd(i,m), mod)) % mod;
    }
    cout << (res * modexp(m, mod-2, mod)) % mod << endl;
}
