#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

void solve(string &s, int n, int k)
{
    if(n - 2*k <= 0) {
	cout << "NO" << endl;
	return;
    }
    for(int i = 0; i < k; ++i) {
	if(s[i] != s[n-i-1]) {
	    cout << "NO" <<endl;
	    return;
	}
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    for(int T = 0; T < t; ++T) {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	solve(s, n, k);
    }
}
