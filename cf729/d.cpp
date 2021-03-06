#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

int T[501][501][501];
int el[505];
int idx[505];
pair<int, int> seq[505];

int main()
{
    int n;
    cin >> n;
    int ii = 1;
    for(int i = 1; i <= n; ++i) {
	string a;
	cin >> a;
	if(a == "-") {
	    seq[i] = {0,-1};
	} else {
	    int x;
	    cin >> x;
	    seq[i] = {1,x};
	    el[ii] = x;
	    idx[ii] = i;
	    ++ii;
	}
    }
    int mod = 998244353;
    for(int j = 1; j < ii; ++j) {
	T[0][j][0] = 1;
    }
    for(int i = 1; i <= n; ++i) {
	for(int j = 1; j < ii; ++j) {
	    T[i][j][0] = T[i-1][j][0];
	    if(seq[i].first == 0) {
		T[i][j][0] = (T[i][j][0] + T[i-1][j][1]) % mod;
		if(idx[j] > i) {
		    T[i][j][0] = (T[i][j][0] + T[i-1][j][0]) % mod;
		}
	    }
	    if(seq[i].first == 1 && seq[i].second > el[j]  || (seq[i].second == el[j] && idx[j] < i)) {
		T[i][j][0] = (T[i][j][0] + T[i-1][j][0]) % mod;
	    }
	    for(int k = 1; k <= n; ++k) {
		T[i][j][k] = T[i-1][j][k];
		if(seq[i].first == 0) {
		    T[i][j][k] = (T[i][j][k] + T[i-1][j][k+1]) % mod;
		}
		if(seq[i].first == 1) {
		    if(seq[i].second < el[j] || (seq[i].second == el[j] && i < idx[j])) {
			T[i][j][k] = (T[i][j][k] + T[i-1][j][k-1]) % mod;
		    } else if(seq[i].second > el[j] || (seq[i].second == el[j] && idx[j] < i)){
			T[i][j][k] = (T[i][j][k] + T[i-1][j][k]) % mod;
		    }
		}
	    }
	}
    }
    long long sum = 0;
    for(int j = 1; j < ii; ++j) {
	for(int k = 0; k <= n; ++k) {
	    //cout << n << " " << j << " " << k << " " << T[n][j][k] << endl;
	    sum = (sum + (long long) el[j] * T[n][j][k]) % mod;
	}
    }
    cout << sum << endl;
}
