#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<list>
#include<string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    list<char> v;
    string s;
    cin >> s;
    int cntd = 0, cntr = 0;
    for(int i = 0; i < n; ++i) {
	if(s[i] == 'D' || s[i] == 'R') v.push_back(s[i]);
	if(s[i] == 'D') {
	    ++cntd;
	} else  if(s[i] == 'R'){
	    ++cntr;
	}
    }
    int deld = 0, delr = 0;
    bool win = false;
    if(cntr == 0) {
	win = true;
    }
    while(cntd > 0 && cntr > 0) {
	// for(auto it = v.begin(); it != v.end(); ++it) {
	//     cout << (*it) << " ";
	// }
	// cout << endl;
	// cout << deld << " " << cntd << " " << delr << " " << cntr << endl;
	for(auto it = v.begin(); it != v.end();) {
	    if((*it) == 'D') {
		if(deld > 0) {
		    --deld;
		    --cntd;
		    if(cntd == 0) {
			win = false;
			break;
		    }
		    it = v.erase(it);
		    continue;
		}
		if(delr < cntr) {
		    ++delr;
		}
		++it;
	    } else {
		if(delr > 0) {
		    --delr;
		    --cntr;
		    if(cntr == 0) {
			win = true;
			break;
		    }
		    it = v.erase(it);
		    continue;
		}
		if(deld < cntd) {
		    ++deld;
		}
		++it;
	    }
	}
    }
    cout << (win ? 'D' : 'R') << endl;
}
