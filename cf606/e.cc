#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<vector<int>> g (n, vector<int>());
	for(int i = 0; i < m; ++i) {
	    int u, v;
	    cin >> u >> v;
	    g[u-1].push_back(v-1);
	    g[v-1].push_back(u-1);
	}
	--a;
	vector<int> visa (n);
	visa[a] = m + 1;
	for(int i = 0; i < g[a].size(); ++i) {
	    queue<int> q;
	    if(visa[g[a][i]] == 0) {
		q.push(g[a][i]);
		visa[g[a][i]] = i+1;
	    }
	    while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v = 0; v < g[u].size(); ++v) {
		    if(visa[g[u][v]] == 0) {
			q.push(g[u][v]);
			visa[g[u][v]] = i+1;
		    }
		}
	    }
	}
	vector<int> cnta (g[a].size());
	for(int i = 0; i < n; ++i) {
	    if(visa[i] != 0 && visa[i] != m+1) {
		++cnta[visa[i]-1];
	    }
	}
	--b;
	vector<long long> visb (n);
	visb[b] = m+1;
	for(int i = 0; i < g[b].size(); ++i) {
	    queue<int> q;
	    if(visb[g[b][i]] == 0) {
		q.push(g[b][i]);
		visb[g[b][i]] = i+1;
	    }
	    while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v = 0; v < g[u].size(); ++v) {
		    if(visb[g[u][v]] == 0) {
			q.push(g[u][v]);
			visb[g[u][v]] = i+1;
		    }
		}
	    }
	}
	vector<long long> cntb (g[b].size());
	for(int i = 0; i < n; ++i) {
	    if(visb[i] != 0 && visb[i] != m+1) {
		++cntb[visb[i]-1];
	    }
	}
	long long resa = 0, resb = 0;
	for(int i = 0; i < g[a].size(); ++i) {
	    if(visa[b] != i+1) resa += cnta[i];
	}
	for(int i = 0; i < g[b].size(); ++i) {
	    if(visb[a] != i+1) resb += cntb[i];
	}
	cout << resa*resb << endl;
    }
}
