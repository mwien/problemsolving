#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int a[300005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
	cin >> a[i];
    }

    sort(a+1, a+n+1);
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
	res += abs(a[i] - i);
    }
    cout << res << endl;
}
