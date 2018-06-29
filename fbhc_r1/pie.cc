#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> c (n);
	for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < m; ++j) {
		int a;
		cin >> a;
		c[i].push_back(a);
	    }
	    sort(c[i].begin(), c[i].end());
	}
	vector<vector<long>> B (n, vector<long> (n+1, -1));
	for(int i = 0; i < n; ++i) {
	    vector<long> cost (m+1);
	    cost[0] = 0;
	    cost[1] = c[i][0] + 1;
	    for(int j = 2; j <= m; ++j) {
		cost[j] = c[i][j-1] + cost[j-1] + (j)*(j) - (j-1)*(j-1);
	    }
	    if(i == 0) {
		for(int j = 1; j <= min(n, m); ++j) {
		    B[i][j] = cost[j];
		}
	    } else {
		for(int j = i; j <= n; ++j) {
		    if(B[i-1][j] == -1) continue;
		    for(int k = 0; k + j <= n && k <= m; ++k) {
			if(B[i][k+j] == -1) {
			    B[i][k+j] = B[i-1][j] + cost[k];
			} else {
			    B[i][k+j] = min(B[i][k+j], B[i-1][j] + cost[k]);
			}
		    }
		}
	    }
	}
	cout << "Case #" << t+1 << ": " << B[n-1][n] << endl;
    }
}
