//TAGS: UNION-FIND, DAGS, LONGEST PATH

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<list>

using namespace std;

int grid[1000005];
pair<int, int> s[1000005];
unordered_map<int, int> nn;
int sn[1000005];
vector<unordered_set<int>> g;
list<int> l;
bool vis[1000005];
int idx = 0;
int dist[1000005];
int p[1000005];
int r[1000005];

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
bool unionf(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px == py)
	return false; // same set -> reject edge
    if (r[px] < r[py]) { // swap so that always h[px]>=h[py]
	int tmp = px;
	px = py;
	py = tmp;
    }
    p[py] = px; // hang flatter tree as child of higher tree
    r[px] = max(r[px], r[py] + 1); // update (worst-case) height
    return true;
}

void dfs(int u) {
    vis[u] = true;
    for(auto it = g[u].begin(); it != g[u].end(); ++it) {
	int v = *it;
	if(!vis[v]) {
	    dfs(v);
	}
    }
    l.push_front(u);
}

int main()
{
    int m, n;
    cin >> m >> n;
    
    for(int i = 0; i < m*n; ++i) {
	cin >> grid[i];
    }
    for(int i = 0; i < m*n; ++i) {
	p[i] = -1;
    }
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    s[j] = {grid[i*n + j], j};
	}
	sort(s, s+n);
	for(int j = 0; j < n-1; ++j) {
	    if(s[j].first == s[j+1].first)
		unionf(i*n + s[j].second, i*n + s[j+1].second);
	}
    }

    for(int j = 0; j < n; ++j) {
	for(int i = 0; i < m; ++i) {
	    s[i] = {grid[i*n + j], i};
	}
	sort(s, s+m);
	for(int i = 0; i < m-1; ++i) {
	    if(s[i].first == s[i+1].first)
		unionf(s[i].second*n + j, s[(i+1)].second*n + j);
	}
    }

    for(int i = 0; i < m*n; ++i) {
	int u = find(i);
	if(nn.find(u) == nn.end()) {
	    nn.insert({u, idx});
	    ++idx;
	}
    }

    for(int i = 0; i < idx; ++i) {
	g.push_back(unordered_set<int> ());
    }

    for(int i = 0; i < m*n; ++i) {
	int u = find(i);
	sn[i] = nn[u];
    }
    
    for(int i = 0; i < m; ++i) {
	for(int j = 0; j < n; ++j) {
	    s[j] = {grid[i*n + j], j};
	}
	sort(s, s+n);
	for(int j = 0; j < n-1; ++j) {
	    if(s[j].first != s[j+1].first)
		g[sn[i*n + s[j].second]].insert(sn[i*n + s[j+1].second]);
	}
    }

    for(int j = 0; j < n; ++j) {
	for(int i = 0; i < m; ++i) {
	    s[i] = {grid[i*n + j], i};
	}
	sort(s, s+m);
	for(int i = 0; i < m-1; ++i) {
	    if(s[i].first != s[i+1].first)
		g[sn[s[i].second*n + j]].insert(sn[s[(i+1)].second*n + j]);
	}
    }

    //for(auto it = nn.begin(); it != nn.end(); ++it) {
    //	cout << it->first << " " << it->second << endl;
    //}
    
    //for(int i = 0; i < idx; ++i) {
    //	cout << i << ": ";
    //	for(auto it = g[i].begin(); it != g[i].end(); ++it) {
    // 	    cout << *it << " ";
    //	}
    //	cout << endl;
    //}
    for(int i = 0; i < idx; ++i) {
	if(!vis[i]) {
	    dfs(i);
	}
    }
    //for(auto it = l.begin(); it != l.end(); ++it) {
    //	cout << *it << endl;
    //}
    for(auto it = l.begin(); it != l.end(); ++it) {
	int u = *it;
	for(auto sit = g[u].begin(); sit != g[u].end(); ++sit) {
	    int v = *sit;
	    if(dist[u] + 1 > dist[v]) {
		dist[v] = dist[u] + 1;
	    }
	}
    }
    int mx = 0;
    for(int i = 0; i < idx; ++i) {
	mx = max(mx, dist[i]);
    }
    cout << mx + 1 << endl;
}
