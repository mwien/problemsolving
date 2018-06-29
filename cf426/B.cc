#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

pair<int, int> t[26];

int main()
{
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    for(int i = 0; i < 26; ++i) {
	t[i].first = 1e6+5;
	t[i].second = -1;
    }
    for(int j = 0; j < a.size(); ++j) {
	t[a[j] - 'A'].first = min(t[a[j] - 'A'].first, j);
	t[a[j] - 'A'].second = max(t[a[j] - 'A'].second, j);
    }
    vector<pair<int, bool>> e;
    for(int i = 0; i < 26; ++i) {
	e.push_back({t[i].first, false});
	e.push_back({t[i].second, true});
    }
    sort(e.begin(), e.end());
    int op = 0;
    int mx = 0;
    for(int i = 0; i < e.size(); ++i) {
	if(e[i].first == -1 || e[i].first == 1e6+5) continue;
	if(!e[i].second) ++op;
	else --op;
	mx = max(mx, op);
    }
    if(mx > k) cout << "YES" << endl;
    else cout << "NO" << endl;
}
