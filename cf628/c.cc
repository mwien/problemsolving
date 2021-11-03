#include<iostream>
#include<vector>

using namespace std;

int T[100005];
pair<int, int> ws[100005];
vector<vector<int>> g;
int out[100005];

pair<int, int> rec_dfs(int u, int prev) {
    if(g[u].size() == 1) return {0, -1};
    int mm = 10e6;
    int im = -2;
    int ms = 10e6;
    int is = -2;
    for(int i = 0; i < g[u].size(); ++i) {
	int v = g[u][i];
	if(v == prev) continue;
	pair<int, int> d = rec_dfs(v, u);
	int a = d.first, b = d.second;
	if(a < mm) {
	    ms = mm;
	    is = im;
	    mm = a;
	    im = b;
	} else if(a < ms) {
	    ms = a;
	    is = b;
	}
    }
    T[u] = mm+ms;
    ws[u] = {im, is};
    return {mm, im};
}

void rec_set(int u) {
    
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	g.push_back(vector<int>());
    }
    for(int i = 0; i < n-1; ++i) {
	int a, b;
	cin >> a >> b;
	g[a-1].push_back(b-1);
	g[b-1].push_back(a-1);
    }
    int st = -1;
    for(int i = 0; i < n; ++i) {
	if(g[i].size() > 1) {
	    st = i;
	    break;
	}
    }
    if(st == -1) {
	for(int i = 0; i < n-1; ++i) {
	    cout << i << endl;
	}
    } else {
	rec_dfs(st, -1);
	int mmm = 10e6, mmi = -1;
	for(int i = 0; i < n; ++i) {
	    if(T[i] < mmm) {
		mmm = T[i];
		mmi = i;
	    }
	}
	
    }
}
