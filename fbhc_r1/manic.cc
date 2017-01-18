#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int mxi = (1 << 30);

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second);
}

int dijkstra(vector<vector<pair<int, int>>> &g, int N, int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) *> pq(cmp);
    vector<int> dist (N, mxi);
    dist[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()) {
	int u = pq.top().first;
	int d = pq.top().second;
	pq.pop();
	if(d > dist[u]) continue;
	if(u == t) return d;
	for(auto it = g[u].begin(); it != g[u].end(); ++it) {
	    int v = it -> first;
	    int w = it -> second;
	    if(w + dist[u] < dist[v]) {
		dist[v] = w + dist[u];
		pq.push({v, dist[v]});
	    }
	}
    }
    return dist[t];
}

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g (n);
	for(int i = 0; i < m; ++i) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    g[a-1].push_back({b-1, c});
	    g[b-1].push_back({a-1, c});
	}
	vector<pair<long long, long long>> ud (2*k);
	vector<pair<int, int>> last (2*k);
	vector<pair<int, int>> fm;
	for(int i = 0; i < k; ++i) {
	    int a, b;
	    cin >> a >> b;
	    fm.push_back({a-1, b-1});
	}
	ud[0].first = dijkstra(g, n, 0, fm[0].first);
	ud[0].second = ud[0].first;
	last[0].first = fm[0].first;
	last[0].second = fm[0].first;
	for(int i = 1; i < 2*k; ++i) {
	    if(i % 2 == 0) {
		ud[i].first = ud[i-1].first + dijkstra(g, n, last[i-1].first, fm[i / 2].first);
		ud[i].second = ud[i-1].second + dijkstra(g, n, last[i-1].second, fm[i / 2-1].second);
		last[i].first = fm[i/2].first;
		last[i].second = fm[i/2-1].second;
	    } else {
		ud[i].first = min(ud[i-1].first + dijkstra(g, n, last[i-1].first, fm[i/2].second), ud[i-1].second + dijkstra(g, n, last[i-1].second, fm[i/2].second));
		last[i].first = fm[i/2].second;
		if(i != 2*k-1) {
		    ud[i].second = min(ud[i-1].first + dijkstra(g, n, last[i-1].first, fm[i/2 + 1].first), ud[i-1].second + dijkstra(g, n, last[i-1].second, fm[i/2+1].first));
		    last[i].second = fm[i/2+1].first;
		}
	    }
	}
	if(ud[2*k-1].first >= mxi) {
	    cout << "Case #" << t+1 << ": " << -1 << endl;
	} else {
	    cout << "Case #" << t+1 << ": " << ud[2*k-1].first << endl;
	}
    }
}
