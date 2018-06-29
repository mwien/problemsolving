#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

int mxi = (1 << 25);

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second);
}

pair<int, int> dijkstra(vector<vector<pair<int, int>>> &g, vector<int> &t, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) *> pq(cmp);
    vector<int> dist (N, mxi);
    vector<int> mt (N, 0);
    dist[0] = 0;
    mt[0] = t[0];
    pq.push({0, 0});
    while(!pq.empty()) {
	int u = pq.top().first;
	int d = pq.top().second;
	pq.pop();
	if(d > dist[u]) continue;
	for(auto it = g[u].begin(); it != g[u].end(); ++it) {
	    int v = it -> first;
	    int w = it -> second;
	    if(w + dist[u] == dist[v] && mt[v] < mt[u]+t[v]) {
		mt[v] = mt[u] + t[v];
	    } else if(w + dist[u] < dist[v]) {
		dist[v] = w + dist[u];
		pq.push({v, dist[v]});
		mt[v] = mt[u] + t[v];
	    }
	}
    }
    return {dist[N-1], mt[N-1]};
}

int main()
{
    int n;
    cin >> n;
    vector<int> t;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	t.push_back(a);
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> g (n);
    for(int i = 0; i < m; ++i) {
	int a, b, d;
	cin >> a >> b >> d;
	g[a-1].push_back({b-1, d});
	g[b-1].push_back({a-1, d});
    }
    pair<int, int> res = dijkstra(g, t, n);
    if(res.first == mxi) {
	cout << "impossible" << endl;
    } else {
	cout << res.first << " " << res.second << endl;
    }
}
