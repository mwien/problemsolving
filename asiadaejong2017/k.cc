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
    int ind = 0;
    while(true) {
	while(true) {
	    if(ind + 2 > n) break;
	    if(dir[ind] != dir[ind+2]) {
		break;
	    }
	}
    }
}
