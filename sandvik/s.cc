#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;

    long long res = 0;
    long long mx = 0;
    for(int i = 0; i < N; ++i) {
	long long a;
	cin >> a;
	res += a;
	mx = max(mx, a);
    }
    cout << res + mx * (P-1) << endl;
}
