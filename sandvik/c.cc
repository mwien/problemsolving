#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int s[105], t[105];
double dist[105][105];

double prob(int u, int dt)
{
    if(dt < s[u]) return 1;
    if(dt > t[u]) return 0;
    return 1 - (dt - s[u]) / (double) (t[u] - s[u]);
}

double dijkstra(vector<vector<int>> &g, int N)
{
    priority_queue<pair<double, pair<int, int>>> pq;
    dist[0][1] = 1;
    pq.push({1, {0, 1}});
    while(!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second.first;
	int dt = pq.top().second.second;
	//cout << d << " " << u << " " << dt << endl;
        pq.pop();
        if(d < dist[u][dt] - 1e-9) continue;
        if(u == N-1) return d;
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
	    double p = prob(u, dt) * prob(v, dt);
	    if(u != 0) {
		p /= prob(u, dt-1);
	    }
            if(p * d > dist[v][dt+1]) {
                dist[v][dt+1] = p * d;
                pq.push({dist[v][dt+1], {v, dt+1}});
            }
        }
    }
    return 0;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
	cin >> s[i] >> t[i];
    }
    vector<vector<int>> g (N, vector<int>());
    for(int i = 0; i < M; ++i) {
	int s, d;
	cin >> s >> d;
	g[s].push_back(d);
    }
    printf("%.12f\n", dijkstra(g, N));
}
