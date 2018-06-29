#include<iostream>
#include<vector>

using namespace std;

long long T[1005][1005];

int main()
{
    int x, n, m, t;
    cin >> x >> n >> m >> t;
    vector<vector<int>> g (n);
    for(int i = 0; i < m; ++i) {
	int a, b;
	cin >> a >> b;
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);
    }
    vector<pair<int,int>> p;
    for(int i = 0; i < n; ++i) {
	int a, b;
	cin >> a >> b;
	p.push_back({a,b});
    }
    for(int i = 0; i <= x; ++i) {
	for(int j = 0; j < n; ++j) {
	    T[i][j] = (1LL << 60);
	}
    }
    if(p[0].first <= x) { 
	T[p[0].first][0] = p[0].second;
	for(int i = p[0].first; i <= x; ++i) {
	    for(int j = 0; j < n; ++j) {
		for(int k = 0; k < g[j].size(); ++k) {
		    int v = g[j][k];
		    int time = i + t + p[v].first;
		    if(time > x) continue;
		    long long prize = T[i][j] + p[v].second;
		    T[time][v] = min(T[time][v], prize);
		}
		if(i + p[j].first > x) continue;
		T[i + p[j].first][j] = min(T[i + p[j].first][j], T[i][j] + p[j].second);
	    }
	}
    }
    if(T[x][0] == (1LL << 60)) {
	cout << "It is a trap." << endl;
    } else {
	cout << T[x][0] << endl;
    }
}
