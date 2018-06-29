#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, string>> p;
    for(int i = 0; i < n; ++i) {
	string a, b;
	cin >> a >> b;
	p.push_back({b, a});
    }
    sort(p.begin(), p.end());
    for(int i = 0; i < n; ++i) {
	cout << p[i].second << " " << p[i].first << endl;
    }
}
