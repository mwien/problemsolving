#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long T[100005];
long long mod = 1000000007;

int main()
{
    int n, p;
    cin >> n >> p;
    vector<pair<int,int>> e;
    for(int i = 0; i < p; ++i) {
	int a, b;
	cin >> a >> b;
	if(a > b) {
	    int tmp = b;
	    b = a;
	    a = tmp;
	}
	e.push_back({b,-a});
    }
    sort(e.begin(), e.end());
    vector<pair<int,int>> ue;
    ue.push_back({1,0});
    int l = -1;
    for(int i = 0; i < p; ++i) {
	e[i].second = -e[i].second;
	if(e[i].second > l) {
	    ue.push_back(e[i]);
	    l = e[i].second;
	}
    }
    //for(int i = 0; i < ue.size(); ++i) {
    //  	cout << ue[i].first << " " << ue[i].second << endl;
    //}
    T[n] = 1;
    int le = n+1;
    int pp = n-1;
    for(int i = ue.size()-1; i >= 0; --i) {
	while(pp >= ue[i].second) {
	    T[pp] = ((((2*T[pp+1] - T[le]) % mod) + mod) % mod);
	    // cout << i << " " << pp << " " << le << " " << T[pp] << endl;
	    --pp;
	}
	le = ue[i].first;
    }
    cout << ((((T[0]-T[1]) % mod) + mod) % mod) << endl;
    //for(int i = 0; i < n; ++i) {
    // 	cout << T[i] << " " << T[i] - T[i+1] << endl;
    //}
}
