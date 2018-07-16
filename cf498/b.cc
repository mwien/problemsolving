// TAGS: SORTING
// Problem: http://codeforces.com/contest/1006/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    vector<int> o;
    o.push_back(-1);
    int sum = 0;
    for(int i = n-1; i >= n-k; --i) {
	o.push_back(v[i].second);
	sum += v[i].first;
    }
    sort(o.begin(), o.end());
    cout << sum << endl;
    for(int i = 0; i < k-1; ++i) {
	cout << o[i+1] - o[i] << " ";
    }
    cout << n- o[k-1]-1 << endl;
}
