#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> s (n);
	vector<int> mx (n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		s[a-1].push_back(b);
		mx[a-1] = max(mx[a-1], b);
	}
	for(int i = 0; i < n; ++i) {
		sort(s[i].begin(), s[i].end());
	}
	sort(mx.begin(), mx.end());
	reverse(mx.begin(), mx.end());
	int first = mx[0] + mx[1];
	int second = 0;
	for(int i = 0; i < n; ++i) {
		reverse(s[i].begin(), s[i].end());
		if(s[i].size() < 2) continue;
		second = max(second, s[i][0] + s[i][1]/2);
	}
	cout << max(first, second) << endl;
}

