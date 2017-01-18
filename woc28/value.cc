#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

bool rev (pair<long long, int> i, pair<long long, int> j) {return (i.first > j.first);}

void bfs(vector<vector<int>> &g, vector<int> &cmp, int cnt, int s)
{
    queue<int> q;
    q.push(s);
    cmp[s] = cnt;
    while(!q.empty()) {
	int u = q.front();
	q.pop();
	for(int j = 0; j < g[u].size(); ++j) {
	    int v = g[u][j];
	    if(cmp[v] == -1) {
		cmp[v] = cnt;
		q.push(v);
	    }
	}
    }
}

int main()
{
    int q;
    cin >> q;
    for(int tc = 0; tc < q; ++tc) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g (n);
	for(int i = 0; i < m; ++i) {
	    int a, b;
	    cin >> a >> b;
	    g[a-1].push_back(b-1);
	    g[b-1].push_back(a-1);
	}
	vector<int> cmp (n, -1);
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
	    if(cmp[i] == -1) {
		bfs(g, cmp, cnt, i);
		++cnt;
	    }
	}
	vector<pair<long long, int>> comp (cnt);
	for(int i = 0; i < cnt; ++i) {
	    comp[i] = {0, i};
	}
	for(int i = 0; i < n; ++i) {
	    ++comp[cmp[i]].first;
	}
	sort(comp.begin(), comp.end(), rev);
	long long ed = 0;
	long long up = 0;
	long long total = 0;
	for(int i = 0; i < cnt; ++i) {
	    ed += comp[i].first - 1;
	    total += up * (comp[i].first-1);
	    for(long long j = 1; j < comp[i].first; ++j) {
		total += (j+1) * j;
	    }
	    up += comp[i].first * (comp[i].first-1);
	}
	total += up * (m - ed);
	cout << total << endl;
    }
}
