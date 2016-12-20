#include<iostream>
#include<vector>
#include<cmath>
#include<utility>

using namespace std;

void process(vector<vector<long long>> &M, vector<long long> &A, int N) {
    for(int i = 0; i < N; i++) {
	M[i][0] = i;
    }
	// filling table M
	// M[i][j] = max(M[i][j-1], M[i+(1<<(j-1))][j-1]),
	// cause interval of length 2^j can be partitioned
	// into two intervals of length 2^(j-1)
	for(int j = 1; 1 << j <= N; j++) {
		for(int i = 0; i + (1 << j) - 1 < N; i++) {
			if(A[M[i][j-1]] >= A[M[i+(1 << (j-1))][j-1]])
				M[i][j] = M[i][j-1];
			else
				M[i][j] = M[i + (1 << (j-1))][j-1];
		}
	}
}

long long query(vector<vector<long long>> &M, vector<long long> &A, int N,
                                     int i, int j) {
	// k = |_ log_2(j-i+1) _|
	int k = (int) (log(j - i + 1) / log(2));
	if(A[M[i][k]] >= A[M[j- (1 << k) + 1][k]])
		return M[i][k];
	else
		return M[j - (1 << k) + 1][k];
}

long long dfs(vector<vector<int>> &g, vector<pair<int, int>> &ts, vector<bool> &vis, vector<int> &p, vector<long long> &pf, vector<int> &mp,  int &time, int u)
{
    ++time;
    ts[u].first = time;
    vis[u] = true;
    int st = time;
    long long pl = p[u];
    for(int j = 0; j < g[u].size(); ++j) {
	int v = g[u][j];
	if(vis[v]) continue;
	pl += dfs(g, ts, vis, p, pf, mp, time, v);
    }
    cout << st << " " << u << " " << pl << endl;
    ts[u].second = time;
    mp[st] = u;
    pf[st] = pl;
    return pl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	p.push_back(a);
    }
    vector<vector<int>> g (n);
    vector<pair<int, int>> ts (n);
    vector<bool> vis (n);
    vector<long long> pf (n);
    vector<int> mp (n);
    for(int i = 0; i < n-1; ++i) {
	int a, b;
	cin >> a >> b;
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);
    }
    int time = -1;
    dfs(g, ts, vis, p, pf, mp, time, 0);
    int sz = (int) (log(n) / log(2)) + 1;
    vector<vector<long long>> M (n, vector<long long> (sz));
    process(M, pf, n);
    long long mx = -1000000005LL;
    for(int i = 0; i < n; ++i) {
	cout << pf[i] << endl;
    }
    for(int i = 0; i < n; ++i) {
	int as = ts[mp[i]].first;
	int ae = ts[mp[i]].second+1;
	cout << i << " " << as << " " << ae << endl;
	long long f = pf[i];
	cout << f << endl;
	if(as <= 0 && ae > n-1) {
	    continue;
	} else {
	    if(as <= 0) {
		mx = max(mx, f+query(M, pf, n, ae, n-1));
	    } else if(ae > n-1) {
		mx = max(mx, f+query(M, pf, n, 0, as-1));
	    } else {
		mx = max(mx, f+query(M, pf, n, ae, n-1));
		mx = max(mx, f+query(M, pf, n, 0, as-1));
	    }
	}
    }
    if(mx == -1000000005LL) {
	cout << "Impossible" << endl;
    } else {
	cout << mx << endl;
    }
}
