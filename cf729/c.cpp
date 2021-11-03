#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

int freq[2];

long long lcm(long long n)
{
    long long ans = 1;   
    for (long long i = 1; i <= n; i++)
        ans = (ans * i)/(__gcd(ans, i));
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int tc = 0; tc < t; ++tc) {
	long long n;
	cin >> n;
	long long k = 2;
	long long fk = 2;
	long long rest = n;
	long long sum = 0;
	long long mod = 1e9+7;
	while(true) {
	    long long val = n / fk;
	    sum = (sum + (rest - val) * k) % mod;
	    if(val == 0) break;
	    rest = val;
	    ++k;
	    fk = lcm(k);
	}
	cout << sum << endl;
    }
}
