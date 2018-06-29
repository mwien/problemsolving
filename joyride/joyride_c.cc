#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

long long mxi = (1LL << 60);

bool cmp(pair<int, long long> a, pair<int, long long> b)
{
  return (a.second > b.second);
}

int dijkstra(vector<vector<int>> &g, vector<pair<int, long long>> &rides, int N, int n, int x, int t)
{
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp) *> pq(cmp);
  vector<long long> dist (N, mxi);
  if(rides[0].first >= x) return mxi;
  dist[rides[0].first] = rides[0].second;
  pq.push({rides[0].first,rides[0].second});
  while(!pq.empty()) {
    int u = pq.top().first;
    int nr = u / x;
    int ti = u % x;
    long long d = pq.top().second;
    pq.pop();
    if(d > dist[u]) continue;
    if(u == x-1) return d;
    for(int i = 0; i < g[nr].size(); ++i) {
      int v = g[nr][i];
      if(ti + t + rides[v].first >= x) continue;
      if(rides[v].second + dist[u] < dist[v * x + ti + t + rides[v].first]) {
	dist[v * x + ti + t + rides[v].first] = rides[v].second + dist[u];
	pq.push({v * x + ti + t + rides[v].first, dist[v* x + ti + t + rides[v].first]});
      }
    }
    if(rides[nr].first + ti < x) {
	if(rides[nr].second + dist[u] < dist[u + rides[nr].first]) {
	    dist[u + rides[nr].first] = rides[nr].second + dist[u];
	    pq.push({u + rides[nr].first, dist[u + rides[nr].first]});
	}
    }
  }
  return dist[x-1];
}

int main()
{
  int x;
  cin >> x;
  int n, m, t;
  cin >> n >> m >> t;
  vector<vector<int>> g (n);
  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  vector<pair<int, long long>> rides;
  for(int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    rides.push_back({a, b});
  }
  long long res =  dijkstra(g, rides, (x+1) * n, n, x+1, t);
  if(res == mxi) {
    cout << "It is a trap." << endl;
  } else {
    cout << res << endl;
  }
}
