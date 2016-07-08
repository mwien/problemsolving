#include<iostream>
#include<climits>

using namespace std;

long long l[1000005];
long long n, r, p;

long long recdeb(long long ls) {
    if(ls == 1) return 0;
    long long min = LLONG_MAX;
    for(int i = 1; i < ls; i++) {
	long long bslice = ls / (i+1);
	if(ls % (i+1) != 0) ++bslice;
	long long nmin = LLONG_MAX;
	if(l[bslice] != -1) {
	    nmin = l[bslice] + i * p + r;
	} else {
	    long long res = recdeb(bslice);
	    l[bslice] = res;
	    nmin = res + i * p + r;
	}
	if(nmin < min) min = nmin;
    }
    return min;
}

int main()
{
    cin >> n >> r >> p;
    for(int i = 0; i <= n; i++) {
	l[i] = -1;
    }
    cout << recdeb(n) << endl;
}
