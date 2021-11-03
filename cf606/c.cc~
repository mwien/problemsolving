#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	int n;
	cin >> n;
	unordered_map<int,int> h;
	for(int i = 0; i < n; ++i) {
	    int a;
	    cin >> a;
	    int cnt = 0;
	    while(a % 2 == 0) {
		++cnt;
		a /= 2;
	    }
	    if(h.find(a) != h.end()) {
		int cmp = h[a];
		if(cnt > cmp) {
		    h[a] = (cnt);
		}
	    } else {
		h[a] = cnt;
	    }
	}
	int res = 0;
	for(auto itt = h.begin(); itt != h.end(); ++itt) {
	    res += (itt->second);
	}
	cout << res << endl;
    }
}
