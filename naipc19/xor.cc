#include<bits/stdc++.h>

using namespace std;

unordered_set<int> hs[32];
const long long mod = 1000000007;

long long rec(vector<int> &p, int idx)
{
    if(p.size() > (1 << (idx+1))) return 0;
    if(idx == -1) return 1;
    long long res = 0;
    res = (res + 2*rec(p, idx-1)) % mod;
    bool poss = true;
    for(int i = 0; i < p.size(); ++i) {
	if(hs[2*idx].find(p[i]) != hs[2*idx].end() && hs[2*idx+1].find(p[i]) != hs[2*idx+1].end()) {
	    poss = false;
	    break;
	}
    }
    if(poss) {
	vector<int> t, f;
	for(int i = 0; i < p.size(); ++i) {
	    if(hs[2*idx].find(p[i]) != hs[2*idx].end()) t.push_back(p[i]);
	    else f.push_back(p[i]);
	}
	if(!(t.empty() || f.empty())) res = (res + rec(t, idx-1) * rec(f, idx-1)) % mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < (1 << m); ++i) {
	int a;
	cin >> a;
	for(int j = 0; j < m; ++j) {
	    if(i & (1 << j)) hs[2*j].insert(a);
	    else hs[2*j+1].insert(a);
	}
    }
    vector<int> p;
    for(int i = 1; i <= n; ++i) {
	p.push_back(i);
    }
    cout << rec(p, m-1) << endl;
}
