#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long fac = 1;
    for(int i = 3; i <= n; ++i) {
	fac = (fac * i) % 1000000007;
    }
    long long res = (fac * n) %  1000000007;
    cout << res << endl;
}
