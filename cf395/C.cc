#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkns(vector<vector<int>> &g, vector<int> &c, int s, int &frt, int &srt) {
    queue<int> q;
    int n = g.size();
    vector<bool> vis (n);
    vis[s] = true;
    for(int i = 0; i < g[s].size(); ++i) {
	q.push(g[s][i]);
	vis[g[s][i]] = true;
    }
    bool poss = true;
    while(!q.empty()) {
	int u = q.front(); q.pop();
	for(int i = 0; i < g[u].size(); ++i) {
	    int v = g[u][i];
	    if(vis[v]) continue;
	    if(c[v] != c[u]) {
		frt = u;
		srt = v;
		poss = false;
		break;
	    }
	    q.push(v);
	    vis[v] = true;
	}
	if(!poss) break;
    }
    if(poss) return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> g (n);
    for(int i = 0; i < n-1; ++i) {
	int u, v;
	cin >> u >> v;
	g[u-1].push_back(v-1);
	g[v-1].push_back(u-1);
    }
    vector<int> c;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	c.push_back(a);
    }
    int frt = 0;
    int srt = 0;
    if(checkns(g, c, 0, frt, srt)) {
	cout << "YES" << endl;
	cout << 1<< endl;
    } else {
	int rnd = 0, srnd = 0;
	if(checkns(g, c, frt, rnd, srnd)) {
	    cout << "YES" << endl;
	    cout << frt+1 << endl;
	} else if(checkns(g, c, srt, rnd, srnd)) {
	    cout << "YES" << endl;
	    cout << srt+1 << endl;
	} else {
	    cout << "NO" << endl;
	}
    }
}
