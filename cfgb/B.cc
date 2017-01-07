#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int y = 20000;
    bool poss = true;
    for(int i = 0; i < n; ++i) {
	int t;
	cin >> t;
	string dir;
	cin >> dir;
	if(dir == "North") {
	    if(y + t > 20000) {
		poss = false;
		break;
	    } else {
		y += t;
	    }
	} else if(dir == "South") {
	    if(y - t < 0) {
		poss = false;
		break;
	    } else {
		y -= t;
	    }
	} else if(y == 20000 || y == 0) {
	    poss = false;
	}
    }
    if(!poss) {
	cout << "NO" << endl;
    } else {
	if(y == 20000) {
	    cout << "YES" << endl;
	} else {
	    cout << "NO" << endl;
	}
    }
}
