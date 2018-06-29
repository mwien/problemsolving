#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> occ (105);
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	++occ[a];
	++occ[a+1];
    }
    int mx = 0;
    for(int i = 0; i < 105; ++i) {
	mx = max(mx, occ[i]);
    }
    cout << mx << endl;
}
