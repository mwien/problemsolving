#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

int gp[1000005];
long long fac[1000005];

bool cs (pair<int, int> i, pair<int, int> j) {
    if(gp[i.first] != gp[j.first]) {
	return (gp[i.first] > gp[j.first]);
    } else {
	return i.second > j.second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    fac[0] = 1;
    long long mod = 1000000007;
    for(int i = 1; i <= m; ++i)  {
	fac[i] = (i * fac[i-1]) % mod;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
	int g;
	cin >> g;
	unordered_map<int, int> mp;
	for(int j = 0; j < g; ++j) {
	    int pk;
	    cin >> pk;
	    if(mp.find(pk) != mp.end()) {
		++mp[pk];
	    } else {
		mp.insert({pk, 1});
	    }
	}
	vector<pair<int, int>> pp;
	for(auto it = mp.begin(); it != mp.end(); ++it) {
	    pp.push_back(*it);
	}
	sort(pp.begin(), pp.end(), cs);
	int occ = -1, gr = -1;
	for(int i = 0; i < pp.size(); ++i) {
	    if(gr != gp[pp[i].first] || occ != pp[i].second) {
		++cnt;
		gr = gp[pp[i].first];
		occ = pp[i].second;
	    }
	    gp[pp[i].first] = cnt;
	}
    }
    unordered_map<int, int> comp;
    for(int i = 1; i <= m; ++i) {
	if(comp.find(gp[i]) != comp.end()) {
	    ++comp[gp[i]];
	} else {
	    comp.insert({gp[i], 1});
	}
    }
    long long res = 1;
    for(auto it = comp.begin(); it != comp.end(); ++it) {
	res = (res * fac[it->second]) % mod;
    }
    cout << res << endl;
}
