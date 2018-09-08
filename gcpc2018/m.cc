//TAGS: UNION-FIND

#include<iostream>
#include<unordered_set>
#include<algorithm>

using namespace std;

int g[505][505];
unordered_set<int> s[250005];
int res[100005];
int height = 0;
int p[250005];
pair<int, int> ss[250005];

int find(int x) {
    int root = x;
    while (p[root] >= 0) { // find root
	root = p[root];
    }
    while (p[x] >= 0) { // path compression
	int tmp = p[x];
	p[x] = root;
	x = tmp;
    }
    return root;
}

// return true, if sets merged and false, if already from same set
bool unio(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py)
	return false; // same set -> reject edge
    if (s[px].size() < s[py].size()) { // swap so that always h[px]>=h[py]
	int tmp = px;
	px = py;
	py = tmp;
    }
    p[py] = px; // hang flatter tree as child of higher tree
    for(auto it = s[py].begin(); it != s[py].end(); ++it) {
	int t = *it;

	if(s[px].find(t) != s[px].end()) {
	    res[t] = max(height, res[t]);
	    s[px].erase(t);
	} else {
	    s[px].insert(t);
	}
    }
    return true;
}

int main()
{
    int m, n, q;
    cin >> m >> n >> q;
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    cin >> g[i][j];
	    ss[i*n + j] = {g[i][j], i*n+j};
	}
    }
    sort(ss, ss+m*n);
    for(int i = 0; i < q; ++i) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	res[i] = max(g[x1-1][y1-1], g[x2-1][y2-1]);
	s[(x1 - 1) * n + y1 - 1].insert(i);
	s[(x2 - 1) * n + y2 - 1].insert(i);
    }
    for(int i = 0; i < m*n; ++i) {
	p[i] = -1;
    }
    for(int i = 0; i < m*n; ++i) {
	height = ss[i].first;
	int u = ss[i].second;
	int ux = u / n;
	int uy = u % n;
	for(int j = -1; j <= 1; ++j) {
	    for(int k = -1; k <= 1; ++k) {
		if(((k + j) % 2) != 0 && ux + j >= 0 && ux + j < m && uy + k >= 0 && uy + k < n && g[ux+j][uy+k] <= height) {
		    unio(u, (ux+j)*n + uy+k);
		}
	    }
	}
    }
    for(int i = 0; i < q; ++i) {
	cout << res[i] << endl;
    }
}
