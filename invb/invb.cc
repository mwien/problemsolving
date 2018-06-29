#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int SZ = 5005;
bool T[SZ][SZ+1][3];

int main()
{
    string a;
    cin >> a;
    bool poss = (a.size() % 2 == 0);
    if(!poss) {
	cout << "impossible" << endl;
    } else {
	if(a[0] == '(') {
	    T[0][1][0] = true;
	    T[0][1][1] = true;
	    T[0][1][2] = true;
	} else {
	    T[0][1][0] = false;
	    T[0][1][1] = true;
	    T[0][1][2] = true;
	}
	int n = a.size();
	for(int i = 1; i < n; ++i) {
	    for(int j = 1; j <= n; ++j) {
		bool check = (j >= i+1 - j);
		if(a[i] == '(') {
		    T[i][j][0] = T[i-1][j-1][0];
		    T[i][j][1] = T[i-1][j-1][0] || (T[i-1][j][1] && check);
		    T[i][j][2] = (T[i-1][j][1] && check) || T[i-1][j-1][2];
		} else {
		    T[i][j][0] = T[i-1][j][0] && check;
		    T[i][j][1] = (T[i-1][j][0] && check) || T[i-1][j-1][1];
		    T[i][j][2] = (T[i-1][j][2] && check) || T[i-1][j-1][1];
		}
	    }
	}
	poss = false;
	if(T[a.size()-1][a.size()/2][0] || T[a.size()-1][a.size()/2][1] || T[a.size()-1][a.size()/2][2]) {
	    poss = true;
	}
	cout << (poss ? "possible" : "impossible") << endl;
    }
}
