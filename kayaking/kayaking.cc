#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

ll p[3];
ll r[3];
ll s[3];
ll vs[9];
ll sf[100005];

ll isposs(ll x)
{
    r[0] = p[0];
    r[1] = p[1];
    r[2] = p[2];
    for(int i = 0; i < (p[0]+p[1]+p[2])/2; ++i) {
	ll mn = 1e9+5;
	int mni = -1;
	for(int j = 0; j < 9; ++j) {
	    if((j%3 == j /3 && r[j%3] < 2) || (r[j/3] < 1 || r[j%3] < 1)) continue;
	    if(sf[i]*vs[j] - x < mn && sf[i]*vs[j] - x >= 0) {
		mn = sf[i]*vs[j] - x;
		mni = j;
	    }
	}
	if(mn == 1e9+5) return false;
	--r[mni%3];
	--r[mni/3];
    }
    return true;
}

int main()
{
    cin >> p[0] >> p[1] >> p[2];
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < (p[0]+p[1]+p[2]) / 2; ++i) {
	cin >> sf[i];
    }
    for(int i = 0; i < 3; ++i) {
	for(int j = 0; j < 3; ++j) {
	    vs[i*3+j] = s[i] + s[j] ;
	}
    }
    ll lo = 0, hi = 1e9+5, mx = 0;
    while(lo <= hi) {
	ll mid = (lo + hi) / 2;
	if(isposs(mid)) {
	    mx = max(mx, mid);
	    lo = mid+1;
	} else {
	    hi = mid-1;
	}
    }
    cout << mx << endl;
}
