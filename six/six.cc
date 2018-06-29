#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<utility>
#include<deque>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
	int M;
	cin >> M;
	int id = 0;
	unordered_map<string, int> dev;
	vector<pair<string, string>> ein;
	for(int i = 0; i < M; ++i) {
	    string a, b;
	    cin >> a >> b;
	    ein.push_back({a, b});
	    if(dev.find(a) == dev.end()) dev.insert({a, id++});
	    if(dev.find(b) == dev.end()) dev.insert({b, id++});
	}
	vector<vector<int>> edges;
	for(int i = 0; i < id; ++i) {
	    edges.push_back({});
	}
	for(int i = 0; i < M; ++i) {
	    edges[dev[ein[i].first]].push_back(dev[ein[i].second]);
	    edges[dev[ein[i].second]].push_back(dev[ein[i].first]);
	}
	vector<vector<int>> sp (id, vector<int> (id));
	for(int i = 0; i < id; ++i) {
	    vector<bool> vis (id);
	    deque<int> q;
	    vector<int> dist (id);
	    q.push_back(i);
	    vis[i] = true;
	    while(!q.empty()) {
		int u = q.front();
		q.pop_front();
		for(int j = 0; j < edges[u].size(); ++j) {
		    int v = edges[u][j];
		    if(vis[v]) continue;
		    sp[i][v] = dist[u] + 1;
		    sp[v][i] = dist[u] + 1;
		    dist[v] = dist[u] + 1;
		    vis[v] = true;
		    q.push_back(v);
		}
	    }
	}
	int limit = id / 20;
	int cnt = 0;
	for(int i = 0; i < id; ++i) {
	    bool greater = false;
	    for(int j = 0; j < id; ++j) {
		if(sp[i][j] > 6) greater = true;
	    }
	    if(greater) ++cnt;
	}
	cout << (cnt <= limit ? "YES" : "NO") << endl;
    }
}
