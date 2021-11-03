#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 200000;
int n;
pair<long long, long long> t[4*MAXN];
long long a[MAXN];
long long mod = 1000000007;

int gcd(long long a, long long b) {
    if(a == 0 && b == 0) return 0;
    if(a == 0) return b;
    if(b == 0) return a;
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
	t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = gcd(t[v*2], t[v*2+1]);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
	cin >> a[i];
    }
    build(1, 0, n-1);
    long long gg = t[1] % mod;
    if(t[1] >  1) {
	for(int i = 0; i < n; ++i) {
	    a[i] /= t[1];
	}
	build(1, 0, n-1);
    }
    for(int i = 0; i < q; ++i) {
	int idx;
	long long x;
	cin >> idx >> x;
	a[idx-1] *= x;
	update(1, 0, n-1, idx-1, a[idx-1]);
	if(t[1] >  1) {
	    gg = (gg * t[1]) % mod;
	    for(int i = 0; i < n; ++i) {
		a[i] /= t[1];
	    }
	    build(1, 0, n-1);
	}
	cout << gg << endl;
    }
}
