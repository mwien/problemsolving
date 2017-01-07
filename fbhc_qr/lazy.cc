#include<iostream>
#include<set>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int tc = 0; tc < T; ++tc) {
	int N;
	cin >> N;
	multiset<int> items;
	for(int i = 0; i < N; ++i) {
	    int a;
	    cin >> a;
	    items.insert(a);
	}
	int cnt = 0;
	while(!items.empty()) {
	    int up = *prev(items.end());
	    items.erase(prev(items.end()));
	    int weight = up;
	    while(!items.empty() && weight < 50) {
		items.erase(items.begin());
		weight += up;
	    }
	    if(weight < 50) {
		break;
	    }
	    ++cnt;
	}
	cout << "Case #" << tc+1 << ": " << cnt << endl;
    }
}
