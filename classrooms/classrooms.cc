#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>

using namespace std;

bool cmp(int lhs, int rhs)
{
    return lhs > rhs;
}

int main()
{
    int n, k;
    cin >> n >> k;
    //finishing time is first in pair
    vector<pair<int, int>> acts;
    for(int i = 0; i < n; ++i) {
	int s, f;
	cin >> s >> f;
	pair<int, int> new_pair(f, s);
	acts.push_back(new_pair);
    }
    sort(acts.begin(), acts.end());
    //key of algorithm is ordered set of classrooms
    multiset<int, decltype(cmp) *> crooms(cmp);
    for(int i = 0; i < k; ++i) {
	crooms.insert(0);
    }
    int sum = 0;
    for(int i = 0; i < n; ++i) {
	auto rm = crooms.lower_bound(acts[i].second - 1);
	if(rm == crooms.end()) continue;
	crooms.erase(rm);
	crooms.insert(acts[i].first);
	++sum;
    }
    cout << sum << endl;
}
