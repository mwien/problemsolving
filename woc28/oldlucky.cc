#include<iostream>
#include<vector>

using namespace std;

long long T[200005][1000];

int main()
{
    int mod = 1000000007;
    int n;
    cin >> n;
    vector<int> dig;
    for(int i = 0; i < n; ++i) {
	char a;
	cin >> a;
	dig.push_back(a - '0');
    }
    T[0][dig[0]] = 1;
    for(int i = 1; i < n; ++i) {
	T[i][dig[i]] = (T[i][dig[i]] + 1) % mod;
	for(int j = 0; j < 1000; ++j) {
	    T[i][(j * 10 + dig[i]) % 1000] = (T[i][(j * 10 + dig[i]) % 1000] + T[i-1][j]) % mod;
	    T[i][j] = (T[i][j] + T[i-1][j]) % mod;
	}
    }
    long long cnt = 0;
    for(int i = 0; i < 1000; ++i) {
	if((i % 8) == 0) {
	    cnt = (cnt + T[n-1][i]) % mod;
	    cout << i << " " << T[n-1][i] << endl;
	}
    }
    cout << cnt << endl;
}
