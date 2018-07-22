// TAGS: MEET IN THE MIDDLE
// Problem: http://codeforces.com/contest/1006/problem/F

#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

long long a[21][21];
unordered_map<long long, long long> x[21][21];
unordered_map<long long, long long> y[21][21];
bool vis[21][21];

int main()
{
    int n, m;
    long long k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    cin >> a[i][j];
	}
    }
    int fs = (n+m-2)/2, ss = (n+m-1)/2;
    queue<pair<int,int>> q;
    q.push({0,0});
    x[0][0].insert({a[0][0], 1});
    vis[0][0] = true;
    while(true) {
	pair<int, int> pp = q.front(); q.pop();
	int i = pp.first, j = pp.second;
	if(i + j >= fs) break;
	if(i + 1 < n) {
	    for(auto it = x[i][j].begin(); it != x[i][j].end(); ++it) {
		long long nx = it->first;
		long long cnt = it->second;
		nx ^= a[i+1][j];
		if(x[i+1][j].find(nx) == x[i+1][j].end()) {
		    x[i+1][j].insert({nx, cnt});
		} else {
		    x[i+1][j][nx] += cnt;
		}
		if(!vis[i+1][j]) {
		    q.push({i+1,j});
		    vis[i+1][j] = true;
		}
	    }
	}
	if(j + 1 < m) {
	    for(auto it = x[i][j].begin(); it != x[i][j].end(); ++it) {
		long long nx = it->first;
		long long cnt = it->second;
		nx ^= a[i][j+1];
		if(x[i][j+1].find(nx) == x[i][j+1].end()) {
		    x[i][j+1].insert({nx, cnt});
		} else {
		    x[i][j+1][nx] += cnt;
		}
		if(!vis[i][j+1]) {
		    q.push({i,j+1});
		    vis[i][j+1] = true;
		}
	    }
	}
    }
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    vis[i][j] = false;
	}
    }
    queue<pair<int,int>> p;
    p.push({n-1,m-1});
    y[n-1][m-1].insert({0, 1});
    vis[n-1][m-1] = true;
    while(true) {
	pair<int, int> pp = p.front(); p.pop();
	int i = pp.first, j = pp.second;
	if(n + m - (i + j + 2) >= ss) break;
	if(i - 1 >= 0) {
	    for(auto it = y[i][j].begin(); it != y[i][j].end(); ++it) {
		long long nx = it->first;
		long long cnt = it->second;
		nx ^= a[i][j];
		if(y[i-1][j].find(nx) == y[i-1][j].end()) {
		    y[i-1][j].insert({nx, cnt});
		} else {
		    y[i-1][j][nx] += cnt;
		}
		if(!vis[i-1][j]) {
		    p.push({i-1,j});
		    vis[i-1][j] = true;
		}
	    }
	}
	if(j - 1 >= 0) {
	    for(auto it = y[i][j].begin(); it != y[i][j].end(); ++it) {
		long long nx = it->first;
		long long cnt = it->second;
		nx ^= a[i][j];
		if(y[i][j-1].find(nx) == y[i][j-1].end()) {
		    y[i][j-1].insert({nx, cnt});
		} else {
		    y[i][j-1][nx] += cnt;
		}
		if(!vis[i][j-1]) {
		    p.push({i,j-1});
		    vis[i][j-1] = true;
		}
	    }
	}
    }

    // for(int i = 0; i < n; ++i) {
    // 	for(int j = 0; j < m; ++j) {
    // 	    cout << i << " " << j << endl;
    // 	    for(auto it = x[i][j].begin(); it != x[i][j].end(); ++it) {
    // 		cout << "(" << it->first << "," << it->second << ");";
    // 	    }
    // 	    cout << endl;
    // 	    for(auto it = y[i][j].begin(); it != y[i][j].end(); ++it) {
    // 		cout << "(" << it->first << "," << it->second << ");";
    // 	    }
    // 	    cout << endl;
    // 	    cout << "----" << endl;
    // 	}
    // }
    
    long long cnt = 0;
    for(int i = 0; i <= (n+m-2)/2; ++i) {
	int j = (n+m-2) / 2 - i;
	for(auto it = x[i][j].begin(); it != x[i][j].end(); ++it) {
	    long long res = it->first;
	    if(y[i][j].find(k ^ res) != y[i][j].end()) {
		cnt += y[i][j][k^res]*x[i][j][res];
	    }
	}
    }
    cout << cnt << endl;
}
