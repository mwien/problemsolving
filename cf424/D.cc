#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >>p;
    int la = 0, ma = 0, ha = 0, lk = 0, mk = 0, hk = 0;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
	int x;
	cin >> x;
	a.push_back(x);
	if(x > p) {
	    ++ha;
	} else if(x < p) {
	    ++la;
	} else {
	    ++ma;
	}
    }
    sort(a.begin(), a.end())
    vector<int> b;
    for(int i = 0; i < k; ++i) {
	int x;
	cin >> x;
	b.push_back(x);
	if(x > p) {
	    ++lk;
	} else if(x < p) {
	    ++hk;
	} else {
	    ++mk;
	}
    }
    sort(b.begin(), b.end());
    long long res = 0;
    int mni = 0;
    if(lk < hk) {
	mni = 1;
	lk += mk;
	ha += ma;
    }
    if(mni == 0) {
	hk += mk;
	la += ma;
    }
    if(la < lk) {
	int i = 0;
	for(; i < n; ++i) {
	    if(a[i] >= 
	}
	res = max(res, 
    }
}
