#include<iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(m < n-1 || m > 2*n - 3) {
	cout << -1 << endl;
	return 0;
    } 
    int cnt = 1;
    for(int i = 2; i <= n; ++i) {
	cout << 1 << " " << i << endl;
	++cnt;
	if(cnt > m) return 0;
    }
    for(int i = 2; i < n; ++i) {
	cout << n << " " << i << endl;
	++cnt;
	if(cnt > m) return 0;
    }
}
