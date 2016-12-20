#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main()
{
    int sz = 10005;
    int m = 1000000007;
    vector<pair<int, int>> P (sz);
    P[1].first = 1;
    P[1].second = 1;
    for(int i = 2; i < sz; ++i) {
	P[i].first = (P[i-1].first + P[i-1].second) % m;
	P[i].second = P[i-1].first % m;
    }
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
	int n;
	cin >> n;
	cout << (P[n].first + P[n].second) % m << endl;
    }
}
