#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

int a[200005], b[200005];
int alt[200005];

int main()
{
    int n, h;
    cin >> n >> h;
    for(int i = 0; i < n; ++i) {
	cin >> a[i] >> b[i];
    }
    for(int i = 1; i < n; ++i) {
	alt[i] = alt[i-1] - (a[i] - b[i-1]);
    }
    int mx = 0;
    for(int i = 0; i < n; ++i) {
	int lo = i;
	int hi = n-1;
	while(lo <= hi) {
	    int mid = (lo + hi) / 2;
	    if((alt[i] - alt[mid]) < h) {
		lo = mid+1;
	    } else {
		hi = mid-1;
	    }
	}
	int res = 0;
	--lo;
	res += (b[lo] - a[i]);
	res += (h - (alt[i] - alt[lo]));
	mx = max(mx, res);
    }
    cout << mx << endl;
}
