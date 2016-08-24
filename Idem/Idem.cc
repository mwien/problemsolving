#include<iostream>

using namespace std;

int fac(long long f)
{
    long long res = 1;
    while(f > 1) {
	res = (res * f) % 1000000007;
	--f;
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
	long long n;
	cin >> n;
	cout << (fac(n) + 1000000006) % 1000000007 << endl;
    }
}
