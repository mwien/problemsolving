#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int,int>> coupons (M);

	multiset<int> prices;
	for(int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		prices.insert(a);
	}
	for(int i = 0; i < M; ++i) {
		int a;
		cin >> a;
		coupons[i].second = a;
	}
	for(int i = 0; i < M; ++i) {
		int a;
		cin >> a;
		coupons[i].first = a;
	}
	sort(coupons.begin(), coupons.end());

	long long res = 0;
	for(int i = M-1; i >= 0; --i) {
		if(prices.empty()) {
			break;	
		}
		auto it = prices.lower_bound(coupons[i].second);
		if (it != prices.end())	{
			res += (*it) - coupons[i].first;
			prices.erase(it);
		}
	}
	for(int p : prices) {
		res += p;
	}
	cout << res << endl;
}
