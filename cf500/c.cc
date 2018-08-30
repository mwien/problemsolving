#include<iostream>
#include<algorithm>

using namespace std;

long long a[200005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; ++i) {
	cin >> a[i];
    }
    sort(a, a+2*n);
    long long res = (1LL << 62);
    for(int i = 0; i < n; ++i) {
	long long x = a[i+n-1] - a[i];
	long long y = a[2*n-1] - a[i+n];
	if(i > 0) {
	    y += a[i+n];
	    y -= a[0];
	}
	res = min(res, x*y);
    }
    cout << res << endl;
}
