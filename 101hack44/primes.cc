#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int g;
    cin >> g;
    vector<int> sieve;
    vector<int> primes;
    
    for(int i = 1; i < 100005; ++i) {
	sieve.push_back(i);
    }
    sieve[0] = 0;
    for(int i = 2; i < 100005; ++i) {
	if(sieve[i-1] != 0) {
	    primes.push_back(sieve[i-1]);
	    for(int j = 2 * sieve[i-1]; j < 100006; j += sieve[i-1]) {
		sieve[j-1] = 0;
	    }
	}
    }
    sort(primes.begin(), primes.end());
    vector<int> num (100005);
    int j = 0;
    int cnt = 0;
    for(int i = 0; i < 100005; ++i) {
	while(j < primes.size() && primes[j] <= i) {
	    ++j;
	    ++cnt;
	}
	num[i] = cnt;
    }
    for(int i = 0; i < g; ++i) {
	int n;
	cin >> n;
	if(num[n] % 2 == 0) {
	    cout << "Bob" << endl;
	} else {
	    cout << "Alice" << endl;
	}
    }
}
