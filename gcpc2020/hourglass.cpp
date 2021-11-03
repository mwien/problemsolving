#include<iostream>

using namespace std;

int a[1005];

int main()
{
    int t, s, n;
    cin >> t >> s >> n;

    int sand = s;

    for(int i = 0; i < n; ++i) {
	cin >> a[i];
    }

    a[n] = t;
    
    int last = a[0];
    for(int i = 1; i <= n; ++i) {
	if(i % 2 == 0) sand = min(s, sand + (a[i] - last));
	if(i % 2 == 1) sand = max(0, sand - (a[i] - last));
	last = a[i];
    }
    if(n % 2 == 0) cout << s - sand << endl;
    if(n % 2 == 1) cout << sand << endl;
}
