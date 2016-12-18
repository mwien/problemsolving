#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    char mx, mn;
    int mini, maxi;
    mini = min(a, b);
    maxi = max(a, b);
    if(a >= b) {
	mx = 'G';
	mn = 'B';
    } else {
	mx = 'B';
	mn = 'G';
    }
    string o (n, mn);
    int sz = maxi / (mini + 1);
    int cmp = sz;
    if(maxi % (mini + 1) != 0) cmp = maxi / (mini + 1) + 1;
    if(sz > k) {
	cout << "NO" << endl;
    } else {
	int rest = maxi % (mini + 1);
	int ind = 0;
	while(ind < o.size()) {
	    for(int i = ind; i < sz + ind; ++i) {
		o[i] = mx;
	    }
	    ind += sz;
	    if(rest > 0) {
		o[ind+1] = mx;
		++ind;
		--rest;
	    }
	    ++ind;
	}
	cout << o << endl;
    }
}
