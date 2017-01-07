#include<iostream>

using namespace std;

int main()
{
    long long mod = 1e9+9;
    int n;
    cin >> n;
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
	int u, v, w;
	cin >> u >> v >> w;
	sum += w;
    }
    long long res = sum % mod;
    for(int i = 
}
