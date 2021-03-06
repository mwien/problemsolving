#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    vector<int> map (26, -1);
    bool poss = true;
    for(int i = 0; i < s.size(); ++i) {
	int f = s[i] - 'a', g = t[i] - 'a';
	if(map[f] == -1 || map[f] == g) {
	    map[f] = g;
	} else {
	    poss = false;
	    break;
	}
	if(f != g) {
	    if(map[g] == -1 || map[g] == f) {
		map[g] = f;
	    } else {
		poss = false;
		break;
	    }
	}
    }
    if(poss) {
	int cnt = 0;
	for(int i = 0; i < 26; ++i) {
	    if(map[i] == -1 || map[i] <= i) {
		continue;
	    }
	    ++cnt;
	}
	cout << cnt << endl;
	for(int i = 0; i < 26; ++i) {
	    if(map[i] == -1 || map[i] <= i) {
		continue;
	    }
	    cout << ((char) ('a' + i)) << " " << (char) ('a' + map[i]) << endl;
	}
    } else {
	cout << -1 << endl;
    }
}
