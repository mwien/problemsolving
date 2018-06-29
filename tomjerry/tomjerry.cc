#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

long long p = 1000000007;

long long fac[100005];
long long invfac[100005];

long long expmod(long long a, long long k) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % p;
    }
    k /= 2;
    cur = (cur * cur) % p;
  }
  return res;
}

long long choose(long long n, long long k)
{
    long long itm = fac[n] * invfac[k] % p;
    return itm * invfac[n-k] % p;
}

long long poss(long long a, long long b, long long c, long long d)
{
    return choose(abs(c-a) + abs(d-b), abs(c-a));
}

int main()
{
    long long w,h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<pair<int,int>> chs;
    for(int i = 0; i < n; ++i) {
	cin >> a >> b;
	chs.push_back({a,b});
    }
    fac[0] = 1;
    invfac[0] = 1;
    fac[1] = 1;
    invfac[1] = 1;
    for(int i = 2; i <= 100000; ++i) {
	fac[i] = fac[i-1] * i % p;
	invfac[i] = expmod(fac[i], p-2);
    }
    
}
