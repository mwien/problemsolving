#include<iostream>

using namespace std;

int l[10005];
int dir[10005];
int res[10005];

int main()
{
    int n;
    cin >> n;
    int cur = 1;
    for(int i = 0; i < n; ++i) {
	cin >> l[i];
	int a;
	cin >> a;
	dir[i] = cur;
	if(i % 2 == 0) {
	    cur = cur * a;
	} else {
	    cur = cur * a *-1;
	}
    }
    int ind = -2, oldind = 0;
    int cnt = 0;
    while(true) {
	int lcnt = 0;
	oldind = ind+2;
	ind = oldind;
	if(oldind > n) break;
	while(true) {
	    ++lcnt;
	    if(ind + 2 > n) {
		break;
	    }
	    if(dir[ind] != dir[ind+2]) {
		break;
	    }
	    ind += 2;
	}
	for(int i = oldind; i <= ind; i += 2) {
	    res[i] = (n - cnt) / lcnt;
	}
	res[ind] += (n - cnt) % lcnt;
	cnt += 2;
    }
    ind = -1;
    oldind = 1;
    cnt = 0;
    while(true) {
	int lcnt = 0;
	oldind = ind+2;
	ind = oldind;
	if(oldind > n) break;
	while(true) {
	    ++lcnt;
	    if(ind + 2 > n) {
		break;
	    }
	    if(dir[ind] != dir[ind+2]) {
		break;
	    }
	    ind += 2;
	}
	for(int i = oldind; i <= ind; i += 2) {
	    res[i] = (n - cnt) / lcnt;
	}
	res[ind] += (n - cnt) % lcnt;
	cnt += 2;
    }
    for(int i = 0; i < n; ++i) {
	cout << res[i] << " ";
    }
    cout << endl;
}
