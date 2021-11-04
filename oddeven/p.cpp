#include<iostream>

using namespace std;

long long T[105][2];

int main()
{
    int n;
    cin >> n;
    T[1][0] = 1;
    T[1][1] = 0;
    T[2][0] = 0;
    T[2][1] = 1;
    
    long long mod = 1000000007;
    
    for(int i = 3; i <= n; ++i) {
	T[i][0] = (T[i-2][0] + T[i-1][1]) % mod;
	T[i][1] = (T[i-2][0] + T[i-2][1]) % mod;
    }

    cout << (T[n][0] + T[n][1]) % mod << endl;
}
