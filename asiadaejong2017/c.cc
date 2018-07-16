// TAGS: TREE, TOPOLOGICAL SORTING
// Problem: http://codeforces.com/gym/101667/attachments (Problem C)


#include<iostream>
#include<vector>
#include<list>

using namespace std;

list<int> l;
bool vis[100005];
int dist[100005];

void dfs(int u, vector<vector<int>> &g) {
    for(int i = 0; i < g[u].size(); ++i) {
	if(!vis[g[u][i]]) {
	    vis[g[u][i]] = true;
	    dfs(g[u][i], g);
	}
    }
    l.push_front(u);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g (n, vector<int>());
    vector<vector<int>> gd (n, vector<int>());
    for(int i = 0; i < m; ++i) {
	int a, b;
	cin >> a >> b;
	g[a].push_back(b);
	g[b].push_back(a);
    }
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < g[i].size(); ++j) {
	    if(g[i].size() < g[g[i][j]].size()) {
		gd[i].push_back(g[i][j]);
	    }
	}
    }
    for(int i = 0; i < n; ++i) {
	vis[i] = true;
	dfs(i, gd);
    }
    for(auto it = l.begin(); it != l.end(); ++it) {
	int u = *it;
	for(int i = 0; i < gd[u].size(); ++i) {
	    if(dist[u] + 1 > dist[gd[u][i]]) {
		dist[gd[u][i]] = dist[u] + 1;
	    }
	}
    }
    int mx = 0;
    for(int i = 0; i < n; ++i) {
	mx = max(mx, dist[i]);
    }
    cout << mx + 1 << endl;
}
