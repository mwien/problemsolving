#include<iostream>

using namespace std;

long long a[100005];
long long b[100005];


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	cin >> a[i] >> b[i];
    }
    long long sa = 0, sas = 0;
    for(int i = 0; i < n; ++i) {
	sa += a[i];
	sas += a[i] * (a[i]-1) / 2;
    }
    long long res = 0;
    for(int i = 0; i < n; ++i) {
	long long ss = sa - a[i], ssa = sas - (a[i] * (a[i]-1)/2);
	res += b[i] * ((ss * (ss-1) / 2) - ssa);
    }
    cout << res << endl;
}
