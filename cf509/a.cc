#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int mn = 1e9+5, mx = 0;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	mn = min(mn, a);
	mx = max(mx, a);
    }
    cout << (mx - mn + 1) - n << endl;
}
