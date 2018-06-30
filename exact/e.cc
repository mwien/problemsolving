// TAGS: DP
// Problem: https://open.kattis.com/problems/exactchange2

#include<iostream>

using namespace std;

const int sz = 20005;

int T[sz];

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	T[0] = 0;
	for(int i = 1; i < sz; ++i) {
	    T[i] = 105;
	}
	int bt;
	cin >> bt;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
	    int a;
	    cin >> a;
	    for(int j = sz-1; j >=0 ; --j) {
		if(j - a < 0) continue;
		T[j] = min(T[j], T[j-a] + 1);
	    }
	}
	for(int i = bt; i < sz; ++i) {
	    if(T[i] != 105) {
		cout << i << " " << T[i] << endl;
		break;
	    }
	}
    }
}
