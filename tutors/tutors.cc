#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

bool dfs(vector<vector<long long>> &g, int u, vector<bool> &vis, vector<int> &match, int N, long long lim)
{
    for(int v = 0; v < N; ++v) {
	if(g[u][v] <= lim && !vis[v]) {
	    vis[v] = true;
	    if(match[v] < 0 || dfs(g, match[v], vis, match, N, lim)) {
		match[v] = u;
		return true;
	    }
	}
    }
    return false;
}

int bpm(vector<vector<long long>> &g, long long lim, int N)
{
    vector<int> match (N, -1);
    int res = 0;
    for(int u = 0; u < N; ++u) {
	vector<bool> vis (N);
	if(dfs(g, u, vis, match, N, lim)) ++res;
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<long long, long long>> s;
    vector<pair<long long, long long>> t;
    for(int i = 0; i < N; ++i) {
	long long a, b;
	cin >> a >> b;
	s.push_back({a, b});
    }
    for(int i = 0; i < N; ++i) {
	long long a, b;
	cin >> a >> b;
	t.push_back({a, b});
    }
    vector<vector<long long>> g(N, vector<long long> (N));
    long long mx = 0;
    for(int i = 0; i < N; ++i) {
	for(int j = 0; j < N; ++j) {
	    g[i][j] = abs(s[i].first - t[j].first) + abs(s[i].second - t[j].second);
	    mx = max(mx, g[i][j]);
	}
    }
    long long lo = 0, hi = mx, mn = mx;
    while(lo <= hi) {
	long long mid = (lo + hi) / 2;
	if(bpm(g, mid, N) == N) {
	    hi = mid - 1;
	    mn = min(mn, mid);
	} else {
	    lo = mid + 1;
	}
    }
    cout << mn << endl;
}
