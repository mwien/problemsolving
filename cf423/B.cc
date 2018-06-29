#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

bool s[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    int xmn = 105, xmx = -1, ymn = 105, ymx = -1;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    char in;
	    cin >> in;
	    if(in == 'B') s[i][j] = true;
	    if(s[i][j]) {
		xmn = min(i, xmn);
		xmx = max(i, xmx);
		ymn = min(j, ymn);
		ymx = max(j, ymx);
		++cnt;
	    }
	}
    }
    int sz = max(xmx-xmn+1, ymx-ymn+1);
    if(cnt == 0) {
	cout << 1 << endl;
    } else if(sz > n || sz > m) {
	cout << -1 << endl;
    } else {
	cout << sz*sz-cnt << endl;
    }
}
