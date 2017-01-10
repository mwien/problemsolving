#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<string>
#include<set>

using namespace std;

bool myfunction (int i, int j) {return (i < j);}

int main()
{
    int n, k;
    set<int, decltype(myfunction) *> s(myfunction);
    for(int i = 0 ; i < n; ++i) {
	int a;
	cin >> a;
	s.insert(a);
    }
    int res = -1;
    while(true) {
	if(s.size() >= k) {
	    auto it = s.begin();
	    auto it2 = s.lower_bound((*it) / 2);
	    if(distance(it, it2) >= k-1) {
		res = 1;
		break;
	    }
	}
	auto it = s.begin();
	int b = *it;
	if(b < 2) {
	    res = -1;
	    break;
	}
	s.erase(it);
    	int a, c;
    	a = b / 2;
    	if(b % 2 == 0) {
    	    c = b / 2;
    	} else {
    	    c = b / 2 + 1;
    	}
    	s.insert(a);
    	s.insert(c);
     }
    
    cout << res << endl;
}
