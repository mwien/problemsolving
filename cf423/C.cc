#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

const int sz = 2000005;
pair<int,int> T[sz];
string M[100005];
char res[sz];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for(int i = 0; i < sz; ++i) {
	T[i] = {0, -1};
	res[i] = 'A';
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	string in;
	cin >> in;
	M[i] = in;
	int l = M[i].size();
	int k;
	cin >> k;
	for(int j = 0; j < k; ++j) {
	    int x;
	    cin >>x;
	    if(l > T[x].first) {
		T[x].first = l;
		T[x].second = i;
	    }
	}
    }
    int r = 0;
    int idx = -1;
    int str = -1;
    for(int i = 0; i < sz; ++i) {
	if(T[i].first != 0) {
	    if(T[i].first + i - 1 > r) {
		r = T[i].first + i - 1;
		idx = 0;
		str = T[i].second;
	    }
	}
	if(str != -1 && r >= i) {
	    res[i] = M[str][idx];
	}
	++idx;
    }
    int last = -1;
    for(int i = sz-1; i >= 0; --i) {
	if(res[i] != 'A') {
	    last = i;
	    break;
	}
    }
    for(int i = 1; i <= last; ++i) {
	if(res[i] == 'A') {
	    cout << 'a';
	} else {
	    cout << res[i];
	}
    }
    cout << endl;
}
