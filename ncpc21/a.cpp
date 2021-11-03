#include<iostream>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    int mn = 1e9;
    int mx = 0;
    for(int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	mn += c;
	mx -= c;
	mn = min(mn, a);
	mx = max(mx, a);
	cout << max(a - mn, mx - a) << endl;
    }
}
