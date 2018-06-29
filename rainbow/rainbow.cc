#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;

bool vis[50005];
vector<int> gd;

void bfs(vector<vector<int>> &g, int j, int i)
{
    vis[j] = true;
    queue<int> q;
    q.push(j);
    gd.push_back(j);
    while(!q.empty()) {
	int u = q.front(); q.pop();
	for(int v = 0; v < g[u].size(); ++v) {
	    if(g[u][v] == i) continue;
	    if(vis[g[u][v]]) continue;
	    q.push(g[u][v]);
	    gd.push_back(g[u][v]);
	    vis[g[u][v]] = true;
	}
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g (n, vector<int>());
    vector<unordered_map<int,vector<int>>> col (n, unordered_map<int,vector<int>>());
    for(int i = 0; i < n-1; ++i) {
	int a, b, c;
	cin >> a >> b >> c;
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);
	col[a-1][c].push_back(b-1);
	col[b-1][c].push_back(a-1);
    }
    int cnt = 0;
    int ind = -1;
    for(int i = 0; i < n; ++i) {
	bool mult = false;
	for(auto it = col[i].begin(); it != col[i].end(); ++it) {
	    if((it->second).size() > 1) {
		mult = true;
		ind = i;
	    }
	}
	if(mult) ++cnt;
    }
    if(cnt == 0) {
	cout << n << endl;
	for(int i = 0;  i < n; ++i) {
	    cout << i + 1 << endl;
	}
    } else if(cnt == 1) {
	for(auto it = col[ind].begin(); it != col[ind].end(); ++it) {
	    if((it->second).size() > 1) {
		for(int j = 0; j < (it->second).size(); ++j) {
		    bfs(g, (it->second)[j], ind);
		}
	    }
	}
	cout << gd.size() << endl;
	sort(gd.begin(), gd.end());
	for(int i = 0; i < gd.size(); ++i) {
	    cout << gd[i] << endl;
	}
    } else if(cnt == 2) {
	cout << 0 << endl;
    }
}
