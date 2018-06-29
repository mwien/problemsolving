#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>
#include<unordered_set>

using namespace std;

bool pal(string &s) {
    bool is = true;
    int n = s.size();
    for(int i = 0; i < n/2; ++i) {
	if(s[i] != s[n-i-1]) {
	    is = false;
	    break;
	}
    }
    return is;
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<pair<string, pair<int, bool>>> s;
    for(int i = 0; i < k; ++i) {
	string in;
	cin >> in;
	int b;
	cin >> b;
	string rev = "";
	for(int i = n-1; i >= 0; --i) {
	    rev += in[i];
	}
	s.push_back({in, {b, false}});
	s.push_back({rev, {b, true}});
    }
    sort(s.begin(), s.end());
    vector<vector<pair<int, pair<bool, bool>>>> g;
    for(int i = 0; i < k;) {
	vector<pair<int, pair<bool, bool>>> ng;
	bool is = pal(s[i].first);
	ng.push_back({s[i].second.first, {is, s[i].second.second}});
	int j = i+1;
	for(; j < k; ++j) {
	    if(s[i] == s[j]) {
		ng.push_back({s[j].second.first, {is, s[i].second.second}});
	    } else break;
	}
	i = j;
    }
    int b = 0;
    int mx = 0;
    for(int i = 0; i < g.size(); ++i) {
	sort(g[i].begin(), g[i].end());
	int j = 0, m = 0;
	while(true) {
	    for(; j < g[i].size(); ++j) {
		if(g[i][j].second.second) continue;
	    }
	    for(; m < g[i].size(); ++m) {
		if(!g[i][j].second.second) continue;
	    }
	    if(m == g[i].size() || j == g[i].size()) {
		if(g[i][0]
		if(m < g[i].size())
	    }
	    if(g[i][j].first + g[i][m].first > 0) {
		b += g[i][j].first + g[i][m].first;
	    } else break;
	}
    }
}
