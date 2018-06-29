#include<iostream>
#include<queue>

using namespace std;

char f[105][105];
bool vis[105][105];

int main()
{
    int m,n;
    cin >> m >> n;
    for(int i = 0;  i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    cin >> f[i][j];
	}
    }
    int cnt = 0;
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    if(vis[i][j]) continue;
	    if(f[i][j] == '.') continue;
	    ++cnt;
	    queue<pair<int, int>> q;
	    vis[i][j] = true;
	    q.push({i, j});
	    while(!q.empty()) {
		pair<int, int> tmp = q.front(); q.pop();
		int u = tmp.first;
		int v = tmp.second;
		for(int k = -1; k <= 1; ++k) {
		    for(int l = -1; l <= 1; ++l) {
			if(u + k >= 0 && u + k < m && v + l >= 0 && v + l < n) {
			    if(!vis[u+k][v+l] && f[u+k][v+l] == '#') {
				vis[u+k][v+l] = true;
				q.push({u+k, v+l});
			    }
			}
		    }
		}
	    }
	}
    }
    cout << cnt << endl;
}
