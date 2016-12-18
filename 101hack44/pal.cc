#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> ch (n);
    for(int i = 0; i < n; ++i) {
	string in;
	cin >> in;
	ch.push_back(in[0] - 'a');
    }
    for(int i = 0; i < q; ++i) {
	int format;
	cin >> format;
	if(format == 1) {
	    int i, j, t;
	    cin >> i >> j >> t;
	    for(int l = i; l <= j; ++l) {
		ch[l] = (ch[l] + t) % 26;
	    }
	} else {
	    int i, j;
	    cin >> i >> j;
	    long long ans = 1;
	    vector<int> occ (26);
	    int num = 0;
	    for(int i = 0; i < n; ++i) {
		++occ[ch[i]];
	    }
	    for(int i = 0; i < 26; ++i) {
		if(occ[i] % 2 == 0) ++num;
	    }
	    for(int i = 0; i < num; ++i) {
		ans = (ans * 2) % 1000000007;
	    }
	    ans = (1 + (2
	}
    }
}
