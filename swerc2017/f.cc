#include<iostream>
#include<unordered_map>

using namespace std;

int entry[2005];
int ext[2005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
	cin >> entry[i];
    }
    for(int i = 0; i < m; ++i) {
	cin >> ext[i];
    }
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    int diff = ext[j] - entry[i];
	    if(diff < 0) continue;
	    if(mp.find(diff) != mp.end()) {
		++mp[diff];
	    } else {
		mp.insert({diff, 1});
	    }
	}
    }
    int mx = 0, mxcnt = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it) {
	if((it->second > mxcnt) || (it->second == mxcnt && it->first < mx)) {
	    mx = it->first;
	    mxcnt = it->second;
	}
    }
    cout << mx << endl;
}
