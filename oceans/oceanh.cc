#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int m = 1000000007;
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
	int n;
	string b;
	cin >> n >> b;
	int l = b.size();
	vector<vector<int>> P (n+1, vector<int> (l));
	vector<vector<int>> S (l);
	for(int i = 0; i < l; ++i) {
	    int mxo = 0, mxz = 0;
	    for(int j = l-i-1; j < l; ++j) {
		bool suff = true;
		bool oz = true;
		if(b[j] == '0') {
		    oz = false;
		}
		for(int k = 1; k+j < l; ++k) {
		    if(b[k+j] != b[l-i-1+k]) {
			suff = false;
			break;
		    }
		}
		if(suff && oz) {
		    mxo = max(mxo, l-j);
		} else if(suff && !oz) {
		    mxz = max(mxz, l-j);
		}
	    }
	    if(mxo < l) {
		S[mxo].push_back(i);
	    }
	    if(mxz < l)  {
		S[mxz].push_back(i);
	    }
	}
	P[1][0] = 1;
	if(l > 0) {
	    P[1][1] = 1;
	}
	for(int i = 2; i < n+1; i++) {
	    for(int j = 0; j < l; ++j) {
		for(int k = 0; k < S[j].size(); ++k) {
		    P[i][j] = (P[i][j] + P[i-1][S[j][k]]) % m;
		}
	    }
	}
	int res = 0;
	for(int i = 0; i < l; ++i) {
	    res = (res + P[n][i]) % m;
	}
	cout << res << endl;
    }
}
