#include<iostream>
#include<algorithm>

using namespace std;

int h[15][105][105];

int rec(int s, int t, int r) {
    if(s > t) return 0;
    if(r == 1) return h[r][s][t];
    int min = (1 << 30);
    for(int i = s; i <= t; i++) {
	if(h[r][i+1][t] == -1) h[r][i+1][t] = rec(i+1, t, r);
	if(h[r-1][s][i-1] == -1) h[r-1][s][i-1] = rec(s, i-1, r-1);
	int res = i + max(h[r][i+1][t], h[r-1][s][i-1]);
	if(res <= min) min = res;
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    for(int tc = 0; tc < n; tc++) {
	int k, m;
	cin >> k >> m;
	for(int i = 1; i <= k; i++) {
	    for(int j = 1; j <= m; j++) {
		for(int l = 1; l <= m; l++) {
		    if(i == 1 && j <= l) {
		    	h[i][j][l] = l + h[i][j][l-1];
		    } else if(j <= l) {
			h[i][j][l] = -1;
		    }
		}
	    }
	}
	cout << rec(1, m, k) << endl;
    }
}
