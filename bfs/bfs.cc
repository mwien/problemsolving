#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void bfs(vector<vector<int>> &g, int s, vector<int> &dist)
{
    vector<bool> vis (dist.size());
    vis[s] = true;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
	int u = q.front(); q.pop();
	for(int i = 0; i < g[u].size(); ++i) {
	    int v = g[u][i];
	    if(vis[v]) continue;
	    dist[v] = dist[u] + 6;
	    vis[v] = true;
	    q.push(v);
	}
    }
}

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g (n);
	for(int j = 0; j < m; ++j) {
	    int u, v;
	    cin >> u >> v;
	    g[u-1].push_back(v-1);
	    g[v-1].push_back(u-1);
	}
	int s;
	cin >> s;
	vector<int> dist (n, -1);
	bfs(g, s-1, dist);
	for(int j = 0; j < n; ++j) {
	    if(j == s-1) continue;
	    cout << dist[j] << " ";
	}
	cout << endl;
    }
}
