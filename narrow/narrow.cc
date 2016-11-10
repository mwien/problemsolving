#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    while(true) {
	int n, k;
	cin >> n >> k;
	if(n == 0 && k == 0) break;
	vector<pair<int, int>> g;
	int sum = 0;
	for(int i = 0; i < n; ++i) {
	    int a, b;
	    cin >> a >> b;
	    sum += a + b;
	    g.push_back({a, b});
	}
	vector<vector<pair<int, int>>> t;
	for(int i = 0; i < n; ++i) {
	    t.push_back({});
	    for(int j = 0; j <= k; ++j) {
		if(j == 0) t[i].push_back({0, 0});
		else if(i == 0) {
		    if(j == 1) t[i].push_back({g[i].first, g[i].second});
		    else if(j >= 2) t[i].push_back({1 << 20, 1 << 20});
		} else {
		    int lmin, rmin;
		    lmin = min({t[i-1][j-1].first + g[i].first, t[i-1][j].first, t[i-1][j].second});
		    rmin = min({t[i-1][j-1].second + g[i].second, t[i-1][j].first, t[i-1][j].second});
		    t[i].push_back({lmin, rmin});
		}
	    }
	}
	cout << sum - min(t[n-1][k].first, t[n-1][k].second) << endl;
    }
}
