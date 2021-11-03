#include<iostream>
#include<cmath>

using namespace std;

int fac[11];

int main()
{
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 10; ++i) {
	fac[i] = i*fac[i-1];
    }
    int n, k;
    cin >> n >> k;
    double p;
    cin >> p;
    double star = 1;
    star *= fac[n] / (fac[k] * fac[n-k]);
    for(int i = 0; i < k; ++i) {
	star *= p;
    }
    for(int i = 0; i < n-k; ++i) {
	star *= (1-p);
    }
    double out = n + 1 / star;
    printf("%.12f\n", out);
}
