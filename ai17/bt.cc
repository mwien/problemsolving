#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

long long powmod(long long base, long long exp, long long mod) {
    base %= mod;
    long long res = 1;
    while (exp > 0) {
	if (exp & 1) res = (res * base) % mod;
	base = (base * base) % mod;
	exp >>= 1;
    }
    return res;
}

long long geomod(long long a, long long n, long long mod) {
    long long factor = 1, sum = 0;
    while(n > 0 && a != 0) {
	if(n % 2 == 0) {
	    long long tmp = (factor * powmod(a, n, mod)) % mod;
	    sum = (sum + tmp) % mod;
	    --n;
	}
	factor = (((1 + a) % mod) * factor) % mod;
	a = a*a % mod;
	n = n / 2;
    }
    return sum + factor % mod;
}

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
	long long x, y, z, l, r;
	cin >> x >> y >> z >> l >> r;
	long long a = -1, b = -1, c = -1;
	for(a = 1; a <= 5000; ++a) {
	    long long res = (x - a*a)*(x - a*a) - (z - a*a*a*a);
	    if(res % 2 != 0) continue;
	    if(res < 0) continue;
	    res /= 2;
	    long long root = round(sqrt(res));
	    if(res != root * root) continue;
	    bool done = false;
	    for(b = 2; b * b <= root; ++b) {
		if(root % b == 0) {
		    c = root / b;
		    if(x == a*a + b*b + c*c && y == a*a*a + b*b*b + c*c*c && z == a*a*a*a + b*b*b*b + c*c*c*c) {
			done = true;
			break;
		    }
		}
	    }
	    if(done) break;
	}
	long long mod = 1e9 + 7;
	long long res = 0;
	res += geomod(a, r,  mod) - geomod(a, l-1, mod);
	res += geomod(b, r, mod) - geomod(b, l-1 ,mod);
	res += geomod(c, r, mod) - geomod(c, l-1, mod);
	res = (res % mod);
	if(res < 0) res += mod;
	cout << res << endl;
    }
}

