#include<iostream>

using namespace std;

long long mod = 1000000009;
const int nos = 105;

long long imult(long long a, long long L)
{
    long long res = 1;
    for(long long i = 0; (1LL << i) <= L; i++) {
	if(((1LL << i) & L) == (1LL << i)) {
	    res = (a * res) % mod;
	}
	a = (a * a) % mod;
    }
    return res;
}

void mult(long long a[][nos], long long b[][nos], int N)
{
    long long res[nos][nos] = {0};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % mod;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            a[i][j] = res[i][j];
        }
    }
}

int main()
{
    int N, L;
    cin >> N >> L;

    long long a[nos][nos] = {0};
    for(int i = 0; i < N; ++i) {
	for(int j = 0; j < N; ++j) {
	    cin >> a[i][j];
	}
    }
    a[N-1][N-1] = 1;
    long long g[nos][nos] = {0};
    for(int i = 0; i < N; ++i) {
	long long sum = 0;
	for(int j = 0; j < N; ++j) {
	    sum += a[i][j];
	}
	for(int j = 0; j < N; ++j) {
	    g[i][j] = a[i][j] * imult(sum, mod-2);
	}
    }
    for(int r = L; r < L + 10; ++r) {
	long long res[nos][nos] = {0};
	for(int i = 0; i < N; i++) {
	    for(int j = 0; j < N; j++) {
		if(i == j) res[i][j] = 1;
	    }
	}
	for(int i = 0; (1 << i) <= r; i++) {
	    if(((1 << i) & r) == (1 << i)) {
		mult(res, g, N);
	    }
	    mult(g, g, N);
	}
	long long sum = 0;
	for(int i = 0; i < N; ++i) {
	    sum += res[0][i];
	}
	for(int i = 0; i < N; ++i) {
	    for(int j = 0; j < N; ++j) {
		cout << res[i][j] << " ";
	    }
	    cout << endl;
	}
	for(int i = 0; i < N; ++i) {
	    long long sum = 0;
	    for(int j = 0; j < N; ++j) {
		sum = (sum + res[i][j]) % mod;
	    }
	    cout << " HI: " << r << ": "  << sum << endl;
	}
	cout << (((95*imult(100, mod-2)) % mod) +  ((5*imult(100, mod-2)) % mod)) % mod << endl;
	if(((95*imult(100, mod-2)) % mod) == res[0][N-1]) {
	    cout << r << endl;
	    return 0;
	}
    }
    cout << -1 << endl;
}
