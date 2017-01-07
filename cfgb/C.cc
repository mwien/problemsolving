#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

int main()
{
    long long SZ = (1LL << 60);
    int n;
    cin >> n;
    long long mx = SZ;
    long long mn = -SZ;
    long long oc = 0;
    bool poss = true;
    for(int i = 0; i < n; ++i) {
	long long c, d;
	cin >> c >> d;
	if(d == 1) {
	    if(mx + oc < 1900) {
		poss = false;
		break;
	    } else {
		if(mx != SZ) {
		    mx = min(mx+oc, SZ);   
		}
		mn = max(mn+oc, 1900LL);
	    }
	} else if(d == 2) {
	    if(mn + oc >= 1900) {
		poss = false;
		break;
	    } else {
		mx = min(mx+oc, 1899LL);
		mn = max(mn+oc, -SZ);
	    }
	}
	oc = c;
    }
    if(poss) {
	if(mx != SZ) {
	    cout << mx+oc << endl;
	} else {
	    cout << "Infinity" << endl;
	}
    } else {
	cout << "Impossible" << endl;
    }
}
