#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

char g[505][505];

int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
	    string x;
	    cin >> x;
	    for(int j = 0; j < m; ++j) {
		g[i][j] = x[j];
	    }
	}
	// for(int i = 0;  i< n; ++i) {
	//     for(int j = 0; j < m; ++j) {
	// 	cout << g[i][j];
	//     }
	//     cout << endl;
	// }
    for(int i = 0; i < n; ++i) {
	if((i % 3) != 0) continue;;
	for(int j = 0; j < m; ++j) {
	    g[i][j] = 'X';
	}
	if(i ==0) continue;
	bool done = false;
	for(int j = 0; j < m; ++j) {
	    if(g[i-2][j] == 'X') {
		g[i-1][j] = 'X';
		done = true;
		break;
	    }
	    if(g[i-1][j] == 'X') {
		g[i-2][j] = 'X';
		done = true;
		break;
	    }
	}
		    if(!done) {
		g[i-1][0] = 'X';
		g[i-2][0] = 'X';
		    }
    }
    if(n % 3 == 0) {
	vector<int> ei;
	for(int j = 0; j < m; ++j) {
	    if(g[n-1][j] == 'X') ei.push_back(j);
	}
	for(int j : ei) {
	    int idx = j;
	    bool done = false;
	    while(idx >= 0) {
		g[n-1][idx] = 'X';
		if(g[n-2][idx] == 'X') {
		    done = true;
		    break;
		}
		--idx;
	    }
	    if(!done) {
		idx = j+1;
		while(idx < m) {
		    if(g[n-1][idx] == 'X') {
			done = true;
			break;
		    }
		    g[n-1][idx] = 'X';
		    if(g[n-2][idx] == 'X') {
			done = true;
			break;
		    }
		    ++idx;
		}
	    }
	    if(!done) {
		g[n-2][m-1] = 'X';
	    }
	}
    }
    for(int i = 0; i < n; ++i) {
	for(int j = 0; j < m; ++j) {
	    cout << g[i][j];
	}
	cout << endl;
    }
    }
}
