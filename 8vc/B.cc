#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_set<string> pb, eb;
    int cp = 0, ce = 0, cb = 0;
    for(int i = 0; i < n; ++i) {
	string a;
	cin >> a;
	pb.insert(a);
    }
    cp = pb.size();
    for(int i = 0; i < m; ++i) {
	string a;
	cin >> a;
	if(eb.find(a) == eb.end()) {
	    if(pb.find(a) != pb.end()) {
		++cb;
	    }
	}
	eb.insert(a);
    }
    ce = eb.size();
    cp -= cb/2;
    ce -= cb/2;
    if(cb % 2 == 1) --ce;
    if(cp > ce) {
	cout << "YES" << endl;
    } else {
	cout << "NO" << endl;
    }
}
