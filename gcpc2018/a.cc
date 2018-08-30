//TAGS: LCA, RMQ, DFS

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>

using namespace std;

int T[2000005][25];
int l[10001];
unordered_map<int, int> il;
bool vis[1000005];
int E[2000005];
int L[2000005];
int H[1000005];
int gidx = 0;
int D[1000005];

void process(int N) {
	for(int i = 0; i < N; i++)
		T[i][0] = i;
	for(int j = 1; 1 << j <= N; j++) {
		for(int i = 0; i + (1 << j) - 1 < N; i++) {
			if(L[T[i][j-1]] <= L[T[i+(1 << (j-1))][j-1]])
				T[i][j] = T[i][j-1];
			else
				T[i][j] = T[i + (1 << (j-1))][j-1];
		}
	}
}

int query(int N, int i, int j) {
	int k = (int) (log(j - i + 1) / log(2));
	if(L[T[i][k]] <= L[T[j- (1 << k) + 1][k]])
		return T[i][k];
	else
		return T[j - (1 << k) + 1][k];
}

void euler(int u, int level, int dist, vector<vector<int>> &g) {
    vis[u] = true;
    D[u] = dist;
    E[gidx] = u;
    L[gidx] = level;
    ++gidx;
    for(int i = 0; i < g[u].size(); ++i) {
	int v = g[u][i];
	if(!vis[v]) {
	    euler(v, level + 1, dist + 1, g);
	    E[gidx] = u;
	    L[gidx] = level;
	    ++gidx;
	}
    }
}

int main()
{
    int h, w;
    cin >> h >> w;
    string trash;
    getline(cin, trash);
    vector<vector<int>> g (h*w, vector<int> ());
    for(int i = -1; i < h; ++i) {
	string rin;
	getline(cin, rin);
	
	for(int j = -1; j < 2*w; ++j) {
	    char in = rin[j+1];
	    if(i < 0 || j < 0 || j >= 2*w-1) continue;
	    int idx = i*w+j/2;
	    if(in == ' ') {
		g[idx].push_back(j % 2 == 0 ? idx + w : idx + 1);
		g[j % 2 == 0 ? idx + w : idx + 1].push_back(idx);
	    }
	}
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
	int x, y;
	cin >> x >> y;
	l[i] = (x-1)*w + y - 1;
	il.insert({l[i], i});
    }
    euler(l[0], 0, 0, g);
    for(int i = 0; i < h*w; ++i) {
	H[i] = -1;
    }
    for(int i = 0; i < 2*h*w-1; ++i) {
	if(H[E[i]] == -1) {
	    H[E[i]] = i;
	}
    }
    process(2*h*w-1);
    long long sum = 0;
    for(int i = 1; i < m; ++i) {
	int ll = l[i-1];
	int nl = l[i];
	int lca = E[query(2*h*w-1, min(H[nl], H[ll]), max(H[nl], H[ll]))];
	sum += D[ll] + D[nl] - 2*D[lca];
    }
    cout << sum << endl;
}
