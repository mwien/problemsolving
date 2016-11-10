#include<iostream>
#include<cmath>

using namespace std;

long long l[10001];

int phi(int n)
{
    double result = n;
    for(int p = 2; p * p <= n; ++p) {
	if(n % p == 0) {
	    while(n % p == 0) n /= p;
	    result *= (1.0 - (1.0 / (double) p));
	}
    }
    if(n > 1) result *= (1.0 - (1.0 / (double) n));
    return round(result);
}

int main()
{
    long long sum = 0;
    for(int i = 0; i <= 10000; ++i) {
	l[i] = sum + phi(i);
	sum += phi(i);
    }
    int P;
    cin >> P;
    for(int i = 0; i < P; ++i) {
	int K, N;
	cin >> K >> N;
	cout << K << " " << l[N]+1 << endl;
    }
}
