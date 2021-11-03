#include<iostream>
#include<queue>

using namespace std;

char m[1005][1005];
int dist[1005][1005];
bool vis[1005][1005];

int main()
{
    int w, h;
    cin >> w >> h;
    int sx, sy;
    for(int i = 0; i < h; ++i) {
	string s;
	cin >> s;
	for(int j = 0; j < w; ++j) {
	    m[i][j] = s[j];
	    if(s[j] == 'S') {
		sx = i;
		sy = j;
	    }
	}
    }

    string dir;
    cin >> dir;

    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy] = true;

    while(!q.empty()) {
	pair<int, int> tp = q.front(); q.pop();
	int x = tp.first;
	int y = tp.second;
	vector<pair<int,int>> pn;
	pn.push_back({x-1,y});
	pn.push_back({x+1,y});
	pn.push_back({x,y-1});
	pn.push_back({x,y+1});
	for(pair<int,int> np : pn) {
	    int nx = np.first;
	    int ny = np.second;
	    if(nx >= 0 && nx < h && ny >= 0 && ny < w && m[nx][ny] != '#' && !vis[nx][ny]) {
		q.push({nx,ny});
		dist[nx][ny] = dist[x][y] + 1;
		vis[nx][ny] = true;
	    }
	}
    }

    for(int i = 0; i < h; ++i) {
	for(int j = 0; j < w; ++j) {
	    vis[i][j] = false;
	}
    }
    
    q.push({sx,sy});
    vis[sx][sy] = true;

    while(!q.empty()) {
	pair<int, int> tp = q.front(); q.pop();
	int x = tp.first;
	int y = tp.second;
	vector<pair<int,int>> pn;
	if(dist[x][y] >= dir.size()) continue;
	if(dir[dist[x][y]] != 'N') {
	    pn.push_back({x-1,y});
	}
	if(dir[dist[x][y]] != 'S') {
	    pn.push_back({x+1,y});
	}
	if(dir[dist[x][y]] != 'W') {
	    pn.push_back({x,y-1});
	}
	if(dir[dist[x][y]] != 'E') {
	    pn.push_back({x,y+1});
	}
	for(pair<int,int> np : pn) {
	    int nx = np.first;
	    int ny = np.second;
	    if(nx >= 0 && nx < h && ny >= 0 && ny < w && m[nx][ny] != '#' && !vis[nx][ny] && dist[nx][ny] == dist[x][y] + 1) {
		q.push({nx,ny});
		vis[nx][ny] = true;
	    }
	}
    }
    // for(int i = 0; i < h; ++i) {
    // 	for(int j = 0; j < w; ++j) {
    // 	    cout << vis[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    //     for(int i = 0; i < h; ++i) {
    // 	for(int j = 0; j < w; ++j) {
    // 	    cout << vis[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    for(int i = 0; i < h; ++i) {
	for(int j = 0; j < w; ++j) {
	    if(dist[i][j] == dir.size() && vis[i][j]) {
		m[i][j] = '!';
	    }
	}
    }
    for(int i = 0; i < h; ++i) {
	string ln = "";
	for(int j = 0; j < w; ++j) {
	    ln += m[i][j];
	}
	cout << ln << endl;
    }
}
