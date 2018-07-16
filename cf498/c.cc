// TAGS: POINTER, AD HOC
// Problem: http://codeforces.com/contest/1006/problem/C

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

long long d[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> d[i];
    }
    long long l = 0, r = n-1;
    long long mx = 0;
    long long lsum = d[l], rsum = d[r];
    while(true) {
	if(lsum == rsum) {
	    if(r <= l) break;
	    mx = max(mx, lsum);
	}
	if(lsum <= rsum) {
	    ++l;
	    if(l >= r) break;
	    lsum += d[l];
	} else if(rsum < lsum) {
	    --r;
	    if(r <= l) break;
	    rsum += d[r];
	}
    }
    cout << mx << endl;
}
