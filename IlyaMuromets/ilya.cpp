#include<iostream>

using namespace std;

long long pre[200005];
long long mx[200005];
long long sx[200005];
long long f[200005];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
	cin >> f[i];
    }
    for(int i = 1; i <= n; ++i) {
	pre[i] = pre[i-1] + f[i];
	mx[i] = max(mx[i-1], pre[i] - pre[max(i-k, 0)]);
    }
    long long res = 0;
    for(int i = n; i >= 0; --i) {
	res = max(res, pre[min(i+k, n)] - pre[i] + mx[i]);
    }
    cout << res << endl;
}
