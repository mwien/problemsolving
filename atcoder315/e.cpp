#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

void dfs(vector<vector<int>> &g, vector<bool> &vis, int u) {
	vis[u] = true;
	for(int v : g[u]) {
		if(!vis[v]) {
			dfs(g, vis, v);
		}
	}
	if(u != 0) {
		cout << u+1 << " ";
	}
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> g (n);
	for(int i = 0; i < n; ++i) {
		int ci;
		cin >> ci;
		for(int j = 0; j < ci; ++j) {
			int a;
			cin >> a;
			g[i].push_back(a-1);
		}
	}
	vector<bool> vis (n);
	dfs(g, vis, 0);
}



