// TAGS: DFS, TREE
// Problem: http://codeforces.com/contest/1006/problem/E

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

vector<int> l;
bool vis[200005];

void dfs(int u, vector<vector<int>> &g, vector<int> &nd) {
    for(int i = 0; i < g[u].size(); ++i) {
	if(!vis[g[u][i]]) {
	    vis[g[u][i]] = true;
	    l.push_back(g[u][i]);
	    dfs(g[u][i], g, nd);
	}
    }
    nd[u] = l.size()-1;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g (n);
    for(int i = 0; i < n-1; ++i) {
	int a;
	cin >> a;
	g[a-1].push_back(i+1);
    }
    vis[0] = true;
    l.push_back(0);
    vector<int> nd(n);
    dfs(0, g, nd);
    vector<int> rev(n);
    for(int i = 0; i < n; ++i) {
	rev[l[i]] = i;
    }
    for(int i = 0; i < q; ++i) {
	int a, b;
	cin >> a >> b;
	if(rev[a-1] + b - 1 <= nd[a-1])
	    cout << l[rev[a-1] + b - 1]+1 << endl;
	else cout << "-1\n";
    }
}
