#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int find(int x, vector<int> &r, vector<int> &p) {
    int root = x;
    while(p[root] >= 0) root = p[root];
    while(p[x] >= 0) {
	int tmp = p[x];
	p[x] = root;
	x = tmp;
    }
    return root;
}

bool unionf(int x, int y, vector<int> &r, vector<int> &p, int &cnt) {
    int px = find(x, r, p);
    int py = find(y, r, p);
    if(px == py) return false;
    if(r[px] < r[py]) {
	int tmp = px;
	px = py;
	py = tmp;
    }
    p[py] = px;
    r[px] = max(r[px], r[py]+1);
    --cnt;
    return true;
}

void change(int x, int y, vector<vector<bool>> &grid, vector<int> &r, vector<int> &p, int &cnt, int n, int m, bool flag) {
    int idx = x * m + y;
    grid[x][y] = flag;
    //if(y > 0) cout << x << " " << y-1 << " " << grid[x][y-1] << endl;
    //cout << x << " " << y << " " << grid[x][y] << endl;
    //if(y < m-1) cout << x << " " << y+1 << " " << grid[x][y+1] << endl;
    ++cnt;
    if(x > 0 && grid[(idx / m) - 1][idx % m] == grid[idx / m][idx % m]) {
	//cout << "HI" << " " << cnt << endl;
	unionf(idx, idx - m, r, p, cnt);
	//cout << "HO" << " " << cnt << endl;
    }
    if(x < n-1 && grid[(idx / m) + 1][idx % m] == grid[idx / m][idx % m]) {
	//cout << "HI" << " " << cnt << endl;
	unionf(idx, idx + m, r, p, cnt);
	//cout << "HO" << " " << cnt << endl;
    }
    if(y > 0 && grid[idx / m][(idx % m) - 1] == grid[idx / m][idx % m]) {
	//cout << "HI" << " " << cnt << endl;
	unionf(idx, idx - 1, r, p, cnt);
	//cout << "HO" << " " << cnt << endl;
    }
    if(y < m-1 && grid[idx / m][(idx % m) + 1] == grid[idx / m][idx % m]) {
	//cout << "HI" << " " << cnt << endl;
	unionf(idx, idx + 1, r, p, cnt);
	//cout << "HO" << " " << cnt << endl;
    }
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> grid (n, vector<bool>(m));
    vector<vector<pair<int, int>>> diff;
    for(int i = 0; i < q; ++i) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	diff.push_back({});
	for(int j = x1-1; j < x2; ++j) {
	    for(int k = y1-1; k < y2; ++k) {
		if(!grid[j][k]) {
		   diff[i].push_back({j, k});
		   grid[j][k] = true;
		}
	    }
	}
    }
    vector<pair<int, int>> start;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    if(!grid[i][j]) start.push_back({i, j});
	    grid[i][j] = false;
	}
    }
    int cnt = 0;
    vector<int> r (n*m);
    vector<int> p (n*m, -1);
    for(int i = 0; i < start.size(); ++i) {
	change(start[i].first, start[i].second, grid, r, p, cnt, n, m, true);
    }
    vector<int> res;
    res.push_back(cnt);
    for(int i = q-1; i >= 0; --i) {
	//int oldcnt = cnt;
	for(int j = 0; j < diff[i].size(); ++j) {
	    if(diff[i][j].second > 0 && diff[i][j].second < m-1) {
		//cout << grid[diff[i][j].first][diff[i][j].second-1] << " "<< grid[diff[i][j].first][diff[i][j].second] << " " << grid[diff[i][j].first][diff[i][j].second+1] << endl;
	    }
	    change(diff[i][j].first, diff[i][j].second, grid, r, p, cnt, n, m, true);
	    //cout << oldcnt << " " << cnt << endl;
	    //cout << j << " " << diff[i].size() << endl;
	    //oldcnt = cnt;
	}
	res.push_back(cnt);
    }
    for(int i = q-1; i >= 0; --i) {
	cout << res[i] << endl;
    }
}
