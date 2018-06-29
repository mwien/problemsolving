#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<set>

using namespace std;

set<int> T[200005];

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, pair<bool,int>>> e;
    vector<pair<int, int>> lk;
    for(int i = 0; i < n; ++i) {
	int l, r, c;
	cin >> l >> r >> c;
	e.push_back({l, {false, i}});
	e.push_back({r, {true, i}});
	lk.push_back({r-l+1, c});
    }
    int mn = 2e9+5;
    sort(e.begin(), e.end());
    for(int i = 0; i < 2*n; ++i) {
	if(e[i].second.first) {
	    T[lk[e[i].second.second].first].insert(lk[e[i].second.second].second);
	} else {
	    int rest = x - lk[e[i].second.second].first;
	    if(rest < 0) continue;
	    if(T[rest].empty()) continue;
	    mn = min(mn, lk[e[i].second.second].second + (*T[rest].begin()));
	}
    }
    if(mn == 2e9+5) {
	cout << -1 << endl;
    } else {
	cout << mn << endl;
    }
}
