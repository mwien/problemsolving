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

int dijkstra(vector<vector<pair<int, int>>> &g, int N, int a, int b)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) *> pq(cmp);
    vector<int> dist (N, mxi);
    dist[a] = 0;
    pq.push({a, 0});
    while(!pq.empty()) {
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if(d > dist[u]) continue;
        if(u == b) return d;
        for(auto it = g[u].begin(); it != g[u].end(); ++it) {
            int v = it -> first;
            int w = it -> second;
            if(w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[b];
}

int main() {
    while(true) {
	int n;
	scanf("%d", &n);
	if(n == 0) break;
	vector<vector<pair<int, int>>> g (n);
	for(int i = 0; i < n; ++i) {
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    g[a].push_back({b, c});
	    g[b].push_back({a, c});
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
	    int a, b;
	    scanf("%d%d", &a, &b);
	    printf("%d\n", dijkstra(g, n, a, b));
	}
    }
}
