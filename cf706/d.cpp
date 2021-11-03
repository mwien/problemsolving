#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

int p[100005];
int l[100005];
int r[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> p[i];
    }
    int mx = 0;
    int streak = 0;
    for(int i = 1; i < n; ++i) {
	if(p[i] > p[i-1]) ++streak;
	else streak = 0;
	l[i] = streak;
	mx = max(mx, streak);
    }
    streak = 0;
    for(int i = n-2; i >= 0; --i) {
	if(p[i] > p[i+1]) ++streak;
	else streak = 0;
	r[i] = streak;
	mx = max(mx, streak);
    }
    if((mx % 2) == 1) {
	cout << 0 << endl;
	return 0;
    }
    int lmax = 0;
    int rmax = 0;
    for(int i = 0; i < n; ++i) {
	if(l[i] == mx) ++lmax;
	if(r[i] == mx) ++rmax;
    }
    if(lmax > 1 || rmax > 1) {
	cout << 0 << endl;
	return 0;
    }
    int res = 0;
    for(int i = 0; i < n; ++i) {
	if(l[i] == mx && r[i] == mx) {
	    ++res;
	}
    }
    cout << res << endl;
}
