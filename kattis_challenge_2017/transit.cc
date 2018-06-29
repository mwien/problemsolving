#include<iostream>

using namespace std;

long long p[105];
long long d[105];
long long a[5005];
long long b[5005];
long long cost[1000005];
long long T[5005];

int main()
{
    int l;
    cin >> l;
    for(int i = 0; i < l; ++i) {
	cin >> p[i];
    }
    d[0] = 0;
    for(int i = 1; i < l; ++i) {
	cin >> d[i];
	d[i] += d[i-1];
    }
    int t, n;
    cin >> t >> n;
    for(int i = 0; i < n; ++i) {
	cin >> a[i] >> b[i];
    }
    cost[0] = 0;
    int rng = 0;
    for(int i = 1; i <= t; ++i) {
	if(rng < l-1 && d[rng+1] < i)
	    ++rng;
	cost[i] = cost[i-1] + p[rng];
    }
    for(int i = 0;  i < n; ++i) {
	long long st = cost[a[i]-1];
	for(int j = 0; j < i; ++j) {
	    long long tmp = T[j] + cost[a[i] - b[j] - 1];
	    if(tmp < st) st = tmp;
	}
	T[i] = st;
    }
    long long mn = cost[t];
    for(int i = 0; i < n; ++i) {
	long long tmp = T[i] + cost[t-b[i]];
	if(tmp < mn) mn = tmp;
    }
    cout << mn << endl;
}
