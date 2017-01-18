#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

bool s[1000005];

void sieve(int M) {
    int n = 1000 * M + 3;
    for(int i = 2; i <= n; ++i) {
	s[i] = true;
    }
    for(int i = 2; i*i <= n; ++i) {
	if(s[i]) {
	    for(int j = i*i; j <= n; j+=i) {
		s[j] = false;
	    }
	}
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for(int i = 1; i <= 1000; ++i) {
	if(!s[i*n+1]) {
	    cout << i << endl;
	    break;
	}
    }
}
