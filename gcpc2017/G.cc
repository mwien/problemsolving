#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

pair<long long, long long> T[100005];

long long gcd(long long a, long long b)
{
    while(b > 0) {
	long long tmp = b;
	b = a % b;
	a = tmp;
    }
    return a;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	long long x, y;
	cin >> x >> y;
	T[i] = {x,y};
    }
    long long a = 0;
    for(int i = 0; i < n; ++i) {
	a += T[i].first * T[(i+1)%n].second;
	a -= T[i].second * T[(i+1)%n].first;
    }
    a = abs(a);
    long long p = 0;
    for(int i = 0; i < n; ++i) {
	int dx = abs(T[i].first - T[(i+1)%n].first);
	int dy = abs(T[i].second - T[(i+1)%n].second);
	p += gcd(dx, dy);
    }
    cout << (a - p + 2) / 2 << endl;
}
