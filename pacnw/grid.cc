#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int g[505][505];
int d[505][505];
bool v[505][505];

int main() {
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
	for(int j = 0; j < n; ++j) {
	    char a;
	    cin >> a;
	    g[i][j] = a - '0';
	}
    }
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    d[i][j] = -1;
	}
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    d[0][0] = 0;
    v[0][0] = true;
    while(!q.empty()) {
	pair<int, int> u = q.front(); q.pop();
	int x = u.first;
	int y = u.second;
	if(g[x][y] + x < m) {
	    int nx = x + g[x][y];
	    if(!v[nx][y]) {
		d[nx][y] = d[x][y] + 1;
		v[nx][y] = true;
		q.push({nx, y});
	    }
	}
	if(y - g[x][y] >= 0) {
	    int ny = y - g[x][y];
	    if(!v[x][ny]) {
		d[x][ny] = d[x][y] + 1;
		v[x][ny] = true;
		q.push({x, ny});
	    }
	}
	if(g[x][y] + y < n) {
	    int ny = y + g[x][y];
	    if(!v[x][ny]) {
		d[x][ny] = d[x][y] + 1;
		v[x][ny] = true;
		q.push({x, ny});
	    }
	}
	if(x - g[x][y] >= 0) {
	    int nx = x - g[x][y];
	    if(!v[nx][y]) {
		d[nx][y] = d[x][y] + 1;
		v[nx][y] = true;
		q.push({nx, y});
	    }
	}
    }
    if(d[m-1][n-1] == -1) {
	cout << "IMPOSSIBLE" << endl;
    } else {
	cout << d[m-1][n-1] << endl;
    }
}
