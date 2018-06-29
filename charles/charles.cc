#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

bool cmp(pair<int, long long> a, pair<int, long long> b)
{
    return (a.second > b.second);
}

long long dijkstra(vector<vector<pair<int, long long>>> &g, long long lim, int N)
{
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp) *> pq(cmp);
    vector<long long> dist (N, 1LL << 50);
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
	int u = pq.top().first;
	long long d = pq.top().second;
	pq.pop();
	if(d > dist[u]) continue;
	if(u == N-1) return dist[u];
	for(auto it = g[u].begin(); it != g[u].end(); ++it) {
	    int v = it -> first;
	    long long w = it -> second;
	    if(w > lim) continue;
	    if(w + dist[u] < dist[v]) {
		dist[v] = w + dist[u];
		pq.push({v, dist[v]});
	    }
	}
    }
    return dist[N-1];
}

int main()
{
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<pair<int, long long>>> g (N);
    long long mx = 0;
    for(int i = 0; i < M; ++i) {
	int a, b;
	long long c;
	cin >> a >> b >> c;
	mx = max(mx, c);
	g[a-1].push_back({b-1, c});
	g[b-1].push_back({a-1, c});
    }
    long long lim = dijkstra(g, mx, N) * (X + 100);
    int lo = 0, hi = mx, mn = mx;
    while(lo <= hi) {
	int mid = (lo + hi) / 2;
	if(dijkstra(g, mid, N) * 100 > lim) {
	    lo = mid + 1;
	} else {
	    hi = mid - 1;
	    mn = min(mn, mid);
	}
    }
    cout << mn << endl;
}
