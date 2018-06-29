#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    int x;
    string p;
    cin >> x >> p;
    int men = 0, women = 0;
    while(abs(men - women) <= x && !p.empty()) {
	if(men >= women) {
	    if(p[0] == 'W') {
		p.erase(0, 1);
		++women;
	    } else if(p[1] == 'W') {
		p.erase(1, 1);
		++women;
	    } else {
		p.erase(0, 1);
		++men;
	    }
	} else {
	    if(p[0] == 'M') {
		p.erase(0, 1);
		++men;
	    } else if(p[1] == 'M') {
		p.erase(1, 1);
		++men;
	    } else {
		p.erase(0, 1);
		++women;
	    }
	}
	// cout << men << " " << women << " " << p << endl;
    }
    int res = men + women;
    if(abs(men - women) > x) --res;
    cout << res << endl;
}
