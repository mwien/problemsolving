#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int T[105][15][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, c;
    cin >> n >> q >> c;
    for(int i = 0; i < n; ++i) {
	int x, y, s;
	cin >> x >> y >> s;
	++T[x][s][y];
    }
    for(int i = 0; i <= 101; ++i) {
	for(int j = 0; j <= c; ++j)  {
	    int sum = 0;
	    for(int k = 0; k <= 101; ++k) {
		sum += T[i][j][k];
		T[i][j][k] = sum;
	    }
	}
    }
    for(int r = 0; r < q; ++r) {
	int t, xl, yl, xh, yh;
	cin >> t >> xl >> yl >> xh >> yh;
	int res = 0;
	for(int i = xl; i <= xh; ++i) {
	    for(int j = 0; j <= c; ++j) {
		int p = T[i][j][yh] - T[i][j][yl-1];
		res += p*((j+t) % (c+1));
	    }
	}
	cout << res << endl;
    }
}
