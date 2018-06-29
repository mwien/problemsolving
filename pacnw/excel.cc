#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	s.push_back(a);
    }
    sort(s.begin(), s.end());
    int mn = 1e6+5;
    for(int i = 0; i < n/2; ++i) {
	mn = min(mn, s[i] + s[n-i-1]);
    }
    cout << mn << endl;
}
