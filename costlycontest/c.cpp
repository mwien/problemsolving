#include<iostream>

using namespace std;

long long sl[100005];
bool lt[100005];
long long d[105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    long long mn = 1e9;
    for(int i = 0; i < n; ++i) {
	cin >> sl[i];
	mn = min(mn, sl[i]);
    }
    for(int i = 0; i < m; ++i) {
	cin >> d[i];
    }
    long long hi = 0;
    lt[0] = true;
    for(int i = 0; i < m; ++i) {
	for(long long j = t; j >= 0; --j) {
	    if(j-d[i]*mn >= 0) lt[j] |= lt[j-d[i]*mn];
	}
    }
    for(int i = t; i >= 0; --i) {
	if(lt[i]) {
	    hi = i;
	    break;
	}
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
	if(hi * sl[i] <= t * mn) ++cnt;
    }
    cout << max(k, cnt) << endl;
}
