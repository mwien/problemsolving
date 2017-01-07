#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

bool check(int x, int y) {
    if(x >= 0 && x < 4 && y >= 0 && y < 4) {
	return true;
    }
    return false;
}

int main()
{
    vector<string> a;
    for(int i = 0; i < 4; ++i) {
	string b;
	cin >> b;
	a.push_back(b);
    }
    bool poss = false;
    for(int k = 0; k < 4; ++k) {
	if(poss) break;
	for(int l = 0; l < 4; ++l) {
	    if(poss) break;
	    if(a[k][l] != '.') continue;
	    a[k][l] = 'x';
	    for(int i = 0; i < 4; ++i) {
		if(poss) break;
		for(int j = 0; j < 4; ++j) {
		    if(a[i][j] != 'x') continue;
		    if(check(i-1, j) && check(i-2, j) && a[i-1][j] == 'x' && a[i-2][j] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i+1, j) && check(i+2, j) && a[i+1][j] == 'x' && a[i+2][j] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i, j+1) && check(i, j+2) && a[i][j+1] == 'x' && a[i][j+2] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i, j-1) && check(i, j-2) && a[i][j-1] == 'x' && a[i][j-2] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i+1, j-1) && check(i+2, j-2) && a[i+1][j-1] == 'x' && a[i+2][j-2] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i-1, j-1) && check(i-2, j-2) && a[i-1][j-1] == 'x' && a[i-2][j-2] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i-1, j+1) && check(i-2, j+2) && a[i-1][j+1] == 'x' && a[i-2][j+2] == 'x') {
			poss = true;
			break;
		    }
		    if(check(i+1, j+1) && check(i+2, j+2) && a[i+1][j+1] == 'x' && a[i+2][j+2] == 'x') {
			poss = true;
			break;
		    }
		}
	    }
	    a[k][l] = '.';
	}
    }
    cout << (poss ? "YES" : "NO") << endl;
}
