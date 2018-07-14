#include<iostream>
#include<algorithm>

using namespace std;

bool cp (pair<long long, long long> i, pair<long long, long long> j) {return (i > j);}
pair<long long, long long> s[10005];

long long cmp(int n) {
    double v = 0, l = 0;
    for(int i = 0; i < n; ++i) {
	l += v*s[i].second+0.5*s[i].first*s[i].second*s[i].second;
	v += s[i].first*s[i].second;
    }
    return l;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
	long long a, t;
	cin >> a >> t;
	s[i] = {a, t};
    }
    double res = cmp(n);
    sort(s, s + n, cp);
    res = cmp(n) - res;
    printf("%.1f\n", res);
}
