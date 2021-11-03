#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
	int n, k;
	cin >> n >> k;
	vector<int> res;
	for(int j = k+1; j <= n; ++j) {
	    res.push_back(j);
	}
	for(int j = k/2; j < k; ++j) {
	    if(j * 2 < k) continue;
	    res.push_back(j);
	}
	cout << res.size() << endl;
	for(int j = 0; j < res.size(); ++j) {
	    cout << res[j] << " ";
	}
	cout << endl;
    }
}
