#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

pair<int, int> j[100005];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
	int a, b;
	cin >> a >> b;
	j[i] = {b, a};
    }
    sort(j, j+n);
    for(int i = 0; i < n; ++i) {
	cout << j[i].first << " " << j[i].second << endl;
    }
    list<pair<int, int>> m;
    for(int i = 0; i < k; ++i) {
	m.push_back({i, -1});
    }
    int ind = 0;
    int cnt = 0;
    while(ind < n) {
	pair<int, int> c = m.front();
	m.pop_front();
	while(ind < n && j[ind].second < c.second) ++ind;
	if(ind == n) break;
	c.second = j[ind].first;
	m.push_back(c);
	++cnt;
	++ind;
    }
    cout << cnt << endl;
}
